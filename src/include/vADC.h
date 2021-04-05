/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef VADC_H
#define VADC_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "task.h"

/*----------------------------------------------------------------------------*/
/* EXPORTED DATA                                                             */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
/* ADCON1 CONFIG */
#define ADC_STOP_IN_IDLE_MODE            0                // Continue in IDLE mode
#define ADC_DATA_OUTPUT_FORMAT            (0b00)            // Integer
#define ADC_TRIGGER_SOURCE                (0b010)            // General purpose Timer3 compare ends sampling and starts conversion
#define ADC_SAMPLE_AUTO_START_BIT        1                // At least one A/D sample/hold amplifier is sampling

/* ADCON2 CONFIG */
#define ADC_VREF                        (0b000)            // AVDD AVSS
#define ADC_SCAN_INPUT_SELECTIONS        1                // Scan inputs
#define ADC_SAMPLE_CONVERT_SEQUANCE        (0b0000)        // 
#define ADC_BUFFER_MODE_SELECTION_BIT    0                // Buffer configured as one 16-word buffer ADCBUF(15...0)
#define ADC_ALTERNATE_INPUT_SAMPLE_MODE 1                // Always use MUX A input multiplexer settings

/* ADCON3 CONFIG */
#define ADC_AUTO_SAMPLE_TIME_BITS        (0b00001)        // Auto Sample Time bits --> 1Tad
#define ADC_CONVERSION_SOURCE_CLOCK        0                // Clock derived from system clock
#define ADC_CONVERSION_CLOCK            (0b010101)        // A/D Conversion Clock Select bits --> 21 * Tcy

/* ADCHS CONFIG */
#define ADC_CHANNEL_0_NEGATIVE_INPUT_MUXB        0
#define ADC_CHANNEL_0_POSITIVE_INPUT_MUXB        (0b0010)
#define ADC_CHANNEL_0_NEGATIVE_INPUT_MUXA        0         // Channel 0 negative input is VREF-
#define ADC_CHANNEL_0_POSITIVE_INPUT_MUXA        (0b0010) // Channel 0 positive input is AN2

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
typedef enum eAdcChannel
{
    AdcCh_0   = 0,
    AdcCh_1   = 1,
    AdcCh_Cnt = 2,

}AdcCh;

extern U16 ADC[AdcCh_Cnt];
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                                         */
/*----------------------------------------------------------------------------*/
void IF_ADC_INIT(void);
void ADC_Sample_Read(void);


#endif /* ADC_H */
