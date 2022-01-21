/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef TRIAC_CONTROL_H
#define TRIAC_CONTROL_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "task.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/
#define TRIAC_FIRE_TIME                (2000ul/T1_TIME_us)            //triac fire time in task1 periods

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
/* Triac control */
#define _FIRE_TRIAC()(                    \
{                                         \
  if(   (_drive_enabled()     != 0)       \
     && (_drive_disabled_pc() == 0))      \
  {                                       \
    pinTH_FIRE = 1;                       \
    _set_triac_state(1);                  \
    _set_over_prot_triac_state(1);        \
  }                                       \
  else                                    \
  {                                       \
    _TRIAC_OFF();                         \
  }                                       \
})    

#define _TRIAC_OFF()(                    \
{                                        \
    pinTH_FIRE = 0;                      \
    _set_triac_state(0);                 \
})    

#define _TRIAC()                        pinTH_FIRE



/*----------------------------------------------------------------------------*/
/* Exported functions                                                           */
/*----------------------------------------------------------------------------*/
void triac_fire_timer(void);
void triac_control_init(void);

#endif /* TRIAC_CONTROL_H */
