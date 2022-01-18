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
#ifdef PARLIST_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define PARLIST_C
#endif

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "PARLIST.h"
#include "systmr.h"
#include "vADC.h"
#include "trace.h"
#include "task.h"
#include "measure.h"
#include "statemachine.h"
#include "tempctrl.h"
#include "ident.h"
#include "eeprom.h"
#include "pid.h"

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
U16 release;            
const U16 version = FIRMWARE_BASE_VERSION + FIRMWARE_SUB_VERSION; 
const U16 C30_Version = __C30_VERSION__;  

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
/* ADC.C */
extern U16 ADC[AdcCh_Cnt];

/* TRACE.C */
extern U16 trace_config;
extern U16 trace_control;
extern U16 STORE_POS;
extern U16 u16TraceParamNumber_1;
extern U16 u16TraceParamNumber_2;
extern S16 s16CmpValue;
extern U16 trace_state;
extern U16 u16CompareParameter;
extern struct parlist_trace par_trace;
extern U16 trace_every_period;

/* STATEMACHINE.C */
extern volatile U16 SYS_CONTROL;
extern volatile U16 PC_CONTROL;
extern volatile U16 ERR_CONTROL;
extern U16 mainstate_T1;
extern U16 mainstate_T2;
//extern U16 prevstate_T2;
extern U16 LCD_update_rate;

/* TASK.C */
extern struct sTaskTimesStruct Ttime;

/* MEASURE.C */
extern struct Mes1 mes1;
extern struct Mes2 mes2;

/* TEMPCTRL_C */
extern struct temperature_control T_ctrl;
extern U16 tmpctrl_mainstate;
extern struct pid_struct pid;
extern struct overload_protection overprot;

/* IDENT.C */
extern struct cartridge_ident ident;

/* SYSTMR.C */
extern struct Times time;

/* EEPROM.C */
extern U16 EE_CHKS[cNumberOfBanks];
extern U16 EE_Valid;
extern U16 EE_par_update;
extern U16 EE_Bank1Valid;
extern U16 EE_Bank2Valid;

