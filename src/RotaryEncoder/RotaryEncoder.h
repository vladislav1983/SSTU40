/* 
 * File:   RotaryEncoder.h
 * Author: GYV1SF4
 *
 * Created on March 30, 2021, 10:20 AM
 */

#ifndef ROTARYENCODER_H
#define  ROTARYENCODER_H

#ifdef  __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "RotaryEncoder_cfg.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
#define ROTARY_ENCODER_PIN_A_SHIFT        0u
#define ROTARY_ENCODER_PIN_B_SHIFT        1u
#define ROTARY_ENCODER_PIN_PUSH_SHIFT     2u

#define ROTARY_ENCODER_PIN_A_MASK         (1u << ROTARY_ENCODER_PIN_A_SHIFT)
#define ROTARY_ENCODER_PIN_B_MASK         (1u << ROTARY_ENCODER_PIN_B_SHIFT)
#define ROTARY_ENCODER_PIN_PUSH_MASK      (1u << ROTARY_ENCODER_PIN_PUSH_SHIFT)
 
 
/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/
#define ENCODER_GET_VALUE(bitmap, mask, shift)       ((bitmap & mask) >> shift)
#define ENCODER_SET_VALUE(bitmap, val, mask, shift)  (bitmap = (bitmap & ~mask) | ((val << shift) & mask))
 
/*----------------------------------------------------------------------------*/
/* Exported functions                                                         */
/*----------------------------------------------------------------------------*/
extern void RotaryEncoder_Init(void);    
extern void RotaryEncoder_Scan_T1(void);
extern teRotaryEncoderState RotaryEncoder_ConsumeStateEvent(teRotaryEncoderClientCfg client);

#ifdef  __cplusplus
}
#endif

#endif  /* ROTARYENCODER_H */

