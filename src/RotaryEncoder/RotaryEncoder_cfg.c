/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "RotaryEncoder_cfg.h"
#include "RotaryEncoder.h"

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

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/
const teRotaryEncoderCfg EncoderClient_cfg[eROTARY_CLIENTS_NUM] = 
{
  eROTARY_ENCODERS_0
};

const teRotaryEncoderPinsPolarity RotaryEncoderPinsPolarity_cfg[eROTARY_ENCODERS_NUM] = 
{
  eRotaryPolarityInverted
};

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Local function prototypes                                                  */
/*----------------------------------------------------------------------------*/

/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*              E X P O R T E D      F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
void RotaryEncoder_cfg_InitPins(void)
{
  // rotary encoder 1 pins init
  pinROTARY_PUSH_dir = 1; //input
  pinROTARY_A_dir = 1;
  pinROTARY_B_dir = 1;
}

/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
uint8_t RotaryEncoder_cfg_ReadPins(uint8_t EncoderIndex)
{
  uint8_t inputs = 0;
  uint8_t pin = 0;
  
  if(EncoderIndex < eROTARY_ENCODERS_NUM)
  {
    pin = !pinROTARY_A ^ RotaryEncoderPinsPolarity_cfg[EncoderIndex];
    ENCODER_SET_VALUE(inputs, pin,    ROTARY_ENCODER_PIN_A_MASK,    ROTARY_ENCODER_PIN_A_SHIFT);
    
    pin = !pinROTARY_B ^ RotaryEncoderPinsPolarity_cfg[EncoderIndex];
    ENCODER_SET_VALUE(inputs, pin,    ROTARY_ENCODER_PIN_B_MASK,    ROTARY_ENCODER_PIN_B_SHIFT);
    
    pin = !pinROTARY_PUSH ^ RotaryEncoderPinsPolarity_cfg[EncoderIndex];
    ENCODER_SET_VALUE(inputs, pin, ROTARY_ENCODER_PIN_PUSH_MASK, ROTARY_ENCODER_PIN_PUSH_SHIFT);
  }
  
  return inputs;
}
