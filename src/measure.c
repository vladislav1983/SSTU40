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
#ifdef MEASURE_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define MEASURE_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "measure.h"
#include "task.h"
#include "tempctrl.h"
#include "statemachine.h"
#include "DigitalIO.h"
#include "ident.h"
#include "adc_drv.h"
#include "MathTools.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/
#define cZC_TIMER_READ                0
#define cZC_TIMER_START               1
#define cZC_TIMER_COUNT               2

// zero cross trip thresholds in TASK1 periods
#define cZC_TRIP_MAX                  MS_TO_T1_TICKS(11.7) // 11.7ms
#define zZC_TRIP_MIN                  MS_TO_T1_TICKS(7.7)  // 7.7ms

// zero cross window times in TASK1 periods
#define cZC_CLOSED_WINDOW_TIMER       MS_TO_T1_TICKS(7.5)                               // zc detection disabled
#define cZC_OPEN_WINDOW_TIMER         (MS_TO_T1_TICKS(12.5) - cZC_CLOSED_WINDOW_TIMER)  // zc detection enabled

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
typedef enum teZeroCrosDetectionState
{
  eZeroCrossOpenWindow,
  eZeroCrossClosedWindow
}eZeroCrosDetectionState;
/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
eZeroCrosDetectionState ZeroCrosDetectionState;

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
/* Data structures declaration */
struct Mes1 mes1 = {0};
struct Mes2 mes2 = {0};
struct mes_par mespar  = 
{
  .dc_average_counter = DC_AVERAGE_TIME,
  .dc_sum = 0,

  /* PARAMS STORED IN EEPROM */
  .Transformer_Voltage =19,
  .Overcurr_limit = 12000,
};

/*----------------------------------------------------------------------------*/
/* Exported data from other modules                                           */
/*----------------------------------------------------------------------------*/
extern volatile U16 TASK_CONTROL;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/
static U16 ZeroCrossTimerT1(U16 u16Command, U16 u16Cons);

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Purpose: Zero Cross detection II. This function is run BEFORE temperature control.
 * Input:   none
 * Output:  none
 * Affected System Flags
 * - _zero_cross()
 */
/******************************************************************************/
void zero_cross_II(void)
{
  struct Mes1 *m1 = _get_mes1();
  struct Mes2 *m2 = _get_mes2();
  
  switch(ZeroCrosDetectionState)
  {
    //--------------------------------------------------------------------------------------------------------------
    case eZeroCrossOpenWindow:
      
      (m1)->Line_period_zc++;  /* Update line period (Zero Cross)*/
      
      if(_INT0IF) 
      {
        _set_zero_cross(1);
        (m2)->Line_period_zc_T2 = (m1)->Line_period_zc;
        (m1)->Line_period_zc = 0;
        
        if(_power_up_ok()) 
        {
          if(    ((m2)->Line_period_zc_T2 >= cZC_TRIP_MAX) 
              || ((m2)->Line_period_zc_T2 <= zZC_TRIP_MIN)) 
          {
            _set_grid_freq_error(1); //Trip Grid Frequency Error
          }
        }
        
        // start closed window timer
        ZeroCrossTimerT1(cZC_TIMER_START, cZC_CLOSED_WINDOW_TIMER);
        ZeroCrosDetectionState = eZeroCrossClosedWindow;
        _INT0IF = 0;
      }
      break;
      //--------------------------------------------------------------------------------------------------------------
    case eZeroCrossClosedWindow:
      
      ZeroCrossTimerT1(cZC_TIMER_COUNT, (U16)NULL);
      
      if(0 != ZeroCrossTimerT1(cZC_TIMER_READ, (U16)NULL))
      {
        ZeroCrosDetectionState = eZeroCrossOpenWindow;
        // we do not want false zero crosses -> clear interrupt flag
        _INT0IF = 0;
      }
      
      break;
      //--------------------------------------------------------------------------------------------------------------
    default:
      mAssert(cFalse);
      _set_global_system_fault(1);
      break;
  }
}
/******************************************************************************/
/*
 * Purpose: DC autotuninning in current measure channel.
 * Input: ADC Channel
 * Output:  1: DC autotunning complete  0: DC autotunning in progress
 */
