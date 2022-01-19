/********************************************************************/
//              Header for Analog Comparator module library functions      */
/********************************************************************/

#if defined (__dsPIC33E__) 
#include <p33Exxxx.h>
#endif

#ifndef __HSCMP_H
#define __HSCMP_H

/* List of SFRs for Analog comparator */
/* This list contains the SFRs with default (POR) values to be used for configuring Analog comparator module */
/* The user can modify this based on the requirement */

#define CMPCON1_VALUE					0x0000
#define CMPCON2_VALUE					0x0000
#define CMPCON3_VALUE					0x0000
#define CMPCON4_VALUE					0x0000

#define CMPDAC1_VALUE					0x0000
#define CMPDAC2_VALUE					0x0000
#define CMPDAC3_VALUE					0x0000
#define CMPDAC4_VALUE					0x0000
			

/*----------------------------------------------------------------------------------------------------*/
/* CMPCON1 Configuration Bit Definitions : */
/*----------------------------------------------------------------------------------------------------*/

#define CMP1_MOD_EN						0x8000  /* Analog comparator #1 module Enabled */
#define CMP1_MOD_DIS					0x0000  /* Analog comparator #1 module Enabled */

#define CMP1_IDLE_DISCONT					0x2000  /* Discontinue device operation when device enters idle mode */
#define CMP1_IDLE_CONT					0x0000  /* Continue device operation in idle mode */

#define CMP1_DAC_OUTPUT_ENABLE			0x0100  /* Enable the DAC Output on DACOUT pin */
#define CMP1_DAC_OUTPUT_DISABLE			0x0000  /* Disable the DAC Output on DACOUT pin */

#define CMP1_A_SEL						0x0000  /* Select comparator #1A as Input pin */
#define CMP1_B_SEL						0x0040  /* Select comparator #1B as Input pin */
#define CMP1_C_SEL						0x0080  /* Select comparator #1C as Input pin */
#define CMP1_D_SEL						0x00C0  /* Select comparator #1D as Input pin */

#define CMP1_SOURCE_SEL_EXT				0x0020  /* External source provides reference to DAC */
#define CMP1_SOURCE_SEL_INT				0x0000  /* Internal reference source provides source to DAC */

#define CMP1_STATE						0x0000  /* Current state of comparator output including the polarity selection bit */

#define CMP1_OP_INV						0x0002  /* comparator output is inverted */
#define CMP1_OP_NONINV					0x0000  /* comparator output is non inverted */

#define CMP1_VOL_HIGH					0x0001  /* High Range: Max DAC value = AVDD */
#define CMP1_VOL_LOW					0x0000  /* Low Range: Max DAC value = Internal reference voltage ie 1.2V +-1% */

#if defined (_CSSMD)

#define CMP1_HYSTERESIS_45mV				0x1800  /* Hysteresis is 45 mV */
#define CMP1_HYSTERESIS_30mV				0x1000  /* Hysteresis is 30 mV */
#define CMP1_HYSTERESIS_15mV				0x0800  /* Hysteresis is 15 mV */
#define CMP1_HYSTERESIS_DISABLE			0x0000  /* Hysteresis is disabled */

#define CMP1_FILTER_ENABLE				0x0400  /* Digital filter is enabled */
#define CMP1_FILTER_DISABLE				0x0000  /* Digital filter is disabled */

#define CMP1_FILTER_CLOCK_PWM				0x0200  /* Digital filter and pulse stretcher use PWM clock */
#define CMP1_FILTER_CLOCK_FCY				0x0000  /* Digital filter and pulse stretcher use system clock */

#define CMP1_HYSTERESIS_FALLING_EDGE		0x0010  /* Hysteresis is applied on falling edge */
#define CMP1_HYSTERESIS_RISING_EDGE			0x0000  /* Hysteresis is applied on rising edge */

#define CMP1_ALTERNATE_INPUTS				0x0004  /* INSEL<1:0> bits select alternate inputs */
#define CMP1_COMPARATOR_INPUTS			0x0000  /* INSEL<1:0> bits select comparator inputs */

#endif

/*----------------------------------------------------------------------------------------------------*/
/* CMPCON2 Configuration Bit Definitions : */
/*----------------------------------------------------------------------------------------------------*/

#define CMP2_MOD_EN						0x8000  /* Analog comparator #2 module Enabled */
#define CMP2_MOD_DIS					0x0000  /* Analog comparator #2 module Enabled */

