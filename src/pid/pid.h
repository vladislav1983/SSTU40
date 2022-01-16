/* 
 * File:   pid.h
 * Author: GYV1SF4
 *
 * Created on January 16, 2022, 6:45 PM
 */
/*-----------------------------------------------------------------------------
    MODULE DEFINITION FOR MULTIPLE INCLUSION
  -------------------------------------------------------------------------- */
#ifndef PID_H
#define	PID_H

/*-----------------------------------------------------------------------------
  INCLUDE FILES
---------------------------------------------------------------------------- */
#include "basedef.h"

/*-----------------------------------------------------------------------------
  DEFINITION OF GLOBAL TYPES
-----------------------------------------------------------------------------*/
typedef struct
{
  S32 x;
  S8  sat;
}tPidIntegral;

typedef struct 
{
 /* PARAMS STORED IN EEPROM */
 U16 Kp;
 U16 Ki2;
 U16 Kd2;
 U8  P_term_scale;
}tPidCfg;

typedef struct
{
  tPidIntegral Integral;
  S16 error_prev;
}tPidData;

typedef struct
{
  const tPidCfg * const cfg;    
  tPidData      * const data;   
}tPidInstance;

/*-----------------------------------------------------------------------------
  DEFINITION OF GLOBAL MACROS/#DEFINES
-----------------------------------------------------------------------------*/
#define PID_INSTANCE_CFG(x) \
  const tPidCfg PID_##x##_Cfg =

#define PID_DECLARE_INSTANCE(x) \
  extern tPidCfg PID_##x##_Cfg; \
  tPidData PID_##x##_Data = {.Integral = {0}, .error_prev = 0}; \
  const tPidInstance PID_##x = {&PID_##x##_Cfg, &PID_##x##_Data}; \
  tPidCfg PID_##x##_Cfg =

#define PID_EXPORT_INSTANCE(x)  \
extern const tPidInstance PID_##x

#define PID_EXPORT_CFG(x)  \
extern tPidCfg PID_##x##_Cfg

#define PID_EXPORT_DATA(x)  \
extern tPidData PID_##x##_Data

#define PID_INSTANCE(x)  &PID_##x

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL VARIABLES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/
extern S16 PidProcess(const tPidInstance * instance, S16 Ref, S16 Fbk, S16 PidMax);
extern void PidReset(const tPidInstance * instance);

/*-----------------------------------------------------------------------------
  END OF MODULE DEFINITION FOR MULTIPLE INCLUSION
-----------------------------------------------------------------------------*/

#endif	/* PID_H */
