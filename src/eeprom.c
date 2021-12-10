/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/

//==========================================================================================================
// Body Identification                                                        
//==========================================================================================================
#ifdef __EEPROM_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define __EEPROM_C
#endif
//==========================================================================================================
// Included files to resolve specific definitions in this file                
//==========================================================================================================
#include "basedef.h"
#include <libpic30.h>

#include "parlist.h"
#include "eeprom.h"
#include "statemachine.h"
#include "Crc16.h"

//==========================================================================================================
// Glocal data                                                                 
//==========================================================================================================
U16 _EEDATA(2)     EEdata_Bank1[EE_BANK_SIZE/(sizeof(U16))];
U16 _EEDATA(2)     EEdata_Bank2[EE_BANK_SIZE/(sizeof(U16))];
U16 _EEDATA(2)     EEdata_ValidFlag;

//==========================================================================================================
// Local types 
//==========================================================================================================
/* Param Actualization states */
typedef enum
{
  PARACT_INIT = 0,
  PARACT_PARAMS_UPDATE,
  PARACT_PARAMS_READ_ALL
}tEE_state_type;

//==========================================================================================================
// Local data                                                                 
//==========================================================================================================
static tEE_state_type ee_state = PARACT_INIT;
static _prog_addressT EE_pio = 0;

//==========================================================================================================
// Local macros
//==========================================================================================================
// Bank definition
#define cBank1                                  (0U)
#define cBank2                                  (1U)

// Value Type define
#define cU8ValueType                            (0U)
#define cU16ValueType                           (1U)

#define cEE_InitializedValue                    ((U16)(0xAA55))
// Checksums in banks addresses
#define EE_BANK_CHK_ADDR												((EE_BANK_SIZE/sizeof(U16)) - sizeof(U16) - 1)
#define mGet_ParamAct()                         (&ParamAct)
//----------------------------------------------------------------------------------------------------------
#define mSetEEpointerChecksumBank1(EEpointer)   _init_prog_address(EEpointer, EEdata_Bank1[EE_BANK_CHK_ADDR])
#define mSetEEpointerChecksumBank2(EEpointer)   _init_prog_address(EEpointer, EEdata_Bank2[EE_BANK_CHK_ADDR])
#define mSetActiveBank1(EEpointer)              _init_prog_address(EEpointer, EEdata_Bank1[0])
#define mSetActiveBank2(EEpointer)							_init_prog_address(EEpointer, EEdata_Bank2[0])
#define mSetActiveBank(Bank)                                    \
do{                                                             \
    if((Bank) == cBank1)      mSetActiveBank1(EE_pio);          \
    else if((Bank) == cBank2) mSetActiveBank2(EE_pio);          \
    else                      mAssert(cFalse);                  \
} while (0)
//----------------------------------------------------------------------------------------------------------
#define mReadU16ValueEE(EEPointer, ReadedValue) EE_MemCopy(&EEPointer, &ReadedValue)

//==========================================================================================================
// Constant local data                                                        
//==========================================================================================================


//==========================================================================================================
// Exported data                                                              
//==========================================================================================================
U16 EE_CHKS[cNumberOfBanks] = {0, 0};
U16 EE_Valid = 0;
U16 EE_par_update = 0;
sParamAct ParamAct = 
{
  .EE_Chk_act = 0,
  .Iopar_Index = 0,
  .Iopar_members = 0,
  .bActiveBank = 0,
  .u8NumberOfUpdatedBanks = 0
};

//==========================================================================================================
// Constant exported data                                                     
//==========================================================================================================

