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
#ifdef TRIAC_CONTROL_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define TRIAC_CONTROL_C
#endif
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "triac_control.h"
#include "tempctrl.h"
#include "statemachine.h"
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
static U16 triac_fire_counter;
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
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/


/******************************************************************************/
/*
* Purpose: Triac fire counter . Triac fire pulse. Called at end of every task1 period 
* Input:
* Output:
*/
/******************************************************************************/
void triac_fire_timer(void)
{
	if(_TRIAC())	//if triack fired
	{
	    if(!--triac_fire_counter) 
        {
		    _TRIAC_OFF();
		    triac_fire_counter = TRIAC_FIRE_TIME;
        }
	}

}
/******************************************************************************/
/*
* Purpose: 
* Input:
* Output:
*/
/******************************************************************************/
void triac_control_init(void)
{

	triac_fire_counter = TRIAC_FIRE_TIME;

}
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/



