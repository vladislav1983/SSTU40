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

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* Temp = Uadc*delta / Ktemp , where
*  Uadc - adc output raw code
*  Temp - actual temerature of cartridge
*  delta - adc step transfer (Vref / 1024) = 5/1024 = 4,88mV
*  Ktemp - thermocouple and it's amplifier transfer function 
*  Kth - thermocouple transfer function 26,85uV / C
*  Gain - amplifier gain = 372,44 ==> Ktemp = Kth * Gain = 26,85uV * 372,44 = 10mV / C
* 
*  Now we calc actual Temp of cartridge
*  Temp = Uadc*delta / Ktemp = Uadc * 4,88 / 10 = Uadc / 2,048
*
* After that bullshits...
* ------------------------------------------------------------------------------
*  WE ASSUME THAT Real Temp = Uadc / 2. TEMP IS CALIBRATE USING "T_cal_gain" -> scaled by 1024.
* ------------------------------------------------------------------------------
*/
/******************************************************************************/

#define RAW_TEMP_MAX					900u		//Max temp = 450C = 1000 -> adc raw value
#define RAW_TEMP_MIN					200u		//min temp = 100C =  200 -> adc raw value
#define MIN_TEMP_TRIP_RAW				10u
#define MAX_TEMP_TRIP_RAW				900u

#define TEMP_USER_MAX					450
#define TEMP_USER_MIN					100
#define TEMP_USER_STEP					5u
#define TEMP_DISPLAY_ACCURACY			5u

/* TMPCTRL Parameters */
#define TMPCTRL_WAIT_AFTER_ZC_TIME		60u
#define TMPCTRL_AVERAGE_TIME			32u
#define TMPCTRL_AVERAGE_DIVIDER			5u
#define TMPCTRL_MAX_HEAT_PERIODS		32u

#define TMPCTRL_TIMER_READ				0
#define TMPCTRL_TIMER_LOAD				1
#define TMPCTRL_TIMER_COUNT				2


/* TEMPERATURE CONTROL STATES */
#define TMPCTRL_INIT					1
#define TMPCTRL_MEASURE_TEMP			2
#define TMPCTRL_CONTROL					3
#define TMPCTRL_TRIAC_FIRE				4
#define TMPCTRL_WAIT_AFTER_ZC_STATE		5
#define TMPCTRL_WAIT_X_PERIODS_STATE	6
#define TMPCTRL_UNDEF_STATE				100

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/	
struct temperature_control
	{
	U16 T_fbk;
	S16 T_delta;
	U16 T_sum;
	U16 per_counter;
	S16 heat_periods;
	U16 heat_periods_debug;
	
	BOOL tmpctrl_triac_state;
	
	U16 T_Ref_User_tmp;			// Temporary User Temperature.
	
	/* PARAMS STORED IN EEPROM */
	U16 tmpctrl_samp_time;	// Temperature control sample time in line halfperiods.
	U16 T_cal_gain;		// Scaled by 1024
    S16 T_cal_offset;
	U16 PID_Out_cal;		// Scaled by 1024
	U16 Ring_reduction_per;
	
	U16 T_Ref_User;			// User Temperature.
	U16 T_Ref_User_Sleep;	// User Temperature in Sleep Mode.
	
	};

struct pid_struct
	{
	S16 P_term;
	S16 I_term;
	S16 D_term;
	
	S16 err;
	S16 err_prev;
	
	S16 Sum;
	S16 Out;
	
	/* PARAMS STORED IN EEPROM */
	S16 Kp;
	S16 Ki;
	S16 Kd;
	
	S16 Ki_Limit;
	S16 Out_Limit;
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
extern volatile struct temperature_control T_ctrl;
#define _get_T_ctrl()	(&T_ctrl)

extern volatile struct pid_struct pid;
#define _get_pid()	(&pid)

extern volatile struct bresenham_struct brs;
#define _get_bresenham_struct()	(&brs)

extern volatile struct overload_protection overprot;
#define _get_overload_protection()	(&overprot)

/*----------------------------------------------------------------------------*/
/* Exported functions                     				     				  */
/*----------------------------------------------------------------------------*/
void temp_ctrl(U16 Temp_ADC_Ch, BOOL sleep_flag);
U16 Get_Temp_Actual(void);
void Set_User_Temp(void);
void Roll_Back_User_Temp(void);
U16 Get_User_Temp(void);
void Inc_User_Temp(void);
void Dec_User_Temp(void);
void temp_ctrl_init(void);
S16 PID(U16 Ref, U16 Fbk);
void Cartridge_overload_protection(void);
void Reset_PID(void);
void Reset_TMPCTRL(void);


#endif /* TEMPCTRL.H */
