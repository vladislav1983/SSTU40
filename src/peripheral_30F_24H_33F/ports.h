/*********************************************************************/
/*              Header for IO ports module library functions         */
/*********************************************************************/

#if defined(__dsPIC30F__)
#include <p30Fxxxx.h>
#elif defined(__dsPIC33F__)
#include <p33Fxxxx.h>
#elif defined(__PIC24H__)
#include <p24Hxxxx.h>
#elif defined(__dsPIC33E__)
#include <p33Exxxx.h>
#elif defined(__PIC24E__)
#include <p24Exxxx.h>
#else
#error "Does not build on this target"
#endif

#ifndef __PORTS_H
#define __PORTS_H

/* List of SFRs for IO ports */
/* This list contains the SFRs with default (POR) values to be used for configuring IOports */
/* The user can modify this based on the requirement */

#if defined(__dsPIC30F__) || defined(__dsPIC33F__) ||  defined(__PIC24H__)

#define CNEN1_VALUE             0x0000
#define CNPU1_VALUE             0x0000

#define CNEN2_VALUE             0x0000
#define CNPU2_VALUE             0x0000

#endif

#if defined(__dsPIC33E__) || defined(__dsPIC24E)

#define CNENA_VALUE             0x0000
#define CNPUA_VALUE             0x0000
#define CNPDA_VALUE             0x0000
 
#define CNENB_VALUE             0x0000
#define CNPUB_VALUE             0x0000
#define CNPDB_VALUE             0x0000

#define CNENC_VALUE             0x0000
#define CNPUC_VALUE             0x0000
#define CNPDC_VALUE             0x0000

#define CNEND_VALUE             0x0000
#define CNPUD_VALUE             0x0000
#define CNPDD_VALUE             0x0000

#define CNENE_VALUE             0x0000
#define CNPUE_VALUE             0x0000
#define CNPDE_VALUE             0x0000

#define CNENF_VALUE             0x0000
#define CNPUF_VALUE             0x0000
#define CNPDF_VALUE             0x0000

#define CNENG_VALUE             0x0000
#define CNPUG_VALUE             0x0000
#define CNPDG_VALUE             0x0000

#define CNENH_VALUE             0x0000
#define CNPUH_VALUE             0x0000
#define CNPDH_VALUE             0x0000

#define CNENJ_VALUE             0x0000
#define CNPUJ_VALUE             0x0000
#define CNPDJ_VALUE             0x0000

#define CNENK_VALUE             0x0000
#define CNPUK_VALUE             0x0000
#define CNPDK_VALUE             0x0000

#endif

#define IEC0_VALUE              0x0000
#define IEC1_VALUE              0x0000
#define IEC2_VALUE              0x0000


#define IFS0_VALUE              0x0000
#define IFS1_VALUE              0x0000
#define IFS2_VALUE              0x0000

#define IPC0_VALUE              0x4444
#define IPC1_VALUE              0x4444
#define IPC2_VALUE              0x4444
#define IPC3_VALUE              0x4444
#define IPC4_VALUE              0x4444
#define IPC5_VALUE              0x4444
#define IPC6_VALUE              0x4444
#define IPC7_VALUE              0x4444
#define IPC8_VALUE              0x4444
#define IPC9_VALUE              0x4444
#define IPC10_VALUE             0x4444
#define IPC11_VALUE             0x4444

#if defined(__dsPIC33F__) || defined(__PIC24H__)

#define IEC3_VALUE              0x0000
#define IEC4_VALUE              0x0000

#define IFS3_VALUE              0x0000
#define IFS4_VALUE              0x0000

#define IPC12_VALUE             0x4444
#define IPC13_VALUE             0x4444
#define IPC14_VALUE             0x4444
#define IPC15_VALUE             0x4444
#define IPC16_VALUE             0x4444
#define IPC17_VALUE             0x4444

#endif

#if defined(__dsPIC33E__) || defined(__dsPIC24E)

#define IEC3_VALUE              0x0000
#define IEC4_VALUE              0x0000
#define IEC5_VALUE              0x0000
#define IEC6_VALUE              0x0000
#define IEC7_VALUE              0x0000
#define IEC8_VALUE              0x0000
#define IEC10_VALUE             0x0000
#define IEC11_VALUE             0x0000

#define IFS3_VALUE              0x0000
#define IFS4_VALUE              0x0000
#define IFS5_VALUE              0x0000
#define IFS6_VALUE              0x0000
#define IFS7_VALUE              0x0000
#define IFS8_VALUE              0x0000
#define IFS10_VALUE             0x0000
#define IFS11_VALUE             0x0000

#define IPC12_VALUE             0x4444
#define IPC13_VALUE             0x4444
#define IPC14_VALUE             0x4444
#define IPC15_VALUE             0x0444
#define IPC16_VALUE             0x4440
#define IPC17_VALUE             0x4444
#define IPC18_VALUE             0x4040
#define IPC20_VALUE             0x4440
#define IPC21_VALUE             0x4400
#define IPC22_VALUE             0x4444
#define IPC23_VALUE             0x4444
#define IPC24_VALUE             0x4444
#define IPC25_VALUE             0x0004
#define IPC29_VALUE             0x4400
#define IPC30_VALUE             0x4444
#define IPC31_VALUE             0x4444
#define IPC32_VALUE             0x4444
#define IPC33_VALUE             0x4404
#define IPC34_VALUE             0x4444
#define IPC35_VALUE             0x0444
#define IPC43_VALUE             0x0049
#define IPC45_VALUE             0x4400
#define IPC46_VALUE             0x0444

/* Config Bit Defines to be used for CN interrupt configuration */
#define CHANGE_INT_ON           0xFFFFFFFF    /* interrupts on  */
#define CHANGE_INT_OFF          0xFFF7FFFF    /* interrupts off */

/* Setting the priority of CN interrupt */
#define CHANGE_INT_PRI_0        0xFFF8FFFF
#define CHANGE_INT_PRI_1        0xFFF9FFFF
#define CHANGE_INT_PRI_2        0xFFFAFFFF
#define CHANGE_INT_PRI_3        0xFFFBFFFF
#define CHANGE_INT_PRI_4        0xFFFCFFFF
#define CHANGE_INT_PRI_5        0xFFFDFFFF
#define CHANGE_INT_PRI_6        0xFFFEFFFF
#define CHANGE_INT_PRI_7        0xFFFFFFFF

#endif

#if defined(__dsPIC30F__) || defined(__dsPIC33F__) ||  defined(__PIC24H__)

/* Config Bit Defines to be used for CN interrupt configuration */
#define CHANGE_INT_ON           0xFFFFFFFF    /* interrupts on  */
#define CHANGE_INT_OFF          0xF7FFFFFF    /* interrupts off */

