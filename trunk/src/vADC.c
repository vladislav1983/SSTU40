/******************************************************************************/
/* 
 *                          ADC IMPLEMENTATION     
 *       
*/
/******************************************************************************/
/*----------------------------------------------------------------------------*/
/* Body Identification                                                        */
/*----------------------------------------------------------------------------*/
#ifdef VADC_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define VADC_C
#endif

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "vADC.h"
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

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
volatile U16 ADC[AdcCh_Cnt];
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
/******************************************************************************/
/*
 * Name:      ADC_INIT
 * Purpose:   INIT ADC
 * 
*/
/******************************************************************************/
void IF_ADC_INIT(void)
{
	//	ADCCON1
	// |--------------------------------------------------------------------------------------------
    // | ADON	x	ADSIDL	x	x	x	FORM<1:0>	SSRC<2:0>	x	   x	 ASAM	SAMP   DONE
    // |--------------------------------------------------------------------------------------------
    // |  0		x	   0	x	x	x	   00			111		x	   x	  1		 x		 0
    // |--------------------------------------------------------------------------------------------
	
	ADCON1bits.ADSIDL 	= 0; 			//ADC_STOP_IN_IDLE_MODE;
	ADCON1bits.FORM 	= (0b00); 		//ADC_DATA_OUTPUT_FORMAT;
	ADCON1bits.SSRC 	= (0b111); 		//ADC_TRIGGER_SOURCE;
	ADCON1bits.ASAM 	= 1; 			//ADC_SAMPLE_AUTO_START_BIT;
	
	//	ADCCON2
	// |--------------------------------------------------------------------------------------------
    // | VCFG<2:0>	!	x	CSCNA	x    x	  BUFS	x	SMPI<3:0>	BUFM	ALTS	
    // |--------------------------------------------------------------------------------------------
    // |  	 000	0	x	  1		x	 x	   0	x	  0000		 0		  0
    // |--------------------------------------------------------------------------------------------	
    
    ADCON2bits.VCFG 	= (0b000); 		//ADC_VREF;
    ADCON2bits.CSCNA 	= 1; 			//ADC_SCAN_INPUT_SELECTIONS;
    ADCON2bits.SMPI 	= (0b0001); 	//ADC_SAMPLE_CONVERT_SEQUANCE;
    ADCON2bits.BUFM 	= 0; 			//ADC_BUFFER_MODE_SELECTION_BIT;
    ADCON2bits.ALTS 	= 0; 			//ADC_ALTERNATE_INPUT_SAMPLE_MODE;
    
	//	ADCCON3
	// |--------------------------------------------------------------------------------------------
    // | x	x	x	SAMC<4:0>	ADRC	x	ADCS<5:0>
    // |--------------------------------------------------------------------------------------------
    // | x	x	x	 00001 		 0		x	 010101
    // |--------------------------------------------------------------------------------------------
    //	Minimum Tad = 334 ns  	-> Minimum ADC conversion period
    //	Tcy = 31.25 ns 			-> CPU inctruction cycle period
    //	ADCS<5:0> = (2 * (Tad / Tcy) - 1) = 20.376 -> ADCS<5:0> = 21
    //	
    //	Actual Tad = (Tcy / 2) * (ADCS<5:0> +1) = 343.75 ns
    //	If SSRC<2:0> = 111 and SAMC<4:0> = 00001
    //	Since,
	//	Sampling Time = Acquisition Time + Conversion Time = = 1 Tad + 14 Tad = 15 * Tad = 5156.25 ns = 193 kHz
	
    ADCON3bits.SAMC = 2; 		//ADC_AUTO_SAMPLE_TIME_BITS;
    ADCON3bits.ADRC = 0; 		//ADC_CONVERSION_SOURCE_CLOCK;
    ADCON3bits.ADCS = 21; 		//ADC_CONVERSION_CLOCK;
    
    //ADCHS
	// |--------------------------------------------------------------------------------------------
    // | CH123NB<1:0>	CH123SB	CH0NB	CH0SB<3:0>	CH123NA<1:0>	CH123SA		CH0NA	CH0SA<3:0>
    // |--------------------------------------------------------------------------------------------
    // | 	00				1	  0		0010			01				1		   0	    0010
    // |--------------------------------------------------------------------------------------------
	
	ADCHS = 0b0000000000000000;
	
    //ADCHSbits.CH0NB		= 0; 			//ADC_CHANNEL_0_NEGATIVE_INPUT_MUXB;
    //ADCHSbits.CH0SB		= (0b0010); 	//ADC_CHANNEL_0_POSITIVE_INPUT_MUXB;
    //ADCHSbits.CH0NA		= 0; 			//ADC_CHANNEL_0_NEGATIVE_INPUT_MUXA;
    //ADCHSbits.CH0SA		= (0b0010); 	//ADC_CHANNEL_0_POSITIVE_INPUT_MUXA;   
    
    //	ADPCFG
	// |--------------------------------------------------------------------------------------------------
    // | x	x	x	x	x	x	x	PCFG8	PCFG7	PCFG6	PCFG5	PCFG4	PCFG3	PCFG2	PCFG1	PCFG0
    // |--------------------------------------------------------------------------------------------------
    // | 1	1	1	1	1	1	1	  1		  1       1       1		  1       0       0       1       1
    // |--------------------------------------------------------------------------------------------------
    
    ADPCFG = 0b1111111111110011;
    
    //ADPCFGbits.PCFG3 = 0;		//ADC_ANALOG_PIN_3_IN_DIGITAL_MODE;
    //ADPCFGbits.PCFG2 = 0;		//ADC_ANALOG_PIN_2_IN_DIGITAL_MODE;
    
    //	ADCSSL
	// |--------------------------------------------------------------------------------------------------
    // | x	x	x	x	x	x	x	CSSL8	CSSL87	CSSL6	CSSL5	CSSL4	CSSL3	CSSL2	CSSL1	CSSL0
    // |--------------------------------------------------------------------------------------------------
    // | 0	0	0	0	0	0	0	  0       0       0       0       0       1       1       0       0
    // |--------------------------------------------------------------------------------------------------
    
    ADCSSL = 0b0000000000001100;
    
    //ADCSSLbits.CSSL3 = 1;		//ADC_SELECT_AN3_FOR_INPUT_SCAN;
    //ADCSSLbits.CSSL2 = 1;		//ADC_SELECT_AN2_FOR_INPUT_SCAN;

    
    _ADIP = cISR_PRIORITY_ADC;
    
    _ADIF = 0;
    _ADIE = 0;
    
			
	ADCON1bits.ADON = 1;		//Enable AD module


}

/******************************************************************************/
/*
 * Name:      ADC_Process
 * Purpose:   Read ADC. Call every TASK1 Interrupt
*/
/******************************************************************************/
void ADC_Sample_Read(void)
{
	/* ADC is 12 bit, so scale it down to 10 bit. */
	
	while(!ADCON1bits.DONE);
	ADCON1bits.DONE = 0;
	ADC[AdcCh_0] = ADCBUF0 >> 2; 
	ADC[AdcCh_1] = ADCBUF1 >> 2;
}