#define CMP2_IDLE_DISCONT				0x2000  /* Discontinue device operation when device enters idle mode */
#define CMP2_IDLE_CONT					0x0000  /* Continue device operation in idle mode */

#define CMP2_DAC_OUTPUT_ENABLE			0x0100  /* Enable the DAC Output on DACOUT pin */
#define CMP2_DAC_OUTPUT_DISABLE			0x0000  /* Disable the DAC Output on DACOUT pin */

#define CMP2_A_SEL						0x0000  /* Select comparator #2A as Input pin */
#define CMP2_B_SEL						0x0040  /* Select comparator #2B as Input pin */
#define CMP2_C_SEL						0x0080  /* Select comparator #2C as Input pin */
#define CMP2_D_SEL						0x00C0  /* Select comparator #2D as Input pin */

#define CMP2_SOURCE_SEL_EXT				0x0020  /* External source provides reference to DAC */
#define CMP2_SOURCE_SEL_INT				0x0000  /* Internal reference source provides source to DAC */

#define CMP2_STATE						0x0000  /* Current state of comparator output including the polarity selection bit */

#define CMP2_OP_INV						0x0002  /* comparator output is inverted */
#define CMP2_OP_NONINV					0x0000  /* comparator output is non inverted */

#define CMP2_VOL_HIGH					0x0001  /* High Range: Max DAC value = Analog VDD voltage/2 ie 2.5V @ 5V VDD Voltage */
#define CMP2_VOL_LOW					0x0000  /* Low Range: Max DAC value = Internal reference voltage ie 1.2V +-1% */

#if defined (_CSSMD)

#define CMP2_HYSTERESIS_45mV				0x1800  /* Hysteresis is 45 mV */
#define CMP2_HYSTERESIS_30mV				0x1000  /* Hysteresis is 30 mV */
#define CMP2_HYSTERESIS_15mV				0x0800  /* Hysteresis is 15 mV */
#define CMP2_HYSTERESIS_DISABLE			0x0000  /* Hysteresis is disabled */

#define CMP2_FILTER_ENABLE				0x0400  /* Digital filter is enabled */
#define CMP2_FILTER_DISABLE				0x0000  /* Digital filter is disabled */

#define CMP2_FILTER_CLOCK_PWM				0x0200  /* Digital filter and pulse stretcher use PWM clock */
#define CMP2_FILTER_CLOCK_FCY				0x0000  /* Digital filter and pulse stretcher use system clock */

#define CMP2_HYSTERESIS_FALLING_EDGE		0x0010  /* Hysteresis is applied on falling edge */
#define CMP2_HYSTERESIS_RISING_EDGE			0x0000  /* Hysteresis is applied on rising edge */

#define CMP2_ALTERNATE_INPUTS				0x0004  /* INSEL<1:0> bits select alternate inputs */
#define CMP2_COMPARATOR_INPUTS			0x0000  /* INSEL<1:0> bits select comparator inputs */

#endif

/*----------------------------------------------------------------------------------------------------*/
/* CMPCON3 Configuration Bit Definitions : */
/*----------------------------------------------------------------------------------------------------*/

#define CMP3_MOD_EN						0x8000  /* Analog comparator #3 module Enabled */
#define CMP3_MOD_DIS					0x0000  /* Analog comparator #3 module Enabled */

#define CMP3_IDLE_DISCONT				0x2000  /* Discontinue device operation when device enters idle mode */
#define CMP3_IDLE_CONT					0x0000  /* Continue device operation in idle mode */

#define CMP3_DAC_OUTPUT_ENABLE			0x0100  /* Enable the DAC Output on DACOUT pin */
#define CMP3_DAC_OUTPUT_DISABLE			0x0000  /* Disable the DAC Output on DACOUT pin */

#define CMP3_A_SEL						0x0000  /* Select comparator #3A as Input pin */
#define CMP3_B_SEL						0x0040  /* Select comparator #3B as Input pin */
#define CMP3_C_SEL						0x0080  /* Select comparator #3C as Input pin */
#define CMP3_D_SEL						0x00C0  /* Select comparator #3D as Input pin */

#define CMP3_SOURCE_SEL_EXT				0x0020  /* External source provides reference to DAC */
#define CMP3_SOURCE_SEL_INT				0x0000  /* Internal reference source provides source to DAC */

