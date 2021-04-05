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
#define IDENT_PERIODS_MAX                16u
#define IDENT_MEASURE_AFTER_TIME        60u        /* Measure after zero cross in task1 time periods */
#define IDENT_AVERAGE_TIME                32u        /* Average time in task1 periods */
#define IDENT_AVERAGE_DIVIDER            5u        /* Average divider  */
#define IDENT_WAIT_AFTER_ZC_TIME        60u
#define IDENT_MES_TIME_AFTER_SHOT        10000    //1.5s in task1 periods for temp update
#define IDENT_TRACE_START_BEFORE_SHOT    1u
#define IDENT_TRACE_START_AFTER_SHOT    2u

/* BRESENHAM DISTRIBUTION PARAMETERS */
#define BSM_CONTROL_PERIODS_MAX            16u

#define SQRT_OF_TWO                    1.4142f    

/* IDENT MODES OF OPERATION */
#define IDENT_INIT                1
#define IDENT_MES_TEMP            2
#define IDENT_TRIAC_FIRE        3
#define IDENT_WAIT_STATE        4
#define IDENT_WAIT_AFTER_ZC        5
#define IDENT_MES_TEMP_2        6
#define IDENT_EXIT                7
#define IDENT_UNDEFINED_STATE    100

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
struct cartridge_ident
    {
    U16 U_Temp_in;
    U16 U_Temp_out;
    U16 U_Temp_max;
    S16 U_Temp_delta;
    U16 U_Temp_sum;
    U16 Ident_peak_current;
    U16 IDENT_Peak_Power;
    U16 IDENT_MAX_RMS_Power;
    
    U16 ident_mode;
    U16 ident_periods;
    U16 ident_periods_load;
    U16 ident_trace_start;
    BOOL ident_mes_temp;
    
    /* PARAMS STORED IN EEPROM */
    U16 ident_deltaT_trip;
    U16 ident_current_trip;
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
BOOL cartridge_ident(BOOL ident_init,U16 ADC_Temp_Ch);

#endif /* IDENT_H */
