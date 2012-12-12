/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/

/*----------------------------------------------------------------------------*/
/* Body Identification                                                        */
/*----------------------------------------------------------------------------*/
#ifdef SYSTMR_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define SYSTMR_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "systmr.h"
#include "statemachine.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
struct Times time;

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
extern volatile U16 TASK_CONTROL;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/


/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
* Purpose: Timer 1 Setup. Give Task 2 reference time
* Input: none
* Output: none
*/
/******************************************************************************/
void IF_SysTmr1_Init(void)
{
   
	T1CONbits.TSIDL = TMR1_STOP_IN_IDLE_MODE;
	T1CONbits.TGATE = TMR1_GATED_TIME_ACUMULATION_ENABLE;
	T1CONbits.TCKPS = TMR1_PRESCALER;
	T1CONbits.TCS 	= TMR1_CLOCK_SOURCE;

    TMR1 = 0;
    PR1 = (U32)((((cFCY_MHZ) * (cTMR1_ISR_TICK_us)) / (cTMR1_PRESC)) - 1ul);	// set period1 register
	
    _T1IP = cISR_PRIORITY_TMR1;     		// set priority level
    _T1IF = 0;                      		// clear interrupt flag
    _T1IE = 1;                      		// enable interrupts

    T1CONbits.TON = 1;              		// start the timer
}
/******************************************************************************/
/*
* Purpose: Timer 3 Setup. Give Task 1 reference time
* Input: none
* Output: none
* Note : Priority --> High
*/
/******************************************************************************/
void IF_SysTmr3_Init(void)
{

    T3CONbits.TSIDL = TMR3_STOP_IN_IDLE_MODE;
	T3CONbits.TGATE = TMR3_GATED_TIME_ACUMULATION_ENABLE;
	T3CONbits.TCKPS = TMR3_PRESCALER;
	T3CONbits.TCS 	= TMR3_CLOCK_SOURCE;
	
	TMR3 = 0;
    PR3 = (U16)((((cFCY_MHZ) * (cTMR3_ISR_TICK_us)) / (cTMR3_PRESC)) - 1ul);	 // set period1 register
	
    _T3IP = cISR_PRIORITY_TMR3;     		// set priority level
    _T3IF = 0;                      		// clear interrupt flag
    _T3IE = 1;                      		// enable interrupts

    T3CONbits.TON = 1;              		// start the timer
}

/******************************************************************************/
/*
* Purpose: Timer 2 Setup. Measure Task 2 time.
* Input: none
* Output: none
*/
/******************************************************************************/
void IF_SysTmr2_Init(void)
{

    T2CONbits.TSIDL = TMR2_STOP_IN_IDLE_MODE;
	T2CONbits.TGATE = TMR2_GATED_TIME_ACUMULATION_ENABLE;
	T2CONbits.TCKPS = TMR2_PRESCALER;
	T2CONbits.T32 	= TMR2_T32;
	T2CONbits.TCS 	= TMR2_CLOCK_SOURCE;
	
	PR2 = 65535;
	
	TMR2 = 0;	
    _T2IP = cISR_PRIORITY_TMR2;     		// set priority level
    _T2IF = 0;                      		// clear interrupt flag
    _T2IE = 0;                      		// disable interrupts

    T2CONbits.TON = 1;              		// start the timer
}

/******************************************************************************/
/*
* Purpose: Delay in microseconds. This function is fucking inaccurate!
* Input: none
* Output: none
*/
/******************************************************************************/
void delay_us(U32 u32us)
{		
	u32us *= (U16)((F32)1000ul/ (F32) cTCY_NS);
	while(u32us--);
}

/******************************************************************************/
/*
* Purpose: Delay in miliseconds. This function is fucking inaccurate!
* Input: none
* Output: none
*/
/******************************************************************************/
void delay_ms(U32 u32ms)
{
	u32ms *= (U16)((F32)1000000ul/ (F32) cTCY_NS);
	while(u32ms--);
}
/******************************************************************************/
/*
* Purpose: Timepiece.
* Input: 
* Output:  
*/
/******************************************************************************/
BOOL Timestate_Cartridge_Control(BOOL Clear)
{
	struct Times *t;
	
	t = _get_time();
	
	if(Clear)
	{
		(t)->min = 0;
		(t)->sec = 0;
		(t)->Timer = 0;
	}
	else
	{
		(t)->Timer++;
		if((t)->Timer >= TIME_PRESCALER)
		{
			(t)->Timer = 0;
			(t)->sec++;
		}
		if((t)->sec >= 60)
		{
			(t)->sec = 0;
			(t)->min++;
		}

		if((t)->min >= (t)->Hib_Time)
		{
			(t)->min = 0;
			return(1);
		}
	}

	return(0);
}
