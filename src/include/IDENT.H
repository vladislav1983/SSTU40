/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef IDENT_H
#define IDENT_H

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
/* IDENT PARAMETERS */
#define IDENT_PERIODS_MAX               100u
#define IDENT_MEASURE_AFTER_TIME        (5E3   / T1_TIME_us) /* 5000 us*/
#define IDENT_AVERAGE_TIME              (500E3 / T1_TIME_us) /* 500ms Average time in task1 periods */

/* IDENT MODES OF OPERATION */
typedef enum
{
  IDENT_INIT = 1,
  IDENT_WAIT_MES_TEMP,
  IDENT_MES_TEMP,
  IDENT_TRIAC_FIRE,
  IDENT_WAIT_AFTER_ZC,
  IDENT_MES_TEMP_2,
  IDENT_EXIT,
  IDENT_UNDEFINED_STATE
}tIdentMode;


/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/
typedef enum 
{
  eIdentTool_Unknown = 0,
  eIdentTool_2210,
  eIdentTool_2245,
  eIdentTool_NR,
}teIdentToolType;

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
struct cartridge_ident
{
  S32 IdentCurrent_filt;
  U16 U_Temp_in;
  U16 U_Temp_out;
  S16 U_Temp_delta;
  S32 U_Temp_filt;
  U16 Ident_peak_current;
  U16 Ident_current;
  U16 IDENT_MAX_RMS_Power;
  
  tIdentMode ident_mode;
  U16 ident_periods;
  teIdentToolType IdentTool;
  
  // https://controlguru.com/design-and-tuning-recipe-must-consider-nonlinear-process-behavior/
  // Kp describes the direction PV moves and how far it travels in response to a change in CO.
  // Kp = delta PV / delta CO = delta Temp / ident periods * 1000
  S16 Kp;
  // Dead time is the delay from when a controller output (CO) signal is issued until when the measured process variable (PV) first begins to respond.
  U32 Dt_us;
  U16 Dt_counter;
  U16 Dt_Temp_in;
  // In general terms, the time constant, Tp, describes how fast the PV moves in response to a change in the CO.
  U32 Tp_us;

  /* PARAMS STORED IN EEPROM */
  U16 ident_deltaT_trip_low;
  U16 ident_deltaT_trip_high;
  U16 ident_current_trip;
  U16 ident_periods_load;
  U16 ident_cur_2210_low;
  U16 ident_cur_2210_high;
  U16 ident_cur_2245_low;
  U16 ident_cur_2245_high;
};
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/


/* IDENT structures pointer initialization */
extern struct cartridge_ident ident;
#define _get_ident()    (&ident)

/*----------------------------------------------------------------------------*/
/* Exported functions                                                          */
/*----------------------------------------------------------------------------*/
BOOL cartridge_ident(BOOL ident_init);
teIdentToolType ident_get_current_tool(void);

#endif /* IDENT_H */
