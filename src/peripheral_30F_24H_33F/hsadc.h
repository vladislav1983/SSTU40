/********************************************************************/
/*              Header for 12 bit High-Speed ADC library functions      	  */
/*                    for 33E devices only              				  */
/********************************************************************/

#if defined(__dsPIC33E__)
#include <p33Exxxx.h>
#else
#error "Does not build on this target"
#endif

#ifndef __ADC_H
#define __ADC_H

/* List of SFRs for ADC */
/* This list contains the SFRs with default (POR) values to be used for configuring ADC */
/* The user can modify this based on the requirement */



/* defines for xxxx register */



/*defines for ANSELA register To Be used With configport_a in OpenADC.c */
#define ENABLE_AN0_ANA 				0x0001 /* _ANSA0 ANSELAbits.ANSA0   */
#define ENABLE_AN1_ANA 				0x0002 /* _ANSA1 ANSELAbits.ANSA1   */
#define ENABLE_AN2_ANA 				0x0004 /* _ANSA2 ANSELAbits.ANSA2   */

/*defines for ANSELB register To Be used With configport_b in OpenADC.c */
#define ENABLE_AN3_ANA 				0x0001 /* _ANSB0 ANSELBbits.ANSB0   */
#define ENABLE_AN6_ANA 				0x0002 /* _ANSB1 ANSELBbits.ANSB1   */
#define ENABLE_AN7_ANA 				0x0004 /* _ANSB2 ANSELBbits.ANSB2   */
#define ENABLE_AN18_ANA				0x0008 /* _ANSB3 ANSELBbits.ANSB3  */
#define ENABLE_AN19_ANA				0x0020 /* _ANSB5 ANSELBbits.ANSB5  */
#define ENABLE_AN20_ANA				0x0040 /* _ANSB6 ANSELBbits.ANSB6  */
#define ENABLE_AN21_ANA				0x0080 /* _ANSB7 ANSELBbits.ANSB7  */
#define ENABLE_AN4_ANA 				0x0200 /* _ANSB9 ANSELBbits.ANSB9   */
#define ENABLE_AN5_ANA				0x0400 /* _ANSB10 ANSELBbits.ANSB10 */

/*defines for ANSELC register To Be used With configport_c in OpenADC.c*/
#define ENABLE_AN8_ANA				0x0002 /* _ANSC1 ANSELCbits.ANSC1 */
#define ENABLE_AN9_ANA				0x0004 /* _ANSC2 ANSELCbits.ANSC2 */
#define ENABLE_AN24_ANA				0x0010 /* _ANSC4 ANSELCbits.ANSC4 */
#define ENABLE_AN23_ANA				0x0020 /* _ANSC5 ANSELCbits.ANSC5 */
#define ENABLE_AN22_ANA				0x0040 /* _ANSC6 ANSELCbits.ANSC6 */
#define ENABLE_AN11_ANA				0x0200 /* _ANSC9 ANSELCbits.ANSC9 */
#define ENABLE_AN10_ANA				0x0400 /* _ANSC10 ANSELCbits.ANSC10 */
#define ENABLE_AN12_ANA				0x0800 /* _ANSC11 ANSELCbits.ANSC11 */
#define ENABLE_AN14_ANA				0x1000 /* _ANSC12 ANSELCbits.ANSC12 */

/*defines for ANSELD register To Be used With configport_d in OpenADC.c */
#define ENABLE_AN16_ANA				0x0004 /* _ANSD2 ANSELDbits.ANSD2 */
#define ENABLE_AN15_ANA				0x0080 /* _ANSD7 ANSELDbits.ANSD7 */
#define ENABLE_AN13_ANA				0x2000 /* _ANSD13 ANSELDbits.ANSD13 */

/* Setting the priority of adc interrupt */
#define ADC_INT_PRI_0                   0xFFF8
#define ADC_INT_PRI_1                   0xFFF9
#define ADC_INT_PRI_2                   0xFFFA
#define ADC_INT_PRI_3                   0xFFFB
#define ADC_INT_PRI_4                   0xFFFC
#define ADC_INT_PRI_5                   0xFFFD
#define ADC_INT_PRI_6                   0xFFFE
#define ADC_INT_PRI_7                   0xFFFF

/* enable / disable interrupts */
#define ADC_INT_ENABLE                  0xFFFF
#define ADC_INT_DISABLE                 0xFFF7

/* Macros to  Enable/Disable interrupts and set Interrupt priority */

#define EnableIntADC()                  (_ADCIE = 1)
#define DisableIntADC()                 (_ADCIE = 0)
#define SetPriorityIntADC(priority)     (_ADCIP = priority)

#endif

