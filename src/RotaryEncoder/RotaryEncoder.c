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
//          - CW  states 0b0001, 0b0111, 0b1000, 0b1110
//          - CCW states 0b0010, 0b0100, 0b1011, 0b1101
static const teRotaryEncoderState RotaryEncoderStates[] = 
{
/*prev.A+B   cur.A+B   (prev.AB+cur.AB)  Array   Encoder State */ 
/*-------   ---------   --------------   -----   ------------- */
/*  00         00            0000          0     stop/idle     */ eRoratyStopIdle,
/*  00         01            0001          1     CW,  0x01     */ eRoratyCW,
/*  00         10            0010         -1     CCW, 0x02     */ eRoratyCCW,
/*  00         11            0011          0     invalid state */ eRoratyInvalid,
/*  01         00            0100         -1     CCW, 0x04     */ eRoratyCCW,
/*  01         01            0101          0     stop/idle     */ eRoratyStopIdle,
/*  01         10            0110          0     invalid state */ eRoratyInvalid,
/*  01         11            0111          1     CW, 0x07      */ eRoratyCW,
/*  10         00            1000          1     CW, 0x08      */ eRoratyCW,
/*  10         01            1001          0     invalid state */ eRoratyInvalid,
/*  10         10            1010          0     stop/idle     */ eRoratyStopIdle,
/*  10         11            1011         -1     CCW, 0x0B     */ eRoratyCCW,
/*  11         00            1100          0     invalid state */ eRoratyInvalid,
/*  11         01            1101         -1     CCW, 0x0D     */ eRoratyCCW,
/*  11         10            1110          1     CW,  0x0E     */ eRoratyCW,
/*  11         11            1111          0     stop/idle     */ eRoratyStopIdle,
};

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/
#define ROTARY_ENCODER_STATES_SIZE			( sizeof(RotaryEncoderStates)/sizeof(teRotaryEncoderState) )
#define ROTARY_ENCODER_DEBOUNCE_TIME		(ROTARY_ENCODER_DEBOUNCE_TIME_us/ROTARY_ENCODER_POLLING_TIME_us)	

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
typedef struct 
{
	tRotaryInputs Inputs;
	tRotaryInputs InputsDebounced;
	tRotaryInputs InputsDebouncedOld;
	teRotaryEncoderState State;
  uint16_t debounce_timer_a;
	uint16_t debounce_timer_b;
	uint16_t debounce_timer_push;
}tRotaryEncoder;

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
static bool RotaryEncoder_InitState = false;
static tRotaryEncoder RotaryEncoder[eROTARY_ENCODERS_NUM] = 
{
	{
		.Inputs.input_a							= false,
		.Inputs.input_b							= false,
		.Inputs.input_push					= false,
		.InputsDebounced.input_a		= false,
		.InputsDebounced.input_b		= false,
		.InputsDebounced.input_push = false,
		.State											= eRoratyStopIdle,
		.debounce_timer_a						= ROTARY_ENCODER_DEBOUNCE_TIME,
		.debounce_timer_b						= ROTARY_ENCODER_DEBOUNCE_TIME,
		.debounce_timer_push				= ROTARY_ENCODER_DEBOUNCE_TIME,	
	}
};

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
		RotaryEncoder_cfg_ReadPins(i, &RotaryEncoder[i].Inputs);
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
	
	for(i = 0; i < eROTARY_ENCODERS_NUM; i++)
	{
		re = &RotaryEncoder[i];
		// rotary encoder input a
		if(re->InputsDebounced.input_a != re->Inputs.input_a)
		{
			if((re->debounce_timer_a--) == 0u)
			{
				re->InputsDebounced.input_a = re->Inputs.input_a;
				re->debounce_timer_a = ROTARY_ENCODER_DEBOUNCE_TIME;
			}
		}
		else
		{
			re->debounce_timer_a = ROTARY_ENCODER_DEBOUNCE_TIME;
		}
		
		// rotary encoder input b
		if(re->InputsDebounced.input_b != re->Inputs.input_b)
		{
			if((re->debounce_timer_b--) == 0u)
			{
				re->InputsDebounced.input_b = re->Inputs.input_b;
				re->debounce_timer_b = ROTARY_ENCODER_DEBOUNCE_TIME;
			}
		}
		else
		{
			re->debounce_timer_b = ROTARY_ENCODER_DEBOUNCE_TIME;
		}
		
		// rotary encoder input push
		if(re->InputsDebounced.input_push != re->Inputs.input_push)
		{
			if((re->debounce_timer_push--) == 0u)
			{
				re->InputsDebounced.input_push = re->Inputs.input_push;
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
	uint8_t RotaryInput_AB = 0;
	uint8_t RotaryInput_AB_old = 0;
	teRotaryEncoderState currentDirection;
	tRotaryEncoder * re = NULL;
	
	for (i = 0; i < eROTARY_ENCODERS_NUM && RotaryEncoder_InitState == 1; i++)
	{
		RotaryEncoder_ReadPins();
		RotaryEncoder_DebouncePins ();
		
		re = &RotaryEncoder[i];
		
		if(re->InputsDebounced.input_push)
		{
			re->State = eRotaryPush;
		}
		else 
		{
			// check that state is consumed, so it can be updated
			if(re->State == eRoratyStopIdle)
			{
				RotaryInput_AB = (re->InputsDebounced.input_a << 1u) 
												| re->InputsDebounced.input_b;

				RotaryInput_AB_old = (re->InputsDebouncedOld.input_a << 1u) 
														| re->InputsDebouncedOld.input_b;

				currentDirection = RotaryEncoderStates[((RotaryInput_AB_old << 2u) | RotaryInput_AB) % ROTARY_ENCODER_STATES_SIZE];

				if(eRoratyInvalid != currentDirection)
				{
					re->State = currentDirection;
				}
				else
				{
					re->State = eRoratyStopIdle;
				}
			}
		}
		
		re->InputsDebouncedOld.input_a	   = re->InputsDebounced.input_a;
		re->InputsDebouncedOld.input_b		 = re->InputsDebounced.input_b;
		re->InputsDebouncedOld.input_push = re->InputsDebounced.input_push;
	}
}

/******************************************************************************
 * Name: 
 * Params: 
 * Purpose:
 ******************************************************************************/
teRotaryEncoderState RotaryEncoder_ConsumeStateEvent(teRotaryEncoderClientCfg client)
{
	teRotaryEncoderState state = eRoratyInvalid;
	
	if(client < EncoderClient_cfg[eROTARY_CLIENTS_NUM])
	{
		state = RotaryEncoder[EncoderClient_cfg[client]].State;
		// set state to idle, so it can be updated
		RotaryEncoder[EncoderClient_cfg[client]].State = eRoratyStopIdle;
	}
	
	return state;
}

