/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef TASK_H
#define TASK_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "systmr.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
#define T1_TIME            cTMR3_ISR_TICK_us /* Timer 3 reference */
#define T2_TIME            cTMR1_ISR_TICK_us /* Timer 1 reference */


/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/

/* Station Statistics. All Parameters must be stored in EEPROM*/
struct sStationStatistic
{
    /* Operation Times */
    U32 OpTime_Hours;
    
    /* Cartridge in stand */
    U32 Cart_Stand_Counter;
    
    /* Changed Cartridge */
    U32 Cart_Change_Counter;
    
    U16 OpTime_Minutes;
    
    /* Hibernation Times */
    U16 HibTimeHours;
    U16 HibCounter;
    U8 HibTimeMinutes;
    U8 HibTimeSeconds;    
};

extern struct sStationStatistic stat_stat;

/* Station Statistics States */
typedef enum eStationStatStates
{
    SS_Stand = 0,
    SS_Extractor,
    SS_Norm_Operation,
    SS_Undefined,

}teStationStatStates;

struct sTaskTimesStruct
{
    U16 Task1Ticks;
    U16 Task2Ticks;
    U32 Task1Time_us;
    U32 Task2Time_us;
    U32 Task1MaxTime_us;
    U32 Task2MaxTime_us;
};

extern struct sTaskTimesStruct Ttime;
#define _get_Ttime()    (&Ttime)
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/
#define _Task2_Timer_Clear()        (TMR2 = 0)
#define _Task2_Timer_Stop()            (T2CONbits.TON = 0)
#define _Task2_Timer_Start()        (T2CONbits.TON = 1)
#define _Task1_GetTime(p)            (p->Task1Ticks = TMR3)
#define _Task2_GetTime(p)            (p->Task2Ticks = TMR2)


/*----------------------------------------------------------------------------*/
/* GET BITS */
#define _is_task1_execute()          (_getbit(TASK_CONTROL,0))         /* bit 0 */
#define _is_task2_execute()          (_getbit(TASK_CONTROL,1))         /* bit 1 */
#define _task1_run_flag()              (_getbit(TASK_CONTROL,2))         /* bit 2 */
#define _task2_run_flag()              (_getbit(TASK_CONTROL,3))         /* bit 3 */
#define _is_idle_enabled()          (_getbit(TASK_CONTROL,4))         /* bit 4 */
#define _is_idle_execute()            (_getbit(TASK_CONTROL,5))         /* bit 5 */


/* SET BITS */
#define _set_task1_execute(x)          (_putbit((x),TASK_CONTROL,0))     /* bit 0 */
#define _set_task2_execute(x)          (_putbit((x),TASK_CONTROL,1))     /* bit 1 */
#define _set_task1_run_flag(x)        (_putbit((x),TASK_CONTROL,2))     /* bit 2 */
#define _set_task2_run_flag(x)        (_putbit((x),TASK_CONTROL,3))     /* bit 3 */
#define idle_task_enable()            (_putbit((1),TASK_CONTROL,4))     /* bit 4 */
#define idle_task_disable()            (_putbit((0),TASK_CONTROL,4))     /* bit 4 */
#define _set_idle_task_execute(x)     (_putbit((x),TASK_CONTROL,5))     /* bit 5 */




/*    
    TASK CONTROL
    Bit 0        -        task1 execution status 1:Task execution in progress,0:Task is not execute
    Bit 1        -        task2 execution status 1:Task execution in progress,0:Task is not execute
    Bit 2        -        Task1 run flag 1:Run task 0:Don't run
    Bit 3        -        Task2 run flag 1:Run task 0:Don't run
    Bit 4        -        Idle task ENABLE, 1:Idle ENABLED, 0:Idle DISABLED
    Bit 5        -        Idle task execution status 1:Idle Task execution in progress,0:Idle Task is not execute
    Bit 6        -        
    Bit 7        -        
*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                           */
/*----------------------------------------------------------------------------*/
void TaskTimesCalc(struct sTaskTimesStruct *p);
void StationStatistic(void);


#endif /* TASK_H */
