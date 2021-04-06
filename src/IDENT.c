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

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/

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
struct cartridge_ident ident;

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
inline U16 ident_timer_t1(U16 cmd, U16 cons);
inline U16 ident_timeout_timer_t1(U16 cmd, U16 cons);
BOOL bresenham(U16 periods);
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
  struct cartridge_ident *id;
  U16 ident_current;
  BOOL result = 0;
  
  id = _get_ident();
  
  if(ident_init) (id)->ident_mode = IDENT_INIT; //Check for identification.
  
  switch((id)->ident_mode)
  {
    /*---------------------------------------------------*/    
    case IDENT_INIT:
      if((id)->ident_periods_load > IDENT_PERIODS_MAX) (id)->ident_periods = IDENT_PERIODS_MAX; //Load halfperiods for identification
      else (id)->ident_periods = (id)->ident_periods_load;
      
      ident_timer_t1(1, IDENT_AVERAGE_TIME);    //load timer for averaging
      
      (id)->ident_mode = IDENT_MES_TEMP;
      (id)->U_Temp_out = 0;
      (id)->U_Temp_in = 0;
      (id)->U_Temp_max = 0;
      (id)->U_Temp_delta = 0;
      (id)->Ident_peak_current = 0;
      (id)->IDENT_Peak_Power = 0;
      (id)->IDENT_MAX_RMS_Power = 0;
      
      result = 0;
      break;
      /*---------------------------------------------------*/    
    case IDENT_MES_TEMP:
      ident_timer_t1(2, 0); //Count timer
      
      if(ident_timer_t1(0, 0)) //Read timer
      {
        (id)->U_Temp_sum += ADC_Temp_Ch;
        (id)->ident_mes_temp = 1;
      }
      else
      {
        (id)->U_Temp_in = (id)->U_Temp_sum >> IDENT_AVERAGE_DIVIDER;
        (id)->U_Temp_sum = 0;
        (id)->ident_mes_temp = 0; // Measure flag used for debug
        
        //if((id)->U_Temp_in > MAX_TEMP_TRIP_RAW) _set_overtemperature_error(1); /* if overtemperature --> trip error */
        
        bresenham((id)->ident_periods); // Load bresenham distribution routine for periods distribution
        
        if((id)->ident_trace_start == IDENT_TRACE_START_BEFORE_SHOT) // Start trace for debug
        {
          _set_reset_trace(1);
          _set_manual_start_trace(1);
        }
        
        (id)->ident_mode = IDENT_TRIAC_FIRE;
      }
      result = 0;
      break;
      /*---------------------------------------------------*/    
    case IDENT_TRIAC_FIRE:
      if(_zero_cross())
      {
        if(bresenham(0)) (id)->ident_mode = IDENT_WAIT_STATE;
      }
      
      ident_current = absi(mes1.Current);
      if(ident_current > (id)->ident_current_trip)
      {
        _set_ident_error(1);
        _set_overcurrent_error(1);
      }
      if(ident_current > (id)->Ident_peak_current) (id)->Ident_peak_current = ident_current;
      
      result = 0;
      break;
      /*---------------------------------------------------*/
    case IDENT_WAIT_STATE: //Wait one task period for temp update 
      
      if((id)->ident_trace_start == IDENT_TRACE_START_AFTER_SHOT)
      {
        _set_reset_trace(1);
        _set_manual_start_trace(1);
      }
      (id)->ident_mode = IDENT_WAIT_AFTER_ZC;
      
      ident_timer_t1(1, IDENT_MEASURE_AFTER_TIME); // Load timer for measure start after zero cross
      
      result = 0;    
      break;
      /*---------------------------------------------------*/    
    case IDENT_WAIT_AFTER_ZC: //Wait one period for temp update 
      ident_timer_t1(2, 0); //Count timer
      
      if(!ident_timer_t1(0, 0))
      {
        (id)->ident_mode = IDENT_MES_TEMP_2;
        ident_timeout_timer_t1(1, IDENT_MES_TIME_AFTER_SHOT);    //load timer 2s
        ident_timer_t1(1, IDENT_AVERAGE_TIME);    //load timer for averaging
        (id)->ident_mes_temp = 1;
      }
      result = 0;    
      break;
      /*---------------------------------------------------*/    
    case IDENT_MES_TEMP_2:
      ident_timeout_timer_t1(2, 0); //count ident timer
      ident_timer_t1(2, 0); //Count timer
      
      if(ident_timer_t1(0, 0))
      {
        (id)->U_Temp_sum += ADC_Temp_Ch;
        result = 0;
      }
      else
      {
        (id)->ident_mes_temp = 0;
        (id)->U_Temp_max = (id)->U_Temp_sum >> IDENT_AVERAGE_DIVIDER;
        (id)->U_Temp_sum = 0;
        
        ident_timer_t1(1, IDENT_AVERAGE_TIME);    //load timer for averaging
        
        //if((id)->U_Temp_max > MAX_TEMP_TRIP_RAW) _set_overtemperature_error(1); /* if overtemperature --> trip error */
        
        if(((id)->U_Temp_max)> ((id)->U_Temp_out))
        {
          (id)->U_Temp_out = (id)->U_Temp_max;
        }
        else
        {
          if(!ident_timeout_timer_t1(0, 0)) (id)->ident_mode = IDENT_EXIT;
        }
        
        result = 0;
      }
      break;
      /*---------------------------------------------------*/    
    case IDENT_EXIT:
      
      (id)->U_Temp_delta = (id)->U_Temp_out - (id)->U_Temp_in;
      if((id)->U_Temp_delta < (id)->ident_deltaT_trip) _set_ident_error(1);
      
      (id)->IDENT_Peak_Power = (((id)->Ident_peak_current / 1000) * mespar.Transformer_Voltage);
      (id)->IDENT_MAX_RMS_Power = ((id)->IDENT_Peak_Power / SQRT_OF_TWO);
      
      (id)->ident_mode = IDENT_UNDEFINED_STATE;
      
      result = 1; //quit ident
      
      break;
      /*---------------------------------------------------*/    
      
    default :   // Undefined state
      mAssert(cFalse);
      _set_global_system_fault(1);
      break;
      
  }//end switch
  
  return(result);
  
}
/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Purpose: Bresenham periods distribution
 * Input: Periods for distribution. If periods !=0 load periods. If periods == 0 execute distrubution.
 * Output: Distribution status: 0: Operation in progress 1: Distribution finished
 * Note: Function is run in zero cross!!!
 */
