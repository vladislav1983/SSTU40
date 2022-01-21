/* 
 * File:   adc_drv.c
 * Author: gyv1sf4
 *
 * Created on January 19, 2022, 9:36 AM
 */
/*-----------------------------------------------------------------------------
    INCLUDE FILES
-----------------------------------------------------------------------------*/
#include "adc_drv.h"
#include "adc12.h"
#include "smpsadc.h"

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL VARIABLES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DECLARATION OF LOCAL FUNCTIONS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DECLARATION OF LOCAL MACROS/#DEFINES
-----------------------------------------------------------------------------*/
#define cTAD_ns             (2 *334ul)

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL TYPES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL VARIABLES
-----------------------------------------------------------------------------*/
tAdcBuffer AdcBuffer = {0};

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL CONSTANTS
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    DEFINITION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/
//- **************************************************************************
//! \brief 
//- **************************************************************************
void AdcDrv_Init(void)
{
  ADCON1 = (U16)~ADCON1_VALUE \
         & ADC_MODULE_OFF \
         & ADC_IDLE_CONTINUE  \
         & ADC_FORMAT_FRACT \
         & ADC_CLK_AUTO \
         & ADC_AUTO_SAMPLING_ON \
         & ADC_SAMP_ON;
  
  ADCON2 = (U16)~ADCON2_VALUE \
         & ADC_VREF_AVDD_AVSS \
         & ADC_SCAN_ON \
         & ADC_SAMPLES_PER_INT_2 \
         & ADC_ALT_BUF_OFF \
         & ADC_ALT_INPUT_OFF;
  
  //    Minimum Tad = 334 ns      -> Minimum ADC conversion period
  //    ADCS<5:0> = 2 * (Tad / Tcy) - 1
  //    
  //    Actual Tad = (Tcy / 2) * (ADCS<5:0> +1)
  //    If SSRC<2:0> = 111 and SAMC<4:0> = 00001
  ADCON3 = (U16)~ADCON3_VALUE \
         & ADC_SAMPLE_TIME_2 \
         & ADC_CONV_CLK_SYSTEM \
         & ADC_CONV_CLK_Tcy2;
  ADCON3 |= (U16)~ADC_CONV_CLK_Tcy2 & (U16)(((2 * (cTAD_ns / cTCY_NS)) - 1) & 0x3F) /* A/D Auto Sample Time */;
    
  ADCHS = (U16)~ADCHS_VALUE \
        & ADC_CH0_POS_SAMPLEA_AN0 \
        & ADC_CH0_NEG_SAMPLEA_VREFN \
        & ADC_CH0_POS_SAMPLEB_AN0 \
        & ADC_CH0_NEG_SAMPLEB_VREFN;
  
  ADCSSL = ADCSSL_VALUE \
         | ~SKIP_SCAN_AN2 \
         | ~SKIP_SCAN_AN3;
  
  ADPCFG = ENABLE_AN2_ANA & ENABLE_AN3_ANA;
  
  SetPriorityIntADC(cISR_PRIORITY_ADC);
  DisableIntADC;
  
  // turn on adc module
  ADCON1 |= (U16)~ADC_MODULE_OFF;
}

//- **************************************************************************
//! \brief 
//- **************************************************************************
void AdcReadAllChannels(void)
{
  while(ADCON1bits.DONE == 0);
  ADCON1bits.DONE = 0;
  // get adc result in Q15 fractional format 
  AdcBuffer[ADC_CH0_TEMP]    = ADCBUF0 >> 1;
  AdcBuffer[ADC_CH1_CURRENT] = ADCBUF1 >> 1;
}

//- **************************************************************************
//! \brief 
//- **************************************************************************
tAdcChannel AdcReadChannel(tAdcChList AdcCh)
{
  tAdcChannel res = 0;
  
  if(AdcCh < ADC_CH_NUM)
  {
    res = AdcBuffer[AdcCh];
  }
  else
  {
    mAssert(cFalse);
  }
  
  return res;
}

/*-----------------------------------------------------------------------------
    DEFINITION OF LOCAL FUNCTIONS
-----------------------------------------------------------------------------*/
//- **************************************************************************
//! \brief 
//- **************************************************************************

/*-----------------------------------------------------------------------------
    END OF MODULE
-----------------------------------------------------------------------------*/


