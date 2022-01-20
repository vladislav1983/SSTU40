/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/

/*----------------------------------------------------------------------------*/
/* Body Identification                                                        */
/*----------------------------------------------------------------------------*/
#ifdef IDENT_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define IDENT_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "ident.h"
#include "tempctrl.h"
#include "statemachine.h"
#include "triac_control.h"
#include "DigitalIO.h"
#include "measure.h"
#include "trace.h"
#include "MathTools.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/
#define TIMER_READ                0
#define TIMER_LOAD                1
#define TIMER_COUNT               2

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
struct cartridge_ident ident = 
{
  .IDENT_MAX_RMS_Power = 0,
  .Ident_peak_current = 0,
  .U_Temp_delta = 0,
  .U_Temp_in = 0,
  .U_Temp_out = 0,
  .U_Temp_filt = 0,
  .ident_mode = IDENT_INIT,
  .ident_periods = 0,
  .triac_state = 0,
  .IdentCurrent_filt = 0,
  .Ident_current = 0,
  .IdentTool = eIdentTool_Unknown,
  .Kp = 0,
  .Dt_counter = 0,
  .Dt_Temp_in = 0,
  .Dt_us = 0,
  .Tp_us = 0,
  // stored in nvm
  .ident_deltaT_trip_low  = 15,
  .ident_deltaT_trip_high = 50,
  .ident_current_trip = 12000,  // 12A default trip
  .ident_periods_load = 16,
  .ident_cur_2210_low = 2000,
  .ident_cur_2210_high = 4000,
  .ident_cur_2245_low  = 4500,
  .ident_cur_2245_high = 9000,
};

/* TRACE.C */
extern S16 TRSB[TRACE_LEN][NB_TRACE_VARS];
extern U16 trace_state;
extern U16 trace_control;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/
U16 ident_timer_t1(U16 cmd, U16 cons);
U16 ident_timeout_timer_t1(U16 cmd, U16 cons);
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Purpose: Cartridge identification.
 * Input: INIT init flag. If '1' perform init. If '0' perform ident.    
 * Output: 1: Ident finished 0: Ident in progress.
 */
