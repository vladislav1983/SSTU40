/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef STATEMACHINE_H
#define STATEMACHINE_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
extern volatile U16 SYS_CONTROL;
extern volatile U16 PC_CONTROL;
extern volatile U16 ERR_CONTROL;

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/* ST1 STATES - Statemachine in task1. Control management. */
#define ST1_INIT                    20
#define ST1_RESET_ERRORS            21
#define ST1_CHECK_ERRORS            22
#define ST1_DC_AUTOTUNNING          23
#define ST1_IDENT_FIRST             24
#define ST1_IDENT                   25
#define ST1_TMPCTRL                 26
#define ST1_STAND                   27
#define ST1_EXTRACTOR               28
#define ST1_NO_CARTRIDGE            29
#define ST1_HIBERNATE               30
//Free                              //31    
#define ST1_ERROR_STATE             32
//Free                              //33
#define ST1_WAIT_STATE              34
#define ST1_TEST_MODE_IDENT         35
#define ST1_LEARNING_MODE           36

/* ST2 STATES - Statemachine in task2. User management. */
#define ST2_INIT                    100
#define ST2_WAIT_POWER_UP           101
#define ST2_POWER_UP_OK             102
#define ST2_CHECKING_CARTRIDGE      103
#define ST2_TMPCTRL                 104
#define ST2_STAND                   105
#define ST2_EXTRACTOR               106
#define ST2_NO_CARTRIDGE            107
#define ST2_HIBERNATE               108
#define ST2_CHANGE_USER_REF         109
#define ST2_TEMP_UP                 110
#define ST2_TEMP_DOWN               111
#define ST2_TEMP_SELECT             112
#define ST2_ERROR_STATE             113
#define ST2_WAIT_STATE              114
#define ST2_WAIT_STATE_II           115


/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/
#define _power_up_ok()                      (_getbit(SYS_CONTROL,0))        /* bit 0 */
#define _set_power_up(x)                    (_putbit((x),SYS_CONTROL,0))    /* bit 0 */

#define _drive_enabled()                    (_getbit(SYS_CONTROL,1))         /* bit 1 */
#define _set_drive(x)                       (_putbit((x),SYS_CONTROL,1))    /* bit 1 */

#define _select_button_pushed()             (_getbit(SYS_CONTROL,2))        /* bit 2 */
#define _set_select_button(x)               (_putbit((x),SYS_CONTROL,2))    /* bit 2 */

#define _up_button_pushed()                 (_getbit(SYS_CONTROL,3))        /* bit 3 */
#define _set_up_button(x)                   (_putbit((x),SYS_CONTROL,3))    /* bit 3 */

#define _down_button_pushed()               (_getbit(SYS_CONTROL,4))        /* bit 4 */
#define _set_down_button(x)                 (_putbit((x),SYS_CONTROL,4))    /* bit 4 */

#define _extractor()                        (_getbit(SYS_CONTROL,5))        /* bit 5 */
#define _set_extractor(x)                   (_putbit((x),SYS_CONTROL,5))    /* bit 5 */

#define _stand()                            (_getbit(SYS_CONTROL,6))        /* bit 6 */
#define _set_stand(x)                       (_putbit((x),SYS_CONTROL,6))     /* bit 6 */

#define _cartridge_present()                (_getbit(SYS_CONTROL,7))        /* bit 7 */
#define _set_cartridge_present(x)           (_putbit((x),SYS_CONTROL,7))    /* bit 7 */

#define _zero_cross()                       (_getbit(SYS_CONTROL,8))        /* bit 8 */
#define _set_zero_cross(x)                  (_putbit((x),SYS_CONTROL,8))    /* bit 8 */

#define _error_check()                      (_getbit(SYS_CONTROL,9))        /* bit 9 */
#define _set_error_check(x)                 (_putbit((x),SYS_CONTROL,9))    /* bit 9 */

#define _hibernate()                        (_getbit(SYS_CONTROL,10))       /* bit 10 */
#define _set_hibernate(x)                   (_putbit((x),SYS_CONTROL,10))   /* bit 10 */

#define _eeprom_busy()                      (_getbit(SYS_CONTROL,11))       /* bit 11 */
#define _set_eeprom_busy(x)                 (_putbit((x),SYS_CONTROL,11))   /* bit 11 */

