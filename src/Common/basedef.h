/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef BASEDEF_H
#define BASEDEF_H

#define FIRMWARE_BASE_VERSION       5000
#define FIRMWARE_SUB_VERSION        00

//PLL=16x, OSC=8Mhz -> Freq = (OSC) * PLL;
#define cOSC_KHz    ((U32)8000ul)                        // Oscillator frequancy
#define cPLL_KHz    ((U32)8ul*(cOSC_KHz))                // PLL frequency kHz.
#define cPLL_MHz    ((U32)(cPLL_KHz)/(U32)1000ul)        // PLL frequency Mhz
#define cFCY_HZ     (((cPLL_KHz)*(U32)1000ul)/(U32)4ul)  // Instruction clock - Hz
#define cFCY_MHZ    ((cPLL_KHz)/(U32)4ul/(U32)1000ul)    // Instruction clock - MHz
#define cTCY_NS     (1000UL/cFCY_MHZ)

/* INTERRUPT PRIORITY LEVELS */
#define cISR_PRIORITY_TMR3    (6u)    /*  Timer3  */        /* HIGHEST TASK 1 */
#define cISR_PRIORITY_TMR1    (3u)    /*  Timer1  */      /* LOWEST TASK 2 */
#define cISR_PRIORITY_U1RX    (4u)    /*  UART RX */        /* LOWEST UART Rx */
#define cISR_PRIORITY_TMR2    (0u)    /*  Timer2  */        /* DISABLED */
#define cISR_PRIORITY_INT0    (0u)    /*  INT0    */        /* - */
#define cISR_PRIORITY_ADC     (0u)    /*  ADC     */        /* DISABLED */
#define cISR_PRIORITY_U1TX    (0u)    /*  UART TX */        /* DISABLED */


typedef unsigned char           U8;
typedef unsigned int            U16;
typedef unsigned long           U32;
typedef unsigned long long      U64;

typedef signed char             S8;
typedef signed int              S16;
typedef signed long             S32;

typedef float                   F32;
typedef double                  f64;

typedef U8                      BOOL;
#define cFalse                  ((BOOL)(0))
#define cTrue                   ((BOOL)(!cFalse))
#define FALSE                   ((BOOL)(0))
#define TRUE                    ((BOOL)(!cFalse))

typedef U8                      HRESULT;
#define S_OK                    ((HRESULT)0x00u)
#define E_OK                    ((HRESULT)0x00u)
#define S_FALSE                 ((HRESULT)0x01u)
#define E_INVALIDARG            ((HRESULT)0x02u)
#define E_FAIL                  ((HRESULT)0x03u)

// Function parameters flow define
#define _IN_
#define _OUT_

#if !defined NULL
#define NULL ((void*)0)
#endif

/* TOOLS AND MACROS */

#define Hi(LongVar)         (*((S16 *)&(LongVar)+1))
#define Lo(LongVar)         (*(S16 *)&(LongVar))

#define Hiu(LongVar)        (*((U16 *)&(LongVar)+1))
#define Lou(LongVar)        (*(U16 *)&(LongVar))

#define HiBy(WordVar)       (*((U8 *)&(WordVar)+1))
#define LoBy(WordVar)       (*(U8 *)&(WordVar))

#define _putbit(value,dst,bitn)     (           \
{                                               \
    if(value)                                   \
    dst = ((dst) | (U16)(1u << bitn));          \
    else                                        \
    dst = ((dst) & (U16)~(1u << bitn));         \
})

#define _getbit(src,bitn)        ((src) & (1 << (bitn)))

#define absi(x)                           ((x)>=0 ? (x) : -(x))            /* absolut of integer */

typedef unsigned int        tCPUItState;
#define SuspendAllInterrupts()        { tCPUItState CPUItState; SET_AND_SAVE_CPU_IPL(CPUItState, 7);
#define ResumeAllInterrupts()           RESTORE_CPU_IPL(CPUItState); }

#define mAssert(Cond)   (                   \
{                                           \
    if(Cond == cFalse) while(1){Nop();}     \
})
#if defined(__dsPIC30F3014__)
    #include <p30f3014.h>
#elif defined(__dsPIC30F4013__)
    #include <p30F4013.h>
#else
    #error "CPU settings not match!"
#endif
#include "libpic30.h"
#include "dsp.h"
#include "libq.h"
#include "DigitalIoCfg.h"

#endif /* BASEDEF_H */