/******************************************************************************/
BOOL cartridge_ident(BOOL ident_init,U16 ADC_Temp_Ch)
{
  struct cartridge_ident *id = _get_ident();
  U16 ident_current;
  BOOL result = 0;
  const BOOL zero_cross = _zero_cross();
  
  if(ident_init) id->ident_mode = IDENT_INIT; //Check for identification.
  
  switch(id->ident_mode)
  {
    /*---------------------------------------------------*/    
    case IDENT_INIT:
    {
      if(id->ident_periods_load > IDENT_PERIODS_MAX) 
        id->ident_periods_load = IDENT_PERIODS_MAX; //Load halfperiods for identification
      
      ident_timer_t1(TIMER_LOAD, 20);    //load timer 
      
      id->ident_mode = IDENT_WAIT_MES_TEMP;     
      id->IDENT_MAX_RMS_Power = 0;
      id->Ident_peak_current = 0;
      id->U_Temp_delta = 0;
      id->U_Temp_in = 0;
      id->U_Temp_out = 0;
      id->U_Temp_filt = 0;
      id->triac_state = 0;
      id->IdentCurrent_filt = 0;
      id->Ident_current = 0;
      id->IdentTool = eIdentTool_Unknown;
      id->ident_periods = id->ident_periods_load;
      id->Kp = 0;
      id->Dt_counter = 0;
      id->Dt_Temp_in = 0;
      id->Dt_us = 0;
      id->Tp_us = 0;
    }
    break;
    /*---------------------------------------------------*/
    case IDENT_WAIT_MES_TEMP:
    {
      if(zero_cross)
      {
        if(ident_timer_t1(TIMER_COUNT, 0)) 
        {
          ident_timer_t1(TIMER_LOAD, IDENT_AVERAGE_TIME);
          id->ident_mode = IDENT_MES_TEMP;
        }
      }
    }
    break;
    /*---------------------------------------------------*/
    case IDENT_MES_TEMP:
    {
      if(ident_timer_t1(TIMER_COUNT, 0))
      {
        #define TEMP_FILT_ms  200.0
        id->U_Temp_filt += (S32)( (S32)( (65.536 * (F32)T1_TIME) / TEMP_FILT_ms ) * (S16)(ADC_Temp_Ch - Hi(id->U_Temp_filt)) );
        #undef TEMP_FILT_ms
      }
      else
      {
        id->U_Temp_in = Hi(id->U_Temp_filt);
        id->U_Temp_filt = 0;
        id->ident_mode = IDENT_TRIAC_FIRE;
      }
    }
    break;
    /*---------------------------------------------------*/    
    case IDENT_TRIAC_FIRE:
    {
      if(zero_cross)
      {
        if(id->ident_periods)
        {
          id->ident_periods--;
          if(_drive_enabled()) 
          {
            _FIRE_TRIAC();
            id->triac_state = TRUE;
          }
        }
        else
        {
          id->ident_mode = IDENT_WAIT_AFTER_ZC;
          ident_timer_t1(TIMER_LOAD, IDENT_MEASURE_AFTER_TIME); // Load timer for measure start after zero cross
          id->triac_state = FALSE;
        }
      }
      
      ident_current = absi(mes1.Current);
      #define CURRENT_FILT_ms  20.0
      id->IdentCurrent_filt += (S32)( (S32)( (65.536 * (F32)T1_TIME) / CURRENT_FILT_ms ) * (S16)(ident_current - Hi(id->IdentCurrent_filt)) );
      #undef CURRENT_FILT_ms
      
      if(ident_current > id->ident_current_trip)
      {
        _set_ident_error(1);
        _set_overcurrent_error(1);
      }
      
      if(ident_current > id->Ident_peak_current)
      {
        id->Ident_peak_current = ident_current;
      }
    }  
    break;
    /*---------------------------------------------------*/    
    case IDENT_WAIT_AFTER_ZC: 
    {
      if(!ident_timer_t1(TIMER_COUNT, 0))
      {
        id->ident_mode = IDENT_MES_TEMP_2;
      }
    }
    break;
    /*---------------------------------------------------*/    
    case IDENT_MES_TEMP_2:
    {
      #define TEMP_FILT_ms  50.0
      id->U_Temp_filt += (S32)( (S32)((65.536 * (F32)T1_TIME) / TEMP_FILT_ms) * (S16)(ADC_Temp_Ch - Hi(id->U_Temp_filt)) );
      #undef TEMP_FILT_ms
      U16 U_Temp_max = Hi(id->U_Temp_filt);
      
      if(id->Dt_counter == 0)
      {
        id->Dt_Temp_in = ADC_Temp_Ch;
        id->Dt_counter = IDENT_MEASURE_AFTER_TIME;
      }

      if(U_Temp_max > id->U_Temp_out)
      {
        id->U_Temp_out = U_Temp_max;
        id->Dt_counter++;
      }
      else
      {
        id->ident_mode = IDENT_EXIT;
      }
    }
    break;
    /*---------------------------------------------------*/    
    case IDENT_EXIT:
    {
      id->U_Temp_delta = id->U_Temp_out - id->U_Temp_in;
      if(id->U_Temp_delta < id->ident_deltaT_trip_low)    _set_ident_error(1);
      if(id->U_Temp_delta > id->ident_deltaT_trip_high)   _set_ident_error(1);
      
      
      U16 IDENT_Peak_Power    = _builtin_divud( ((U32)id->Ident_peak_current  * mespar.Transformer_Voltage), 1000u);
      id->IDENT_MAX_RMS_Power =  fmul_qu15(qSQRT2, IDENT_Peak_Power);
      
      id->ident_mode = IDENT_UNDEFINED_STATE;
      
      // calculate identification current
      ident_current = Hi(id->IdentCurrent_filt);
      id->Ident_current = fmul_qu15(ident_current, ( (PI / (2.0 * SQRT2) ) * 32768.0)); // from avg to rms current
      
      if(   id->Ident_current > id->ident_cur_2210_low
         && id->Ident_current < id->ident_cur_2210_high )
      {
        id->IdentTool = eIdentTool_2210;
      }
      else if(   id->Ident_current > id->ident_cur_2245_low 
              && id->Ident_current < id->ident_cur_2245_high )
      {
        id->IdentTool = eIdentTool_2245;
      }
      else
      {
        id->IdentTool = eIdentTool_Unknown;
      }
      
      // process gain calculation
      if(id->ident_periods_load > 0)
      {
        id->Kp = ( ((S16)id->U_Temp_out - (S16)id->Dt_Temp_in) * (S32)1000uL) / id->ident_periods_load;
      }
      else
      {
        _set_param_limit_error(1);
      }
      // process dead time calculation
      id->Dt_us = ((U32)id->Dt_counter * 100u);
      
      // process time constant calculation
      // tp = 0.63 * dt. ident_periods_load is in half periods (10ms)
      // (U16)(0.63 * 100.0) * (U16)( (id->ident_periods_load * ((10u * 1000u) / 100u) ) + ( id->Dt_counter * (100u / 100u) ) );
      id->Tp_us = (U32)(63u) * (U16)( (id->ident_periods_load * 100u) + id->Dt_counter );
      
      result = 1; //quit ident
    }
    break;
    /*---------------------------------------------------*/
    case IDENT_UNDEFINED_STATE:
      // do nothing here
      break;
    default :   // Undefined state
      mAssert(cFalse);
      _set_global_system_fault(1);
      break;
      
  }//end switch
  
  return(result);
}
/******************************************************************************/
/*
 * Purpose: 
 * Input: 
 * Output: 
 */
/******************************************************************************/
teIdentToolType ident_get_current_tool(void)
{
  return ident.IdentTool;
}

/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Name: Software Timer for IDENT module  TASK1 
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task1 periods
 */
/******************************************************************************/
U16 ident_timer_t1(U16 cmd, U16 cons)               
{         
  static U16 count = 0;
  
  if(cmd == TIMER_LOAD)
  {
    count = cons;    
  }
  else if(count > 0 && cmd == TIMER_COUNT) 
  {
    count--;
  }
  
  return(count);
}
/******************************************************************************/
/*
 * Name: Software Timer for IDENT module  TASK1 
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task1 periods
 */
/******************************************************************************/
U16 ident_timeout_timer_t1(U16 cmd, U16 cons)               
{         
  static U16 count = 0;
  
  if(cmd == TIMER_LOAD)
  {
    count = cons;    
  }
  else if(count > 0 && cmd == TIMER_COUNT)
  {
    count--;
  }
  
  return(count);
}