//==========================================================================================================
// Local function prototypes                                                  
//==========================================================================================================
static void    EE_Write_U16(_IN_ U16 *EEWord,_IN_ _prog_addressT *EEpointer);
static void    EE_Erase_U16(_IN_ _prog_addressT *EEpointer);
static void    EE_Erase_All(void);
static void    EE_MemCopy(_IN_ _prog_addressT *EEpointer,_OUT_ U16 *U16EE_Read_Temp);
static void    EE_WriteU32(_IN_ const _prog_addressT pEEpointer, _IN_ iolist *pIop);
static void    EE_WriteU16(_IN_ const _prog_addressT pEEpointer, _IN_ iolist *pIop,_IN_ const BOOL bValueType);
static U32     EE_ReadU32(_IN_ const _prog_addressT pEEpointer);
static void    EE_WriteChecksum(_IN_ U16 u16Cheksum,_IN_ const BOOL bBank);
static HRESULT EE_VerifyChecksum(_IN_ U16 u16CheksumToVerify,_IN_ const BOOL bBank);

//==========================================================================================================
//                                                                            
//                                        L O C A L    F U N C T I O N S                        
//                                                                            
//==========================================================================================================
//==========================================================================================================
// Function Name: EEwrite
//
// Parameters: EEWord - pointer to U16 written value. EEpointer - pointer to eeprom cell.
//
// Return: none.
//
// Description: Write a WORD! into a eeprom
//
//==========================================================================================================
static void EE_Write_U16(_IN_ U16 *EEWord, _IN_ _prog_addressT *EEpointer)
{
  _write_eedata_word(*EEpointer, *EEWord);
  _wait_eedata();
}
//==========================================================================================================
// Function Name: EE_Erase_All
//
// Parameters: 
//
// Return: 
//
// Description: Erase all EEprom
//
//==========================================================================================================
static void EE_Erase_All(void)
{
  _erase_eedata_all();
  _wait_eedata();
}
//==========================================================================================================
// Function Name: EE_Erase_U16
//
// Parameters: EEprom pointer.
//
// Return: none
//
// Description: Erase a fixed word at address of EEpointer
//
//==========================================================================================================
static void EE_Erase_U16(_IN_ _prog_addressT *EEpointer)
{
  _erase_eedata(*EEpointer, _EE_WORD);
  _wait_eedata();    
}
//==========================================================================================================
// Function Name: EE_MemCopy  
//
// Parameters: EEpointer - pointer too eeprom cell. U16EE_Read_Temp - readed value
//
// Return: 
//
// Description: Read U16 (WORD) value from EEprom - EEpointer
//
//==========================================================================================================
static void EE_MemCopy(_IN_ _prog_addressT *EEpointer,_OUT_ U16 *U16EE_Read_Temp)
{
  (void) _memcpy_p2d16(U16EE_Read_Temp, *EEpointer, _EE_WORD);    //High first
}

//==========================================================================================================
// Function Name: EE_WriteU32  
//
// Parameters: EEprom pointer. Iopar pointer.
//
// Return: none.
//
// Description: Write U32 value to EEPROM.
//
//==========================================================================================================
static void EE_WriteU32(_IN_ const _prog_addressT pEEpointer, _IN_ iolist *pIop)
{
  _prog_addressT EEpointer;
  U32 u32ParamTemp;
  U16 u16ParamTemp;
  U16 u16ToEEprom;
  U32 value_to_write = *(U32*)pIop->read_adress;
  
  EEpointer = pEEpointer;
  
  u16ToEEprom = (value_to_write & 0xFFFFu);    // extract low 16 bytes form U32
  
  _set_eeprom_busy(1);
  
  EE_Erase_U16(&EEpointer);
  EE_Write_U16(&u16ToEEprom, &EEpointer);
  EEpointer += sizeof(U16);    // increment EEPROM pointer
  
  u16ToEEprom = (value_to_write >> 16) & 0xFFFFu;    // extract high 16 bytes from U32
  
  EE_Erase_U16(&EEpointer);
  EE_Write_U16(&u16ToEEprom, &EEpointer);        // Write high 16 bytes to eeprom.
  EEpointer -= sizeof(U16);                    // Move back EEPROM pointer to begin of U32 value
  
  _set_eeprom_busy(0);
  
  EE_par_update++;    // increment debug counter
  
  /* Read U32 Param from EEPROM AGAIN to be sure that written value is there :) - Little Endian - LOW FIRST*/
  EE_MemCopy(&EEpointer, &u16ParamTemp);        // Copy LOW byte from EEPROM
  EEpointer += sizeof(U16);                    // increment eeprom pointer with 2 bytes to read next bytes from U32 value
  
  u32ParamTemp = (U32)u16ParamTemp;            // store to U32 low 
  
  EE_MemCopy(&EEpointer, &u16ParamTemp);        // Copy High byte from EEPROM, we do not decrement eeprom pointer, because this is done at end of state
  
  u32ParamTemp |=  (U32)u16ParamTemp << 16;    // store U16ParamTemp to high
  
  if(u32ParamTemp != value_to_write)
  {
    _set_ee_write_error(1);
  }
}

