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
#ifdef TRACE_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define TRACE_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "string.h"

#include "basedef.h"
#include "trace.h"
#include "sirem.h"
#include "parlist.h"
#include "vuart.h"
#include "vADC.h"
#include "measure.h"
#include "tempctrl.h"
#include "ident.h"
#include "systmr.h"

/*----------------------------------------------------------------------------*/
/* EXPORTED from other modules                                                */
/*----------------------------------------------------------------------------*/
extern volatile U16 U16Adc[AdcCh_Cnt];
extern const iolist iopar[];

/* MEASURE.C */
extern volatile struct Mes1 mes1;
extern volatile struct Mes2 mes2;

/* TempCtrl.C */
extern volatile struct temperature_control T_ctrl;
extern volatile struct bresenham_struct brs;

/* IDENT.C */
extern volatile struct cartridge_ident ident;

extern volatile U16 ERR_CONTROL;
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
S16 TRSB[TRACE_LEN][NB_TRACE_VARS] __attribute__ ((aligned));

volatile U16 trace_state;
volatile U16 trace_control;
volatile U16 STORE_POS;
U16 trace_counter;
S16 trace_trigger;
struct parlist_trace par_trace;

/* PARAMS STORED IN EEPROM */
volatile U16 trace_config;
volatile U16 trace_every_period;
U16 u16TraceParamNumber_1;
U16 u16TraceParamNumber_2;
U16 u16CompareParameter;
S16 s16CmpValue;


S16 *trace_source_addr[]  =
{
/* 0 */    (S16*)NULL,
/*******************************************************/
/* MEASURE.C */
/* 1 */    (S16*)&ADC[AdcCh_0],
/* 2 */    (S16*)&ADC[AdcCh_1],

/* 3 */    (S16*)&mes1.Current,
/* 4 */    (S16*)&mes1.line_phase,

/* 5 */    (S16*)&T_ctrl.T_fbk,
/* 6 */    (S16*)&T_ctrl.heat_periods,
/* 7 */    (S16*)&T_ctrl.tmpctrl_triac_state,

/* 8 */(S16*)&ident.ident_mes_temp,
/* 9 */(S16*)&ident.U_Temp_in,
/* 10 */(S16*)&ident.U_Temp_out,
/* 11 */(S16*)&brs.triac_state,
/* 12 */(S16*)&ERR_CONTROL,
/* 13 */(S16*)&mes2.Line_period_zc_T2,
/*******************************************************/
};

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
* Purpose: Get nimber of parameters
* Input: none
* Output:  return number of params in system
*/
/******************************************************************************/
U16 IF_Get_TRSB_CntBytes(void)
{
    return(sizeof(TRSB));
}

/******************************************************************************/
/*
* Purpose: Trace variables in trace array. 
* Input: none
* Output:  none
*/
/******************************************************************************/
void do_trace(void)
{
    static U16 trace_period;
    S16 comp_param_local;
    
    
    par_trace.par_ptr[0] =  (S16*)trace_source_addr[u16TraceParamNumber_1];    
    par_trace.trace_display[0] = *par_trace.par_ptr[0];

    par_trace.par_ptr[1] =  (S16*)trace_source_addr[u16TraceParamNumber_2];
    par_trace.trace_display[1] = *par_trace.par_ptr[1];
    
    
    if(_reset_trace_manual() || _reset_trace())
    {
        _set_reset_trace_manual(0);
        _set_reset_trace(0);
        
        _set_trace_state(1);
        STORE_POS = 0;                //perform clear
        Clear_Trace_Array();
    }
    
    if(_condition_start_bit() && _trace_state() && !_trace_running())
    {
        
        comp_param_local = (S16)*trace_source_addr[u16CompareParameter];
        
        if(_more_than_bit())
        {
            if(comp_param_local > s16CmpValue)
            {
                _set_trace_running(1);
                //_set_reset_trace(1);
                STORE_POS = 0;
            }
        }
        else if(_less_than_bit())
        {
            if(comp_param_local < s16CmpValue)
            {
                _set_trace_running(1);
                //_set_reset_trace(1);
                STORE_POS = 0;
            }
        }    
        else if(_equal_bit())
        {
            if(comp_param_local == s16CmpValue)
            {
                _set_trace_running(1);
                //_set_reset_trace(1);
                STORE_POS = 0;
            }
        }        
        else if(_not_equal_bit())
        {
            if(comp_param_local != s16CmpValue)
            {
                _set_trace_running(1);
                //_set_reset_trace(1);
                STORE_POS = 0;
            }
        }    
    }
    if(_manual_start_trace() && !_trace_running())
    {
        _set_manual_start_trace(0);
        _set_trace_running(1);
        _set_trace_state(1);
    }
    
    
    if(_trace_running())    //if trace is running
    {

        if(STORE_POS >= TRACE_STEPS)
        {
            _set_trace_state(0);
            _set_trace_running(0);
        }
        else
        {
            if(!trace_period)
            {
                TRSB[STORE_POS][0] = (S16)*par_trace.par_ptr[0];
                TRSB[STORE_POS][1] = (S16)*par_trace.par_ptr[1];
                STORE_POS++;
                trace_period = trace_every_period;
            }
            else trace_period--;
        }    
    }    
}

/******************************************************************************/
/*
* Purpose: Trace array clear
* Input: none
* Output:  none
*/
/******************************************************************************/
void Clear_Trace_Array(void)
{
    U16 steps;
    U16 vars;

    for(vars = 0;vars <= NB_TRACE_VARS;vars++)
    {
        for(steps = 0;steps <= TRACE_STEPS;steps++)
        {
            TRSB[steps][vars] = 0;
        }
    }
}

/******************************************************************************/
/*
* Purpose: Trace Initialization.
* Input: none
* Output:  
*/
/******************************************************************************/
void trace_init_first(void)
{
    par_trace.trace_length = sizeof(trace_source_addr);
    
    Clear_Trace_Array();
    
    /* set pc control side config*/
    _set_reset_trace(1);
    
    /* set trace state*/
    _set_trace_state(0);            //put trace in blocked state

    // Check that par indexes are bound in trace source address array
    if((u16TraceParamNumber_1 > sizeof(trace_source_addr)) || (u16TraceParamNumber_2 > sizeof(trace_source_addr)) || (u16CompareParameter > sizeof(trace_source_addr)))
    {
        u16TraceParamNumber_1 = 0;
        u16TraceParamNumber_2 = 0;
        u16CompareParameter = 0;
    }

}



/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

//-----------------------------------------------------------------------------



/******************************************************************************/
/*
 * Name:      
 * Purpose:   
 * 
*/
/******************************************************************************/
