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
#ifdef STATEMACHINE_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define STATE_MACHINE_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "statemachine.h"
#include "basedef.h"
#include "DigitalIO.h"
#include "LCD.h"
#include "systmr.h"
#include "sirem.h"
#include "PARLIST.h"
#include "vuart.h"
#include "vADC.h"
#include "trace.h"
#include "eeprom.h"
#include "measure.h"
#include "ident.h"
#include "trace.h"
#include "tempctrl.h"
#include "triac_control.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/
/* LOAD VALUES FOR STATEMACHINE TIMERS */
/* TIMER VALUES RUN IN TASK2 */
#define LOAD_T2_4SEC            800u  
#define LOAD_T2_3SEC            600u
#define LOAD_T2_2SEC            400u 
#define LOAD_T2_1SEC            200u
#define LOAD_T2_500mS            100u
#define LOAD_T2_250mS            50u

/* TIMER VALUES RUN IN TASK1 */
#define LOAD_T1_40m                400u       //40ms in task1 time
#define LOAD_T1_100m            1000u      //100ms in task1 time
#define LOAD_T1_200m            2000u      //200ms in task1 time
#define LOAD_T1_500m            5000u      //500ms in task1 time
#define LOAD_T1_1s                10000u  //1s in task1 time
#define LOAD_T1_1500ms            15000u  //1.5s in task1 time
#define LOAD_T1_2s                20000u  //2s in task1 time
#define LOAD_T1_3s                30000u  //3s in task1 time
#define LOAD_T1_4s                40000u  //4s in task1 time

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
volatile U16 mainstate_T2;
static volatile U16 prevstate_T2;
static volatile U16 nextstate_T2;

volatile U16 mainstate_T1;
static volatile U16 nextstate_T1;
static volatile U16 prevstate_T1;
/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/
#define TEMP_UPDATE_RATE_DEFAULT    200   // 1s LCD update rate - default
/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
/* STATEMACHINE transil parameters. */
volatile U16 SYS_CONTROL;
volatile U16 PC_CONTROL;
volatile U16 ERR_CONTROL;

U16 LCD_update_rate;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/
U16 stm_timer_T2(U16 cmd,U16 cons);
U16 stm_timer_II_T2(U16 cmd, U16 cons);
U16 stm_timer_T1(U16 cmd,U16 cons);
void PrintHibernationTime(void);

/******************************************************************************/
/*
 * Purpose: Statemachine running in TASK1. Manage Control.
 * Inputs:  none
 * Output:    none
 */
