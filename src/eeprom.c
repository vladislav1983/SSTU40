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
// Local constants                                                            
//==========================================================================================================
// Define here physical start and end address of eeprom.
#define EE_BASE_ADDR                0x7FFC00
#define EE_END_ADDR                 0x7FFFFE

#define EE_ALIGNMENT                (2U)
#define EE_START_LOG_ADDRESS        (0U)
#define EE_INIT_VALUE_ADDRESS       ((EE_END_ADDR - EE_BASE_ADDR) / EE_ALIGNMENT)
#define EE_END_LOG_ADDRESS          (((EE_END_ADDR - EE_BASE_ADDR) / EE_ALIGNMENT) - 2)

// Banks start addresses
#define EE_BANK1_START_ADDR         EE_START_LOG_ADDRESS
#define EE_BANK2_START_ADDR         (EE_END_LOG_ADDRESS / 2)

// Checksums in banks addresses
#define EE_BANK1_CHK_ADDR           ((EE_END_LOG_ADDRESS / 2) - 1)
#define EE_BANK2_CHK_ADDR           EE_END_LOG_ADDRESS

#define cNumberOfBanks              (2U)

// Bank definition
#define cBank1                      (0U)
#define cBank2                      (1U)

/* Param Actualization states */
#define PARACT_INIT                 1
#define PARACT_CHECKSUM_POOL        2
#define PARACT_PARAMS_UPDATE        3
#define PARACT_PARAMS_READ_ALL      4

// Value Type define
#define cU8ValueType                (0U)
#define cU16ValueType               (1U)

#define cEE_InitializedValue        ((U16)(0xAA55))


//==========================================================================================================
// Local macros                                                               
//==========================================================================================================

#define mGet_ParamAct()                         (&ParamAct)
//----------------------------------------------------------------------------------------------------------
#define mSetEEpointerChecksumBank1(EEpointer)   _init_prog_address(EEpointer, EEdata[EE_BANK1_CHK_ADDR])
#define mSetEEpointerChecksumBank2(EEpointer)   _init_prog_address(EEpointer, EEdata[EE_BANK2_CHK_ADDR])
//----------------------------------------------------------------------------------------------------------
#define mSetActiveBank1(EEpointer)                              \
do{                                                             \
    _init_prog_address(EEpointer, EEdata[EE_BANK1_START_ADDR]); \
		ParamAct.bActiveBank = cBank1;                              \
		} while(0)
//----------------------------------------------------------------------------------------------------------
#define mSetActiveBank2(EEpointer)                              \
do{                                                             \
    _init_prog_address(EEpointer, EEdata[EE_BANK2_START_ADDR]); \
		ParamAct.bActiveBank = cBank2;                              \
		} while(0)
//----------------------------------------------------------------------------------------------------------
#define mSwapBanks()                                            \
do{                                                             \
    if(ParamAct.bActiveBank == cBank1)                          \
		mSetActiveBank2(EE_pio);                                \
		else                                                        \
		mSetActiveBank1(EE_pio);                                    \
		} while (0)
//----------------------------------------------------------------------------------------------------------
#define mReadU16ValueEE(EEPointer, ReadedValue) EE_MemCopy(&EEPointer, &ReadedValue)

//==========================================================================================================
// Local types 
//==========================================================================================================


//==========================================================================================================
// Local data                                                                 
//==========================================================================================================
static U16 _EEDATA(512)     EEdata[512];
static U16 ee_state;

//==========================================================================================================
// Constant local data                                                        
//==========================================================================================================


