/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef SYSTMR_H
#define SYSTMR_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
#define CPU_CYCLE_ns							(31.25)

/* Task 2 Timer reference */
#define cTMR1_ISR_TICK_us						(5000u)		//timer1 tick in us = task2 time
#define cTMR1_PRESC								(64ul)		//timer1 prescaller
#define TMR1_STOP_IN_IDLE_MODE 					0			//Disable
#define TMR1_GATED_TIME_ACUMULATION_ENABLE		0			//Disable
#define TMR1_PRESCALER							(0b10)		//Prescaler = 64
#define TMR1_CLOCK_SOURCE						0			//Internal clock

/* Task 1 Timer reference */
#define cTMR3_ISR_TICK_us						(100u)		//timer3 tick in us = task1 time
#define cTMR3_PRESC								(1u)
#define TMR3_STOP_IN_IDLE_MODE 					0			//Disable
#define TMR3_GATED_TIME_ACUMULATION_ENABLE		0			//Disable
#define TMR3_PRESCALER							(0b00)		//Prescaler = 1
#define TMR3_CLOCK_SOURCE						0			//Internal clock

/* Task 2 Timer measure */
#define TMR2_STOP_IN_IDLE_MODE 					0			//Disable
#define TMR2_GATED_TIME_ACUMULATION_ENABLE		0			//Disable
#define TMR2_PRESCALER							(0b00)		//Prescaler = 1
#define TMR2_T32								0
#define TMR2_CLOCK_SOURCE						0

/* Time Parameters */
#define TIME_PRESCALER			10000	//	Prescaler for secons count in task1 periods.

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/
struct Times
	{
	U16 Timer;
	U16 sec;
	U16 min;
	
	/* PARAMS STORED IN EEPROM */
	U16 Hib_Time;
	};
/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/
extern struct Times time;
#define _get_time()		(&time)
/*----------------------------------------------------------------------------*/
/* Exported functions                     				      				  */
/*----------------------------------------------------------------------------*/
void IF_SysTmr1_Init(void);
void IF_SysTmr2_Init(void);
void IF_SysTmr3_Init(void);

void delay_ms(U32 u32ms);
void delay_us(U32 u32us);
void Soft_WDT1_Start(U32 U16us);
void Soft_WDT1_Clear(void);
BOOL Timestate_Cartridge_Control(BOOL Clear);

#endif /* SYSTMR_H */
