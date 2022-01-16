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
#include "pid_cfg.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
typedef enum
{
  eLoadDustibutionPeriods, 
  eRunDistribution,
}tDistributionCmd;

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
U16 tmpctrl_mainstate;
U16 tmpctrl_nextstate;
/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
struct temperature_control T_ctrl = 
{
  .T_Ref_User = 350,
  .T_Ref_User_Sleep = 220,
  .T_Ref_User_tmp = 350,
  .T_cal_gain = 1126,
  .T_cal_offset = 20,
  .T_delta = 0,
  .T_fbk = 0,
  .T_sum = 0,
  .bresenham_distribution = 0,
  .heat_periods = 0,
  .heat_periods_debug = 0,
  .per_counter = 0,
  .tmpctrl_samp_time = 10,
  .tmpctrl_triac_state = 0,
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
static S16 bresenham_distribution(tDistributionCmd cmd, U16 distribution_periods_y, U16 max_periods_x);
static void CalcThermalTimeConstant(U16 Ref, U16 Fbk, BOOL reset);

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
void temp_ctrl(U16 Temp_ADC_Ch, BOOL sleep_flag)
{
  struct temperature_control *tc = _get_T_ctrl();
  U16 T_Ref_local;
  
  switch(tmpctrl_mainstate)
  {
    /*---------------------------------------------------*/    
    case TMPCTRL_INIT:
      tmpctrl_mainstate = TMPCTRL_MEASURE_TEMP;
      break;
      /*---------------------------------------------------*/    
    case TMPCTRL_MEASURE_TEMP:
      tmpctrl_timer_t1(TMPCTRL_TIMER_COUNT, 0);
      
      if(tmpctrl_timer_t1(TMPCTRL_TIMER_READ, 0))
      {
        (tc)->T_sum += Temp_ADC_Ch;
      }
      else
      {
        (tc)->T_fbk = (tc)->T_sum >> TMPCTRL_AVERAGE_DIVIDER;
        (tc)->T_sum = 0;
        
        (tc)->T_fbk = ((U32)(tc)->T_fbk * (tc)->T_cal_gain) >> 10;
        (tc)->T_fbk += (S16)tc->T_cal_offset;
        
        if((tc)->T_fbk > MAX_TEMP_TRIP_RAW) _set_overtemperature_error(1); /* if overtemperature --> trip error */
        tmpctrl_mainstate = TMPCTRL_CONTROL;
      }
      break;
      /*---------------------------------------------------*/
    case TMPCTRL_CONTROL:
      
      if(sleep_flag) T_Ref_local = (tc)->T_Ref_User_Sleep << 1;
      else T_Ref_local = (tc)->T_Ref_User << 1;
      
      (tc)->T_delta = T_Ref_local - (tc)->T_fbk;
      
      (tc)->heat_periods = PidProcess(PID_INSTANCE(C245ToolPid), T_Ref_local, (tc)->T_fbk, (tc)->tmpctrl_samp_time,(tc)->tmpctrl_samp_time);
      (tc)->heat_periods_debug = (tc)->heat_periods;
      CalcThermalTimeConstant(T_Ref_local, (tc)->T_fbk, cFalse);
      
      if((tc)->heat_periods > 0)
      {
        S16 brs_output = 0;
        
        if(FALSE != tc->bresenham_distribution)
        {
           brs_output = bresenham_distribution(eLoadDustibutionPeriods, (tc)->heat_periods , (tc)->tmpctrl_samp_time);
        }
        
        if(-1 != brs_output)
        {
          tmpctrl_mainstate = TMPCTRL_TRIAC_FIRE;
          pinLED = 1;
          
          if((tc)->heat_periods >= (tc)->tmpctrl_samp_time)
          {
            // immediately measure temp
            tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_WAIT_AFTER_ZC_TIME);
            tmpctrl_nextstate = TMPCTRL_WAIT_AFTER_ZC_STATE;
            (tc)->per_counter = 0;
          }
          else
          {
            // wait for sample time
            tmpctrl_nextstate = TMPCTRL_WAIT_X_PERIODS_STATE;  
            (tc)->per_counter = (tc)->heat_periods;
          }
        }
      }
      else
      {
        (tc)->per_counter = 0;
        tmpctrl_mainstate = TMPCTRL_WAIT_X_PERIODS_STATE;
      }
      break;
      /*---------------------------------------------------*/
    case TMPCTRL_TRIAC_FIRE:
      if(_zero_cross())
      {
        if(FALSE != tc->bresenham_distribution)
        {
          S16 output = bresenham_distribution(eRunDistribution, 0 , 0);
          
          if(1 == output && _drive_enabled())
          {
            _FIRE_TRIAC();
            pinLED = 1; 
            (tc)->tmpctrl_triac_state = 1;
          }
          else if(0 == output)
          {
            (tc)->tmpctrl_triac_state = 0;
            pinLED = 0; 
          }
          else if(-1 == output)
          {
            tmpctrl_mainstate = tmpctrl_nextstate;
            (tc)->tmpctrl_triac_state = 0;
            pinLED = 0; 
          }
          else
          {
            //nothing to do here
          }
        }
        else
        {
          if((tc)->heat_periods)
          {
            (tc)->heat_periods--;
            if(_drive_enabled())
            {
              _FIRE_TRIAC();
              (tc)->tmpctrl_triac_state = 1;
            }
          }
          else
          {
            tmpctrl_mainstate = tmpctrl_nextstate;
            (tc)->tmpctrl_triac_state = 0;
            pinLED = 0;    
          }
        }     
      }
        
      break;
      /*---------------------------------------------------*/
    case TMPCTRL_WAIT_AFTER_ZC_STATE:
      tmpctrl_timer_t1(TMPCTRL_TIMER_COUNT, 0);
      
      if(!tmpctrl_timer_t1(TMPCTRL_TIMER_READ, 0))
      {
        tmpctrl_mainstate = TMPCTRL_MEASURE_TEMP;
        tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_AVERAGE_TIME);
      }
      
