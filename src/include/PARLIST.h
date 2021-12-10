/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef PARLIST_H
#define PARLIST_H
    
/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"

/*----------------------------------------------------------------------------*/
/* Constant data                                                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported type                                                              */
/*----------------------------------------------------------------------------*/
typedef struct __attribute__ ((packed)) tIOlist
{
    U16   number;      // parameter number
    char* name;        // calling name, max. 10 char.
    void* write_adress;
    void* read_adress;
    U16   size;        // number of bytes
    U8    type[4] ;     // type[0]: 's'=signed
                                                //          'u'=unsigned
                                                //          'p'=pointer
                                                //          'f'=float
                                                //          'a'=array
                                                //          'b'=bitmap
                                                // type[1]: 'r'=RAM    (write)
                                                //          'n'=NOVRAM
                                                //          'o'=ROM
                                                // type[2]: like type[1] (read)
    S32   max;         // maximum value
    S32   min;                                  // minimum value
    U16   passwd_write;
    U16   passwd_read; //  0 = free
                                                //  1 = operator
                                                //  2 = engineer
                                                //  3 = service
                                                //  4 = programmer
                                                //  >4= no access*/
    S16   scale;       // (int)value/(float)value
}iolist;

/*----------------------------------------------------------------------------*/
/* Exported data                                                              */
/*----------------------------------------------------------------------------*/
extern const iolist iopar[];

/*----------------------------------------------------------------------------*/
/* Constant exported data                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported Macros                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Exported functions                                                         */
/*----------------------------------------------------------------------------*/
U16 IF_Parlist_GetCntMembers(void);
U16 IF_Parlist_GetCntBytes(void);
iolist* IF_Parlist_bnu(U16 u16PrmNumber);
void Params_check_limit(void);
void Params_Conversion(void);

#endif /* PARLIST_H */