/******************************************************************************/
BOOL DC_Autotunning(void)
{
  struct Mes1 *m1 = _get_mes1();
  struct mes_par *mp = _get_mespar();
  BOOL result;
  const _Q15 ADC_Currnet_Raw = AdcReadChannel(ADC_CH1_CURRENT);
  
  if((mp)->dc_average_counter)
  {
    
    (mp)->dc_sum += ADC_Currnet_Raw;
    (mp)->dc_average_counter--;
    result = 0;
  }
  else
  {
    (m1)->Curr_offset = (mp)->dc_sum >> DC_AVERAGE_DIVIDER;
    
    (mp)->dc_sum = 0;
    (mp)->dc_average_counter = DC_AVERAGE_TIME;
    if((m1)->Curr_offset < DC_OFFSET_LOWER_LIMIT || (m1)->Curr_offset > DC_OFFSET_UPPER_LIMIT) _set_current_offset_error(1);
    result = 1;
  }
  
  return(result);
}
/******************************************************************************/
/*
 * Purpose: Current measure and overcurrent trip. Run in task1
 * Input: ADC current channel
 * Output:  none
 * 
 * Current conversion calculations
 * 
 * Rsh = 0.05 Ohm - Current measure resistor
 * G = 2 - Current measure amplifier gain
 * Uoff = 2.5 V - Voltage offset
 * U_Rsh_max = 2.5 / 2 = 1.25V
 * Imax = U_Rsh_max / Rsh 1.25 / 0.05 = 25A
 */
/******************************************************************************/
void Current_measure(void)
{
  struct Mes1 *m1 = _get_mes1();
  struct mes_par *mp = _get_mespar();
  S16 Current_limit;
  S16 Current_tmp;
  const _Q15 ADC_Currnet_Raw = AdcReadChannel(ADC_CH1_CURRENT);
  
  Current_limit = (m1)->Curr_offset + (mp)->Overcurr_limit;
  Current_tmp = ADC_Currnet_Raw - (m1)->Curr_offset;

  (m1)->Current = fmul_q15(Current_tmp,  CURRENT_MAX_mA);
  
  if(_power_up_ok())
  {
    if(    ((m1)->Current > Current_limit) 
        || ((m1)->Current < -Current_limit)) 
    {
      _set_overcurrent_error(1);
    }
  }
}

/******************************************************************************/
/*
 * Purpose: Measurements and conversion in task2 
 * Input: 
 * Output:  
 */
/******************************************************************************/
void measure_T2(void)
{
  struct Mes2 *m2 = _get_mes2();
  struct overload_protection *cop = _get_overload_protection();
  struct cartridge_ident *id = _get_ident();
  
  if((m2)->Line_period_zc_T2 > 0)
  {
    (m2)->Line_frequency_zc = _builtin_divud(60000u, (m2)->Line_period_zc_T2);
  }
  
  (m2)->Actaul_Power = ((id)->IDENT_MAX_RMS_Power * (cop)->power_half_periods) / 100;
}
/******************************************************************************/
/*
 * Name:      INIT Measure values
 * Purpose:   
 * 
 */
/******************************************************************************/
void measure_init(void)
{
  mespar.dc_average_counter = DC_AVERAGE_TIME;
  ZeroCrosDetectionState = eZeroCrossOpenWindow;
}

/******************************************************************************/
/*
 * Name: Zero Cross Window Timer in TASK1 
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task periods
 */
/******************************************************************************/
static U16 ZeroCrossTimerT1(U16 u16Command, U16 u16Cons)               
{         
  static U16 u16Count;
  
  if(cZC_TIMER_START == u16Command)    
  {
    u16Count = u16Cons;    
  }
  else if((cZC_TIMER_READ != u16Count) && (cZC_TIMER_COUNT == u16Command)) 
  {
    u16Count--;
  }
  else
  {
    // command = 1 -> read timer
  }
  
  return(u16Count);
}
