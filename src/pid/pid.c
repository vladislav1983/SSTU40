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
#include "pid_cfg.h"
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

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/
//- **************************************************************************
//! \brief 
//- **************************************************************************
S16 PidProcess(const tPidInstance * instance, S16 Ref, S16 Fbk, U16 SampleTime_ms, S16 PidMax)
{
  S32 PidOut = 0;
  S32 P_term;
  S32 D_term;
  S16 error_filt;
  
  if(NULL != instance)
  {
    if(   instance->cfg->P_term_scale < 16
       && instance->cfg->Fbk_Filt_ms > 0
       && instance->cfg->Fbk_Filt_ms >= SampleTime_ms
       && SampleTime_ms > 10)
    {
      S32 P_term_min = -(S32)((U32)1uL << (15u + instance->cfg->P_term_scale));
      S32 P_term_max = (S32)((U32)1uL << (15u + instance->cfg->P_term_scale)) - 1uL;
      S32 ID_term_min = -(S32)((U32)PidMax << 16);
      S32 ID_term_max = (S32)((U32)PidMax << 16);
      
      // input filtration
      if(instance->cfg->Fbk_Filt_ms != instance->data->Fbk_Filt_ms)
      {
          if(((U32)instance->cfg->Fbk_Filt_ms + SampleTime_ms) < 65535)
        {
          instance->data->Fbk_Filt = _builtin_divsd( ((S32)65536L * SampleTime_ms), (instance->cfg->Fbk_Filt_ms));
          instance->data->Fbk_Filt_ms = instance->cfg->Fbk_Filt_ms;
        }
        else
        {
          _set_param_limit_error(1);
        }
      }
      // Filter function: y(n)=y(n?1)+a[x(n)?(y(n?1)/65536)],
      instance->data->Fbk_filt += (S32)((S32)instance->data->Fbk_Filt * (S16)(Fbk - Hi(instance->data->Fbk_filt )));
      // error calculation
      error_filt = Ref - Hi(instance->data->Fbk_filt);
      
      // integration
      if((error_filt < 0 && instance->data->Integral.sat < 0) || (error_filt > 0 && instance->data->Integral.sat > 0))
      {
        // do nothing if there is saturation, and error is in the same direction;
      }
      else
      {
        instance->data->Integral.x += (S32)instance->cfg->Ki2 * error_filt;
      }
      // integral saturation
      instance->data->Integral = pid_satlimit(instance->data->Integral.x, ID_term_min, ID_term_max);
      
      // P and D terms calculation
      P_term = pid_limit((S32)instance->cfg->Kp * error_filt, P_term_min, P_term_max);
      D_term = pid_limit((S32)instance->cfg->Kd2 * (error_filt - instance->data->error_filt_prev), ID_term_min, ID_term_max);
      
      // PID output limitation
      PidOut = pid_limit((P_term >> instance->cfg->P_term_scale) + (instance->data->Integral.x >> 16) + (D_term >> 16), -PidMax, PidMax);
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
  
  return PidOut;
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
    instance->data->Fbk_filt = 0;
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
/*-----------------------------------------------------------------------------
    END OF MODULE
-----------------------------------------------------------------------------*/


