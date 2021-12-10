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
#ifdef DIGITALIO_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define DIGITALIO_C
#endif

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "DigitalIO.h"
#include "statemachine.h"
#if defined(ROTARY_ENCODER_USED) 
#include "RotaryEncoder.h"
#endif

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/  
#define DEBOUNCE_TIME_T2          5        // Debounce time in task2 periods. 5*5ms = 25ms. Used for user buttons.
#define DEBOUNCE_TIME_STAND       10       // Debounce time in line periods  10*10ms = 100ms. 
#define DEBOUNCE_TIME_CART        10       // Debounce time in line periods  10*10ms = 100ms. 
#define DEBOUNCE_TIME_EXTR        10       // Debounce time in line periods  10*10ms = 50ms.

#define CARTRIDGE_DETECTION_TIMEOUT        95    //task1 periods
/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
U16 debounce_timer_2;

U16 deb_timer_cart;
U16 deb_timer_stand;
U16 deb_timer_extr;

U16 cart_det_state;

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/
U16 cart_stat_timer_T1(U16 cmd, U16 cons);


/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*
 * Name:    IF_DigitalIO_Init
 * Purpose: Digital IO init
 */
/******************************************************************************/
void IF_DigitalIO_Init(void)
{   
  pinLCD_DB4 = 0;        pinLCD_DB4_dir = 0;     //output,0
  pinLCD_DB5 = 0;        pinLCD_DB5_dir = 0;     //output,0
  pinLCD_DB6 = 0;        pinLCD_DB6_dir = 0;     //output,0
  pinLCD_DB7 = 0;        pinLCD_DB7_dir = 0;     //output,0
  pinLCD_RS = 0;        pinLCD_RS_dir = 0;         //output,0
  pinLCD_E = 0;        pinLCD_E_dir = 0;         //output,0
  
  pinTH_FIRE = 0;        pinTH_FIRE_dir = 0;        //output,0
  pinMES_EN = 1;         pinMES_EN_dir = 0;        //output,1
  pinLED = 1;            pinLED_dir = 0;            //output,1 //Light User Led
  
  pinSTAT_DET    = 0;    pinSTAT_DET_dir    =0;        //output,0
#if !defined(ROTARY_ENCODER_USED)    
  pinBUT_SEL_dir = 1;    //input
  pinBUT_UP_dir = 1;    //input
  pinBUT_DOWN_dir = 1;//input
#endif
  pinEXTR_dir = 1;    //input
  pinSTAND_dir = 1;    //input
  pinCART_STAT = 1;    //input
  
  pinZC_dir = 1;        //input
  
  /* Load debounce timers */
  debounce_timer_2 = DEBOUNCE_TIME_T2;
  deb_timer_cart = DEBOUNCE_TIME_CART;
  deb_timer_stand = DEBOUNCE_TIME_STAND;
  deb_timer_extr = DEBOUNCE_TIME_EXTR;
  
  cart_det_state = CART_DET_SCAN_INIT;
  
  /* Setup Interrupt at INT0 */
  _INT0IP = cISR_PRIORITY_INT0; 
  _INT0EP = INT0_FALLING_EDGE;
  _INT0IE = 1;                    //Interrupt Enable
  _INT0IF = 0;                    //Clear INT flag
  
  
  
}
extern S16 debug_var_1;
/******************************************************************************/
/*
 * Name:    User Button scan in task 2.  5ms 
 * Purpose: Digital IO scan. Input active when 0. We do not allow more than one button pushed.
 * Affected system flasgs:
 * - _select_button_pushed()    
 * - _up_button_pushed()
 * - _down_button_pushed()
 * NOTES FOR SSTU. CHANGES DEPEND BUTTONS USED!!!
 * SELECT BUTTON: 1: NOT PUSHED 0: PUSHED
 * UP BUTTON : 1: PUSHED 0: NOT PUSHED
 * DOWN BUTTON: 1: PUSHED 0: NOT PUSHED
 *
 */