/******************************************************************************/
void state_machine_T1(void)
{
    if(_power_up_ok() && _error_check())
    {
        if(ERR_CONTROL)    //All errors are handled here
        {
            _set_drive(0);
            _TRIAC_OFF();    // Turn OFF Triac
            mainstate_T1 = ST1_ERROR_STATE;
        }
        else 
        {
        /* Handle High Priority State Machine Transil's */
        /* These Transil's don't care about statemachine state except error state! */
        if(!_cartridge_present()) mainstate_T1 = ST1_NO_CARTRIDGE;
        }
    }
    switch(mainstate_T1)
    /*------------------------*/
    {
    case ST1_INIT:
        //SYS_CONTROL = 0;
        stm_timer_T1(1, LOAD_T1_500m);
        nextstate_T1 = ST1_RESET_ERRORS;
        mainstate_T1 = ST1_WAIT_STATE;
        prevstate_T1 = ST1_INIT;
        mainstate_T2 = ST2_WAIT_POWER_UP;
        
    break;
    /*------------------------*/
    case ST1_RESET_ERRORS:
        _set_grid_freq_error(0);
        stm_timer_T1(1, LOAD_T1_1s);
        nextstate_T1 = ST1_CHECK_ERRORS;
        prevstate_T1 = ST1_RESET_ERRORS;
        mainstate_T1 = ST1_WAIT_STATE;
    break;
    /*------------------------*/
    case ST1_CHECK_ERRORS:
        if(ERR_CONTROL)
        {
            mainstate_T1 = ST1_ERROR_STATE;
            prevstate_T1 = ST1_CHECK_ERRORS;
            _set_error_check(0);
            _set_power_up(0);
        }
        else 
        {
            mainstate_T1 = ST1_DC_AUTOTUNNING;
            _set_error_check(1);
        }
    break;
    /*------------------------*/
    case ST1_DC_AUTOTUNNING:
        if(DC_Autotunning(ADC[1])) //Current measure DC autotunning
        {
            cartridge_ident(1, 0);     // INIT ident routine
            stm_timer_T1(1,LOAD_T1_500m);
            nextstate_T1 = ST1_IDENT;
            mainstate_T1 = ST1_WAIT_STATE;
            prevstate_T1 = ST1_DC_AUTOTUNNING;
            mainstate_T2 = ST2_POWER_UP_OK;
        }
    break;
    /*------------------------*/    
    case ST1_IDENT:
        if(prevstate_T1 != mainstate_T1)
        {
            _set_power_up(1);        // Set power up flag OK
            _set_drive(1);            // <------- Drive Enable Here
            prevstate_T1 = ST1_IDENT;
            mainstate_T2 = ST2_CHECKING_CARTRIDGE;
        }
        
        if(_extractor()) mainstate_T1 = ST1_EXTRACTOR;
        else if(cartridge_ident(0,ADC[AdcCh_0]))
        {
            stm_timer_T1(1, LOAD_T1_100m);
            if(_stand()) nextstate_T1 = ST1_STAND;
            else nextstate_T1 = ST1_TMPCTRL;
            mainstate_T1 = ST1_WAIT_STATE;
            prevstate_T1 = ST1_IDENT;
        }
    break;
    /*------------------------*/    
    case ST1_TMPCTRL:
        if(prevstate_T1 != mainstate_T1)
        {
            mainstate_T2 = ST2_TMPCTRL;
            prevstate_T1 = ST1_TMPCTRL;
            /* OK, We must reset pid controller and tmpctrl module before use it for first time in this state ! */
            Reset_TMPCTRL();
            Reset_PID();
        }
        
        temp_ctrl(ADC[AdcCh_0], 0); //<------ Control User Temp
        
        if(_extractor()) mainstate_T1 = ST1_EXTRACTOR;
        else if(_stand()) mainstate_T1 = ST1_STAND;
        
    break;
    /*------------------------*/    
    case ST1_STAND:    
        if(prevstate_T1 != mainstate_T1)
        {
            mainstate_T2 = ST2_STAND;
            prevstate_T1 = ST1_STAND;
            /* OK, We must reset pid controller and tmpctrl module before use it for first time in this state ! */
            Reset_TMPCTRL();
            Reset_PID();
        }
        
        temp_ctrl(ADC[AdcCh_0], 1); // Control User Temp Sleep
        
        if(Timestate_Cartridge_Control(0))
        {
            mainstate_T1 = ST1_HIBERNATE;
            _set_hibernate(1);
        }

        if(!_stand())
        {
            mainstate_T1 = ST1_TMPCTRL;
            Timestate_Cartridge_Control(1);
        }
    break;
    /*------------------------*/    
    case ST1_EXTRACTOR:
            mainstate_T2 = ST2_EXTRACTOR;
            prevstate_T1 = ST1_EXTRACTOR;
            
        if(!_extractor())
        {
            stm_timer_T1(1, LOAD_T1_500m);
            cartridge_ident(1, 0); //INIT ident routine
            nextstate_T1 = ST1_IDENT;
            mainstate_T1 = ST1_WAIT_STATE;
        }
    break;
    /*------------------------*/    
    case ST1_NO_CARTRIDGE:
        if(_cartridge_present())
        {
            stm_timer_T1(1, LOAD_T1_500m);
            cartridge_ident(1, 0); //INIT ident routine
            nextstate_T1 = ST1_IDENT;
            mainstate_T1 = ST1_WAIT_STATE;
        }

        mainstate_T2 = ST2_NO_CARTRIDGE;
        prevstate_T1 = ST1_NO_CARTRIDGE;    
    break;
    /*------------------------*/
    case ST1_HIBERNATE:
        mainstate_T2 = ST2_HIBERNATE;
        prevstate_T1 = ST1_HIBERNATE;
        
        if(!_stand())
        {
            stm_timer_T1(1, LOAD_T1_500m);
            cartridge_ident(1, 0); //INIT ident routine
            nextstate_T1 = ST1_IDENT;
            mainstate_T1 = ST1_WAIT_STATE;
            _set_hibernate(0);
        }
    break;
    /*------------------------*/        
    case ST1_ERROR_STATE:
        if(!ERR_CONTROL)
        {
            stm_timer_T1(1, LOAD_T1_500m);
            nextstate_T1 = ST1_INIT;
            mainstate_T1 = ST1_WAIT_STATE;
        }
        else
        {
            mainstate_T2 = ST2_ERROR_STATE;
            prevstate_T1 = ST1_ERROR_STATE;
        }        
    break;
    /*------------------------*/
    case ST1_WAIT_STATE:
        stm_timer_T1(2,0);
        if(!stm_timer_T1(0,0)) mainstate_T1 = nextstate_T1;
    break;
    /*------------------------*/    
    case ST1_TEST_MODE_IDENT:
        
        Nop();
        
    break;
    /*------------------------*/    
    case ST1_LEARNING_MODE:
        
        Nop();
        
    break;
    /*------------------------*/    
    
    default:
        mAssert(cFalse);
        _set_global_system_fault(1);
        break;
    }//end switch

}
/******************************************************************************/
/*
 * Purpose: Statemachine running in TASK2. Manage User Interface. State Reference is given from Statemachine in TASK1.
 * Inputs:  none
 * Output:    none
 * 
 */