#define CMP3_STATE						0x0000  /* Current state of comparator output including the polarity selection bit */

#define CMP3_OP_INV						0x0002  /* comparator output is inverted */
#define CMP3_OP_NONINV					0x0000  /* comparator output is non inverted */

#define CMP3_VOL_HIGH					0x0001  /* High Range: Max DAC value = Analog VDD voltage/2 ie 2.5V @ 5V VDD Voltage */
#define CMP3_VOL_LOW					0x0000  /* Low Range: Max DAC value = Internal reference voltage ie 1.2V +-1% */

#if defined (_CSSMD)

#define CMP3_HYSTERESIS_45mV				0x1800  /* Hysteresis is 45 mV */
#define CMP3_HYSTERESIS_30mV				0x1000  /* Hysteresis is 30 mV */
#define CMP3_HYSTERESIS_15mV				0x0800  /* Hysteresis is 15 mV */
#define CMP3_HYSTERESIS_DISABLE			0x0000  /* Hysteresis is disabled */

#define CMP3_FILTER_ENABLE				0x0400  /* Digital filter is enabled */
#define CMP3_FILTER_DISABLE				0x0000  /* Digital filter is disabled */

#define CMP3_FILTER_CLOCK_PWM				0x0200  /* Digital filter and pulse stretcher use PWM clock */
#define CMP3_FILTER_CLOCK_FCY				0x0000  /* Digital filter and pulse stretcher use system clock */

#define CMP3_HYSTERESIS_FALLING_EDGE		0x0010  /* Hysteresis is applied on falling edge */
#define CMP3_HYSTERESIS_RISING_EDGE			0x0000  /* Hysteresis is applied on rising edge */

#define CMP3_ALTERNATE_INPUTS				0x0004  /* INSEL<1:0> bits select alternate inputs */
#define CMP3_COMPARATOR_INPUTS			0x0000  /* INSEL<1:0> bits select comparator inputs */

#endif

/*----------------------------------------------------------------------------------------------------*/
/* CMPCON4 Configuration Bit Definitions : */
/*----------------------------------------------------------------------------------------------------*/

#define CMP4_MOD_EN						0x8000  /* Analog comparator #4 module Enabled */
#define CMP4_MOD_DIS					0x0000  /* Analog comparator #4 module Enabled */

#define CMP4_IDLE_DISCONT				0x2000  /* Discontinue device operation when device enters idle mode */
#define CMP4_IDLE_CONT					0x0000  /* Continue device operation in idle mode */

#define CMP4_DAC_OUTPUT_ENABLE			0x0100  /* Enable the DAC Output on DACOUT pin */
#define CMP4_DAC_OUTPUT_DISABLE			0x0000  /* Disable the DAC Output on DACOUT pin */

#define CMP4_A_SEL						0x0000  /* Select comparator #4A as Input pin */
#define CMP4_B_SEL						0x0040  /* Select comparator #4B as Input pin */
#define CMP4_C_SEL						0x0080  /* Select comparator #4C as Input pin */
#define CMP4_D_SEL						0x00C0  /* Select comparator #4D as Input pin */

#define CMP4_SOURCE_SEL_EXT				0x0020  /* External source provides reference to DAC */
#define CMP4_SOURCE_SEL_INT				0x0000  /* Internal reference source provides source to DAC */

#define CMP4_STATE						0x0000  /* Current state of comparator output including the polarity selection bit */

#define CMP4_OP_INV						0x0002  /* comparator output is inverted */
#define CMP4_OP_NONINV					0x0000  /* comparator output is non inverted */

#define CMP4_VOL_HIGH					0x0001  /* High Range: Max DAC value = Analog VDD voltage/2 ie 2.5V @ 5V VDD Voltage */
#define CMP4_VOL_LOW					0x0000  /* Low Range: Max DAC value = Internal reference voltage ie 1.2V +-1% */

#if defined (_CSSMD)

#define CMP4_HYSTERESIS_45mV				0x1800  /* Hysteresis is 45 mV */
#define CMP4_HYSTERESIS_30mV				0x1000  /* Hysteresis is 30 mV */
#define CMP4_HYSTERESIS_15mV				0x0800  /* Hysteresis is 15 mV */
#define CMP4_HYSTERESIS_DISABLE			0x0000  /* Hysteresis is disabled */