/* Setting the priority of CN interrupt */
#define CHANGE_INT_PRI_0        0xF8FFFFFF
#define CHANGE_INT_PRI_1        0xF9FFFFFF
#define CHANGE_INT_PRI_2        0xFAFFFFFF
#define CHANGE_INT_PRI_3        0xFBFFFFFF
#define CHANGE_INT_PRI_4        0xFCFFFFFF
#define CHANGE_INT_PRI_5        0xFDFFFFFF
#define CHANGE_INT_PRI_6        0xFEFFFFFF
#define CHANGE_INT_PRI_7        0xFFFFFFFF

#endif

/* Setting the priority of External interrupt */
#define EXT_INT_PRI_0           0xFFF8
#define EXT_INT_PRI_1           0xFFF9
#define EXT_INT_PRI_2           0xFFFA
#define EXT_INT_PRI_3           0xFFFB
#define EXT_INT_PRI_4           0xFFFC
#define EXT_INT_PRI_5           0xFFFD
#define EXT_INT_PRI_6           0xFFFE
#define EXT_INT_PRI_7           0xFFFF

/* enable / disable External interrupt */
#define EXT_INT_ENABLE          0xFFFF
#define EXT_INT_DISABLE         0xFFF7

/* External interrupts edge selection defines */
#define RISING_EDGE_INT         0xFFEF    /*Interrupt is set by a rising edge  */
#define FALLING_EDGE_INT        0xFFFF    /*Interrupt is set by a falling edge */

#define GLOBAL_INT_ENABLE       0xFFFF
#define GLOBAL_INT_DISABLE      0xFFDF


#if defined(__dsPIC30F__) || defined(__dsPIC33F__) ||  defined(__PIC24H__)

/* Macros to Enable CN interrupts */

#define EnableCN0               CNEN1bits.CN0IE = 1
#define EnableCN1               CNEN1bits.CN1IE = 1
#define EnableCN2               CNEN1bits.CN2IE = 1
#define EnableCN3               CNEN1bits.CN3IE = 1
#define EnableCN4               CNEN1bits.CN4IE = 1
#define EnableCN5               CNEN1bits.CN5IE = 1
#define EnableCN6               CNEN1bits.CN6IE = 1
#define EnableCN7               CNEN1bits.CN7IE = 1

#ifdef _CN8IE

#define EnableCN8               CNEN1bits.CN8IE = 1
#define EnableCN9               CNEN1bits.CN9IE = 1
#define EnableCN10              CNEN1bits.CN10IE = 1
#define EnableCN11              CNEN1bits.CN11IE = 1
#define EnableCN12              CNEN1bits.CN12IE = 1
#define EnableCN13              CNEN1bits.CN13IE = 1
#define EnableCN14              CNEN1bits.CN14IE = 1
#define EnableCN15              CNEN1bits.CN15IE = 1
#define EnableCN16              CNEN2bits.CN16IE = 1
#define EnableCN17              CNEN2bits.CN17IE = 1
#define EnableCN18              CNEN2bits.CN18IE = 1

#endif

#ifdef _CN19IE

#define EnableCN19              CNEN2bits.CN19IE = 1
#define EnableCN20              CNEN2bits.CN20IE = 1
#define EnableCN21              CNEN2bits.CN21IE = 1

#endif

#ifdef _CN22IE

#define EnableCN22              CNEN2bits.CN22IE = 1
#define EnableCN23              CNEN2bits.CN23IE = 1

#endif

/* Macros to Disable CN interrupts */

#define DisableCN0              CNEN1bits.CN0IE = 0
#define DisableCN1              CNEN1bits.CN1IE = 0
#define DisableCN2              CNEN1bits.CN2IE = 0
#define DisableCN3              CNEN1bits.CN3IE = 0
#define DisableCN4              CNEN1bits.CN4IE = 0
#define DisableCN5              CNEN1bits.CN5IE = 0
#define DisableCN6              CNEN1bits.CN6IE = 0
#define DisableCN7              CNEN1bits.CN7IE = 0

#ifdef _CN8IE

#define DisableCN8              CNEN1bits.CN8IE = 0
#define DisableCN9              CNEN1bits.CN9IE = 0
#define DisableCN10             CNEN1bits.CN10IE = 0
#define DisableCN11             CNEN1bits.CN11IE = 0
#define DisableCN12             CNEN1bits.CN12IE = 0
#define DisableCN13             CNEN1bits.CN13IE = 0
#define DisableCN14             CNEN1bits.CN14IE = 0
#define DisableCN15             CNEN1bits.CN15IE = 0
#define DisableCN16             CNEN2bits.CN16IE = 0
#define DisableCN17             CNEN2bits.CN17IE = 0
#define DisableCN18             CNEN2bits.CN18IE = 0

#endif

#ifdef _CN19IE

#define DisableCN19             CNEN2bits.CN19IE = 0
#define DisableCN20             CNEN2bits.CN20IE = 0
#define DisableCN21             CNEN2bits.CN21IE = 0

#endif

#ifdef _CN22IE

#define DisableCN22             CNEN2bits.CN22IE = 0
#define DisableCN23             CNEN2bits.CN23IE = 0

#endif

#endif