/******************************************************************************/
void state_machine_T2(void)
{
    
    switch(mainstate_T2)
    /*------------------------*/
    {
    case ST2_INIT:
        mainstate_T2 = ST2_WAIT_POWER_UP;
    break;
    /*------------------------*/
    case ST2_WAIT_POWER_UP:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPutc('\n');
            IF_LCDPuts(" POWER UP...");
            prevstate_T2 = ST2_WAIT_POWER_UP;
        }
    break;
    /*------------------------*/
    case ST2_POWER_UP_OK:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPutc('\n');
            IF_LCDPuts(" POWER UP...OK");
            prevstate_T2 = ST2_POWER_UP_OK;
        }
    break;
    /*------------------------*/
    case ST2_CHECKING_CARTRIDGE:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPutc('\n');
            IF_LCDPuts("  CHECKING ...");
            prevstate_T2 = ST2_CHECKING_CARTRIDGE;
        }
    break;
    /*------------------------*/
    case ST2_TMPCTRL:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("   TOOL: 2245");
            IF_LCDPutc('\n');
            IF_LCDPuts("ACT. TEMP: ");
            IF_LCDGotoXY(15,2);
            IF_LCDPutc(0xDF);    //Degree Sign
            IF_LCDPuts("C");
            
            prevstate_T2 = ST2_TMPCTRL;
            stm_timer_T2(1, LCD_update_rate);
        }
        stm_timer_T2(2,0);
        if(!stm_timer_T2(0,0))
        {
            IF_LCDGotoXY(11,2);
            IF_LCDPuts("   ");
            IF_LCDGotoXY(11,2);
            IF_LCDPutn(Get_Temp_Actual());
            stm_timer_T2(1, LCD_update_rate);
        }
        
        if(_up_button_pushed() || _down_button_pushed()) mainstate_T2 = ST2_CHANGE_USER_REF; //<------ Only in this state user can change ref temperature
        
    break;
    /*------------------------*/    
    case ST2_STAND:
        if(mainstate_T2 != prevstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("     STAND");
            IF_LCDPutc('\n');
            IF_LCDPuts("SLEEP TEMP: ");
            IF_LCDGotoXY(15,2);
            IF_LCDPutc(0xDF);    //Degree Sign
            IF_LCDPuts("C");
            prevstate_T2 = ST2_STAND;
            stm_timer_T2(1, LCD_update_rate);
        }
        
        stm_timer_T2(2,0);
        if(!stm_timer_T2(0,0))
        {
            IF_LCDGotoXY(12,2);
            IF_LCDPuts("   ");
            IF_LCDGotoXY(12,2);
            IF_LCDPutn(Get_Temp_Actual());

            stm_timer_T2(1, LCD_update_rate);
        }
    break;
    /*------------------------*/    
    case ST2_EXTRACTOR:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("   EXTRACTOR");
            prevstate_T2 = ST2_EXTRACTOR;
        }        
    break;
    /*------------------------*/    
    case ST2_NO_CARTRIDGE:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("  NO CARTRIDGE");
            prevstate_T2 = ST2_NO_CARTRIDGE;
        }    
    break;
    /*------------------------*/
    case ST2_HIBERNATE:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("  HIBERNATION");
            prevstate_T2 = ST2_HIBERNATE;
            // Clear hibernation times
            stat_stat.HibTimeHours = 0;
            stat_stat.HibTimeMinutes = 0;
            stat_stat.HibTimeSeconds = 0;
            stat_stat.HibCounter = 0;
            
            // Load timer 
            stm_timer_T2(1, LCD_update_rate);
        }
        
        stm_timer_T2(2,0);
        if(!stm_timer_T2(0,0))
        {
            PrintHibernationTime();
            stm_timer_T2(1, LCD_update_rate);
        }
        
    break;
    /*------------------------*/
    case ST2_CHANGE_USER_REF:
        if(prevstate_T2 != mainstate_T2)
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("   TOOL: 2245");
            IF_LCDPutc('\n');
            IF_LCDPuts("  SET TEMP: ");
            IF_LCDGotoXY(15,2);
            IF_LCDPutc(0xDF);    //Degree Sign
            IF_LCDPuts("C");
            prevstate_T2 = ST2_CHANGE_USER_REF;
            stm_timer_T2(1,LOAD_T2_500mS);
        }
        
        if(_select_button_pushed())
        {
            mainstate_T2 = ST2_TEMP_SELECT;
        }
        else if(_up_button_pushed())
        {
            mainstate_T2 = ST2_TEMP_UP;
        }
        else if(_down_button_pushed())
        {
            mainstate_T2 = ST2_TEMP_DOWN;
        }
        else
        {
            stm_timer_T2(2,0);
            if(!stm_timer_T2(0,0))        // User have 2s to push SELECT button and confirm ref temp
            {
                Roll_Back_User_Temp();    //<------ If SELECT Button is not pushed do not update user reference temperature and roll - back it.
                mainstate_T2 = ST2_TMPCTRL;
            }
        } 
    break;
    /*------------------------*/
    case ST2_TEMP_UP:
        Inc_User_Temp(); //Increment User Temperature with 5deg
        
        IF_LCDGotoXY(12,2);
        IF_LCDPuts("   ");
        IF_LCDGotoXY(12,2);
        IF_LCDPutn(Get_User_Temp());
        
        stm_timer_T2(1,LOAD_T2_2SEC);        //<------ Overload 2s timer again. Used for confirm time.
        stm_timer_II_T2(1, LOAD_T2_250mS);     //<------ Load 250ms timer before scan buttons again.
        nextstate_T2 = ST2_CHANGE_USER_REF;
        mainstate_T2 = ST2_WAIT_STATE_II;
    break;
    /*------------------------*/    
    case ST2_TEMP_DOWN:
        Dec_User_Temp();  //Decrement User Temperature with 5deg

        IF_LCDGotoXY(12,2);
        IF_LCDPuts("   ");
        IF_LCDGotoXY(12,2);
        IF_LCDPutn(Get_User_Temp());
        
        stm_timer_T2(1,LOAD_T2_2SEC);
        stm_timer_II_T2(1, LOAD_T2_250mS);
        nextstate_T2 = ST2_CHANGE_USER_REF;
        mainstate_T2 = ST2_WAIT_STATE_II;         
    break;
    /*------------------------*/    
    case ST2_TEMP_SELECT:
        Set_User_Temp(); //Select User Temperature with 5deg
        
        IF_LCDGotoXY(12,2);
        IF_LCDPuts("   ");
        IF_LCDGotoXY(12,2);
        IF_LCDPutn(Get_User_Temp());
        
        stm_timer_T2(1,LOAD_T2_2SEC);
        stm_timer_II_T2(1, LOAD_T2_250mS);
        nextstate_T2 = ST2_TMPCTRL;
        mainstate_T2 = ST2_WAIT_STATE_II;
    break;
    /*------------------------*/    
    case ST2_ERROR_STATE:
        stm_timer_T2(2,0);
        if(!stm_timer_T2(0,0))
        {
            IF_LCDPutc('\f');
            IF_LCDPuts("   ERROR: ");
            IF_LCDPutn(ERR_CONTROL); //<------ Update LCD error register.
            prevstate_T2 = ST2_ERROR_STATE;
            stm_timer_T2(1, LCD_update_rate); 
        }
    break;
    /*------------------------*/        
    case ST2_WAIT_STATE:
        stm_timer_T2(2,0); //Count here stm_timer
        if(!stm_timer_T2(0,0)) mainstate_T2 = nextstate_T2;
    break;
    /*------------------------*/
    case ST2_WAIT_STATE_II:
        stm_timer_II_T2(2,0); //Count here stm_timer_II
        if(!stm_timer_II_T2(0,0)) mainstate_T2 = nextstate_T2;
    break;
    /*------------------------*/    

    default:
        mAssert(cFalse);
        _set_global_system_fault(1);
    break;
    }

}
/******************************************************************************/
/*
 * Purpose: INIT State Machines
 * Inputs:  none
 * Output:    none
 * 
 */
