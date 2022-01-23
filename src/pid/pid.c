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
#if PID_DEBUG != 0
static void pid_calc_period_and_overshoot(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms);
#endif

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/
//- **************************************************************************
//! \brief 
// https://www.embeddedrelated.com/showarticle/123.php
//- **************************************************************************
S16 PidProcess(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms, S16 PidMax)
{
  S32 PidOut = 0;
  _Q15 q15P_term;
  _Q15 q15D_term;
  S16 error;
  
  if(NULL != instance)
  {
    if(   (SampleTime_ms > 50 && SampleTime_ms < 20000) 
       && PidMax > 0)
    {    
      error = Ref - Fbk;
      
      if(instance->cfg->Ki_ms > (2* SampleTime_ms))
      {
        // integration
        if(instance->cfg->Ki_ms != instance->data->Ki_ms)
        {
          instance->data->Ki2 = _builtin_divud( ((U32)65536uL * SampleTime_ms), instance->cfg->Ki_ms);
          instance->data->Ki_ms = instance->cfg->Ki_ms;
        }
          instance->data->Integral += (S32)_builtin_mulus(instance->data->Ki2, error);
        // integral saturation
        S16 s16Integral = Hi(instance->data->Integral);
        S16 s16Integral_lim = s16Integral;
        if (s16Integral > (S16)instance->cfg->I_term_limit) 
          s16Integral_lim = (S16)instance->cfg->I_term_limit;
        if (s16Integral < -(S16)instance->cfg->I_term_limit) 
          s16Integral_lim = -(S16)instance->cfg->I_term_limit;
        if (s16Integral != s16Integral_lim)
          Hi(instance->data->Integral) = s16Integral_lim;
      }
      else
      {
        instance->data->Integral = 0;
      }
      
      // P term calculation
      q15P_term = fmul_q15(instance->cfg->Kp, error);
      
      // D term calculation
      q15D_term = (S32)fmul_q15(instance->cfg->Kd2, (error - instance->data->error_prev));

      // PID output limitation
      S32 Pid = q15P_term + Hi(instance->data->Integral) + q15D_term; 
      PidOut = pid_limit(Pid, -PidMax, PidMax);
      
      // calculate period and overshoot 
#if PID_DEBUG != 0
      pid_calc_period_and_overshoot(instance, Ref, Fbk, SampleTime_ms);
#endif
      // save prev. error
      instance->data->error_prev = error;
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
  
  return PidOut;
}

//- **************************************************************************
//! \brief 
//- **************************************************************************
void PidReset(const tPidInstance * instance)
{
  if(NULL!= instance)
  {
    instance->data->Integral = 0;

    instance->data->error_prev = 0;
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

#if PID_DEBUG != 0
//- **************************************************************************
//! \brief 
//- **************************************************************************
static void pid_calc_period_and_overshoot(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms)
{
  S16 error;
  S16 sign_prev = 0;

  error = Ref - Fbk;
  
  if(Fbk > Ref)
  {
    instance->data->OutCnt_pos++;
    sign_prev = instance->data->out_sign;
    instance->data->out_sign = 1;
  }
  else if(Fbk < Ref)
  {
    instance->data->OutCnt_neg++;
    sign_prev = instance->data->out_sign;
    instance->data->out_sign = -1;
  }
  
  // overshoot calculation
  if(error > instance->data->OutOvershootTmp_pos)
  {
    instance->data->OutOvershootTmp_pos = error;
  }
  
  // overshoot calculation
  if(error < instance->data->OutOvershootTmp_neg)
  {
    instance->data->OutOvershootTmp_neg = error;
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


