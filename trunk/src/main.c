/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#include "basedef.h"

#if defined(__dsPIC30F3014__)
    /* Configuration Bit Settings */
    _FOSC(CSW_FSCM_OFF & XT_PLL8);                 //Fail safe monitor ON & HS / 2 * PLLX16
    _FWDT(WDT_OFF & WDTPSA_1 & WDTPSB_16);           //WDT Period = 2 ms • Prescale A • Prescale B
    _FBORPOR(PBOR_ON & BORV_27 & PWRT_64 & MCLR_EN);
#   if defined(__DEBUG)
    _FGS(CODE_PROT_OFF);
#   else
    _FGS(CODE_PROT_ON);
#   endif
#elif defined(__dsPIC30F4013__)
/* Configuration Bit Settings */
    _FOSC(CSW_FSCM_OFF & XT_PLL8);                 //Fail safe monitor ON & HS / 2 * PLLX16
    _FWDT(WDT_OFF & WDTPSA_1 & WDTPSB_16);           //WDT Period = 2 ms • Prescale A • Prescale B
    _FBORPOR(PBOR_ON & BORV27 & PWRT_64 & MCLR_EN);
#   if defined(__DEBUG)
        _FGS(CODE_PROT_OFF);
#   else
        _FGS(CODE_PROT_ON);
#   endif
#endif

/* User Include */
#include<stdlib.h>
#include "DigitalIO.h"
#include "task.h"
#include "vuart.h"
#include "vADC.h"
#include "statemachine.h"
#include "eeprom.h"
#include "LCD.h"
#include "triac_control.h"
#include "measure.h"
#include "tempctrl.h"
#include "trace.h"
#include "sirem.h"


/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
extern struct sTaskTimesStruct Ttime;
extern U16 TASK_CONTROL;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/
const char *Revision = "$WCREV$";

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported functions                     				      				  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/

int main()
{
	struct sTaskTimesStruct *pTtime_pointer = &Ttime;
    U16 u16Rev;
    U16 u16SubRev;

/*----------------------------------------------------------------------------*/
/*								SYSTEM INIT			                          */
/*----------------------------------------------------------------------------*/	
	_SWDTEN = 0; // Disable WDT
	
	OSCCONbits.COSC = 0b111;
	OSCCONbits.NOSC = 0b111;
	OSCCONbits.CF = 0;
	while(OSCCONbits.LOCK!=1) {}; // Wait for PLL to lock
	
	SET_CPU_IPL(0b111);			// Force CPU interrupt priority to max.All user masked interrupts with ptiority from 0 to 7 are Disabled.(Safe version)			
	 
/*----------------------------------------------------------------------------*/
/*								MAIN PROGRAM		                          */
/*----------------------------------------------------------------------------*/
	/* INIT */
	delay_ms(10);
	
    if(EE_CheckEEprom() == S_OK)
    {
        /* Parameters Read */
	    ee_param_act(1,1); 	// INIT and put in PARACT_PARAMS_READ_ALL state
	    ee_param_act(0,0);	// RUN read all parameters. NO NEED REINIT!
    }
	
	IF_DigitalIO_Init();
	IF_LCDInit();
	trace_init_first();
	IF_SysTmr1_Init();
	IF_SysTmr2_Init();
	IF_SysTmr3_Init();
	IF_ADC_INIT();
	state_machine_init();
	triac_control_init();
	measure_init();
	temp_ctrl_init();
	
	/* END INIT */
	u16Rev = atoi(Revision);

	IF_LCDPutc('\f');
	IF_LCDPuts("    SSTU 4.0");
	IF_LCDPutc('\n');
	IF_LCDPuts("     V");
	IF_LCDPutn((u16Rev / 100));
	IF_LCDPutc('.');
	IF_LCDPutn(u16Rev - ((u16Rev / 100) * 100));
	
	delay_ms(200);
	
	INTCON1bits.NSTDIS = 0;	// Enable Nested Interrupts
	SET_CPU_IPL(0b000);		// Force CPU interrupt priority to low. All user masked interrupts with ptiority from 0 to 7 are Enabled.(Safe version)
	
	IF_Uart_Init(38400);
	
	ClrWdt(); 		// Clear WDT
	_SWDTEN = 1;	// Enable WDT	
	
	while(1)
	{
	/* BACKGROUND LOOP. */
		
		if(!_is_task1_execute() && !_is_task2_execute()) Sirem_Engine(); // Serial Communication run in background loop	
		
		Idle();
	
		if(!_is_task1_execute() && !_is_task2_execute()) TaskTimesCalc(pTtime_pointer);
		
		Idle();
		
		if(!_is_task1_execute() && !_is_task2_execute()) ee_param_act(0,0); // Online parameters actualization in background
		
		Idle();
		
		if(!_is_task1_execute() && !_is_task2_execute()) Params_check_limit();

        ClrWdt();	//<------ Clear Watchdog timer

        Idle();
	}

	return(0);
}



