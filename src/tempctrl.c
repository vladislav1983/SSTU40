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
#ifdef TEMPCTRL_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define TEMPCTRL_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "task.h"
#include "tempctrl.h"
#include "measure.h"
#include "statemachine.h"
#include "triac_control.h"
#include "ident.h"
#include "MathTools.h"
#include "pid.h"
#include "adc_drv.h"
#include "MathTools.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/
#define TMPCTRL_TIMER_READ                0
#define TMPCTRL_TIMER_LOAD                1
#define TMPCTRL_TIMER_COUNT               2

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/
#define TEMP_TO_Q15(X)                    (_Q15)(Q15( (F32)(X) / TEMP_MAX))

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
typedef enum
{
  eLoadDustibutionPeriods = 0, 
  eRunDistribution,
}tDistributionCmd;

typedef enum 
{
  eDistr_OFF = 0,
  eDistr_ON  = 1,
  eDistr_FINISH = 255
}tDistributionResult;

/* TEMPERATURE CONTROL STATES */
typedef enum
{
  TMPCTRL_INIT = 0,
  TMPCTRL_MEASURE_TEMP,
  TMPCTRL_CONTROL,
  TMPCTRL_TRIAC_FIRE,
  TMPCTRL_WAIT_AFTER_ZC_STATE,
  TMPCTRL_WAIT_X_PERIODS_STATE,
  TMPCTRL_UNDEF_STATE
}tTmpCtrlState;

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
tTmpCtrlState tmpctrl_mainstate = TMPCTRL_INIT;
tTmpCtrlState tmpctrl_nextstate = TMPCTRL_INIT;

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
struct temperature_control T_ctrl = 
{
  .T_Ref_User = TEMP_TO_Q15(350),
  .T_Ref_User_Sleep = TEMP_TO_Q15(220),
  .T_Ref_User_tmp = TEMP_TO_Q15(350),
  .T_cal_gain = 1126,
  .T_cal_offset = 20,
  .T_fbk = 0,
  .T_PID_fbk = 0,
  .T_sum = 0,
  .bresenham_distribution = 0,
  .heat_periods = 0,
  .heat_periods_debug = 0,
  .per_counter = 0,
  .tmpctrl_samp_time = 10,
  .T_UserStep = 5,
};

struct overload_protection overprot = 
{
  .cop_periods = 0,
  .cop_periods_trip = 700,
  .cop_time_sec = 0,
  .cop_time_trip_sec = 7,
  .cop_timer = 0,
  .power_half_periods = 0,
};

/* Exported from MEASURE.C */
extern struct Mes1 mes1;

/* Exported from STATEMACHINE.C */
extern volatile U16 SYS_CONTROL;
extern volatile U16 PC_CONTROL;
extern volatile U16 ERR_CONTROL;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/
U16 tmpctrl_timer_t1(U16 cmd, U16 cons);
static tDistributionResult bresenham_distribution(tDistributionCmd cmd, U16 distribution_periods_y, U16 max_periods_x);

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Purpose:    Temperature Control    
 * Input:  ADC Channel - Actual temperature. Sleep flag -> 1: Reg sleep temp 0: Reg Ref temp
 * Output:    none
 */
