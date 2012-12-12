/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef DIGITALIOCFG_h
#define DIGITALIOCFG_h
    
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

/*----------------------------------------------------------------------------*/
/* Pins declaration                                    		                  */
/*----------------------------------------------------------------------------*/
/* LCD PIN DEFINE */
#define pinLCD_DB4			_LATB11
#define pinLCD_DB4_dir		_TRISB11

#define pinLCD_DB5			_LATB12
#define pinLCD_DB5_dir		_TRISB12

#define pinLCD_DB6			_LATD0
#define pinLCD_DB6_dir		_TRISD0

#define pinLCD_DB7			_LATD1	
#define pinLCD_DB7_dir		_TRISD1

#define pinLCD_RS			_LATF0	
#define pinLCD_RS_dir		_TRISF0

#define pinLCD_E			_LATF1
#define pinLCD_E_dir		_TRISF1

/* BUTTON PIN DEFINE */
#define pinBUT_SEL			_RF3
#define pinBUT_SEL_dir		_TRISF3

#define pinBUT_UP			_RF4
#define pinBUT_UP_dir		_TRISF4

#define pinBUT_DOWN			_RF5
#define pinBUT_DOWN_dir		_TRISF5

/* LED PIN DEFINE */
#define pinLED 				_LATF6
#define pinLED_dir			_TRISF6

/* Solder state digital inputs */
#define pinEXTR				_RD3
#define pinEXTR_dir			_TRISD3

#define pinSTAND			_RD8
#define pinSTAND_dir		_TRISD8

#define pinCART_STAT		_RB5
#define pinCART_STAT_dir	_TRISB5

/* Cartridge detection control */
#define pinSTAT_DET			_LATD9
#define pinSTAT_DET_dir		_TRISD9

/* Measure Enable */
#define pinMES_EN			_LATB10
#define pinMES_EN_dir		_TRISB10

/* Triac fire */
#define pinTH_FIRE			_LATD2
#define pinTH_FIRE_dir		_TRISD2

/* Zero Cross pooling */
#define pinZC				_RA11	
#define pinZC_dir			_TRISA11

/* Analog pin */
//#define pinANA_1			_RB2	
//#define pinANA_1_dir		_TRISB2

//#define pinANA_2			_RB3	
//#define pinANA_2_dir		_TRISB3

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                                         */
/*----------------------------------------------------------------------------*/

#endif /* DIGITALIOCFG_h */