      break;
      /*---------------------------------------------------*/
    case TMPCTRL_WAIT_X_PERIODS_STATE:
      if(_zero_cross())
      {
        (tc)->per_counter++;
        
        if((tc)->per_counter >= (tc)->tmpctrl_samp_time)
        {
          (tc)->per_counter = 0;
          tmpctrl_timer_t1(TMPCTRL_TIMER_LOAD, TMPCTRL_WAIT_AFTER_ZC_TIME);
          tmpctrl_mainstate = TMPCTRL_WAIT_AFTER_ZC_STATE;
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
  (tc)->per_counter = (tc)->tmpctrl_samp_time;
  
  (tc)->T_fbk = 0;
  (tc)->heat_periods = 0;
  CalcThermalTimeConstant(0, 0, cTrue);
  PidReset(PID_INSTANCE(C245ToolPid));
}

/*************************************************************************************************/
/*
 * Purpose: 
 * Input: 
 * Output: 
 * Note: 
 */
/*************************************************************************************************/
static void CalcThermalTimeConstant(U16 Ref, U16 Fbk, BOOL reset)
{
  struct temperature_control *tc = _get_T_ctrl();
  
  static S16 sign = 0;
  static S16 sign_prev = 0;
  static U16 Fbk_prev = 0;
  static S16 ThermalOvershoot_pos_loc = 0;
  static S16 ThermalOvershoot_neg_loc = 0;
  S16 error;
  
  if(reset != cFalse)
  {
    tc->ThermalPeriod_pos = 0;
    tc->ThermalPeriod_neg = 0;
    sign = 0;
    sign_prev = 0;
    Fbk_prev = 0;
    tc->ThermalPeriod = 0;
    tc->ThermalOvershoot_pos = 0;
    tc->ThermalOvershoot_neg = 0;
  }
  
  if(Fbk > Fbk_prev)
  {
    tc->ThermalPeriod_pos++;
    sign_prev = sign;
    sign = 1;
  }
  else if(Fbk < Fbk_prev)
  {
    tc->ThermalPeriod_neg++;
    sign_prev = sign;
    sign = -1;
  }
  
  Fbk_prev = Fbk;
  
  error = Fbk - Ref;
  
  if(error > 0)
  {
    if(error > ThermalOvershoot_pos_loc)
    {
      ThermalOvershoot_pos_loc = error;
    }
  }
  else if(error < 0)
  {
    if(error < ThermalOvershoot_neg_loc)
    {
      ThermalOvershoot_neg_loc = error;
    }
  }
  
  if(sign == 1 && sign_prev == -1)
  {
    if(tc->ThermalPeriod_pos > 0 && tc->ThermalPeriod_neg > 0)
    {
      tc->ThermalPeriod = (tc->ThermalPeriod_pos + tc->ThermalPeriod_neg) * (tc->tmpctrl_samp_time * 10u);
    }
    
    tc->ThermalOvershoot_pos = ThermalOvershoot_pos_loc;
    tc->ThermalOvershoot_neg = ThermalOvershoot_neg_loc;
    
    tc->ThermalPeriod_pos = 0;
    tc->ThermalPeriod_neg = 0;
    ThermalOvershoot_pos_loc = 0;
    ThermalOvershoot_neg_loc = 0;
    sign_prev = sign;
  }
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
  tmpp = (T_ctrl.T_fbk >> 1) + (TEMP_DISPLAY_ACCURACY / 2);
  tmpp /= TEMP_DISPLAY_ACCURACY;
  tmpp *= TEMP_DISPLAY_ACCURACY;
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
    T_ctrl.T_Ref_User_tmp += T_ctrl.T_UserStep;
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
    T_ctrl.T_Ref_User_tmp -= T_ctrl.T_UserStep;
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
  
  if(cmd==1)    count = cons;    
  else if(count && cmd==2) count--;
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
static S16 bresenham_distribution(tDistributionCmd cmd, U16 distribution_periods_y, U16 max_periods_x)
{
  static S16 delta_error = 0;
  static U16 periods_counter = 0;
  static S16 dy = 0;
  static S16 dx = 0;
  static S16 bias = 0;
  S16 output = 0;
  
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
      output = -1;
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
        
        output = 1;
        delta_error -= 2 * dx;
      }
      
      delta_error += 2 * dy;
    }
    else
    {
      output = -1;
    }
  }
  else
  {
    mAssert(cFalse);
    _set_global_system_fault(1);
    output = -1;
  }
  
  return output;
}
