/* 
 * File:   pid.c
 * Author: GYV1SF4
 *
 * Created on January 16, 2022, 6:44 PM
 */
/*-----------------------------------------------------------------------------
    INCLUDE FILES
-----------------------------------------------------------------------------*/
#include "pid.h"
#include "pid_types.h"
#include "MathTools.h"

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL VARIABLES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DECLARATION OF LOCAL FUNCTIONS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DECLARATION OF LOCAL MACROS/#DEFINES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL TYPES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL VARIABLES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------------*/
static S32 pid_limit(S32 x, S32 min, S32 max);
static tPidIntegral pid_satlimit(S32 x, S32 min, S32 max);
#if PID_DEBUG != 0
static void pid_calc_period_and_overshoot(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms);
#endif

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/
//- **************************************************************************
//! \brief 
// evaluate process gain:
// Kp = deltaT / deltaHalfHeatPeriods - get it from identification component
// Kp is around 40 / 20 = 2 adc_deg/half_period - 1 deg/hp
// selecting p term scaling:
// Max input = 1024 adc (temperature)
// Max output = 10 half periods fo sample time = 100ms
// select gain = 10 -> 1 adc_deg = 10 half periods
// (1 * K)>> 4 = 10 -> K = 160
// for gain = 1 to 10 -> output = 1 to 10 half periods
// (1 * K) >> 4 = 1 -> K = 16
// (1 * K) >> 4 = 10 -> K = 160
// full range overflow check T e max , Gain = max
// (1024 * 160) >> 4 = 10240
//- **************************************************************************
S16 PidProcess(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms, S16 PidMax)
{
  S32 PidOut = 0;
  S16 PidOut_Filt = 0;
  S32 P_term;
  S32 D_term;
  S16 error_filt;
  S16 error;
  
  if(NULL != instance)
  {
    if(   instance->cfg->P_term_scale < 16
       && instance->cfg->Fbk_Filt_ms >= (2 * SampleTime_ms)
       && instance->cfg->Out_Filt_ms >= (2 * SampleTime_ms)
       && (SampleTime_ms > 50 && SampleTime_ms < 32768) )
    {
      S32 P_term_min  = -(S32)((U32)1uL << (15u + instance->cfg->P_term_scale));
      S32 P_term_max  =  (S32)((U32)1uL << (15u + instance->cfg->P_term_scale)) - 1uL;
      S32 ID_term_min = -(S32)((U32)PidMax << 16);
      S32 ID_term_max =  (S32)((U32)PidMax << 16);
      
      // input filtration
      if(instance->cfg->Fbk_Filt_ms != instance->data->Fbk_Filt_ms)
      {
        if(((U32)instance->cfg->Fbk_Filt_ms + SampleTime_ms) < 65535)
        {
          instance->data->Fbk_Filt_coeff = _builtin_divud( ((U32)65536ul * SampleTime_ms), (instance->cfg->Fbk_Filt_ms));
          instance->data->Fbk_Filt_ms = instance->cfg->Fbk_Filt_ms;
        }
        else
        {
          _set_param_limit_error(1);
        }
      }
      // Filter function: y(n)=y(n?1)+a[x(n)?(y(n?1)/65536)],
      instance->data->Fbk_Filt += (S32)((S32)instance->data->Fbk_Filt_coeff * (S16)(Fbk - Hi(instance->data->Fbk_Filt )));
      // error calculation
      error_filt = Ref - Hi(instance->data->Fbk_Filt);
      error = Ref = Fbk;
      
      // integration
      if((error < 0 && instance->data->Integral.sat < 0) || (error > 0 && instance->data->Integral.sat > 0))
      {
        // do nothing if there is saturation, and error is in the same direction;
      }
      else
      {
        instance->data->Integral.x += (S32)instance->cfg->Ki2 * error;
      }
      // integral saturation
      instance->data->Integral = pid_satlimit(instance->data->Integral.x, ID_term_min, ID_term_max);
      
      // P and D terms calculation
      P_term = pid_limit((S32)instance->cfg->Kp * error, P_term_min, P_term_max);
      D_term = pid_limit((S32)instance->cfg->Kd2 * (error_filt - instance->data->error_filt_prev), ID_term_min, ID_term_max);
      
      // PID output limitation
      PidOut = pid_limit((P_term >> instance->cfg->P_term_scale) + (instance->data->Integral.x >> 16) + (D_term >> 16), -PidMax, PidMax);
      
      // output filtration coefficient calculation
      if(instance->cfg->Out_Filt_ms != instance->data->Out_Filt_ms)
      {
        instance->data->Out_Filt_coeff = _builtin_divud( ((U32)65536ul * SampleTime_ms), (instance->cfg->Out_Filt_ms));
        instance->data->Out_Filt_ms = instance->cfg->Out_Filt_ms;
      }
      // output filtration
      instance->data->Out_Filt += (S32)((S32)instance->data->Out_Filt_coeff * (S16)(PidOut - Hi(instance->data->Out_Filt)));
      PidOut_Filt = Hi(instance->data->Out_Filt);
      // calculate period and overshoot 
#if PID_DEBUG != 0
      pid_calc_period_and_overshoot(instance, Ref, Fbk, SampleTime_ms);
#endif
      // save prev. error
      instance->data->error_filt_prev = error_filt;
    }
    else
    {
      _set_param_limit_error(1);
    }
  }
  else
  {
    mAssert(cFalse);
    _set_global_system_fault(1);
  }
  
  return PidOut_Filt;
}