/******************************************************************************/
void temp_ctrl(BOOL sleep_flag)
{
  struct temperature_control *tc = _get_T_ctrl();
  const U16 Temp_ADC_Ch = AdcReadChannel(ADC_CH0_TEMP);
  
  switch(tmpctrl_mainstate)
  {
    /*---------------------------------------------------*/    
    case TMPCTRL_INIT:
    {
      tc->T_sum = 0;
      tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_AVERAGE_TIME);
      tmpctrl_mainstate = TMPCTRL_MEASURE_TEMP;
    }
    break;
    /*---------------------------------------------------*/
    case TMPCTRL_MEASURE_TEMP:
    {
      if(tmpctrl_timer_t1(TMPCTRL_TIMER_COUNT, 0))
      {
        tc->T_sum += Temp_ADC_Ch;
      }
      else
      {
        tc->T_fbk = tc->T_sum >> TMPCTRL_AVERAGE_DIV;
        tc->T_PID_fbk = ((U32)tc->T_fbk * tc->T_cal_gain) >> TMPCTRL_CAL_GAIN_SCALE_DIV;
        tc->T_PID_fbk += (S16)tc->T_cal_offset;
        
        if(tc->T_fbk > TEMP_TRIP_Q15) _set_overtemperature_error(1); /* if overtemperature --> trip error */
        tmpctrl_mainstate = TMPCTRL_CONTROL;
      }
    }
    break;
    /*---------------------------------------------------*/
    case TMPCTRL_CONTROL:
    {
      U16 T_ref_pid;
      
      if(sleep_flag) 
        T_ref_pid = tc->T_Ref_User_Sleep;
      else 
        T_ref_pid = tc->T_Ref_User;
      
      tc->heat_periods = PidProcess(PID_INSTANCE(C245ToolPid), T_ref_pid, tc->T_PID_fbk, ((tc->tmpctrl_samp_time + 1u) * 10u),tc->tmpctrl_samp_time);
      tc->heat_periods_debug = tc->heat_periods;
      
      if(tc->heat_periods > 0)
      {
        tDistributionResult brs_output = 0;
        
        if(FALSE != tc->bresenham_distribution)
        {
           brs_output = bresenham_distribution(eLoadDustibutionPeriods, tc->heat_periods , tc->tmpctrl_samp_time);
        }
        
        if(eDistr_FINISH != brs_output)
        {
          tmpctrl_mainstate = TMPCTRL_TRIAC_FIRE;
          pinLED = 1;
          
          if(tc->heat_periods >= tc->tmpctrl_samp_time)
          {
            // immediately measure temp
            tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_WAIT_AFTER_ZC_TIME);
            tmpctrl_nextstate = TMPCTRL_WAIT_AFTER_ZC_STATE;
            tc->per_counter = 0;
          }
          else
          {
            // wait for sample time
            tmpctrl_nextstate = TMPCTRL_WAIT_X_PERIODS_STATE;
            tc->per_counter = tc->heat_periods;
          }
        }
      }
      else
      {
        tc->per_counter = 0;
        tmpctrl_mainstate = TMPCTRL_WAIT_X_PERIODS_STATE;
      }
    }
    break;
    /*---------------------------------------------------*/
    case TMPCTRL_TRIAC_FIRE:
    {
      if(_zero_cross())
      {
        if(FALSE != tc->bresenham_distribution)
        {
          tDistributionResult output = bresenham_distribution(eRunDistribution, 0 , 0);
          
          if(eDistr_ON == output)
          {
            _FIRE_TRIAC();
            pinLED = 1; 
          }
          else if(eDistr_OFF == output)
          {
            pinLED = 0; 
          }
          else if(eDistr_FINISH == output)
          {
            tmpctrl_mainstate = tmpctrl_nextstate;
            pinLED = 0; 
          }
          else
          {
            //nothing to do here
          }
        }
        else
        {
          if(tc->heat_periods)
          {
            tc->heat_periods--;
            _FIRE_TRIAC();
          }
          else
          {
            tmpctrl_mainstate = tmpctrl_nextstate;
            pinLED = 0;    
          }
        }     
      }
    }
    break;
    /*---------------------------------------------------*/
    case TMPCTRL_WAIT_AFTER_ZC_STATE:
    {
      tmpctrl_timer_t1(TMPCTRL_TIMER_COUNT, 0);
      
      if(!tmpctrl_timer_t1(TMPCTRL_TIMER_READ, 0))
      {
        tmpctrl_mainstate = TMPCTRL_MEASURE_TEMP;
        tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_AVERAGE_TIME);
      }
    } 
    break;
    /*---------------------------------------------------*/
    case TMPCTRL_WAIT_X_PERIODS_STATE:
    {
      if(_zero_cross())
      {
        tc->per_counter++;
        
        if(tc->per_counter >= tc->tmpctrl_samp_time)
        {
          tc->per_counter = 0;
          tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_WAIT_AFTER_ZC_TIME);
          tmpctrl_mainstate = TMPCTRL_WAIT_AFTER_ZC_STATE;
        }
      }    
    }
    break;
    /*---------------------------------------------------*/
    default :   // Undefined state 
      mAssert(cFalse);
      _set_global_system_fault(1);
      break;
  }//end switch   
  
}
/*************************************************************************************************/
/*
 * Purpose: Reset Temp Ctrl
 * Input: 
 * Output: 
 * Note: 
 */
