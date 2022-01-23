/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef TEMPCTRL_H
#define TEMPCTRL_H

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "MathTools.h"
#include "IDENT.H"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* Temp = Uadc*delta / Ktemp , where
 *  Uadc - adc output raw code
 *  Temp - actual temerature of cartridge
 *  Ktemp - thermocouple and it's amplifier transfer function 
 *  Kth - thermocouple transfer function 26,85uV / C
 *  Gain - amplifier gain = 372,44 ==> Ktemp = Kth * Gain = 26uV * 372,44 = 9,7mV / C
 *  Temp Max = 5000mV / 9,7mV = 512deg 
 * 
 *  Now we calc actual Temp of cartridge
 *  Temp Max = 32768 = 500 degC
 *  K = 32768 / 500 = 65.536
 *
 * After that bullshits...
 * ------------------------------------------------------------------------------
 *  WE ASSUME THAT Real Temp = Uadc / 2. TEMP IS CALIBRATE USING "T_cal_gain" -> scaled by 1024.
 * ------------------------------------------------------------------------------
 */
/******************************************************************************/
#define TEMP_MAX                          (512.0)
#define TEMP_SCALE                        (32768.0 / TEMP_MAX)

#define TEMP_TRIP                         460u
#define TEMP_USER_MAX                     450u
#define TEMP_USER_MIN                     100u
#define TEMP_DISPLAY_ACCURACY_DIV         1u
#define TEMP_DISPLAY_ACCURACY             (1u << TEMP_DISPLAY_ACCURACY_DIV)

#define TEMP_USER_MAX_Q15                 Q15((F32)TEMP_USER_MAX / TEMP_MAX)
#define TEMP_USER_MIN_Q15                 Q15((F32)TEMP_USER_MIN / TEMP_MAX)
#define TEMP_TRIP_Q15                     Q15((F32)TEMP_TRIP / TEMP_MAX)
#define TEMP_1DEG_Q15                     Q15(1.0 / TEMP_MAX)

/* TMPCTRL Parameters */
#define TMPCTRL_WAIT_AFTER_ZC_TIME        MS_TO_T1_TICKS(5ul)
#define TMPCTRL_AVERAGE_DIV               5u
#define TMPCTRL_AVERAGE_TIME              (1u << TMPCTRL_AVERAGE_DIV)
#define TMPCTRL_MAX_HEAT_PERIODS          32u

#define TMPCTRL_CAL_GAIN_SCALE_DIV        10u
#define TMPCTRL_CAL_GAIN_SCALE            (1u << TMPCTRL_CAL_GAIN_SCALE_DIV)

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/
typedef enum
{
  eTEMP_USER,
  eTEMP_USER_SLEEP,
}teTemperatureUsers;

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/    
struct temperature_control
{
 _Q15 T_fbk;
 U32 T_sum;
 U16 per_counter;
 S16 heat_periods;
 S16 heat_periods_max;
 
 _Q15 T_Ref_User_tmp;            // Temporary User Temperature.
 
 /* PARAMS STORED IN EEPROM */
 U16 tmpctrl_samp_time;    // Temperature control sample time in line halfperiods.
 U16 T_cal_gain;        // Scaled by 1024
 S16 T_cal_offset;
 
 _Q15 T_Ref_User;            // User Temperature.
 _Q15 T_Ref_User_Sleep;    // User Temperature in Sleep Mode.
 BOOL bresenham_distribution;
 U8 T_UserStep_deg;
};

struct bresenham_struct
{
 U16 control_periods;
 S16 delta_err;
 U16 bs_period_counter;
 BOOL triac_state;
};

struct overload_protection
{
 U16 cop_timer;
 U16 cop_periods;
 U16 cop_time_sec;
 U16 power_half_periods;
 
 /* PARAMS STORED IN EEPROM */
 U16 cop_periods_trip;
 U16 cop_time_trip_sec;
};
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/
/* Macros and extern struct definitions */
extern struct temperature_control T_ctrl;
#define _get_T_ctrl()    (&T_ctrl)

extern struct overload_protection overprot;
#define _get_overload_protection()    (&overprot)

/*----------------------------------------------------------------------------*/
/* Exported functions                                                            */
/*----------------------------------------------------------------------------*/
void temp_ctrl(BOOL sleep_flag, teIdentToolType tool);
_Q15 Get_Temp_Actual(void);
void Set_User_Temp(teTemperatureUsers user);
void Reset_User_Temp(teTemperatureUsers user);
_Q15 Get_User_Temp(void);
void Inc_User_Temp(void);
void Dec_User_Temp(void);
void temp_ctrl_init(void);
void Cartridge_overload_protection(void);
void Reset_TMPCTRL(void);


#endif /* TEMPCTRL.H */