//- **************************************************************************
//! \brief 
//- **************************************************************************
void PidReset(const tPidInstance * instance)
{
  if(NULL!= instance)
  {
    instance->data->Integral.x = 0;
    instance->data->Integral.sat = 0;
    instance->data->error_filt_prev = 0;
    instance->data->Fbk_Filt = 0;
    instance->data->Out_Filt = 0;
#if PID_DEBUG != 0
    instance->data->OutOvershootTmp_neg = 0;
    instance->data->OutOvershootTmp_pos = 0;
    instance->data->Overshoot_neg = -1;
    instance->data->Overshoot_pos = -1;
    instance->data->OutPeriod = -1;
    instance->data->OutCnt_neg = 0;
    instance->data->OutCnt_pos = 0;
    instance->data->out_sign = 0;
    instance->data->error_filt = 0;
#endif
  }
  else
  {
    mAssert(cFalse);
    _set_global_system_fault(1);
  }
}
/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL FUNCTIONS
-----------------------------------------------------------------------------*/
//- **************************************************************************
//! \brief 
//- **************************************************************************
static S32 pid_limit(S32 x, S32 min, S32 max)
{
  if(x > min && x < max) 
    return x;
  else if(x < min)
    return min;
  else if(x > max)
   return max;
  else
    return x;
}

//- **************************************************************************
//! \brief 
//- **************************************************************************
static tPidIntegral pid_satlimit(S32 x, S32 min, S32 max)
{
  tPidIntegral PidIntegral = {0};
  
  if(x > min && x < max)
  {
    PidIntegral.x = x;
    PidIntegral.sat = 0;
  }
  else if(x < min)
  {
    PidIntegral.x = min;
    PidIntegral.sat = -1;
  }
  else if(x > max)
  {
    PidIntegral.x = max;
    PidIntegral.sat = 1;
  }
   
  return PidIntegral;
}

#if PID_DEBUG != 0
//- **************************************************************************
//! \brief 
//- **************************************************************************
static void pid_calc_period_and_overshoot(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms)
{
  S16 error;
  S16 error_filt;
  S16 sign_prev = 0;

  error = Ref - Fbk;

  // 10 seconds filtration of error
  instance->data->error_filt += (S32)(_builtin_divud( ((S32)65536L * SampleTime_ms), 10000u) * (S16)(error - Hi(instance->data->error_filt )));
  error_filt = Hi(instance->data->error_filt);
  
  if(error > error_filt)
  {
    instance->data->OutCnt_pos++;
    sign_prev = instance->data->out_sign;
    instance->data->out_sign = 1;
    
    // overshoot calculation
    if(error > instance->data->OutOvershootTmp_pos)
    {
      instance->data->OutOvershootTmp_pos = error;
    }
  }
  else if(error < error_filt)
  {
    instance->data->OutCnt_neg++;
    sign_prev = instance->data->out_sign;
    instance->data->out_sign = -1;
    
    // overshoot calculation
    if(error < instance->data->OutOvershootTmp_neg)
    {
      instance->data->OutOvershootTmp_neg = error;
    }
  }

  if(instance->data->out_sign == 1 && sign_prev == -1)
  {
    if(instance->data->OutCnt_pos > 0 && instance->data->OutCnt_neg > 0)
    {
      instance->data->OutPeriod = (instance->data->OutCnt_pos + instance->data->OutCnt_neg) * SampleTime_ms;
      instance->data->Overshoot_pos = instance->data->OutOvershootTmp_pos;
      instance->data->Overshoot_neg = instance->data->OutOvershootTmp_neg;
    }
    else
    {
      instance->data->OutPeriod = -1;
      instance->data->Overshoot_pos = -1;
      instance->data->Overshoot_neg = -1; 
    }
    
    instance->data->OutCnt_pos = 1;
    instance->data->OutCnt_neg = 0;
    instance->data->OutOvershootTmp_pos = 0;
    instance->data->OutOvershootTmp_neg = 0;
  }
}
#endif

/*-----------------------------------------------------------------------------
    END OF MODULE
-----------------------------------------------------------------------------*/


