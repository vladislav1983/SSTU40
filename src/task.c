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
#ifdef TASK_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define TASK_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "task.h" 
#include "systmr.h"
#include "sirem.h"
#include "triac_control.h"
#include "measure.h"
#include "statemachine.h"
#include "trace.h"
#include "DigitalIO.h"
#include "tempctrl.h"
#include "vuart.h"
#if defined(ROTARY_ENCODER_USED) 
#include "RotaryEncoder.h"
#endif
#include "adc_drv.h"

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
U16 TASK_CONTROL;
struct sTaskTimesStruct Ttime = {0};
struct sStationStatistic stat_stat = {0};


/*----------------------------------------------------------------------------*/
/* Exported data from other modules                                           */
/*----------------------------------------------------------------------------*/
extern U16 trace_config;
extern U16 trace_state;

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/
void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void);
void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void);
void __attribute__((__interrupt__,no_auto_psv)) _INT0Interrupt(void);

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Purpose: Timer 3 Interrupt Handler. High priority level in system. Used to drive task 1. Interrupt Time -> 100us
 * Input: none
 * Output: none
 */
/******************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void)
{
  struct sTaskTimesStruct *pT1time;
  
  pT1time = _get_Ttime();
  _set_task1_execute(1);     // Task is executing
  _Task2_Timer_Stop();    // Stop task2 timer when task1 execute.    
  
  zero_cross_II();
  
  AdcReadAllChannels();
  
  state_machine_T1();
  
  Current_measure();
  
  cart_stat_det();
  
  triac_fire_timer();    /* Triac power off control */
  
  do_trace();
  
  Cartridge_overload_protection();
  
  sci_timer();
  
  StationStatistic();
#if defined(ROTARY_ENCODER_USED) 
  RotaryEncoder_Scan_T1();
#endif    
  _set_zero_cross(0); //<----- Zero cross cleared at end of interrupt
  
  _Task1_GetTime(pT1time);
  _Task2_Timer_Start();
  _set_task1_execute(0); //task ended
  
  _T3IF = 0;    /* clear interrupt flag */
}

/******************************************************************************/
/*
 * Purpose: TIMER 1 Interrupt Handler. Used to drive task 2. Task Time -> 5ms
 * Input: none
 * Output: none
 */
/******************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
{
  struct sTaskTimesStruct *pT1time;
  
  pT1time = _get_Ttime();
  
  _Task2_Timer_Clear();
  _set_task2_execute(1); //task2 is executing
  
  measure_T2();
  Dio_Scan_T2();
  state_machine_T2();
  
  _RESET_ERROR_PC_HANDLER(); /* Check for reset errors from PC_CONTROL:3 */
  
  _Task2_GetTime(pT1time);
  _set_task2_execute(0); //task ended
  
  _T1IF = 0; /* clear interrupt flag */
}

/******************************************************************************/
/*
 * Purpose: INT0 Interrupt handler. Flag is handled from zero cross routine.
 * Input: none
 * Output: none
 */
/******************************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _INT0Interrupt(void)
{
  Nop();
}


/******************************************************************************/
/*
 * Purpose: Calc Task Runtimes.
 * Input: Pointer to task runtimes data structure
 * Output: none
 */
/******************************************************************************/
void TaskTimesCalc(struct sTaskTimesStruct *p)
{
  
  (p)->Task1Time_us = (U32)(CPU_CYCLE_ns * (p)->Task1Ticks);
  (p)->Task2Time_us = (U32)(CPU_CYCLE_ns * (p)->Task2Ticks);
  
  if(p->Task1Time_us > p->Task1MaxTime_us)
  {
    p->Task1MaxTime_us = p->Task1Time_us;
  }
  
  if(p->Task2Time_us > p->Task2MaxTime_us)
  {
    p->Task2MaxTime_us = p->Task2Time_us;
  }
}

/******************************************************************************/
/*
 * Purpose: Statistic
 * Input: none
 * Output: none
 * Statistics of operation time , cartridge change and etc. Run at end of TASK1
 */
/******************************************************************************/
void StationStatistic(void)
{
  struct sStationStatistic *ss;
  static U16 counter = 0;
  static U16 seconds = 0;
  static teStationStatStates ss_state_stand;
  static teStationStatStates old_ss_state_stand = SS_Stand;
  static teStationStatStates ss_state_extr;
  static teStationStatStates old_ss_state_extr = SS_Extractor;
  
  ss = &stat_stat;
  
  counter ++;
  
  if(counter >= 10000)    // 1s
  {
    counter = 0;
    
    if( ++seconds >= 60)
    {
      seconds = 0;
      
      if( ++(ss)->OpTime_Minutes >= 60 )
      {
        (ss)->OpTime_Minutes = 0;
        (ss)->OpTime_Hours++;
      }
    }
  }
  
  if(_power_up_ok())
  {
    if(_stand() && !_extractor())
    {
      if(old_ss_state_stand != ss_state_stand)
      {
        (ss)->Cart_Stand_Counter++;
      }
      
      ss_state_stand = SS_Stand;
      old_ss_state_stand = ss_state_stand;
      
    }
    else
    {
      ss_state_stand = SS_Norm_Operation;
    }
    
    
    if(_extractor() && !_stand())
    {
      if(old_ss_state_extr != ss_state_extr)
      {
        (ss)->Cart_Change_Counter++;
      }
      
      ss_state_extr = SS_Stand;
      old_ss_state_extr = ss_state_extr;
      
    }
    else
    {
      ss_state_extr = SS_Norm_Operation;
    }
  }
  
  // Hibernation Time Measure
  if(_hibernate())
  {
    (ss)->HibCounter++;
    
    if((ss)->HibCounter >= 10000)
    {
      (ss)->HibCounter = 0;
      
      if(++(ss)->HibTimeSeconds >= 60)
      {
        (ss)->HibTimeSeconds = 0;
        
        if(++(ss)->HibTimeMinutes >= 60)
        {
          (ss)->HibTimeMinutes = 0;
          (ss)->HibTimeHours++;
        }
      }    
    }           
  }       
}