/*************************************************************************************************/
void Reset_TMPCTRL(void)
{
  struct temperature_control *tc = _get_T_ctrl();
  
  tmpctrl_mainstate = TMPCTRL_WAIT_X_PERIODS_STATE;
  tc->per_counter = tc->tmpctrl_samp_time;
  
  tc->T_fbk = 0;
  tc->T_PID_fbk = 0;
  tc->heat_periods = 0;
  PidReset(PID_INSTANCE(C245ToolPid));
}

/******************************************************************************/
/*
 * Purpose: Cartridge Overload Protection. Protect Cartridge too many heat periods. Function run in EVERY TASK1
 * Input: none
 * Output: none
 */
/******************************************************************************/
void Cartridge_overload_protection(void)
{
  struct overload_protection *cop = _get_overload_protection();
  static U16 heat_periods;
  
  (cop)->cop_timer++;
  
  if(_over_prot_triac_state())
  {
    _set_over_prot_triac_state(0);
    (cop)->cop_periods++;
    heat_periods++;
  }
  
  if((cop)->cop_timer >= 10000) //10000 cycles in TASK1 = 1s
  {
    (cop)->cop_timer = 0;
    (cop)->cop_time_sec++;
    (cop)->power_half_periods = heat_periods;
    heat_periods = 0;
  }
  
  if((cop)->cop_time_sec == (cop)->cop_time_trip_sec)
  {
    if((cop)->cop_periods > (cop)->cop_periods_trip) _set_overload_error(1);
    (cop)->cop_periods = 0;
    (cop)->cop_time_sec = 0;
  }    
}
/******************************************************************************/
/*
 * Purpose: Temperature control init
 * Input: none
 * Output: none
 */
/******************************************************************************/
void temp_ctrl_init(void)
{
  
  tmpctrl_mainstate = TMPCTRL_INIT;
  T_ctrl.per_counter = 0;
  T_ctrl.T_Ref_User_tmp = T_ctrl.T_Ref_User;
}

/******************************************************************************/
/*
 * Purpose: Get Real Actual Cartridge Temperature
 * Input: none
 * Output: Real Cartridge Temperature
 */
/******************************************************************************/
U16 Get_Temp_Actual(void)
{
  U16 tmpp;
  U16 T_fbk_tmp = T_ctrl.T_fbk;
  
  tmpp = fmul_q15(T_fbk_tmp, TEMP_MAX) + (TEMP_DISPLAY_ACCURACY / 2);
  tmpp >>= TEMP_DISPLAY_ACCURACY_DIV;
  tmpp <<= TEMP_DISPLAY_ACCURACY_DIV;
  return(tmpp);
}
/******************************************************************************/
/*
 * Purpose: Set User Temperature
 * Input:  none
 * Output: none
 */
/******************************************************************************/
void Set_User_Temp(teTemperatureUsers user)
{
  if(eTEMP_USER == user)
  {
    T_ctrl.T_Ref_User = T_ctrl.T_Ref_User_tmp;
  }
  else if(eTEMP_USER_SLEEP == user)
  {
    T_ctrl.T_Ref_User_Sleep = T_ctrl.T_Ref_User_tmp;
  }
  else
  {
    mAssert(cFalse);
    _set_global_system_fault(1);
  }
}
/******************************************************************************/
/*
 * Purpose: Roll Back user temp
 * Input:  none
 * Output: none
 */