//==========================================================================================================
// Exported data                                                              
//==========================================================================================================
U16 EE_CHKS;
U16 EE_Valid;
U16 EE_par_update;
sParamAct ParamAct;


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
	
	u16ToEEprom = (U16)Lou(value_to_write);    // extract low 16 bytes form U32
	
	_set_eeprom_busy(1);
	
	EE_Erase_U16(&EEpointer);
	EE_Write_U16(&u16ToEEprom, &EEpointer);
	EEpointer += sizeof(U16);    // increment EEPROM pointer
	
	u16ToEEprom = (U16)Hiu(value_to_write);    // extract high 16 bytes from U32
	
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
	U16 u16ToEEprom;
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
	_prog_addressT EEpointer;
	
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
	HRESULT ChkState;
	
	ChkState = S_FALSE;
	
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
	static iolist *pio;
	static _prog_addressT EE_pio;
	U16 U16ParamTemp;
	U32 U32ParamTemp = 0;
	BOOL  bBreak = cFalse;
	
	pa = mGet_ParamAct();
	
	if(init) ee_state = PARACT_INIT;
	
	switch(ee_state)
	{
    /*------------------------*/
    case PARACT_INIT:
			pio=(iolist*)iopar;
			(pa)->Iopar_members = IF_Parlist_GetCntMembers();
			(pa)->Iopar_Index = 0;
			(pa)->EE_Chk_act = Crc_CalculateCRC16(NULL, 0, 0, cTrue);
			(pa)->u8NumberOfUpdatedBanks = cNumberOfBanks;
			mSetActiveBank1(EE_pio);
			
			if(read_all_params)
				ee_state = PARACT_PARAMS_READ_ALL;
			else
				ee_state = PARACT_CHECKSUM_POOL;    
			break;
			/*------------------------*/
    case PARACT_CHECKSUM_POOL:
			if(pio->type[1] == 'n')
			{
				if( sizeof(U32) == pio->size )
				{
					(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U32), (pa)->EE_Chk_act, cFalse);
				}
				else if(sizeof(U16) == pio->size)
				{
					(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U16), (pa)->EE_Chk_act, cFalse);
				}
				else if( sizeof(U8) == pio->size )
				{
					(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U8), (pa)->EE_Chk_act, cFalse);
				}
			}
			
			(pa)->Iopar_Index++;
			
			if((pa)->Iopar_Index >= (pa)->Iopar_members)
			{
				(pa)->Iopar_Index = 0;
				pio=(iolist*)iopar;
				
				if((pa)->EE_Chk_act != EE_CHKS) ee_state = PARACT_PARAMS_UPDATE;
				
				(pa)->EE_Chk_act = 0;
			}
			else pio++;    
			break;
			/*------------------------*/
    case PARACT_PARAMS_UPDATE:
			
			if((pio->type[1] == 'n') && (!_ee_write_error()))
			{
        /**********************************************************************************************************/
				if( sizeof(U32) == pio->size )    // U32 size
				{
					U32ParamTemp = EE_ReadU32(EE_pio);
					
					/* Write U32 param to EEPROM - Little Endian - LOW FIRST */
					if(U32ParamTemp != *(U32*)pio->read_adress)    // If parameter in EEPROM is different from parameter in parlist
					{
						EE_WriteU32(EE_pio, pio);
					}
					
					EE_pio += sizeof(U32);                
					
					/* Actualize checksum */
					(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U32), (pa)->EE_Chk_act, cFalse);
				}
				else if(sizeof(U16) == pio->size)    // U16 size
				{
					/**********************************************************************************************************/
					mReadU16ValueEE(EE_pio, U16ParamTemp);
					
					if(U16ParamTemp != *(U16*)pio->read_adress)
					{
						EE_WriteU16(EE_pio, pio, cU16ValueType);
					}
					
					EE_pio += sizeof(U16);
					
					(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U16), (pa)->EE_Chk_act, cFalse);
				}
				else if(sizeof(U8) == pio->size)    // U8 size
				{
					/**********************************************************************************************************/
					mReadU16ValueEE(EE_pio, U16ParamTemp);
					
					if((U8)U16ParamTemp != *(U8*)pio->read_adress)
					{
						EE_WriteU16(EE_pio, pio, cU8ValueType);
					}
					
					EE_pio += sizeof(U16);
					
					(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U8), (pa)->EE_Chk_act, cFalse);
				}                       
			}    // END if(pio->type[1] == 'n')
			
			(pa)->Iopar_Index++;
			
			if((pa)->Iopar_Index >= (pa)->Iopar_members)
			{
				(pa)->Iopar_Index = 0;
				pio=(iolist*)iopar;
				
				EE_CHKS = (pa)->EE_Chk_act;
				(pa)->EE_Chk_act = 0;
				
				EE_WriteChecksum(EE_CHKS, (pa)->bActiveBank);
				
				//if(EE_VerifyChecksum(EE_CHKS,(pa)->bActiveBank) == S_FALSE) _set_ee_checksum_read_error(1);
				
				// switch between banks
				mSwapBanks();
				
				if(--(pa)->u8NumberOfUpdatedBanks == 0)
				{
					ee_state = PARACT_INIT;
				}
			}
			else
			{
				pio++;
			}      
			break;
			/*------------------------*/
    case PARACT_PARAMS_READ_ALL:
			_set_eeprom_busy(1);
			
			do
			{
				for((pa)->Iopar_Index = 0; ((pa)->Iopar_Index < (pa)->Iopar_members); (pa)->Iopar_Index++)
				{
					if(pio->type[1] == 'n')
					{
						if( sizeof(U32) == pio->size )
						{
							U32ParamTemp = EE_ReadU32(EE_pio);
							EE_pio += sizeof(U32);        // increment eeprom pointer
							
							*(U32*)pio->write_adress = U32ParamTemp;
							
							(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U32), (pa)->EE_Chk_act, cFalse);
						}
						else if( sizeof(U16) == pio->size )
						{
							mReadU16ValueEE(EE_pio, U16ParamTemp);
							EE_pio += sizeof(U16);        // increment eeprom pointer
							
							*(U16*)pio->write_adress = U16ParamTemp;
							
							(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U16), (pa)->EE_Chk_act, cFalse);
						}
						else if( sizeof(U8) == pio->size )
						{
							mReadU16ValueEE(EE_pio, U16ParamTemp);
							EE_pio += sizeof(U16);        // increment eeprom pointer
							
							*(U8*)pio->write_adress = (U8)U16ParamTemp;
							
							(pa)->EE_Chk_act = Crc_CalculateCRC16(pio->read_adress, sizeof(U8), (pa)->EE_Chk_act, cFalse);							
						}
					}//end if(pio->type[1] == 'n')
					pio++;
				}//end for
				
				/* Checksum Verify */
				if(EE_VerifyChecksum((pa)->EE_Chk_act, (pa)->bActiveBank) == S_OK)
				{
					bBreak = cTrue;
					_set_ee_checksum_read_error(0);
				}
				else
				{
					mSwapBanks();
					pio=(iolist*)iopar;
					_set_ee_checksum_read_error(1);
				}
				
				(pa)->EE_Chk_act = 0;
				
			} while( (--(pa)->u8NumberOfUpdatedBanks != 0) && (bBreak == cFalse) );
			
			// Check that eeprom is valid (Value 1000)
			if(EE_Valid != 1000) 
			{
				_set_ee_valid_error(1);    
			}
			
			ee_state = PARACT_INIT;
			_set_eeprom_busy(0);
			
			break;
			/*------------------------*/
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
	_prog_addressT EEpointer;
	U16  u16Temp;
	U16  u16Counter;
	U16 u16IoParMembers;
	U16 u16EepromMembers = 0;
	iolist *pio = (iolist*)iopar;
	HRESULT EEState;
	
	EEState = S_FALSE;
	
	// Init prog address to location EE_INIT_VALUE_ADDRESS
	_init_prog_address(EEpointer, EEdata[EE_INIT_VALUE_ADDRESS]);
	
	mReadU16ValueEE(EEpointer, u16Temp);
	
	if(u16Temp != cEE_InitializedValue)
	{
		// EEprom not initialized. Erase content ant write 0x0000 in all eeprom cells, because after erase 
		// eeprom cell value is 0xFFFF, it is too dangerous to leave eeprom uninitialized.
		EE_Erase_All();
		
		_init_prog_address(EEpointer, EEdata[EE_START_LOG_ADDRESS]);
		u16Temp = 0x0000;
		
		for(u16Counter = 0; u16Counter < EE_END_LOG_ADDRESS; u16Counter++)
		{
			EE_Erase_U16(&EEpointer);
			EE_Write_U16(&u16Temp, &EEpointer);
			EEpointer += sizeof(U16);
		}
		
		// Write proper value that indicate eeprom is initialized.
		u16Temp = cEE_InitializedValue;
		_init_prog_address(EEpointer, EEdata[EE_INIT_VALUE_ADDRESS]);
		
		EE_Erase_U16(&EEpointer);
		EE_Write_U16(&u16Temp, &EEpointer);
	}
	
	// Check size of eeprom is enough.
	u16IoParMembers = IF_Parlist_GetCntMembers();
	for(u16Counter = 0; u16Counter < u16IoParMembers; u16Counter++)
	{
		if(pio->type[1] == 'n')
		{
			u16EepromMembers++;
		}
		pio++;
	}
	
	if(u16EepromMembers < (EE_END_LOG_ADDRESS / 2) ) 
	{
		EEState = S_OK;
	}
	else
	{
		_set_ee_size_error(1);
	}
	
	return(EEState);
}
