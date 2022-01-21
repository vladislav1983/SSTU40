/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef MEASURE_H
#define MEASURE_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
/* DC autotunning parameters */
#define DC_AVERAGE_DIVIDER            14u
#define DC_AVERAGE_TIME               (1u << DC_AVERAGE_DIVIDER)

#define DC_OFFSET_IDEAL               (Q15(1.0/2.0))
#define DC_OFFSET_UPPER_LIMIT         (DC_OFFSET_IDEAL + (DC_OFFSET_IDEAL * 0.05))
#define DC_OFFSET_LOWER_LIMIT         (DC_OFFSET_IDEAL - (DC_OFFSET_IDEAL * 0.05))
#define CURRENT_MAX_mA                25000u

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/

/* Measured and Values */
struct Mes1
{
  BOOL line_phase;
  BOOL line_phase_old;
  S16 Line_per_delta_corr;
  U16 Line_period_zc;

  U16 Curr_offset;
  S16 Current;
};

struct Mes2
{
  U16 Line_period_zc_T2;
  U16 Line_frequency_zc;

  U16 Actaul_Power;
};
    
struct mes_par
{
  U16 dc_average_counter;
  U32 dc_sum;

  /* PARAMS STORED IN EEPROM */
  U16 Transformer_Voltage;
  U16 Overcurr_limit;
};

/* Macros and extern struct definitions */
extern struct Mes1 mes1;
#define _get_mes1()    (&mes1)

extern struct Mes2 mes2;
#define _get_mes2()    (&mes2)

extern struct mes_par mespar;
#define _get_mespar()    (&mespar)
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                                           */
/*----------------------------------------------------------------------------*/
void zero_cross(void);
void zero_cross_II(void);
void measure_T2(void);
BOOL DC_Autotunning(void);
void Current_measure(void);
void measure_init(void);

#endif /* MEASURE_H */