#define CMP4_FILTER_ENABLE				0x0400  /* Digital filter is enabled */
#define CMP4_FILTER_DISABLE				0x0000  /* Digital filter is disabled */

#define CMP4_FILTER_CLOCK_PWM				0x0200  /* Digital filter and pulse stretcher use PWM clock */
#define CMP4_FILTER_CLOCK_FCY				0x0000  /* Digital filter and pulse stretcher use system clock */

#define CMP4_HYSTERESIS_FALLING_EDGE		0x0010  /* Hysteresis is applied on falling edge */
#define CMP4_HYSTERESIS_RISING_EDGE			0x0000  /* Hysteresis is applied on rising edge */

#define CMP4_ALTERNATE_INPUTS				0x0004  /* INSEL<1:0> bits select alternate inputs */
#define CMP4_COMPARATOR_INPUTS			0x0000  /* INSEL<1:0> bits select comparator inputs */

#endif

/*----------------------------------------------------------------------------------------------------*/
/* Enable/Disable Comparator interrupt : */
/*----------------------------------------------------------------------------------------------------*/

#define CMP1_INT_EN						0x0001  /*Analog comparator #1 Interrupt Enable */
#define CMP1_INT_DIS					0x0000  /*Analog comparator #1 Interrupt Disable */

#define CMP2_INT_EN						0x0001  /*Analog comparator #2 Interrupt Enable */
#define CMP2_INT_DIS					0x0000  /*Analog comparator #2 Interrupt Disable */

#define CMP3_INT_EN						0x0001  /*Analog comparator #3 Interrupt Enable */
#define CMP3_INT_DIS					0x0000  /*Analog comparator #3 Interrupt Disable */
 
#define CMP4_INT_EN						0x0001  /*Analog comparator #4 Interrupt Enable */
#define CMP4_INT_DIS					0x0000  /*Analog comparator #4 Interrupt Disable */

/*----------------------------------------------------------------------------------------------------*/
/* ADC interrupt priority : */
/*----------------------------------------------------------------------------------------------------*/

#define CMP1_INT_PR7					0x0007  /* Analog comparator #1 Interrupt Priority 7 (High Priority) */
#define CMP1_INT_PR6					0x0006  /* Analog comparator #1 Interrupt Priority 6                 */
#define CMP1_INT_PR5					0x0005  /* Analog comparator #1 Interrupt Priority 5                 */
#define CMP1_INT_PR4					0x0004  /* Analog comparator #1 Interrupt Priority 4                 */
#define CMP1_INT_PR3					0x0003  /* Analog comparator #1 Interrupt Priority 3                 */
#define CMP1_INT_PR2					0x0002  /* Analog comparator #1 Interrupt Priority 2                 */
#define CMP1_INT_PR1					0x0001  /* Analog comparator #1 Interrupt Priority 1 (Low Priority)  */
#define CMP1_INT_DIS					0x0000  /* Analog comparator #1 Interrupt Priority Disabled          */

#define CMP2_INT_PR7					0x0007  /* Analog comparator #2 Interrupt Priority 7 (High Priority) */
#define CMP2_INT_PR6					0x0006  /* Analog comparator #2 Interrupt Priority 6                 */
#define CMP2_INT_PR5					0x0005  /* Analog comparator #2 Interrupt Priority 5                 */
#define CMP2_INT_PR4					0x0004  /* Analog comparator #2 Interrupt Priority 4                 */
#define CMP2_INT_PR3					0x0003  /* Analog comparator #2 Interrupt Priority 3                 */
#define CMP2_INT_PR2					0x0002  /* Analog comparator #2 Interrupt Priority 2                 */
#define CMP2_INT_PR1					0x0001  /* Analog comparator #2 Interrupt Priority 1 (Low Priority)  */
#define CMP2_INT_DIS					0x0000  /* Analog comparator #2 Interrupt Priority Disabled          */

#define CMP3_INT_PR7					0x0007  /* Analog comparator #3 Interrupt Priority 7 (High Priority) */
#define CMP3_INT_PR6					0x0006  /* Analog comparator #3 Interrupt Priority 6                 */
#define CMP3_INT_PR5					0x0005  /* Analog comparator #3 Interrupt Priority 5                 */
#define CMP3_INT_PR4					0x0004  /* Analog comparator #3 Interrupt Priority 4                 */
#define CMP3_INT_PR3					0x0003  /* Analog comparator #3 Interrupt Priority 3                 */
#define CMP3_INT_PR2					0x0002  /* Analog comparator #3 Interrupt Priority 2                 */
#define CMP3_INT_PR1					0x0001  /* Analog comparator #3 Interrupt Priority 1 (Low Priority)  */
#define CMP3_INT_DIS					0x0000  /* Analog comparator #3 Interrupt Priority Disabled          */