#if defined(__dsPIC33E__) || defined(__dsPIC24E)		

	/* Macros to Enable/Disable CN interrupts on PORTA*/
    #ifdef _CNIEA0
 	#define EnableCNA0               CNENAbits.CNIEA0= 1
	#endif
	
	#ifdef _CNIEA1
	#define EnableCNA1               CNENAbits.CNIEA1= 1
	#endif
	
	#ifdef _CNIEA2
	#define EnableCNA2               CNENAbits.CNIEA2= 1
	#endif
	
	#ifdef _CNIEA3
	#define EnableCNA3               CNENAbits.CNIEA3= 1
	#endif
	
	#ifdef _CNIEA4
	#define EnableCNA4               CNENAbits.CNIEA4= 1
	#endif
	
	#ifdef _CNIEA5
	#define EnableCNA5               CNENAbits.CNIEA5= 1
	#endif
	
	#ifdef _CNIEA6
	#define EnableCNA6               CNENAbits.CNIEA6= 1
	#endif
	
	#ifdef _CNIEA7
	#define EnableCNA7               CNENAbits.CNIEA7= 1
	#endif
	
	#ifdef _CNIEA8
	#define EnableCNA8               CNENAbits.CNIEA8= 1
	#endif
	
	#ifdef _CNIEA9
    #define EnableCNA9               CNENAbits.CNIEA9= 1
	#endif
	
	#ifdef _CNIEA10
    #define EnableCNA10              CNENAbits.CNIEA10= 1
	#endif
	
	#ifdef _CNIEA11
    #define EnableCNA11              CNENAbits.CNIEA11= 1
	#endif
	
	#ifdef _CNIEA12
    #define EnableCNA12              CNENAbits.CNIEA12= 1
	#endif
	
	#ifdef _CNIEA13
    #define EnableCNA13              CNENAbits.CNIEA13= 1
	#endif
	
	#ifdef _CNIEA14
    #define EnableCNA14              CNENAbits.CNIEA14= 1
	#endif
	
	#ifdef _CNIEA15
    #define EnableCNA15              CNENAbits.CNIEA15= 1
	#endif
	
    #ifdef _CNIEA0
 	#define DisableCNA0               CNENAbits.CNIEA0= 0
	#endif
	
	#ifdef _CNIEA1
	#define DisableCNA1               CNENAbits.CNIEA1= 0
	#endif
	
	#ifdef _CNIEA2
	#define DisableCNA2               CNENAbits.CNIEA2= 0
	#endif
	
	#ifdef _CNIEA3
	#define DisableCNA3               CNENAbits.CNIEA3= 0
	#endif
	
	#ifdef _CNIEA4
	#define DisableCNA4               CNENAbits.CNIEA4= 0
	#endif
	
	#ifdef _CNIEA5
	#define DisableCNA5               CNENAbits.CNIEA5= 0
	#endif
	
	#ifdef _CNIEA6
	#define DisableCNA6               CNENAbits.CNIEA6= 0
	#endif
	
	#ifdef _CNIEA7
	#define DisableCNA7               CNENAbits.CNIEA7= 0
	#endif
	
	#ifdef _CNIEA8
	#define DisableCNA8               CNENAbits.CNIEA8= 0
	#endif
	
	#ifdef _CNIEA9
    #define DisableCNA9               CNENAbits.CNIEA9= 0
	#endif
	
	#ifdef _CNIEA10
    #define DisableCNA10              CNENAbits.CNIEA10= 0
	#endif
	
	#ifdef _CNIEA11
    #define DisableCNA11              CNENAbits.CNIEA11= 0
	#endif
	
	#ifdef _CNIEA12
    #define DisableCNA12              CNENAbits.CNIEA12= 0
	#endif
	
	#ifdef _CNIEA13
    #define DisableCNA13              CNENAbits.CNIEA13= 0
	#endif
	
	#ifdef _CNIEA14
    #define DisableCNA14              CNENAbits.CNIEA14= 0
	#endif
	
	#ifdef _CNIEA15
    #define DisableCNA15              CNENAbits.CNIEA15= 0
	#endif
	

	/* Macros to Enable/Disable CN interrupts on PORTB*/
    #ifdef _CNIEB0
 	#define EnableCNB0               CNENBbits.CNIEB0= 1
	#endif
	
	#ifdef _CNIEB1
	#define EnableCNB1               CNENBbits.CNIEB1= 1
	#endif
	
	#ifdef _CNIEB2
	#define EnableCNB2               CNENBbits.CNIEB2= 1
	#endif
	
	#ifdef _CNIEB3
	#define EnableCNB3               CNENBbits.CNIEB3= 1
	#endif
	
	#ifdef _CNIEB4
	#define EnableCNB4               CNENBbits.CNIEB4= 1
	#endif
	
	#ifdef _CNIEB5
	#define EnableCNB5               CNENBbits.CNIEB5= 1
	#endif
	
	#ifdef _CNIEB6
	#define EnableCNB6               CNENBbits.CNIEB6= 1
	#endif
	
	#ifdef _CNIEB7
	#define EnableCNB7               CNENBbits.CNIEB7= 1
	#endif
	
	#ifdef _CNIEB8
	#define EnableCNB8               CNENBbits.CNIEB8= 1
	#endif
	
	#ifdef _CNIEB9
    #define EnableCNB9               CNENBbits.CNIEB9= 1
	#endif
	
	#ifdef _CNIEB10
    #define EnableCNB10              CNENBbits.CNIEB10= 1
	#endif
	
	#ifdef _CNIEB11
    #define EnableCNB11              CNENBbits.CNIEB11= 1
	#endif
	
	#ifdef _CNIEB12
    #define EnableCNB12              CNENBbits.CNIEB12= 1
	#endif
	
	#ifdef _CNIEB13
    #define EnableCNB13              CNENBbits.CNIEB13= 1
	#endif
	
	#ifdef _CNIEB14
    #define EnableCNB14              CNENBbits.CNIEB14= 1
	#endif
	
	#ifdef _CNIEB15
    #define EnableCNB15              CNENBbits.CNIEB15= 1
	#endif
	
    #ifdef _CNIEB0
 	#define DisableCNB0               CNENBbits.CNIEB0= 0
	#endif
	
	#ifdef _CNIEB1
	#define DisableCNB1               CNENBbits.CNIEB1= 0
	#endif
	
	#ifdef _CNIEB2
	#define DisableCNB2               CNENBbits.CNIEB2= 0
	#endif
	
	#ifdef _CNIEB3
	#define DisableCNB3               CNENBbits.CNIEB3= 0
	#endif
	
	#ifdef _CNIEB4
	#define DisableCNB4               CNENBbits.CNIEB4= 0
	#endif
	
	#ifdef _CNIEB5
	#define DisableCNB5               CNENBbits.CNIEB5= 0
	#endif
	
	#ifdef _CNIEB6
	#define DisableCNB6               CNENBbits.CNIEB6= 0
	#endif
	
	#ifdef _CNIEB7
	#define DisableCNB7               CNENBbits.CNIEB7= 0
	#endif
	
	#ifdef _CNIEB8
	#define DisableCNB8               CNENBbits.CNIEB8= 0
	#endif
	
	#ifdef _CNIEB9
    #define DisableCNB9               CNENBbits.CNIEB9= 0
	#endif
	
	#ifdef _CNIEB10
    #define DisableCNB10              CNENBbits.CNIEB10= 0
	#endif
	
	#ifdef _CNIEB11
    #define DisableCNB11              CNENBbits.CNIEB11= 0
	#endif
	
	#ifdef _CNIEB12
    #define DisableCNB12              CNENBbits.CNIEB12= 0
	#endif
	
	#ifdef _CNIEB13
    #define DisableCNB13              CNENBbits.CNIEB13= 0
	#endif
	
	#ifdef _CNIEB14
    #define DisableCNB14              CNENBbits.CNIEB14= 0
	#endif
	
	#ifdef _CNIEB15
    #define DisableCNB15              CNENBbits.CNIEB15= 0
	#endif

	/* Macros to Enable/Disable CN interrupts on PORTC*/
    #ifdef _CNIEC0
 	#define EnableCNC0               CNENCbits.CNIEC0= 1
	#endif
	
	#ifdef _CNIEC1
	#define EnableCNC1               CNENCbits.CNIEC1= 1
	#endif
	
	#ifdef _CNIEC2
	#define EnableCNC2               CNENCbits.CNIEC2= 1
	#endif
	
	#ifdef _CNIEC3
	#define EnableCNC3               CNENCbits.CNIEC3= 1
	#endif
	
	#ifdef _CNIEC4
	#define EnableCNC4               CNENCbits.CNIEC4= 1
	#endif
	
	#ifdef _CNIEC5
	#define EnableCNC5               CNENCbits.CNIEC5= 1
	#endif
	
	#ifdef _CNIEC6
	#define EnableCNC6               CNENCbits.CNIEC6= 1
	#endif
	
	#ifdef _CNIEC7
	#define EnableCNC7               CNENCbits.CNIEC7= 1
	#endif
	
	#ifdef _CNIEC8
	#define EnableCNC8               CNENCbits.CNIEC8= 1
	#endif
	
	#ifdef _CNIEC9
    #define EnableCNC9               CNENCbits.CNIEC9= 1
	#endif
	
	#ifdef _CNIEC10
    #define EnableCNC10              CNENCbits.CNIEC10= 1
	#endif
	
	#ifdef _CNIEC11
    #define EnableCNC11              CNENCbits.CNIEC11= 1
	#endif
	
	#ifdef _CNIEC12
    #define EnableCNC12              CNENCbits.CNIEC12= 1
	#endif
	
	#ifdef _CNIEC13
    #define EnableCNC13              CNENCbits.CNIEC13= 1
	#endif
	
	#ifdef _CNIEC14
    #define EnableCNC14              CNENCbits.CNIEC14= 1
	#endif
	
	#ifdef _CNIEC15
    #define EnableCNC15              CNENCbits.CNIEC15= 1
	#endif
	
    #ifdef _CNIEC0
 	#define DisableCNC0               CNENCbits.CNIEC0= 0
	#endif
	
	#ifdef _CNIEC1
	#define DisableCNC1               CNENCbits.CNIEC1= 0
	#endif
	
	#ifdef _CNIEC2
	#define DisableCNC2               CNENCbits.CNIEC2= 0
	#endif
	
	#ifdef _CNIEC3
	#define DisableCNC3               CNENCbits.CNIEC3= 0
	#endif
	
	#ifdef _CNIEC4
	#define DisableCNC4               CNENCbits.CNIEC4= 0
	#endif
	
	#ifdef _CNIEC5
	#define DisableCNC5               CNENCbits.CNIEC5= 0
	#endif
	
	#ifdef _CNIEC6
	#define DisableCNC6               CNENCbits.CNIEC6= 0
	#endif
	
	#ifdef _CNIEC7
	#define DisableCNC7               CNENCbits.CNIEC7= 0
	#endif
	
	#ifdef _CNIEC8
	#define DisableCNC8               CNENCbits.CNIEC8= 0
	#endif
	
	#ifdef _CNIEC9
    #define DisableCNC9               CNENCbits.CNIEC9= 0
	#endif
	
	#ifdef _CNIEC10
    #define DisableCNC10              CNENCbits.CNIEC10= 0
	#endif
	
	#ifdef _CNIEC11
    #define DisableCNC11              CNENCbits.CNIEC11= 0
	#endif
	
	#ifdef _CNIEC12
    #define DisableCNC12              CNENCbits.CNIEC12= 0
	#endif
	
	#ifdef _CNIEC13
    #define DisableCNC13              CNENCbits.CNIEC13= 0
	#endif
	
	#ifdef _CNIEC14
    #define DisableCNC14              CNENCbits.CNIEC14= 0
	#endif
	
	#ifdef _CNIEC15
    #define DisableCNC15              CNENCbits.CNIEC15= 0
	#endif

	/* Macros to Enable/Disable CN interrupts on PORTD*/

    #ifdef _CNIED0
 	#define EnableCND0               CNENDbits.CNIED0= 1
	#endif
	
	#ifdef _CNIED1
	#define EnableCND1               CNENDbits.CNIED1= 1
	#endif
	
	#ifdef _CNIED2
	#define EnableCND2               CNENDbits.CNIED2= 1
	#endif
	
	#ifdef _CNIED3
	#define EnableCND3               CNENDbits.CNIED3= 1
	#endif
	
	#ifdef _CNIED4
	#define EnableCND4               CNENDbits.CNIED4= 1
	#endif
	
	#ifdef _CNIED5
	#define EnableCND5               CNENDbits.CNIED5= 1
	#endif
	
	#ifdef _CNIED6
	#define EnableCND6               CNENDbits.CNIED6= 1
	#endif
	
	#ifdef _CNIED7
	#define EnableCND7               CNENDbits.CNIED7= 1
	#endif
	
	#ifdef _CNIED8
	#define EnableCND8               CNENDbits.CNIED8= 1
	#endif
	
	#ifdef _CNIED9
    #define EnableCND9               CNENDbits.CNIED9= 1
	#endif
	
	#ifdef _CNIED10
    #define EnableCND10              CNENDbits.CNIED10= 1
	#endif
	
	#ifdef _CNIED11
    #define EnableCND11              CNENDbits.CNIED11= 1
	#endif
	
	#ifdef _CNIED12
    #define EnableCND12              CNENDbits.CNIED12= 1
	#endif
	
	#ifdef _CNIED13
    #define EnableCND13              CNENDbits.CNIED13= 1
	#endif
	
	#ifdef _CNIED14
    #define EnableCND14              CNENDbits.CNIED14= 1
	#endif
	
	#ifdef _CNIED15
    #define EnableCND15              CNENDbits.CNIED15= 1
	#endif
	
    #ifdef _CNIED0
 	#define DisableCND0               CNENDbits.CNIED0= 0
	#endif
	
	#ifdef _CNIED1
	#define DisableCND1               CNENDbits.CNIED1= 0
	#endif
	
	#ifdef _CNIED2
	#define DisableCND2               CNENDbits.CNIED2= 0
	#endif
	
	#ifdef _CNIED3
	#define DisableCND3               CNENDbits.CNIED3= 0
	#endif
	
	#ifdef _CNIED4
	#define DisableCND4               CNENDbits.CNIED4= 0
	#endif
	
	#ifdef _CNIED5
	#define DisableCND5               CNENDbits.CNIED5= 0
	#endif
	
	#ifdef _CNIED6
	#define DisableCND6               CNENDbits.CNIED6= 0
	#endif
	
	#ifdef _CNIED7
	#define DisableCND7               CNENDbits.CNIED7= 0
	#endif
	
	#ifdef _CNIED8
	#define DisableCND8               CNENDbits.CNIED8= 0
	#endif
	
	#ifdef _CNIED9
    #define DisableCND9               CNENDbits.CNIED9= 0
	#endif
	
	#ifdef _CNIED10
    #define DisableCND10              CNENDbits.CNIED10= 0
	#endif
	
	#ifdef _CNIED11
    #define DisableCND11              CNENDbits.CNIED11= 0
	#endif
	
	#ifdef _CNIED12
    #define DisableCND12              CNENDbits.CNIED12= 0
	#endif
	
	#ifdef _CNIED13
    #define DisableCND13              CNENCbits.CNIED13= 0
	#endif
	
	#ifdef _CNIED14
    #define DisableCND14              CNENDbits.CNIED14= 0
	#endif
	
	#ifdef _CNIED15
    #define DisableCND15              CNENDbits.CNIED15= 0
	#endif

	/* Macros to Enable/Disable CN interrupts on PORTE*/

    #ifdef _CNIEE0
 	#define EnableCNE0               CNENEbits.CNIEE0= 1
	#endif
	
	#ifdef _CNIEE1
	#define EnableCNE1               CNENEbits.CNIEE1= 1
	#endif
	
	#ifdef _CNIEE2
	#define EnableCNE2               CNENEbits.CNIEE2= 1
	#endif
	
	#ifdef _CNIEE3
	#define EnableCNE3               CNENEbits.CNIEE3= 1
	#endif
	
	#ifdef _CNIEE4
	#define EnableCNE4               CNENEbits.CNIEE4= 1
	#endif
	
	#ifdef _CNIEE5
	#define EnableCNE5               CNENEbits.CNIEE5= 1
	#endif
	
	#ifdef _CNIEE6
	#define EnableCNE6               CNENEbits.CNIEE6= 1
	#endif
	
	#ifdef _CNIEE7
	#define EnableCNE7               CNENEbits.CNIEE7= 1
	#endif
	
	#ifdef _CNIEE8
	#define EnableCNE8               CNENEbits.CNIEE8= 1
	#endif
	
	#ifdef _CNIEE9
    #define EnableCNE9               CNENEbits.CNIEE9= 1
	#endif
	
	#ifdef _CNIEE10
    #define EnableCNE10              CNENEbits.CNIEE10= 1
	#endif
	
	#ifdef _CNIEE11
    #define EnableCNE11              CNENEbits.CNIEE11= 1
	#endif
	
	#ifdef _CNIEE12
    #define EnableCNE12              CNENEbits.CNIEE12= 1
	#endif
	
	#ifdef _CNIEE13
    #define EnableCNE13              CNENEbits.CNIEE13= 1
	#endif
	
	#ifdef _CNIEE14
    #define EnableCNE14              CNENEbits.CNIEE14= 1
	#endif
	
	#ifdef _CNIEE15
    #define EnableCNE15              CNENEbits.CNIEE15= 1
	#endif
	
    #ifdef _CNIEE0
 	#define DisableCNE0               CNENEbits.CNIEE0= 0
	#endif
	
	#ifdef _CNIEE1
	#define DisableCNE1               CNENEbits.CNIEE1= 0
	#endif
	
	#ifdef _CNIEE2
	#define DisableCNE2               CNENEbits.CNIEE2= 0
	#endif
	
	#ifdef _CNIEE3
	#define DisableCNE3               CNENEbits.CNIEE3= 0
	#endif
	
	#ifdef _CNIEE4
	#define DisableCNE4               CNENEbits.CNIEE4= 0
	#endif
	
	#ifdef _CNIEE5
	#define DisableCNE5               CNENEbits.CNIEE5= 0
	#endif
	
	#ifdef _CNIEE6
	#define DisableCNE6               CNENEbits.CNIEE6= 0
	#endif
	
	#ifdef _CNIEE7
	#define DisableCNE7               CNENEbits.CNIEE7= 0
	#endif
	
	#ifdef _CNIEE8
	#define DisableCNE8               CNENEbits.CNIEE8= 0
	#endif
	
	#ifdef _CNIEE9
    #define DisableCNE9               CNENEbits.CNIEE9= 0
	#endif
	
	#ifdef _CNIEE10
    #define DisableCNE10              CNENEbits.CNIEE10= 0
	#endif
	
	#ifdef _CNIEE11
    #define DisableCNE11              CNENEbits.CNIEE11= 0
	#endif
	
	#ifdef _CNIEE12
    #define DisableCNE12              CNENEbits.CNIEE12= 0
	#endif
	
	#ifdef _CNIEE13
    #define DisableCNE13              CNENEbits.CNIEE13= 0
	#endif
	
	#ifdef _CNIEE14
    #define DisableCNE14              CNENDbits.CNIEE14= 0
	#endif
	
	#ifdef _CNIEE15
    #define DisableCNE15              CNENEbits.CNIEE15= 0
	#endif

   /* Macros to Enable/Disable CN interrupts on PORTF*/

  
    #ifdef _CNIEF0
 	#define EnableCNF0               CNENFbits.CNIEF0= 1
	#endif
	
	#ifdef _CNIEF1
	#define EnableCNF1               CNENFbits.CNIEF1= 1
	#endif
	
	#ifdef _CNIEF2
	#define EnableCNF2               CNENFbits.CNIEF2= 1
	#endif
	
	#ifdef _CNIEF3
	#define EnableCNF3               CNENFbits.CNIEF3= 1
	#endif
	
	#ifdef _CNIEF4
	#define EnableCNF4               CNENFbits.CNIEF4= 1
	#endif
	
	#ifdef _CNIEF5
	#define EnableCNF5               CNENFbits.CNIEF5= 1
	#endif
	
	#ifdef _CNIEF6
	#define EnableCNF6               CNENFbits.CNIEF6= 1
	#endif
	
	#ifdef _CNIEF7
	#define EnableCNF7               CNENFbits.CNIEF7= 1
	#endif
	
	#ifdef _CNIEF8
	#define EnableCNF8               CNENFbits.CNIEF8= 1
	#endif
	
	#ifdef _CNIEF9
    #define EnableCNF9               CNENFbits.CNIEF9= 1
	#endif
	
	#ifdef _CNIEF10
    #define EnableCNF10              CNENFbits.CNIEF10= 1
	#endif
	
	#ifdef _CNIEF11
    #define EnableCNF11              CNENDbits.CNIEF11= 1
	#endif
	
	#ifdef _CNIEF12
    #define EnableCNF12              CNENFbits.CNIEF12= 1
	#endif
	
	#ifdef _CNIEF13
    #define EnableCNF13              CNENFbits.CNIEF13= 1
	#endif
	
	#ifdef _CNIEF14
    #define EnableCNF14              CNENFbits.CNIEF14= 1
	#endif
	
	#ifdef _CNIEF15
    #define EnableCNF15              CNENDbits.CNIEF15= 1
	#endif
	
    #ifdef _CNIEF0
 	#define DisableCNF0               CNENFbits.CNIEF0= 0
	#endif
	
	#ifdef _CNIEF1
	#define DisableCNF1               CNENFbits.CNIEF1= 0
	#endif
	
	#ifdef _CNIEF2
	#define DisableCNF2               CNENFbits.CNIEF2= 0
	#endif
	
	#ifdef _CNIEF3
	#define DisableCNF3               CNENFbits.CNIEF3= 0
	#endif
	
	#ifdef _CNIEF4
	#define DisableCNF4               CNENFbits.CNIEF4= 0
	#endif
	
	#ifdef _CNIEF5
	#define DisableCNF5               CNENFbits.CNIEF5= 0
	#endif
	
	#ifdef _CNIEF6
	#define DisableCNF6               CNENFbits.CNIEF6= 0
	#endif
	
	#ifdef _CNIEF7
	#define DisableCNF7               CNENFbits.CNIEF7= 0
	#endif
	
	#ifdef _CNIEF8
	#define DisableCNF8               CNENFbits.CNIEF8= 0
	#endif
	
	#ifdef _CNIEF9
    #define DisableCNF9               CNENFbits.CNIEF9= 0
	#endif
	
	#ifdef _CNIEF10
    #define DisableCNF10              CNENFbits.CNIEF10= 0
	#endif
	
	#ifdef _CNIEF11
    #define DisableCNF11              CNENFbits.CNIEF11= 0
	#endif
	
	#ifdef _CNIEF12
    #define DisableCNF12              CNENFbits.CNIEF12= 0
	#endif
	
	#ifdef _CNIEF13
    #define DisableCNF13              CNENFbits.CNIEF13= 0
	#endif
	
	#ifdef _CNIEF14
    #define DisableCNF14              CNENFbits.CNIEF14= 0
	#endif
	
	#ifdef _CNIEF15
    #define DisableCNF15              CNENFbits.CNIEF15= 0
	#endif

    /* Macros to Enable/Disable CN interrupts on PORTG*/

    #ifdef _CNIEG0
 	#define EnableCNG0               CNENGbits.CNIEG0= 1
	#endif
	
	#ifdef _CNIEG1
	#define EnableCNG1               CNENGbits.CNIEG1= 1
	#endif
	
	#ifdef _CNIEG2
	#define EnableCNG2               CNENGbits.CNIEG2= 1
	#endif
	
	#ifdef _CNIEG3
	#define EnableCNG3               CNENGbits.CNIEG3= 1
	#endif
	
	#ifdef _CNIEG4
	#define EnableCNG4               CNENGbits.CNIEG4= 1
	#endif
	
	#ifdef _CNIEG5
	#define EnableCNG5               CNENGbits.CNIEG5= 1
	#endif
	
	#ifdef _CNIEG6
	#define EnableCNG6               CNENGbits.CNIEG6= 1
	#endif
	
	#ifdef _CNIEG7
	#define EnableCNG7               CNENGbits.CNIEG7= 1
	#endif
	
	#ifdef _CNIEG8
	#define EnableCNG8               CNENGbits.CNIEG8= 1
	#endif
	
	#ifdef _CNIEG9
    #define EnableCNG9               CNENGbits.CNIEG9= 1
	#endif
	
	#ifdef _CNIEG10
    #define EnableCNG10              CNENGbits.CNIEG10= 1
	#endif
	
	#ifdef _CNIEG11
    #define EnableCNG11              CNENGbits.CNIEG11= 1
	#endif
	
	#ifdef _CNIEG12
    #define EnableCNG12              CNENGbits.CNIEG12= 1
	#endif
	
	#ifdef _CNIEG13
    #define EnableCNG13              CNENGbits.CNIEG13= 1
	#endif
	
	#ifdef _CNIEG14
    #define EnableCNG14              CNENGbits.CNIEG14= 1
	#endif
	
	#ifdef _CNIEG15
    #define EnableCNG15              CNENGbits.CNIEG15= 1
	#endif
	
    #ifdef _CNIEG0
 	#define DisableCNG0               CNENGbits.CNIEG0= 0
	#endif
	
	#ifdef _CNIEG1
	#define DisableCNG1               CNENGbits.CNIEG1= 0
	#endif
	
	#ifdef _CNIEG2
	#define DisableCNG2               CNENGbits.CNIEG2= 0
	#endif
	
	#ifdef _CNIEG3
	#define DisableCNG3               CNENGbits.CNIEG3= 0
	#endif
	
	#ifdef _CNIEG4
	#define DisableCNG4               CNENGbits.CNIEG4= 0
	#endif
	
	#ifdef _CNIEG5
	#define DisableCNG5               CNENGbits.CNIEG5= 0
	#endif
	
	#ifdef _CNIEG6
	#define DisableCNG6               CNENGbits.CNIEG6= 0
	#endif
	
	#ifdef _CNIEG7
	#define DisableCNG7               CNENGbits.CNIEG7= 0
	#endif
	
	#ifdef _CNIEG8
	#define DisableCNG8               CNENGbits.CNIEG8= 0
	#endif
	
	#ifdef _CNIEG9
    #define DisableCNG9               CNENGbits.CNIEG9= 0
	#endif
	
	#ifdef _CNIEG10
    #define DisableCNG10              CNENGbits.CNIEG10= 0
	#endif
	
	#ifdef _CNIEG11
    #define DisableCNG11              CNENGbits.CNIEG11= 0
	#endif
	
	#ifdef _CNIEG12
    #define DisableCNG12              CNENGbits.CNIEG12= 0
	#endif
	
	#ifdef _CNIEG13
    #define DisableCNG13              CNENGbits.CNIEG13= 0
	#endif
	
	#ifdef _CNIEG14
    #define DisableCNG14              CNENGbits.CNIEG14= 0
	#endif
	
	#ifdef _CNIEG15
    #define DisableCNG15              CNENGbits.CNIEG15= 0
	#endif
	
	/* Macros to Enable/Disable CN interrupts on PORTH*/
	
     #ifdef _CNIEH0
 	#define EnableCNH0               CNENHbits.CNIEH0= 1
	#endif
	
	#ifdef _CNIEH1
	#define EnableCNH1               CNENHbits.CNIEH1= 1
	#endif
	
	#ifdef _CNIEH2
	#define EnableCNH2               CNENHbits.CNIEH2= 1
	#endif
	
	#ifdef _CNIEH3
	#define EnableCNH3               CNENHbits.CNIEH3= 1
	#endif
	
	#ifdef _CNIEH4
	#define EnableCNH4               CNENHbits.CNIEH4= 1
	#endif
	
	#ifdef _CNIEH5
	#define EnableCNH5               CNENHbits.CNIEH5= 1
	#endif
	
	#ifdef _CNIEH6
	#define EnableCNH6               CNENHbits.CNIEH6= 1
	#endif
	
	#ifdef _CNIEH7
	#define EnableCNH7               CNENHbits.CNIEH7= 1
	#endif
	
	#ifdef _CNIEH8
	#define EnableCNH8               CNENHbits.CNIEH8= 1
	#endif
	
	#ifdef _CNIEH9
    #define EnableCNH9               CNENHbits.CNIEH9= 1
	#endif
	
	#ifdef _CNIEH10
    #define EnableCNH10              CNENHbits.CNIEH10= 1
	#endif
	
	#ifdef _CNIEH11
    #define EnableCNH11              CNENHbits.CNIEH11= 1
	#endif
	
	#ifdef _CNIEH12
    #define EnableCNH12              CNENHbits.CNIEH12= 1
	#endif
	
	#ifdef _CNIEH13
    #define EnableCNH13              CNENHbits.CNIEH13= 1
	#endif
	
	#ifdef _CNIEH14
    #define EnableCNH14              CNENHbits.CNIEH14= 1
	#endif
	
	#ifdef _CNIEH15
    #define EnableCNH15              CNENHbits.CNIEH15= 1
	#endif
	
    #ifdef _CNIEH0
 	#define DisableCNH0               CNENHbits.CNIEH0= 0
	#endif
	
	#ifdef _CNIEH1
	#define DisableCNH1               CNENHbits.CNIEH1= 0
	#endif
	
	#ifdef _CNIEH2
	#define DisableCNH2               CNENHbits.CNIEH2= 0
	#endif
	
	#ifdef _CNIEH3
	#define DisableCNH3               CNENHbits.CNIEH3= 0
	#endif
	
	#ifdef _CNIEH4
	#define DisableCNH4               CNENHbits.CNIEH4= 0
	#endif
	
	#ifdef _CNIEH5
	#define DisableCNH5               CNENHbits.CNIEH5= 0
	#endif
	
	#ifdef _CNIEH6
	#define DisableCNH6               CNENHbits.CNIEH6= 0
	#endif
	
	#ifdef _CNIEH7
	#define DisableCNH7               CNENHbits.CNIEH7= 0
	#endif
	
	#ifdef _CNIEH8
	#define DisableCNH8               CNENHbits.CNIEH8= 0
	#endif
	
	#ifdef _CNIEH9
    #define DisableCNH9               CNENHbits.CNIEH9= 0
	#endif
	
	#ifdef _CNIEH10
    #define DisableCNH10              CNENHbits.CNIEH10= 0
	#endif
	
	#ifdef _CNIEH11
    #define DisableCNH11              CNENHbits.CNIEH11= 0
	#endif
	
	#ifdef _CNIEH12
    #define DisableCNH12              CNENHbits.CNIEH12= 0
	#endif
	
	#ifdef _CNIEH13
    #define DisableCNH13              CNENHbits.CNIEH13= 0
	#endif
	
	#ifdef _CNIEH14
    #define DisableCNH14              CNENHbits.CNIEH14= 0
	#endif
	
	#ifdef _CNIEH15
    #define DisableCNH15              CNENDbits.CNIEH15= 0
	#endif

	/* Macros to Enable/Disable CN interrupts on PORTJ*/

    #ifdef _CNIEJ0
 	#define EnableCNJ0               CNENJbits.CNIE0J= 1
	#endif
	
	#ifdef _CNIEJ1
	#define EnableCNJ1               CNENJbits.CNIEJ1= 1
	#endif
	
	#ifdef _CNIEJ2
	#define EnableCNJ2               CNENJbits.CNIEJ2= 1
	#endif
	
	#ifdef _CNIEJ3
	#define EnableCNJ3               CNENJbits.CNIEJ3= 1
	#endif
	
	#ifdef _CNIEJ4
	#define EnableCNJ4               CNENJbits.CNIEJ4= 1
	#endif
	
	#ifdef _CNIEJ5
	#define EnableCNJ5               CNENJbits.CNIEJ5= 1
	#endif
	
	#ifdef _CNIEJ6
	#define EnableCNJ6               CNENJbits.CNIEJ6= 1
	#endif
	
	#ifdef _CNIEJ7
	#define EnableCNJ7               CNENJbits.CNIEJ7= 1
	#endif
	
	#ifdef _CNIEJ8
	#define EnableCNJ8               CNENJbits.CNIEJ8= 1
	#endif
	
	#ifdef _CNIEJ9
    #define EnableCNJ9               CNENJbits.CNIEJ9= 1
	#endif
	
	#ifdef _CNIED10
    #define EnableCND10              CNENDbits.CNIEJ10= 1
	#endif
	
	#ifdef _CNIEJ11
    #define EnableCNJ11              CNENJbits.CNIEJ11= 1
	#endif
	
	#ifdef _CNIEJ12
    #define EnableCNJ12              CNENJbits.CNIEJ12= 1
	#endif
	
	#ifdef _CNIEJ13
    #define EnableCNJ13              CNENJbits.CNIEJ13= 1
	#endif
	
	#ifdef _CNIEJ14
    #define EnableCNJ14              CNENJbits.CNIEJ14= 1
	#endif
	
	#ifdef _CNIEJ15
    #define EnableCNJ15              CNENJbits.CNIEJ15= 1
	#endif
	
    #ifdef _CNIEJ0
 	#define DisableCNJ0               CNENJbits.CNIEJ0= 0
	#endif
	
	#ifdef _CNIEJ1
	#define DisableCNJ1               CNENJbits.CNIEJ1= 0
	#endif
	
	#ifdef _CNIEJ2
	#define DisableCNJ2               CNENJbits.CNIEJ2= 0
	#endif
	
	#ifdef _CNIEJ3
	#define DisableCNJ3               CNENJbits.CNIEJ3= 0
	#endif
	
	#ifdef _CNIEJ4
	#define DisableCNJ4               CNENJbits.CNIEJ4= 0
	#endif
	
	#ifdef _CNIEJ5
	#define DisableCNJ5               CNENJbits.CNIEJ5= 0
	#endif
	
	#ifdef _CNIEJ6
	#define DisableCNJ6               CNENJbits.CNIEJ6= 0
	#endif
	
	#ifdef _CNIEJ7
	#define DisableCNJ7               CNENJbits.CNIEJ7= 0
	#endif
	
	#ifdef _CNIEJ8
	#define DisableCNJ8               CNENJbits.CNIEJ8= 0
	#endif
	
	#ifdef _CNIEJ9
    #define DisableCNJ9               CNENJbits.CNIEJ9= 0
	#endif
	
	#ifdef _CNIEJ10
    #define DisableCNJ10              CNENJbits.CNIEJ10= 0
	#endif
	
	#ifdef _CNIEJ11
    #define DisableCNJ11              CNENJbits.CNIEJ11= 0
	#endif
	
	#ifdef _CNIEJ12
    #define DisableCNJ12              CNENJbits.CNIEJ12= 0
	#endif
	
	#ifdef _CNIEJ13
    #define DisableCNJ13              CNENJbits.CNIEJ13= 0
	#endif
	
	#ifdef _CNIEJ14
    #define DisableCNJ14              CNENJbits.CNIEJ14= 0
	#endif
	
	#ifdef _CNIEJ15
    #define DisableCNJ15              CNENJbits.CNIEJ15= 0
	#endif
	
	/* Macros to Enable/Disable CN interrupts on PORTK*/

    #ifdef _CNIEK0
 	#define EnableCNK0               CNENKbits.CNIEK0= 1
	#endif
	
	#ifdef _CNIEK1
	#define EnableCNK1               CNENKbits.CNIEDK1= 1
	#endif
	
	#ifdef _CNIEK2
	#define EnableCNK2               CNENDbits.CNIEK2= 1
	#endif
	
	#ifdef _CNIEK3
	#define EnableCNK3               CNENDbits.CNIEK3= 1
	#endif
	
	#ifdef _CNIEK4
	#define EnableCNK4               CNENKbits.CNIEK4= 1
	#endif
	
	#ifdef _CNIEK5
	#define EnableCNK5               CNENKbits.CNIEK5= 1
	#endif
	
	#ifdef _CNIEK6
	#define EnableCNK6               CNENKbits.CNIEK6= 1
	#endif
	
	#ifdef _CNIEK7
	#define EnableCNK7               CNENKbits.CNIEK7= 1
	#endif
	
	#ifdef _CNIEK8
	#define EnableCNK8               CNENKbits.CNIEK8= 1
	#endif
	
	#ifdef _CNIEK9
    #define EnableCNK9               CNENKbits.CNIEK9= 1
	#endif
	
	#ifdef _CNIEK10
    #define EnableCNK10              CNENKbits.CNIEK10= 1
	#endif
	
	#ifdef _CNIEK11
    #define EnableCNK11              CNENKbits.CNIEK11= 1
	#endif
	
	#ifdef _CNIEK12
    #define EnableCNK12              CNENKbits.CNIEK12= 1
	#endif
	
	#ifdef _CNIEK13
    #define EnableCNK13              CNENKbits.CNIEK13= 1
	#endif
	
	#ifdef _CNIEK14
    #define EnableCNK14              CNENKbits.CNIEK14= 1
	#endif
	
	#ifdef _CNIEK15
    #define EnableCNK15              CNENKbits.CNIEK15= 1
	#endif
	
    #ifdef _CNIEK0
 	#define DisableCNK0               CNENKbits.CNIEK0= 0
	#endif
	
	#ifdef _CNIEK1
	#define DisableCNK1               CNENKbits.CNIEK1= 0
	#endif
	
	#ifdef _CNIEK2
	#define DisableCNK2               CNENKbits.CNIEK2= 0
	#endif
	
	#ifdef _CNIEK3
	#define DisableCNK3               CNENKbits.CNIEK3= 0
	#endif
	
	#ifdef _CNIEK4
	#define DisableCNK4               CNENKbits.CNIEK4= 0
	#endif
	
	#ifdef _CNIEK5
	#define DisableCNK5               CNENKbits.CNIEK5= 0
	#endif
	
	#ifdef _CNIEK6
	#define DisableCNK6               CNENKbits.CNIEK6= 0
	#endif
	
	#ifdef _CNIEK7
	#define DisableCNK7               CNENKbits.CNIEK7= 0
	#endif
	
	#ifdef _CNIEK8
	#define DisableCNK8               CNENKbits.CNIEK8= 0
	#endif
	
	#ifdef _CNIEK9
    #define DisableCNK9               CNENKbits.CNIEK9= 0
	#endif
	
	#ifdef _CNIEK10
    #define DisableCNK10              CNENKbits.CNIEK10= 0
	#endif
	
	#ifdef _CNIEK11
    #define DisableCNK11              CNENKbits.CNIEK11= 0
	#endif
	
	#ifdef _CNIEK12
    #define DisableCNK12              CNENKbits.CNIEK12= 0
	#endif
	
	#ifdef _CNIEK13
    #define DisableCNK13              CNENKbits.CNIEK13= 0
	#endif
	
	#ifdef _CNIEK14
    #define DisableCNK14              CNENKbits.CNIEK14= 0
	#endif
	
	#ifdef _CNIEK15
    #define DisableCNK15              CNENKbits.CNIEK15= 0
	#endif

