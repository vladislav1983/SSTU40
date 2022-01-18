/* 
 * File:   pid_types.h
 * Author: GYV1SF4
 *
 * Created on January 17, 2022, 5:42 PM
 */
/*-----------------------------------------------------------------------------
    MODULE DEFINITION FOR MULTIPLE INCLUSION
  -------------------------------------------------------------------------- */
#ifndef PID_TYPES_H
#define	PID_TYPES_H

/*-----------------------------------------------------------------------------
  INCLUDE FILES
---------------------------------------------------------------------------- */
#include "basedef.h"

/*-----------------------------------------------------------------------------
  DEFINITION OF GLOBAL TYPES
-----------------------------------------------------------------------------*/
typedef enum
{
  PidSat_none = 0,
  PidSat_pos =  1,
  PidSat_neg = -1,
}tPidSat;

typedef struct
{
  S32 x;
  tPidSat  sat;
}tPidIntegral;

typedef struct 
{
 /* PARAMS STORED IN EEPROM */
 U16 Kp;
 U16 Ki2;
 U16 Kd2;
 U8  P_term_scale;
 U16 Fbk_Filt_ms;
 U16 Out_Filt_ms;
}tPidCfg;

typedef struct
{
  tPidIntegral Integral;
  S16 error_filt_prev;
  U16 Fbk_Filt_ms;
  U32 Fbk_Filt_coeff;
  U16 Out_Filt_ms;
  U32 Out_Filt_coeff;
  S32 Fbk_Filt;
  S32 Out_Filt;
#if PID_DEBUG != 0
  // pid control period
  S32 error_filt;
  S8  out_sign;
  U16 OutCnt_pos;
  U16 OutCnt_neg;
  S16 OutPeriod;
  // pid control overshoot
  U16 OutOvershootTmp_pos;
  U16 OutOvershootTmp_neg;
  S16 Overshoot_pos;
  S16 Overshoot_neg;
#endif
}tPidData;

typedef struct
{
  const tPidCfg * const cfg;    
  tPidData      * const data;   
}tPidInstance;

/*-----------------------------------------------------------------------------
  DEFINITION OF GLOBAL MACROS/#DEFINES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL VARIABLES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  INCLUDE FILES
---------------------------------------------------------------------------- */
#include "pid_cfg.h"

/*-----------------------------------------------------------------------------
  END OF MODULE DEFINITION FOR MULTIPLE INCLUSION
-----------------------------------------------------------------------------*/

#endif	/* PID_TYPES_H */
