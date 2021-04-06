/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "RotaryEncoder.h"
#include "RotaryEncoder_cfg.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/
//   - Quadrature encoder makes two waveforms that are 90° out of phase:
//                           _______         _______         __
//                  PinA ___|       |_______|       |_______|   PinA
//          CCW <--              _______         _______
//                  PinB _______|       |_______|       |______ PinB
//                               _______         _______
//                  PinA _______|       |_______|       |______ PinA
//          CW  -->          _______         _______         __
//                  PinB ___|       |_______|       |_______|   PinB
//                           ^   ^   ^   ^    
//                           |   |   |   |
//                           +---+---+---+---> sampling pints for one detent / 4 edges

#define R_TRANSITION_MASK       0x0F 

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/
#define ROTARY_ENCODER_STATES_SIZE      ( sizeof(RotaryEncoderStates)/sizeof(teRotaryEncoderState) )
#define ROTARY_ENCODER_DEBOUNCE_TIME    (ROTARY_ENCODER_DEBOUNCE_TIME_us/ROTARY_ENCODER_POLLING_TIME_us)  

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
typedef struct 
{
  uint8_t Inputs;
  uint8_t InputsDebounced;
  teRotaryEncoderState State;
  uint8_t  CurrentState;
  uint16_t debounce_timer_a;
  uint16_t debounce_timer_b;
  uint16_t debounce_timer_push;
}tRotaryEncoder;

typedef enum
{
  eSTART         = 0x00,
  eCW_FINAL      = 0x01,
  eCW_BEGIN      = 0x02,
  eCW_NEXT       = 0x03,
  eCCW_BEGIN     = 0x04,
  eCCW_FINAL     = 0x05,
  eCCW_NEXT      = 0x06,
  eSUB_STATES_NR = 0x07
}reRotaryEncoderSubStates;

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
static bool RotaryEncoder_InitState = false;