#endif

/* Macros to Enable External interrupts */

#define EnableINT0              _INT0IE = 1
#define DisableINT0             _INT0IE = 0
#define SetPriorityInt0(priority)     _INT0IP = priority

/* ConfigINT0
 * Enable/disable INT0 interrupts,set priority and falling edge/rising edge
 */
void ConfigINT0(unsigned int) __attribute__ ((section (".libperi")));

/* CloseINT0
 * Disable INT0 interrupts, registers
 */
void CloseINT0() __attribute__ ((section (".libperi")));

#ifdef _INT1IF

#define EnableINT1              _INT1IE = 1
#define DisableINT1             _INT1IE = 0
#define SetPriorityInt1(priority)     _INT1IP = priority

/* ConfigINT1
 * Enable/disable INT1 interrupt,set priority and falling edge/rising edge
 */
void ConfigINT1(unsigned int) __attribute__ ((section (".libperi")));

/* CloseINT1
 * Disable INT1 interrupts, registers
 */
void CloseINT1() __attribute__ ((section (".libperi")));

#endif

#ifdef _INT2IF

#define EnableINT2              _INT2IE = 1
#define DisableINT2             _INT2IE = 0
#define SetPriorityInt2(priority)     _INT2IP = priority

/* ConfigINT2
 * Enable/disable INT2 interrupt,set priority and falling edge/rising edge
 */