/******************************************************************************/
void state_machine_init(void)
{
    mainstate_T1 = ST1_INIT;
    mainstate_T2 = ST2_INIT;
    if(!LCD_update_rate) LCD_update_rate = TEMP_UPDATE_RATE_DEFAULT; // LCD update rate = 0 is not recommended
    _set_power_up(0);
}

/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/*
 * Name: Software Timer for state machine module  TASK2
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task periods
 */
/******************************************************************************/
U16 stm_timer_T2(U16 cmd, U16 cons)               
{         
    static U16 count;

    if(cmd==1)    count = cons;    
    else if(count && cmd==2) count--;
    return(count);
}
/******************************************************************************/
/*
 * Name: Software Timer for state machine module  TASK2
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task periods
 */
/******************************************************************************/
U16 stm_timer_II_T2(U16 cmd, U16 cons)               
{         
    static U16 count;

    if(cmd==1)    count = cons;    
    else if(count && cmd==2) count--;
    return(count);
}
/******************************************************************************/
/*
 * Name: Software Timer for state machine module  TASK1 
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task periods
 */
/******************************************************************************/
U16 stm_timer_T1(U16 cmd, U16 cons)               
{         
    static U16 count;

    if(cmd==1)    count = cons;    
    else if(count && cmd==2) count--;
    return(count);
}
/******************************************************************************/
/*
 * Name: 
 * Params: 
 * Purpose:   
 */
/******************************************************************************/
void PrintHibernationTime(void)
{
    IF_LCDGotoXY(3,2);
    IF_LCDPutn(stat_stat.HibTimeHours);
    IF_LCDGotoXY(6,2);
    IF_LCDPuts(":   ");
    IF_LCDGotoXY(8,2);
    IF_LCDPutn(stat_stat.HibTimeMinutes);
    IF_LCDGotoXY(11,2);
    IF_LCDPuts(":   ");
    IF_LCDGotoXY(13,2);
    IF_LCDPutn(stat_stat.HibTimeSeconds);
}    