tRotaryEncoder RotaryEncoder[eROTARY_ENCODERS_NUM] = 
{
  {
    .Inputs              = 0,
    .InputsDebounced     = 0,
    .State               = eRoratyStopIdle,
    .CurrentState        = eSTART,
    .debounce_timer_a    = ROTARY_ENCODER_DEBOUNCE_TIME,
    .debounce_timer_b    = ROTARY_ENCODER_DEBOUNCE_TIME,
    .debounce_timer_push = ROTARY_ENCODER_DEBOUNCE_TIME,  
  }
};

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/
static const uint8_t EncoderTruthTable[eSUB_STATES_NR][4] = 
{
  // 00        01           10           11
  {eSTART,    eCW_BEGIN,  eCCW_BEGIN, eSTART              },  // R_START
  {eCW_NEXT,  eSTART,     eCW_FINAL,  eSTART | eRoratyCW  },  // R_CW_FINAL
  {eCW_NEXT,  eCW_BEGIN,  eSTART,     eSTART              },  // R_CW_BEGIN
  {eCW_NEXT,  eCW_BEGIN,  eCW_FINAL,  eSTART              },  // R_CW_NEXT
  {eCCW_NEXT, eSTART,     eCCW_BEGIN, eSTART              },  // R_CCW_BEGIN
  {eCCW_NEXT, eCCW_FINAL, eSTART,     eSTART | eRoratyCCW },  // R_CCW_FINAL
  {eCCW_NEXT, eCCW_FINAL, eCCW_BEGIN, eSTART              }   // R_CCW_NEXT
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
static void RotaryEncoder_ReadPins(void)
{
  uint16_t i;
  
  for (i = 0; i < eROTARY_ENCODERS_NUM; i++)
  {
    RotaryEncoder[i].Inputs = RotaryEncoder_cfg_ReadPins(i);
  }
}

/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
static void RotaryEncoder_DebouncePins(void)
{
  tRotaryEncoder * re = NULL;
  uint16_t i;
  uint8_t input;
  uint8_t input_deb;
  
  for(i = 0; i < eROTARY_ENCODERS_NUM; i++)
  {
    re = &RotaryEncoder[i];
    
    // rotary encoder input a
    input     = ENCODER_GET_VALUE(re->Inputs,          ROTARY_ENCODER_PIN_A_MASK, ROTARY_ENCODER_PIN_A_SHIFT);
    input_deb = ENCODER_GET_VALUE(re->InputsDebounced, ROTARY_ENCODER_PIN_A_MASK, ROTARY_ENCODER_PIN_A_SHIFT);
    
    if(input != input_deb)
    {
      if((re->debounce_timer_a--) == 0u)
      {
        ENCODER_SET_VALUE(re->InputsDebounced, input, ROTARY_ENCODER_PIN_A_MASK, ROTARY_ENCODER_PIN_A_SHIFT);
        re->debounce_timer_a = ROTARY_ENCODER_DEBOUNCE_TIME;
      }
    }
    else
    {
      re->debounce_timer_a = ROTARY_ENCODER_DEBOUNCE_TIME;
    }
    
    // rotary encoder input b
    input     = ENCODER_GET_VALUE(re->Inputs,          ROTARY_ENCODER_PIN_B_MASK, ROTARY_ENCODER_PIN_B_SHIFT);
    input_deb = ENCODER_GET_VALUE(re->InputsDebounced, ROTARY_ENCODER_PIN_B_MASK, ROTARY_ENCODER_PIN_B_SHIFT);
    
    if(input != input_deb)
    {
      if((re->debounce_timer_b--) == 0u)
      {
        ENCODER_SET_VALUE(re->InputsDebounced, input, ROTARY_ENCODER_PIN_B_MASK, ROTARY_ENCODER_PIN_B_SHIFT);
        re->debounce_timer_b = ROTARY_ENCODER_DEBOUNCE_TIME;
      }
    }
    else
    {
      re->debounce_timer_b = ROTARY_ENCODER_DEBOUNCE_TIME;
    }
    
    // rotary encoder input push
    input     = ENCODER_GET_VALUE(re->Inputs,          ROTARY_ENCODER_PIN_PUSH_MASK, ROTARY_ENCODER_PIN_PUSH_SHIFT);
    input_deb = ENCODER_GET_VALUE(re->InputsDebounced, ROTARY_ENCODER_PIN_PUSH_MASK, ROTARY_ENCODER_PIN_PUSH_SHIFT);
    
    if(input != input_deb)
    {
      if((re->debounce_timer_push--) == 0u)
      {
        ENCODER_SET_VALUE(re->InputsDebounced, input, ROTARY_ENCODER_PIN_PUSH_MASK, ROTARY_ENCODER_PIN_PUSH_SHIFT);
        re->debounce_timer_push = ROTARY_ENCODER_DEBOUNCE_TIME;
      }
    }
    else
    {
      re->debounce_timer_push = ROTARY_ENCODER_DEBOUNCE_TIME;
    }
  }
}

/******************************************************************************/
/*                                                                            */
/*              E X P O R T E D      F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
void RotaryEncoder_Init(void)
{
  RotaryEncoder_InitState = true;
  RotaryEncoder_cfg_InitPins();
}

/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
void RotaryEncoder_Scan_T1(void)
{
  uint16_t i;
  tRotaryEncoder * re = NULL;

  for (i = 0; i < eROTARY_ENCODERS_NUM && RotaryEncoder_InitState == 1; i++)
  {
    RotaryEncoder_ReadPins();
    RotaryEncoder_DebouncePins ();
    
    re = &RotaryEncoder[i];
    
    if(ENCODER_GET_VALUE(re->InputsDebounced, ROTARY_ENCODER_PIN_PUSH_MASK, ROTARY_ENCODER_PIN_PUSH_SHIFT))
    {
      re->State = eRotaryPush;
    }
    
    uint8_t state_index = re->CurrentState & R_TRANSITION_MASK;
    uint8_t pin_index   = re->InputsDebounced & (ROTARY_ENCODER_PIN_B_MASK | ROTARY_ENCODER_PIN_A_MASK);
    re->CurrentState    = EncoderTruthTable[state_index][pin_index];
    
    // check that state is consumed, so it can be updated
    if(re->State == eRoratyStopIdle)
    {
      re->State |= re->CurrentState & (eRoratyCW | eRoratyCCW);
    }
  }
}

/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
teRotaryEncoderState RotaryEncoder_ConsumeStateEvent(teRotaryEncoderClientCfg client)
{
  teRotaryEncoderState state = eRoratyStopIdle;
  
  if(client < eROTARY_CLIENTS_NUM)
  {
    state = RotaryEncoder[EncoderClient_cfg[client] % eROTARY_ENCODERS_NUM].State;
    // set state to idle, so it can be updated
    RotaryEncoder[EncoderClient_cfg[client]].State = eRoratyStopIdle;
  }
  
  return state;
}

