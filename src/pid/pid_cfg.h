/* 
 * File:   pid_cfg.h
 * Author: GYV1SF4
 *
 * Created on January 16, 2022, 6:46 PM
 */
/*-----------------------------------------------------------------------------
    MODULE DEFINITION FOR MULTIPLE INCLUSION
  -------------------------------------------------------------------------- */
#ifndef PID_CFG_H
#define	PID_CFG_H

/*-----------------------------------------------------------------------------
  DEFINITION OF COMPILER SWITCHES
-----------------------------------------------------------------------------*/
#define PID_DEBUG     1

/*-----------------------------------------------------------------------------
  INCLUDE FILES
---------------------------------------------------------------------------- */
#include "statemachine.h"
#include "pid_types.h"

/*-----------------------------------------------------------------------------
  DEFINITION OF GLOBAL TYPES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DEFINITION OF GLOBAL MACROS/#DEFINES
-----------------------------------------------------------------------------*/
#define PID_INSTANCE_CFG(x) \
  const tPidCfg PID_##x##_Cfg =

#define PID_DECLARE_INSTANCE(x) \
  extern tPidCfg PID_##x##_Cfg; \
  tPidData PID_##x##_Data = \
  { \
    .Integral = {0}, \
    .error_filt_prev = 0, \
    .Fbk_Filt_ms = 0, \
    .Fbk_Filt_coeff = 0, \
    .Out_Filt_ms = 0, \
    .Out_Filt_coeff = 0, \
    .Fbk_Filt = 0,  \
    .Out_Filt = 0, \
  }; \
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
PID_EXPORT_INSTANCE(C245ToolPid);
PID_EXPORT_CFG(C245ToolPid);
PID_EXPORT_DATA(C245ToolPid);

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  DECLARATION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
  END OF MODULE DEFINITION FOR MULTIPLE INCLUSION
-----------------------------------------------------------------------------*/

#endif	/* PID_CFG_H */