//==========================================================================================================
// Function Name: EE_WriteU16  
//
// Parameters: EEprom pointer. Iopar pointer. Value type.
//
// Return: none.
//
// Description: Write U16 value to EEPROM.
//
//==========================================================================================================
static void EE_WriteU16(_IN_ const _prog_addressT pEEpointer, _IN_ iolist *pIop,_IN_ const BOOL bValueType)
{
  _prog_addressT EEpointer;
  U16 u16ToEEprom = 0;
  U16 u16ParamTemp;
  
  EEpointer = pEEpointer;
  
  if(bValueType == cU16ValueType)
  {
    u16ToEEprom = *(U16*)pIop->read_adress;
  }
  else if(bValueType == cU8ValueType)
  {
    u16ToEEprom = 0x00FF & *(U8*)pIop->read_adress;
  }
  
  _set_eeprom_busy(1);
  EE_Erase_U16(&EEpointer);
  EE_Write_U16(&u16ToEEprom, &EEpointer);
  _set_eeprom_busy(0);
  
  EE_par_update++;
  
  EE_MemCopy(&EEpointer, &u16ParamTemp);
  
  if(bValueType == cU16ValueType)
  {
    if(u16ParamTemp != u16ToEEprom)
    {
      _set_ee_write_error(1);
    }
  }
  else if(bValueType == cU8ValueType)
  {
    if(u16ParamTemp != u16ToEEprom)
    {
      _set_ee_write_error(1);
    }
  }
}
//==========================================================================================================
// Function Name: EE_ReadU32  
//
// Parameters: EEprom pointer.
//
// Return: Readed U32 value.
//
// Description: Read U32 value from EEPROM.
//
//==========================================================================================================
static U32 EE_ReadU32(_IN_ const _prog_addressT pEEpointer)
{
  _prog_addressT EEpointer;
  U16 u16ParamTemp;
  U32 u32ReadValue = 0;
  
  EEpointer = pEEpointer;
  
  /* Read U32 Param from EEPROM - LOW 16 Bytes FIRST*/
  EE_MemCopy(&EEpointer, &u16ParamTemp);        // Copy LOW byte from EEPROM
  EEpointer += sizeof(U16);                    // increment eeprom pointer with 2 bytes to read next bytes from U32 value
  
  u32ReadValue = (U32)u16ParamTemp;            // store to U32 low
  
  EE_MemCopy(&EEpointer, &u16ParamTemp);        // Copy High byte from EEPROM
  
  u32ReadValue |= (U32)u16ParamTemp << 16;    // store U16ParamTemp to high
  
  return(u32ReadValue);
}