/******************************************************************************/
BOOL bresenham(U16 periods)
{
  struct bresenham_struct *bs;
  
  bs = _get_bresenham_struct();
  
  if(periods)
  {
    (bs)->delta_err = (periods << 1) - BSM_CONTROL_PERIODS_MAX;
    (bs)->control_periods = periods;
    (bs)->bs_period_counter = BSM_CONTROL_PERIODS_MAX;
    return(0);
  }
  else if((bs)->bs_period_counter)
  {
    if((bs)->delta_err > 0)
    {
      (bs)->delta_err += ((bs)->control_periods - BSM_CONTROL_PERIODS_MAX) << 1;
      if(_drive_enabled()) _FIRE_TRIAC();
      (bs)->triac_state = 1;
    }
    else
    {
      (bs)->delta_err += (bs)->control_periods << 1;
      _TRIAC_OFF();
      (bs)->triac_state = 0;
    }
    
    (bs)->bs_period_counter--;
    return(0);
  }
  else
  {
    (bs)->bs_period_counter = 0;
    (bs)->triac_state = 0;
    return(1);
  }
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
inline U16 ident_timer_t1(U16 cmd, U16 cons)               
{         
  static U16 count;
  
  if(cmd==1)    count = cons;    
  else if(count && cmd==2) count--;
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
inline U16 ident_timeout_timer_t1(U16 cmd, U16 cons)               
{         
  static U16 count;
  
  if(cmd==1)    count = cons;    
  else if(count && cmd==2) count--;
  return(count);
}