void ConfigINT2(unsigned int) __attribute__ ((section (".libperi")));

/* CloseINT2
 * Disable INT2 interrupts, registers
 */
void CloseINT2() __attribute__ ((section (".libperi")));

#endif

#ifdef _INT3IF

#define EnableINT3              _INT3IE = 1
#define DisableINT3             _INT3IE = 0
#define SetPriorityInt3(priority)     _INT3IP = priority

/* ConfigINT3
 * Enable/disable INT3 interrupt,set priority and falling edge/rising edge
 */
void ConfigINT3(unsigned int) __attribute__ ((section (".libperi")));

/* CloseINT3
 * Disable INT3 interrupts, registers
 */
void CloseINT3() __attribute__ ((section (".libperi")));

#endif

#ifdef _INT4IF

#define EnableINT4              _INT4IE = 1
#define DisableINT4             _INT4IE = 0
#define SetPriorityInt4(priority)     _INT4IP = priority

/* ConfigINT4
 * Enable/disable INT4 interrupt,set priority and falling edge/rising edge
 */
void ConfigINT4(unsigned int) __attribute__ ((section (".libperi")));

/* CloseINT4
 * Disable INT4 interrupts, registers
 */
void CloseINT4() __attribute__ ((section (".libperi")));

#endif

/* Function Prototypes */

/* ConfigCNPullups
 * Enable/ disable pull up registers
 */
void ConfigCNPullups(long int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortA(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortB(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortC(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortD(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortE(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortF(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortG(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortH(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortJ(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPullupsPortK(unsigned int) __attribute__ ((section (".libperi")));

/* ConfigCNPulldown
 * Enable/ disable pull up registers
 */
void ConfigCNPulldownPortA(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortB(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortC(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortD(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortE(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortF(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortG(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortH(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortJ(unsigned int) __attribute__ ((section (".libperi")));
void ConfigCNPulldownPortK(unsigned int) __attribute__ ((section (".libperi")));


/* ConfigIntCN
 * Enable/Disable CN interrupt and set priority
 */
void ConfigIntCN(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortA(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortB(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortC(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortD(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortE(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortF(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortG(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortH(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortJ(long int) __attribute__ ((section (".libperi")));
void ConfigIntCNPortK(long int) __attribute__ ((section (".libperi")));
void CloseINTCN()__attribute__ ((section (".libperi")));

#endif