//==========================================================================================================
// Function Name:   EE_WriteChecksum
//
// Parameters: Checksum value. Bank select.
//
// Return: none.
//
// Description: Write checksum to EEPROM bank checksum location. 
//
//==========================================================================================================
static void EE_WriteChecksum(_IN_ U16 u16Cheksum,_IN_ const BOOL bBank)
{
  _prog_addressT EEpointer = 0 ;
  
  if(bBank == cBank1)
  {
    mSetEEpointerChecksumBank1(EEpointer);
  }
  else if(bBank == cBank2)
  {
    mSetEEpointerChecksumBank2(EEpointer);
  }    
  else
  {
    mAssert(cFalse);
  }   
  
  _set_eeprom_busy(1);
  EE_Erase_U16(&EEpointer);
  EE_Write_U16(&u16Cheksum, &EEpointer);
  _set_eeprom_busy(0);
}
//==========================================================================================================
// Function Name: EE_VerifyChecksum
//
// Parameters: Checksum value. Bank select.
//
// Return: Checksum State. S_OK - checksum is ok.
//
// Description: Write checksum to EEPROM bank.
//
//==========================================================================================================
static HRESULT EE_VerifyChecksum(_IN_ U16 u16CheksumToVerify,_IN_ const BOOL bBank)
{
  _prog_addressT EEpointer;
  U16  u16ChecksumTemp;
  HRESULT ChkState = S_FALSE;
  
  if(bBank == cBank1)
  {
    mSetEEpointerChecksumBank1(EEpointer);
  }
  else if(bBank == cBank2)
  {
    mSetEEpointerChecksumBank2(EEpointer);
  }    
  else
  {
    mAssert(cFalse);
  } 
  
  EE_MemCopy(&EEpointer, &u16ChecksumTemp);
  
  if(u16ChecksumTemp == u16CheksumToVerify)
  {
    ChkState = S_OK;
  }
  
  return(ChkState);
}

