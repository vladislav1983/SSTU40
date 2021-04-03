/* 
 * File:   RotaryEncoder_cfg.h
 * Author: GYV1SF4
 *
 * Created on April 1, 2021, 10:08 PM
 */

#ifndef ROTARYENCODER_CFG_H
#define  ROTARYENCODER_CFG_H

#ifdef  __cplusplus
extern "C"
{
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "stddef.h"
#include "stdint.h"
#include "stdbool.h"
#include "DigitalIoCfg.h"
#include "RotaryEncoderTypes.h"
 
 /*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
#define ROTARY_ENCODER_POLLING_TIME_us    100u
#define ROTARY_ENCODER_DEBOUNCE_TIME_us   2000u 
 
/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/
typedef enum
{
  eROTARY_ENCODERS_0 = 0,
  eROTARY_ENCODERS_NUM
}teRotaryEncoderCfg;

typedef enum
{
  eROTARY_CLIENT_0 = 0,
  eROTARY_CLIENTS_NUM
}teRotaryEncoderClientCfg;

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
extern const teRotaryEncoderCfg EncoderClient_cfg[eROTARY_CLIENTS_NUM];

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                                         */
/*----------------------------------------------------------------------------*/
 extern void RotaryEncoder_cfg_InitPins(void);
 extern void RotaryEncoder_cfg_ReadPins(uint8_t EncoderIndex, tRotaryInputs * inputs);
 
#ifdef  __cplusplus
}
#endif

#endif  /* ROTARYENCODER_CFG_H */