#define _triac_state()                      (_getbit(SYS_CONTROL,12))       /* bit 12 */
#define _set_triac_state(x)                 (_putbit((x),SYS_CONTROL,12))   /* bit 12 */

#define _over_prot_triac_state()            (_getbit(SYS_CONTROL,13))       /* bit 13 */
#define _set_over_prot_triac_state(x)       (_putbit((x),SYS_CONTROL,13))   /* bit 13 */

//#define _()                            (_getbit(SYS_CONTROL,14))          /* bit 14 */
//#define _(x)                            (_putbit((x),SYS_CONTROL,14))     /* bit 14 */

//#define _()                            (_getbit(SYS_CONTROL,15))          /* bit 15 */
//#define _(x)                            (_putbit((x),SYS_CONTROL,15))     /* bit 15 */


/* SYSTEM CONTROL  */
/*    
    SYS_CONTROL 
    Bit 0        -    Power UP OK               1: Power Up OK 0: Power Up Fail    
    Bit 1        -    Drive Enable              1: Drive ENABLED  0: Drive DISABLED    
    Bit 2        -    pinBUT_SEL                1: SELECT button pushed  0: SELECT button NOT pushed. Note that value is inverted from IO PORT!!!
    Bit 3        -    pinBUT_UP                 1: UP button pushed  0: UP button NOT pushed. Note that value is inverted from IO PORT!!!    
    Bit 4        -    pinBUT_DOWN               1: DOWN button pushed  0: DOWN button NOT pushed. Note that value is inverted from IO PORT!!!
    Bit 5        -    pinEXTR                   1: Cartridge is in EXTRACTOR  0: Cartridge is NOT in EXTRACTOR    
    Bit 6        -    pinSTAND                  1: Cartridge is in STAND  0: Cartridge is NOT in STAND
    Bit 7        -    Cart. Present             1: Cartridge is present in system  0: Cartridge is not present
    Bit 8        -    ZERO CROSS                1: Zero cross occur 0: No zero cross. Note: Zero cross is "live" one task1 period /100us/.
    Bit 9        -    ERR_CHECK                 1: Check foe errors in beginning of ST1 state machine  0: Do not check for errors in beginning of ST1 state machine
    Bit 10       -    Hibernate                 1: Hibernation    0: Norm modes
    Bit 11       -    EE Busy                   1: EEprom busy (operation performed)    0: EEprom NOT busy
    Bit 12       -    Triac state               1: Triac fired 0: Triac not fired     Note: bit is set from macros in triac_control.h
    Bit 13       -    OVERPROT triac state      1: Triac Fired    0: Triac not fired. set in macros in triac_control.h Note: Cleared in overload protection routine.
    Bit 14       -    
    Bit 15       -    
*/


/* PC CONTROL FLAGS */
//#define _()                            (_getbit(PC_CONTROL,0))     /* bit 0 */
//#define _(x)                            (_putbit((x),PC_CONTROL,0)) /* bit 0 */

//#define _()                            (_getbit(PC_CONTROL,1))     /* bit 1 */
//#define _(x)                            (_putbit((x),PC_CONTROL,1)) /* bit 1 */

//#define _()                            (_getbit(PC_CONTROL,2))     /* bit 2 */
//#define _(x)                            (_putbit((x),PC_CONTROL,2)) /* bit 2 */

#define _reset_error_reg()                (_getbit(PC_CONTROL,3))     /* bit 3 */
#define _set_reset_error_reg(x)            (_putbit((x),PC_CONTROL,3)) /* bit 3 */

//#define _()                            (_getbit(PC_CONTROL,4))     /* bit 4 */
//#define _(x)                            (_putbit((x),PC_CONTROL,4)) /* bit 4 */


/*    
    PC_CONTROL 
    Bit 0        -    
    Bit 1        -    
    Bit 2        -    
    Bit 3        -    Reset error register ERR_CONTROL     1: Reset  0: Do not reset
    Bit 4        -    
    Bit 5        -    
    Bit 6        -    
    Bit 7        -    
    Bit 8        -
    Bit 9        -
    Bit 10        -
    Bit 11        -
    Bit 12        -
    Bit 13        -
    Bit 14        -    
    Bit 15        -    
*/

/* ERROR CONTROL MACROS */
#define _RESET_ERROR_INTERNAL()            ERR_CONTROL = 0