/******************************************************************************/
void Reset_User_Temp(teTemperatureUsers user)
{
  if(eTEMP_USER == user)
  {
    T_ctrl.T_Ref_User_tmp = T_ctrl.T_Ref_User;
  }
  else if(eTEMP_USER_SLEEP == user)
  {
    T_ctrl.T_Ref_User_tmp = T_ctrl.T_Ref_User_Sleep;
  }
  else
  {
    mAssert(cFalse);
    _set_global_system_fault(1);
  }
}
/******************************************************************************/
/*
 * Purpose: Get Temporary User Temperature
 * Input: none
 * Output: User Temperature
 */
/******************************************************************************/
U16 Get_User_Temp(void)
{
  return(T_ctrl.T_Ref_User_tmp);
}
/******************************************************************************/
/*
 * Purpose: Increment User Temp with fixed step.
 * Input: none
 * Output: none
 */
/******************************************************************************/
void Inc_User_Temp(void)
{
  if(T_ctrl.T_Ref_User_tmp < TEMP_USER_MAX)
  {
    T_ctrl.T_Ref_User_tmp += (TEMP_1DEG_Q15 * T_ctrl.T_UserStep);
  }
}
/******************************************************************************/
/*
 * Purpose: Decrement User Temp with fixed step.
 * Input: none
 * Output: none
 */
/******************************************************************************/
void Dec_User_Temp(void)
{
  if(T_ctrl.T_Ref_User_tmp > TEMP_USER_MIN)
  {
    T_ctrl.T_Ref_User_tmp -= (TEMP_1DEG_Q15 * T_ctrl.T_UserStep);
  }
}
/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Name: Software Timer for TEMPCTRL module - TASK1 
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task1 periods
 */
/******************************************************************************/
U16 tmpctrl_timer_t1(U16 cmd, U16 cons)               
{         
  static U16 count;
  
  if(cmd == TMPCTRL_TIMER_LOAD)
    count = cons;    
  else if((count > 0) && (cmd == TMPCTRL_TIMER_COUNT)) 
    count--;
  
  return(count);
}

/******************************************************************************
 * Name: 
 * Params: 
 * output:  1 - fire triac, bresenham distribution hit
 *          0 - do not fire triac
 *         -1 - internal error or distribution finished over given period
 * Purpose:
 bresenham line equation used as heating period distribution 
 used simplified verion os algorithm for 
  dx = x1 - x0
  dy = y1 - y0
  D = 2*dy - dx
  y = y0

  for x from x0 to x1
      plot(x,y)
      if D > 0
          y = y + 1
          D = D - 2*dx
      end if
      D = D + 2*dy
 in out case x0 = 0 and y0 = 0, ->
  dx = x1 - max periods, last point 
  dy = y1 - periods for distribution
  D = 2*dy - dx
  output = 0

  for x from 0 to x1
      if D > 0
        output = 1 - fire output
        D = D - 2*dx
      end if
      D = D + 2*ydy
 
 ******************************************************************************/
static tDistributionResult bresenham_distribution(tDistributionCmd cmd, U16 distribution_periods_y, U16 max_periods_x)
{
  static S16 delta_error = 0;
  static U16 periods_counter = 0;
  static S16 dy = 0;
  static S16 dx = 0;
  static S16 bias = 0;
  tDistributionResult output = eDistr_OFF;
  
  if(cmd == eLoadDustibutionPeriods)
  {
    if(   distribution_periods_y <= max_periods_x 
       && distribution_periods_y > 0 
       && max_periods_x > 0)
    {
      dy = distribution_periods_y;
      dx = max_periods_x;
      periods_counter = max_periods_x;
      // calculate initial error
      delta_error = (2 * dy) - dx;
    }
    else
    {
      _set_param_limit_error(1);
      output = eDistr_FINISH;
    }
  }
  else if(cmd == eRunDistribution)
  {
    if((periods_counter--) > 0)
    {
      if(delta_error > 0 || bias != 0)
      {
        if((periods_counter % 2) == 0) { bias++;  }// even
        else { bias--; }// odd
        
        output = eDistr_ON;
        delta_error -= 2 * dx;
      }
      
      delta_error += 2 * dy;
    }
    else
    {
      output = eDistr_FINISH;
    }
  }
  else
  {
    mAssert(cFalse);
    _set_global_system_fault(1);
    output = eDistr_FINISH;
  }
  
  return output;
}