// debug
S16 debug_var_1 = 0;
/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/
const iolist iopar[] =
{  
//number name                         write_adress                               read_adress                             size type[4]  max            min passwd_write passwd_read scale
  /* STATEMACHINE.C */       
  {10,"SYS_CONTROL",                  (U16*)&SYS_CONTROL,                        (U16*)&SYS_CONTROL,                       2,"brr",    0xFFFFul,      0, 5,0,    1 },
  {11,"PC_CONTROL",                   (U16*)&PC_CONTROL,                         (U16*)&PC_CONTROL,                        2,"brr",    0xFFFFul,      0, 0,0,    1 },
  {12,"ERR_CONTROL",                  (U16*)&ERR_CONTROL,                        (U16*)&ERR_CONTROL,                       2,"brr",    0xFFFFul,      0, 5,0,    1 },
//{13,"Mainstate ST1",                (U16*)&mainstate_T1,                       (U16*)&mainstate_T1,                      2,"urr",    0xFFFFul,      0, 4,0,    1 },
//{14,"Mainstate ST2",                (U16*)&mainstate_T2,                       (U16*)&mainstate_T2,                      2,"urr",    0xFFFFul,      0, 4,0,    1 },
  //{15,"Prevstate ST2",              (U16*)&prevstate_T2,                       (U16*)&prevstate_T2,                      2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {16,"LCD Update Rate",              (U16*)&LCD_update_rate,                    (U16*)&LCD_update_rate,                   2,"unr",    0xFFFFul,      0, 0,0,    1 },
  /* TRACE.C */   
  {49,"TRACE CONTROL",                (U16 *)&trace_control,                     (U16 *)&trace_control,                    2,"brr",    0xFFFFul,      0, 0,0,    1 },
  {50,"TRACE CONFIG",                 (U16 *)&trace_config,                      (U16 *)&trace_config,                     2,"bnr",    0xFFFFul,      0, 0,0,    1 },
  {52,"STORE_POS",                    (U16 *)&STORE_POS,                         (U16 *)&STORE_POS,                        2,"urr",    0xFFFFul,      0, 5,0,    1 },   
  {53,"Trace Parameter Nr:1",         (U16 *)&u16TraceParamNumber_1,             (U16 *)&u16TraceParamNumber_1,            2,"unr",    0xFFFFul,      0, 0,0,    1 },   
  {54,"Trace Parameter Nr:2",         (U16 *)&u16TraceParamNumber_2,             (U16 *)&u16TraceParamNumber_2,            2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {55,"Compare Value",                (S16 *)&s16CmpValue,                       (S16 *)&s16CmpValue,                      2,"snr",    32767ul,  -32768, 0,0,    1 },
  {56,"TRACE STATE",                  (U16 *)&trace_state,                       (U16 *)&trace_state,                      2,"brr",    0xFFFFul,      0, 5,0,    1 }, 
  {57,"Compare Parameter Number",     (U16 *)&u16CompareParameter,               (U16 *)&u16CompareParameter,              2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {58,"Trace Parameter 1 Value =",    (S16 *)&par_trace.trace_display[0],        (S16 *)&par_trace.trace_display[0],       2,"srr",    32767ul,  -32768, 5,0,    1 }, 
  {59,"Trace Parameter 2 Value =",    (S16 *)&par_trace.trace_display[1],        (S16 *)&par_trace.trace_display[1],       2,"srr",    32767ul,  -32768, 5,0,    1 }, 
  {60,"Trace every period",           (U16 *)&trace_every_period,                (U16 *)&trace_every_period,               2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {61,"Trace array length",           (U16 *)&par_trace.trace_length,            (U16 *)&par_trace.trace_length,           2,"urr",    0xFFFFul,      0, 5,0,    1 },
  /* MEASURE.C*/   
  {146,"Transformer Voltage",         (U16 *)&mespar.Transformer_Voltage,        (U16 *)&mespar.Transformer_Voltage,       2,"unr",    0xFFFFul,      0, 0,0,    1 },
//{147,"empty",                       (U16 *)&empty,  (U16 *)&empty,                                                       2,"unr",    0xFFFFul,      0, 0,0,    0 },
//{148,"empty",                       (U16 *)&empty,  (U16 *)&empty,                                                       2,"unr",    0xFFFFul,      0, 0,0,    0 },
  {149,"Line Period Zero Cross",      (U16 *)&mes2.Line_period_zc_T2,            (U16 *)&mes2.Line_period_zc_T2,           2,"urr",    0xFFFFul,      0, 5,0,   10 },
  {150,"Curr offset",                 (U16 *)&mes1.Curr_offset,                  (U16 *)&mes1.Curr_offset,                 2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {151,"Current",                     (S16 *)&mes1.Current,                      (S16 *)&mes1.Current,                     2,"srr",    32767ul,  -32768, 5,0,    1 },
  {152,"Curr conv coeff",             (U16 *)&mespar.Curr_conv_coeff,            (U16 *)&mespar.Curr_conv_coeff,           2,"unr",    0xFFFFul,      0, 0,0, 1024 },
  {153,"Overcurrent limit",           (U16 *)&mespar.Overcurr_limit,             (U16 *)&mespar.Overcurr_limit,            2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {154,"Line Frequency (zero cross)", (U16 *)&mes2.Line_frequency_zc,            (U16 *)&mes2.Line_frequency_zc,           2,"urr",    0xFFFFul,      0, 5,0,    6 },
//{155,"empty",                       (U16 *)&empty,                             (U16 *)&empty,                            2,"urr",    0xFFFFul,      0, 5,0,0},
  {156,"Actual Power",                (U16 *)&mes2.Actaul_Power,                 (U16 *)&mes2.Actaul_Power,                2,"urr",    0xFFFFul,      0, 5,0,    0 },
  /* ADC.C */   
  {160,"ADC[0]",                      (U16 *)&ADC[AdcCh_0],                      (U16 *)&ADC[AdcCh_0],                     2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {161,"ADC[1]",                      (U16 *)&ADC[AdcCh_1],                      (U16 *)&ADC[AdcCh_1],                     2,"urr",    0xFFFFul,      0, 5,0,    1 },
 /* SYSTMR.C */   
  {170,"Hib Min",                     (U16 *)&time.min,                          (U16 *)&time.min,                         2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {171,"Hib Sec",                     (U16 *)&time.sec,                          (U16 *)&time.sec,                         2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {172,"Hib Time",                    (U16 *)&time.Hib_Time,                     (U16 *)&time.Hib_Time,                    2,"unr",    0xFFFFul,      0, 0,0,    1 },
 /* IDENT.C */   
  {200,"U_Temp_in",                   (U16 *)&ident.U_Temp_in,                   (U16 *)&ident.U_Temp_in,                  2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {201,"U_Temp_out",                  (U16 *)&ident.U_Temp_out,                  (U16 *)&ident.U_Temp_out,                 2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {202,"U_Temp_delta",                (S16 *)&ident.U_Temp_delta,                (S16 *)&ident.U_Temp_delta,               2,"srr",    32767ul,  -32768, 5,0,    1 },
  {204,"Ident_periods_current",       (U16 *)&ident.ident_periods,               (U16 *)&ident.ident_periods,              2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {206,"Load Ident Periods",          (U16 *)&ident.ident_periods_load,          (U16 *)&ident.ident_periods_load,         2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {207,"U_Temp_delta trip low raw",   (U16 *)&ident.ident_deltaT_trip_low,       (U16 *)&ident.ident_deltaT_trip_low,      2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {208,"ident Overcurrent Trip",      (U16 *)&ident.ident_current_trip,          (U16 *)&ident.ident_current_trip,         2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {209,"Ident Peak Current",          (U16 *)&ident.Ident_peak_current,          (U16 *)&ident.Ident_peak_current,         2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {211,"Ident Max RMS Power",         (U16 *)&ident.IDENT_MAX_RMS_Power,         (U16 *)&ident.IDENT_MAX_RMS_Power,        2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {212,"U_Temp_delta trip high raw",  (U16 *)&ident.ident_deltaT_trip_high,      (U16 *)&ident.ident_deltaT_trip_high,     2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {213,"ident current 2210 low",      (U16 *)&ident.ident_cur_2210_low,          (U16 *)&ident.ident_cur_2210_low,         2,"unr",    15000ul,       0, 0,0,    1 },
  {214,"ident current 2210 high",     (U16 *)&ident.ident_cur_2210_high,         (U16 *)&ident.ident_cur_2210_high,        2,"unr",    15000ul,       0, 0,0,    1 },
  {215,"ident current 2245 low",      (U16 *)&ident.ident_cur_2245_low,          (U16 *)&ident.ident_cur_2245_low,         2,"unr",    15000ul,       0, 0,0,    1 },
  {216,"ident current 2245 high",     (U16 *)&ident.ident_cur_2245_high,         (U16 *)&ident.ident_cur_2245_high,        2,"unr",    15000ul,       0, 0,0,    1 },
  {217,"ident tool",                  (U8 * )&ident.IdentTool,                   (U8  *)&ident.IdentTool,                  1,"urr",    0xFFul,        0, 5,0,    1 },
  {218,"Ident Current",               (U16 *)&ident.Ident_current,               (U16 *)&ident.Ident_current,              2,"urr",    0xFFFFul,      0, 5,0,    1 },
     
 /* TMPCTRL.C */                                                                                                                                      
  {250,"Temp Ref User (Real)",        (U16 *)&T_ctrl.T_Ref_User,                 (U16 *)&T_ctrl.T_Ref_User,                2,"unr",    450ul,         0, 0,0,    1 },
  {251,"Temp Ref User Sleep (Real)",  (U16 *)&T_ctrl.T_Ref_User_Sleep,           (U16 *)&T_ctrl.T_Ref_User_Sleep,          2,"unr",    450ul,         0, 0,0,    1 },
  {252,"TMPCTRL Sample Time",         (U16 *)&T_ctrl.tmpctrl_samp_time,          (U16 *)&T_ctrl.tmpctrl_samp_time,         2,"unr",    100ul,        10, 0,0,    1 },
  {253,"Temp Calibration Gain",       (U16 *)&T_ctrl.T_cal_gain,                 (U16 *)&T_ctrl.T_cal_gain,                2,"unr",    32767ul,       0, 0,0, 1024 },
  {254,"Overload Periods Trip",       (U16 *)&overprot.cop_periods_trip,         (U16 *)&overprot.cop_periods_trip,        2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {255,"Overload Time Trip",          (U16 *)&overprot.cop_time_trip_sec,        (U16 *)&overprot.cop_time_trip_sec,       2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {256,"Temp Feedback",               (U16 *)&T_ctrl.T_fbk,                      (U16 *)&T_ctrl.T_fbk,                     2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {257,"Temp Delta",                  (S16 *)&T_ctrl.T_delta,                    (S16 *)&T_ctrl.T_delta,                   2,"srr",    32767ul,  -32768, 5,0,    1 },
  {258,"Heat Periods",                (S16 *)&T_ctrl.heat_periods,               (S16 *)&T_ctrl.heat_periods,              2,"srr",    32767ul,  -32768, 5,0,    1 },
  {260,"heat_periods_debug",          (S16 *)&T_ctrl.heat_periods_debug,         (S16 *)&T_ctrl.heat_periods_debug,        2,"srr",    32767ul,  -32768, 0,0,    1 },
  {261,"Triac State",                 (U16 *)&T_ctrl.tmpctrl_triac_state,        (U16 *)&T_ctrl.tmpctrl_triac_state,       2,"urr",    0xFFFFul,      0, 5,0,    1 },
//{262,"TMPCTRL State",               (U16 *)&tmpctrl_mainstate,                 (U16 *)&tmpctrl_mainstate,                2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {264,"Temp Calibration Offset",     (S16 *)&T_ctrl.T_cal_offset,               (S16 *)&T_ctrl.T_cal_offset,              2,"snr",    50ul,        -50, 0,0,    1 },
  {265,"Bresenham distribution",      (U8 * )&T_ctrl.bresenham_distribution,     (U8  *)&T_ctrl.bresenham_distribution,    1,"unr",    1,             0, 0,0,    1 },
  {266,"Set Temperature Step",        (U8 * )&T_ctrl.T_UserStep,                 (U8  *)&T_ctrl.T_UserStep,                1,"unr",    50,            1, 0,0,    1 },
  //PID Controller   
  {280,"Kp",                          (U16 *)&PID_C245ToolPid_Cfg.Kp,            (U16 *)&PID_C245ToolPid_Cfg.Kp,            2,"unr",    0xFFFFul,             0, 0,0,    1 },
  {281,"Ki2 [Ki*dt]",                 (U16 *)&PID_C245ToolPid_Cfg.Ki2,           (U16 *)&PID_C245ToolPid_Cfg.Ki2,           2,"unr",    0xFFFFul,             0, 0,0,    1 },
  {282,"Kd2 [Kd/dt]",                 (U16 *)&PID_C245ToolPid_Cfg.Kd2,           (U16 *)&PID_C245ToolPid_Cfg.Kd2,           2,"unr",    0xFFFFul,             0, 0,0,    1 },
  {283,"P term Scale [1<<(15+X)]",    (U8  *)&PID_C245ToolPid_Cfg.P_term_scale,  (U8  *)&PID_C245ToolPid_Cfg.P_term_scale,  2,"unr",    15,                   0, 0,0,    1 },
  {284,"Fbk Filter [ms]",             (U16 *)&PID_C245ToolPid_Cfg.Fbk_Filt_ms,   (U16 *)&PID_C245ToolPid_Cfg.Fbk_Filt_ms,   2,"unr",    10000,        (1+2*110), 0,0,    1 },
  {285,"Out Filter [ms]",             (U16 *)&PID_C245ToolPid_Cfg.Out_Filt_ms,   (U16 *)&PID_C245ToolPid_Cfg.Out_Filt_ms,   2,"unr",    10000,        (1+2*110), 0,0,    1 },
  {286,"Integral",                    (S32 *)&PID_C245ToolPid_Data.Integral.x,   (S32 *)&PID_C245ToolPid_Data.Integral.x,   4,"srr",    2147483647, -2147483647, 5,0,    1 },
  {287,"Integral Saturation",         (S8  *)&PID_C245ToolPid_Data.Integral.sat, (S8  *)&PID_C245ToolPid_Data.Integral.sat, 1,"srr",    1,                   -1, 5,0,    1 },
#if PID_DEBUG != 0
  {288,"Output Period [ms]",          (S16 *)&PID_C245ToolPid_Data.OutPeriod,    (S16 *)&PID_C245ToolPid_Data.OutPeriod,    2,"srr",    32767ul,         -32768, 5,0,    1 },
  {289,"Overshoot_pos",               (S16 *)&PID_C245ToolPid_Data.Overshoot_pos,(S16 *)&PID_C245ToolPid_Data.Overshoot_pos,2,"srr",    32767ul,         -32768, 5,0,    1 },
  {290,"Overshoot_neg",               (S16 *)&PID_C245ToolPid_Data.Overshoot_neg,(S16 *)&PID_C245ToolPid_Data.Overshoot_neg,2,"srr",    32767ul,         -32768, 5,0,    1 },
#endif
  /* TASK */  
  {900,"Task1 Time",                  (U32 *)&Ttime.Task1Time_us,                (U32 *)&Ttime.Task1Time_us,               4,"urr",    0xFFFFFFFFul,  0, 5,0, 1000 },
  {901,"Task2 Time",                  (U32 *)&Ttime.Task2Time_us,                (U32 *)&Ttime.Task2Time_us,               4,"urr",    0xFFFFFFFFul,  0, 5,0, 1000 },
  {911,"Task1 Max Time",              (U32 *)&Ttime.Task1MaxTime_us,             (U32 *)&Ttime.Task1MaxTime_us,            4,"urr",    0xFFFFFFFFul,  0, 0,0, 1000 },
  {912,"Task2 Max Time",              (U32 *)&Ttime.Task2MaxTime_us,             (U32 *)&Ttime.Task2MaxTime_us,            4,"urr",    0xFFFFFFFFul,  0, 0,0, 1000 },
  /* Station Statistics */   
  {902,"Operation Time - Hours",      (U32 *)&stat_stat.OpTime_Hours,            (U32 *)&stat_stat.OpTime_Hours,           4,"unr",    0xFFFFFFFFul,  0, 4,0,    1 },
  {903,"Operation Time - Minutes",    (U16 *)&stat_stat.OpTime_Minutes,          (U16 *)&stat_stat.OpTime_Minutes,         2,"unr",    59ul,          0, 4,0,    1 },
  {904,"Cartridge Stand Counter",     (U32 *)&stat_stat.Cart_Stand_Counter,      (U32 *)&stat_stat.Cart_Stand_Counter,     4,"unr",    0xFFFFFFFFul,  0, 4,0,    1 },
  {905,"Cartridge Change Counter",    (U32 *)&stat_stat.Cart_Change_Counter,     (U32 *)&stat_stat.Cart_Change_Counter,    4,"unr",    0xFFFFFFFFul,  0, 4,0,    1 },
  /* debug */   
  {910,"debug_var_1",                 (S16 *)&debug_var_1,                       (S16 *)&debug_var_1,                      2,"srr",    32767ul,  -32768, 0,0,    1 },
  /* EEPROM.C */                                                                                                                                                   
  {949,"EEPROM Checksum bank 1",      (U16 *)&EE_CHKS[0],                        (U16 *)&EE_CHKS[0],                       2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {950,"EEPROM Checksum bank 2",      (U16 *)&EE_CHKS[1],                        (U16 *)&EE_CHKS[1],                       2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {951,"EEPROM Valid (1000)",         (U16 *)&EE_Valid,                          (U16 *)&EE_Valid,                         2,"unr",    0xFFFFul,      0, 0,0,    1 },
  {952,"EEPROM Update (Debug)",       (U16 *)&EE_par_update,                     (U16 *)&EE_par_update,                    2,"urr",    0xFFFFul,      0, 5,0,    1 },
  {953,"EEPROM ActiveBank",           (BOOL *)&ParamAct.bActiveBank,             (BOOL *)&ParamAct.bActiveBank,            1,"urr",    0xFFFFul,      0, 5,0,    1 },
  {995,"Compiled with C30 VERSION",   (U16 *)&C30_Version,                       (U16 *)&C30_Version,                      2,"uoo",    65535u ,       0, 0,0,  100 },
  {996,__TIME__,                      (U16 *)&release,                           (U16 *)&release,                          2,"uoo",    65535u ,       0, 0,0,    1 },
  {997,__DATE__,                      (U16 *)&release,                           (U16 *)&release,                          2,"uoo",    65535u ,       0, 0,0,    1 },
  /* Soft Version */      
  {998,"Release",                     (U16 *)&release,                           (U16 *)&release,                          2,"unr",    65535u ,       0, 0,0,    1 },
  {999,"Version",                     (U16 *)&version,                           (U16 *)&version,                          2,"uoo",    65535u ,       0, 5,0,  100 },
  {  0,"",                            NULL,                                      NULL,                                     0,"srr",    0u ,           0, 0,1,    1 }
};
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
/*
* Purpose: Get nimber of parameters
* Output:  return number of params in system
*/
/******************************************************************************/
U16 IF_Parlist_GetCntMembers(void)
{
    return( sizeof(iopar)/sizeof(iopar[0]) );
}

/******************************************************************************/
/*
* Purpose: Get bytes of "iopar" structure
* Output:  return number bytes
*/
/******************************************************************************/
U16 IF_Parlist_GetCntBytes(void)
{
    return( sizeof(iopar) );
}

/******************************************************************************/
/*
* Purpose: Get desired param number
* Output:  return pointer to desired parameter
*/
/******************************************************************************/
iolist* IF_Parlist_bnu(U16 U32PrmNumber)
{
    iolist* pio;

    // get pointer to current parameter
    for( pio=(iolist*)iopar; (0 != pio->number) && (U32PrmNumber != pio->number); pio++ )
        ;
    
    return(pio);
}
/******************************************************************************/
/*
* Purpose: Get number of parameters stored in EEPROM
* Output:  return pointer to desired parameter
*/
/******************************************************************************/


/******************************************************************************/
/*
 * Purpose: Checking for parameters limit. Check critical parameters for correct values. Run in background loop in main.c
 * Inputs:  none
 * Output:    none
 */
/******************************************************************************/
void Params_check_limit(void)
{
    
    if(EE_Valid != 1000)                  _set_ee_valid_error(1);
    if(time.Hib_Time == 0)                _set_param_limit_error(1);
    if(T_ctrl.T_Ref_User > TEMP_USER_MAX) _set_param_limit_error(1);
    if((T_ctrl.tmpctrl_samp_time == 0) || (T_ctrl.tmpctrl_samp_time > 50)) _set_param_limit_error(1);
    if(T_ctrl.T_cal_gain < 10) _set_param_limit_error(1);
}
/******************************************************************************/
/*
 * Purpose: Parameters conversion. Called every TASK 2.
 * Inputs:  none
 * Output:    none
 */
/******************************************************************************/
void Params_Conversion(void)
{








}