/* Reset error register macro */
#define _RESET_ERROR_PC_HANDLER()(      \
{                                       \
  if(_reset_error_reg())                \
  {                                     \
    ERR_CONTROL = 0;                    \
    _set_reset_error_reg(0);            \
  }                                     \
})
                                    
#define _grid_freq_error()                  (_getbit(ERR_CONTROL,0))        /* bit 0 */
#define _set_grid_freq_error(x)             (_putbit((x),ERR_CONTROL,0))    /* bit 0 */

#define _ee_checksum_error()                (_getbit(ERR_CONTROL,1))        /* bit 1 */
#define _set_ee_checksum_error(x)           (_putbit((x),ERR_CONTROL,1))    /* bit 1 */

#define _param_limit_error()                (_getbit(ERR_CONTROL,2))        /* bit 2 */
#define _set_param_limit_error(x)           (_putbit((x),ERR_CONTROL,2))    /* bit 2 */

#define _overtemperature_error()            (_getbit(ERR_CONTROL,3))        /* bit 3 */
#define _set_overtemperature_error(x)       (_putbit((x),ERR_CONTROL,3))    /* bit 3 */

#define _ident_error()                      (_getbit(ERR_CONTROL,4))        /* bit 4 */
#define _set_ident_error(x)                 (_putbit((x),ERR_CONTROL,4))     /* bit 4 */

#define _offset_current_error()             (_getbit(ERR_CONTROL,5))        /* bit 5 */
#define _set_current_offset_error(x)        (_putbit((x),ERR_CONTROL,5))     /* bit 5 */

#define _overcurrent_error()                (_getbit(ERR_CONTROL,6))        /* bit 6 */
#define _set_overcurrent_error(x)           (_putbit((x),ERR_CONTROL,6))    /* bit 6 */

#define _global_system_fault()              (_getbit(ERR_CONTROL,7))        /* bit 7 */
#define _set_global_system_fault(x)         (_putbit((x),ERR_CONTROL,7))    /* bit 7 */

#define _ee_size_error()                    (_getbit(ERR_CONTROL,8))        /* bit 8 */
#define _set_ee_size_error(x)               (_putbit((x),ERR_CONTROL,8))    /* bit 8 */

#define _ee_write_error()                   (_getbit(ERR_CONTROL,9))        /* bit 9 */
#define _set_ee_write_error(x)              (_putbit((x),ERR_CONTROL,9))    /* bit 9 */

#define _overload_error()                   (_getbit(ERR_CONTROL,10))       /* bit 10 */
#define _set_overload_error(x)              (_putbit((x),ERR_CONTROL,10))   /* bit 10 */

#define _ee_valid_error()                   (_getbit(ERR_CONTROL,11))       /* bit 11 */
#define _set_ee_valid_error(x)              (_putbit((x),ERR_CONTROL,11))   /* bit 11 */

/*    
    ERR_CONTROL 
    Bit 0        -    Grid Frequency_error              1: Line overfrequency  0: Line freq OK
    Bit 1        -    Checksum Error EEPROM Read        1: Checksum Error read    0: OK
    Bit 2        -    Prameters error                   1: Param errors detected in -> void Params_check_limit(void)    0: OK
    Bit 3        -    Overtemperature trip              1: Overtemperature  0: Temperature OK
    Bit 4        -    IDENT ERROR                       1: IDENT ERROR  0: IDENT OK        
    Bit 5        -    OFFSET CURRENT ERROR              1: Offset error in current mesasure channel  
    Bit 6        -    OVERCURRENT ERROR                 1: Overcurrent error 0: Current OK
    Bit 7        -    global system fault
    Bit 8        -    eeprom size error
    Bit 9        -    EE SIZE ERROR                     1: EEPROM size fault        0: OK
    Bit 10       -    OVERLOAD ERROR                   1: Cartridge overload. Too many heat periods over cartridge.        0: OK
    Bit 11       -    EE_VALID                        1: Invalid EEPROM Params    0: OK
    Bit 12       -   
    Bit 13       -   
    Bit 14       -
*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                                               */
/*----------------------------------------------------------------------------*/
void state_machine_T1(void);
void state_machine_T2(void);
void state_machine_init(void);

#endif /* STATEMACHINE_H */