//==========================================================================================================
//                                                                            
//                                        E X P O R T E D    F U N C T I O N S                        
//                                                                            
//==========================================================================================================
//==========================================================================================================
// Function Name: ee_param_act
//
// Parameters: init - initialization flag 1: INIT 0: Normal operation. read_all_params 1: Perform all parameters read from eeprom -> must be combined with init = 1
//
// Return: none.
//
// Description: Parameters actualization. Run in background loop.
//
//==========================================================================================================
void ee_param_act(BOOL init,BOOL read_all_params)
{
  sParamAct *pa;
  static iolist *pio = (iolist*)iopar;
  U16 U16ParamTemp = 0;
  U32 U32ParamTemp = 0;
  BOOL checksum_ok = cFalse;
  
  pa = mGet_ParamAct();
  
  if(init) ee_state = PARACT_INIT;
  
  switch(ee_state)
  {
    /**********************************************************************************************************/
    case PARACT_INIT:
      pio=(iolist*)iopar;
      (pa)->Iopar_members = IF_Parlist_GetCntMembers();
      (pa)->Iopar_Index = 0;
      (pa)->EE_Chk_act = Crc_CalculateCRC16(NULL, 0, 0, cTrue);
      (pa)->u8NumberOfUpdatedBanks = cNumberOfBanks;
      pa->bActiveBank = cBank1;
      mSetActiveBank(pa->bActiveBank);
      
      if(read_all_params)
        ee_state = PARACT_PARAMS_READ_ALL;
      else
        ee_state = PARACT_PARAMS_UPDATE;    
      break;
    /**********************************************************************************************************/
    case PARACT_PARAMS_UPDATE:
      if(pio->type[1] == 'n')
      {
        BOOL bSizeOk = cFalse;
        
        switch(pio->size)
        {
          /*------------------------*/
          case sizeof(U32):
          {
            U32ParamTemp = EE_ReadU32(EE_pio);

            /* Write U32 param to EEPROM - Little Endian - LOW FIRST */
            if(U32ParamTemp != *(U32*)pio->read_adress)    // If parameter in EEPROM is different from parameter in parlist
            {
              EE_WriteU32(EE_pio, pio);
            }
            
            EE_pio += sizeof(U32);
            bSizeOk = cTrue;
          }
          break;
          /*------------------------*/
          case sizeof(U16):
          {
            mReadU16ValueEE(EE_pio, U16ParamTemp);
            
            if(U16ParamTemp != *(U16*)pio->read_adress)
            {
              EE_WriteU16(EE_pio, pio, cU16ValueType);
            }
            
            EE_pio += sizeof(U16);
            bSizeOk = cTrue;
          }
          break;
          /*------------------------*/
          case sizeof(U8):
          {
            mReadU16ValueEE(EE_pio, U16ParamTemp);
            
            if((U8)U16ParamTemp != *(U8*)pio->read_adress)
            {
              EE_WriteU16(EE_pio, pio, cU8ValueType);
            }
            
            EE_pio += sizeof(U16);
            bSizeOk = cTrue;
          }
          break;
          /*------------------------*/
          default: mAssert(cFalse); break;
        }
        
        // update checksum
        if(bSizeOk == cTrue)
        {
          (pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, pio->size, (pa)->EE_Chk_act, cFalse);
        }
      }// END if(pio->type[1] == 'n')
      
      if(++((pa)->Iopar_Index) >= (pa)->Iopar_members)
      {
        (pa)->Iopar_Index = 0;
        pio=(iolist*)iopar;
        
        if(EE_CHKS[pa->bActiveBank] != (pa)->EE_Chk_act)
        {
          EE_CHKS[pa->bActiveBank] = pa->EE_Chk_act;
          EE_WriteChecksum(EE_CHKS[pa->bActiveBank], (pa)->bActiveBank);
        }
        
        // switch between banks
        pa->bActiveBank = (pa->bActiveBank + 1) % cNumberOfBanks;
        mSetActiveBank(pa->bActiveBank);
        
        if(--(pa)->u8NumberOfUpdatedBanks == 0)
        {
          ee_state = PARACT_INIT;
        }
        (pa)->EE_Chk_act = Crc_CalculateCRC16(NULL, 0, 0, cTrue);
      }
      else
      {
        pio++;
      }      
      break;
    /**********************************************************************************************************/
    case PARACT_PARAMS_READ_ALL:
      _set_eeprom_busy(1);
      
      do
      {
        // reset checksum
        (pa)->EE_Chk_act = Crc_CalculateCRC16(NULL, 0, 0, cTrue);
        
        for((pa)->Iopar_Index = 0; ((pa)->Iopar_Index < (pa)->Iopar_members); (pa)->Iopar_Index++, pio++)
        {
          if(pio->type[1] == 'n')
          {
            BOOL bSizeOk = cFalse;
            
            switch(pio->size)
            {
              /*------------------------*/
              case sizeof(U32):
              {
                U32ParamTemp = EE_ReadU32(EE_pio);
                EE_pio += sizeof(U32);        // increment eeprom pointer
                *(U32*)pio->write_adress = U32ParamTemp;
                bSizeOk = cTrue;
              }
              break;
              /*------------------------*/
              case sizeof(U16):
              {
                mReadU16ValueEE(EE_pio, U16ParamTemp);
                EE_pio += sizeof(U16);        // increment eeprom pointer
                *(U16*)pio->write_adress = U16ParamTemp;
                bSizeOk = cTrue;
              }
              break;
              /*------------------------*/
              case sizeof(U8):
              {
                mReadU16ValueEE(EE_pio, U16ParamTemp);
                EE_pio += sizeof(U16);        // increment eeprom pointer
                *(U8*)pio->write_adress = (U8)U16ParamTemp;
                bSizeOk = cTrue;
              }
              break;
              /*------------------------*/
              default: mAssert(cFalse); break;
            }
            // update checksum
            if(bSizeOk == cTrue)
            {
              (pa)->EE_Chk_act = Crc_CalculateCRC16(pio->write_adress, pio->size, (pa)->EE_Chk_act, cFalse);
            }
          }//end if(pio->type[1] == 'n')
        }//end for
        
        // store checksum
        EE_CHKS[pa->bActiveBank] = pa->EE_Chk_act;
        /* Checksum Verify */
        if(EE_VerifyChecksum((pa)->EE_Chk_act, (pa)->bActiveBank) == S_OK)
        {
          checksum_ok = cTrue;
          _set_ee_checksum_error(0);
        }
        else
        {
          // switch between banks
          pa->bActiveBank = (pa->bActiveBank + 1) % cNumberOfBanks;
          mSetActiveBank(pa->bActiveBank);
          pio=(iolist*)iopar;
        }        
      } while( (--(pa)->u8NumberOfUpdatedBanks != 0) && (checksum_ok == cFalse) );
      
      // Check that eeprom is valid (Value 1000)
      if(EE_Valid != 1000)      _set_ee_valid_error(1);
      if(checksum_ok == cFalse) _set_ee_checksum_error(1);
      
      ee_state = PARACT_INIT;
      _set_eeprom_busy(0);
      
      break;
    /**********************************************************************************************************/
    default:
      mAssert(cFalse);
      _set_global_system_fault(1);
      break;
  }
}
//==========================================================================================================
// Function Name: EE_CheckEEprom
//
// Parameters: none
//
// Return: Status of eeprom. S_OK - EEPROM initialized . S_FALSE - EEPROM is not initialized.
//
// Description: Check eeprom is initialized. Check value on eeprom location EE_INIT_VALUE_ADDRESS. If value is
//              different from 0xAA55 Erase and null eeprom , also write correct value on location EE_INIT_VALUE_ADDRESS.
//              Check is it enough eeprom size for all parameter (iopar) members. 
//==========================================================================================================
HRESULT EE_CheckEEprom(void)
{
  _prog_addressT EEpointer = 0;
  U16  u16Temp;
  U16  u16Counter;
  U16 u16IoParMembers;
  U16 u16EepromMembers = 0;
  iolist *pio = (iolist*)iopar;
  HRESULT EEState;
  
  EEState = S_FALSE;
  
  // Init prog address to location EE_INIT_VALUE_ADDRESS
  _init_prog_address(EEpointer, EEdata_ValidFlag);
  
  mReadU16ValueEE(EEpointer, u16Temp);
  
  if(u16Temp != cEE_InitializedValue)
  {
    // EEprom not initialized. Erase content ant write 0x0000 in all eeprom cells, because after erase 
    // eeprom cell value is 0xFFFF, it is too dangerous to leave eeprom uninitialized.
    EE_Erase_All();

    u16Temp = 0x0000;
    
        
    for(mSetActiveBank1(EEpointer), u16Counter = 0; 
        u16Counter < (EE_BANK_SIZE/sizeof(U16)); 
        u16Counter++)
    {
      EE_Erase_U16(&EEpointer);
      EE_Write_U16(&u16Temp, &EEpointer);
      EEpointer += sizeof(U16);
    }
           
    for(mSetActiveBank2(EEpointer), u16Counter = 0; 
        u16Counter < (EE_BANK_SIZE/sizeof(U16)); 
        u16Counter++)
    {
      EE_Erase_U16(&EEpointer);
      EE_Write_U16(&u16Temp, &EEpointer);
      EEpointer += sizeof(U16);
    }
    
    // Write proper value that indicate eeprom is initialized.
    u16Temp = cEE_InitializedValue;
    _init_prog_address(EEpointer, EEdata_ValidFlag);
    
    EE_Erase_U16(&EEpointer);
    EE_Write_U16(&u16Temp, &EEpointer);
  }
  
  // Check size of eeprom is enough.
  u16IoParMembers = IF_Parlist_GetCntMembers();
  for(u16Counter = 0; u16Counter < u16IoParMembers; u16Counter++)
  {
    if(pio->type[1] == 'n')
    {
      u16EepromMembers += pio->size;
    }
    pio++;
  }
  
  if(u16EepromMembers < (EE_BANK_SIZE/sizeof(U16)) ) 
  {
    EEState = S_OK;
  }
  else
  {
    _set_ee_size_error(1);
  }
  
  return(EEState);
}