/******************************************************************************/
void Dio_Scan_T2(void)
{
#if defined(ROTARY_ENCODER_USED)
  teRotaryEncoderState state;
  
  state = RotaryEncoder_ConsumeStateEvent(eROTARY_CLIENT_0);
  
  if(state == eRoratyCW)
  {
    _set_up_button(1);
    debug_var_1++;
  }
  else if(state == eRoratyCCW)
  {
    _set_down_button(1);
    debug_var_1--;
  }
  else if(state == eRotaryPush)
  {
    _set_select_button(1);
    debug_var_1 = 0;
  }
  else
  {
    _set_up_button(0);
    _set_down_button(0);
    _set_select_button(0);
  }
  
#else
  /* Scan select button */
  if(!pinBUT_SEL && pinBUT_UP && pinBUT_DOWN) //if SELECT button is pushed AND no others
  {
    debounce_timer_2--;
    if(debounce_timer_2 == 0)
    {
      debounce_timer_2 = DEBOUNCE_TIME_T2;
      _set_select_button(1);
      return;
    }
  }
  else 
  {
    _set_select_button(0);
  }
  
  if(pinBUT_SEL && !pinBUT_UP && pinBUT_DOWN)
  {
    debounce_timer_2--;
    if(debounce_timer_2 == 0)
    {
      debounce_timer_2 = DEBOUNCE_TIME_T2;
      _set_up_button(1);
      return;
    }
  }
  else 
  {
    _set_up_button(0);
  }
  
  if(pinBUT_SEL && pinBUT_UP && !pinBUT_DOWN)
  {
    debounce_timer_2--;
    if(debounce_timer_2 == 0)
    {
      debounce_timer_2 = DEBOUNCE_TIME_T2;
      _set_down_button(1);
      return;
    }
  }
  else 
  {
    _set_down_button(0);
  }
  
  if(pinBUT_SEL && pinBUT_UP && pinBUT_DOWN) 
  {
    debounce_timer_2 = DEBOUNCE_TIME_T2;
  }
#endif
}


/******************************************************************************/
/*
 * Purpose: Cartridge status detection. Run in zero cross.
 * Inputs:  none
 * Output:  none
 * Affected system flags:
 * - _extractor()
 * - _stand()
 * - _cartridge_present()
 */
/******************************************************************************/
void cart_stat_det(void)
{
  switch(cart_det_state)
    /*------------------------*/
  {
    case CART_DET_SCAN_INIT:
      cart_stat_timer_T1(1, CARTRIDGE_DETECTION_TIMEOUT);
      cart_det_state = CART_DET_SCAN_ZERO_CROSS;
      break;
      /*------------------------*/    
    case CART_DET_SCAN_ZERO_CROSS:
      if(_zero_cross() && !_triac_state())
      {
        cart_stat_timer_T1(1, CARTRIDGE_DETECTION_TIMEOUT);
        cart_det_state = CART_DET_WAIT_STATE;
      }    
      break;
      /*------------------------*/
    case CART_DET_SCAN_CARTRIDGE:
      if(!pinEXTR && pinSTAND)
      {
        deb_timer_extr--;
        if(deb_timer_extr == 0)
        {
          _set_extractor(1);
          deb_timer_extr = DEBOUNCE_TIME_EXTR;
        }
      }    
      else
      {
        _set_extractor(0);
        deb_timer_extr = DEBOUNCE_TIME_EXTR;
      }
      
      if(pinEXTR && !pinSTAND)
      {
        deb_timer_stand--;
        if(deb_timer_stand == 0)
        {
          _set_stand(1);
          deb_timer_stand = DEBOUNCE_TIME_STAND;
        }
      }    
      else
      {
        _set_stand(0);
        deb_timer_stand = DEBOUNCE_TIME_STAND;
      }
      
      if(!pinCART_STAT)
      {
        deb_timer_cart--;
        if(deb_timer_cart == 0)
        {
          _set_cartridge_present(1);
          deb_timer_cart = DEBOUNCE_TIME_CART;
        }
      }
      else
      {
        _set_cartridge_present(0);
        deb_timer_cart = DEBOUNCE_TIME_CART;
      }
      
      pinMES_EN = 1;
      
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      Nop();
      
      pinSTAT_DET = 0;
      
      cart_det_state = CART_DET_SCAN_ZERO_CROSS;
      break;
      /*------------------------*/
    case CART_DET_WAIT_STATE:
      cart_stat_timer_T1(2, 0);
      
      if(!cart_stat_timer_T1(0, 0))
      {
        pinMES_EN = 0;
        
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        
        pinSTAT_DET = 1;
        
        cart_det_state = CART_DET_SCAN_CARTRIDGE;
      }
      break;
      /*------------------------*/
      
    default:
      _set_global_system_fault(1);
      break;
  }
}
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/*
 * Name: 
 * Params: 
 * cmd: 0 read, 1 start, 2 count 
 * cons: count time in task periods
 * Purpose:   
 * 
 *  cmd: 0 read, 1 start, 2 count 
 *  cons: count time in task periods
 */
/******************************************************************************/
U16 cart_stat_timer_T1(U16 cmd, U16 cons)               
{         
  static U16 count;
  
  if(cmd==1)    count = cons;    
  else if(count && cmd==2) count--;
  return(count);
}