#define CMP4_INT_PR7					0x0007  /* Analog comparator #4 Interrupt Priority 7 (High Priority) */
#define CMP4_INT_PR6					0x0006  /* Analog comparator #4 Interrupt Priority 6                 */
#define CMP4_INT_PR5					0x0005  /* Analog comparator #4 Interrupt Priority 5                 */
#define CMP4_INT_PR4					0x0004  /* Analog comparator #4 Interrupt Priority 4                 */
#define CMP4_INT_PR3					0x0003  /* Analog comparator #4 Interrupt Priority 3                 */
#define CMP4_INT_PR2					0x0002  /* Analog comparator #4 Interrupt Priority 2                 */
#define CMP4_INT_PR1					0x0001  /* Analog comparator #4 Interrupt Priority 1 (Low Priority)  */
#define CMP4_INT_DIS					0x0000  /* Analog comparator #4 Interrupt Priority Disabled          */

/*****************************Function prototypes**************************************************/

void OpenHSCMP1(unsigned int config1) __attribute__((section (".libperi")));
void OpenHSCMP2(unsigned int config1) __attribute__((section (".libperi")));
void OpenHSCMP3(unsigned int config1) __attribute__((section (".libperi")));
void OpenHSCMP4(unsigned int config1) __attribute__((section (".libperi")));

void SetHSCMPRef1(unsigned int config1) __attribute__((section (".libperi")));
void SetHSCMPRef2(unsigned int config1) __attribute__((section (".libperi")));
void SetHSCMPRef3(unsigned int config1) __attribute__((section (".libperi")));
void SetHSCMPRef4(unsigned int config1) __attribute__((section (".libperi")));

void ConfigIntHSCMP1(unsigned int cmp_intp, unsigned int cmp_Intp_priority) __attribute__((section (".libperi")));
void ConfigIntHSCMP2(unsigned int cmp_intp, unsigned int cmp_Intp_priority) __attribute__((section (".libperi")));
void ConfigIntHSCMP3(unsigned int cmp_intp, unsigned int cmp_Intp_priority) __attribute__((section (".libperi")));
void ConfigIntHSCMP4(unsigned int cmp_intp, unsigned int cmp_Intp_priority) __attribute__((section (".libperi")));

void CloseHSCMP1(void) __attribute__((section (".libperi")));
void CloseHSCMP2(void) __attribute__((section (".libperi")));
void CloseHSCMP3(void) __attribute__((section (".libperi")));
void CloseHSCMP4(void) __attribute__((section (".libperi")));


/*******************************************Macros******************************************/
/* Macros to  Enable/Disable interrupts and set Interrupt priority of Comparator */

#define ClearHSCMP1IntFlag()					(_AC1IF = 0)
#define EnableIntHSCMP1()                    			(_AC1IE = 1)
#define DisableIntHSCMP1()					(_AC1IE = 0)
#define SetPriorityIntHSCMP1(priority)			(_AC1IP = priority)

#define ClearHSCMP2IntFlag()					(_AC2IF = 0)
#define EnableIntHSCMP2()                    			(_AC2IE = 1)
#define DisableIntHSCMP2()					(_AC2IE = 0)
#define SetPriorityIntHSCMP2(priority)			(_AC2IP = priority)

#define ClearHSCMP3IntFlag()					(_AC3IF = 0)
#define EnableIntHSCMP3()                    			(_AC3IE = 1)
#define DisableIntHSCMP3()					(_AC3IE = 0)
#define SetPriorityIntHSCMP3(priority)			(_AC3IP = priority)

#define ClearHSCMP4IntFlag()					(_AC4IF = 0)
#define EnableIntHSCMP4()                    			(_AC4IE = 1)
#define DisableIntHSCMP4()					(_AC4IE = 0)
#define SetPriorityIntHSCMP4(priority)			(_AC4IP = priority)


#endif /*__HSCMP_H*/




  
