/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
//     Note: rw permanently connected to gnd
//     D2  rs
//     D3  en
//     D4  D4
//     D5  D5
//     D6  D6
//     D7  D7 
//     LCD pins D0-D3 are not used
/*----------------------------------------------------------------------------*/
/* Body Identification                                                        */
/*----------------------------------------------------------------------------*/
#ifdef LCD_C
#error "!!! FileName ID. It should be Unique !!!"
#else
#define LCD_C
#endif

/*----------------------------------------------------------------------------*/
/* Included files to resolve specific definitions in this file                */
/*----------------------------------------------------------------------------*/
#include "basedef.h"
#include "LCD.h"
#include "string.h"
#include "stdarg.h"
#include "stdio.h"
#include "systmr.h"
#include "stdio.h"

/*----------------------------------------------------------------------------*/
/* Local constants                                                            */
/*----------------------------------------------------------------------------*/ 
#define LCD_TYPE                      2u
#define LCD_LINE_ADDRESS_1            0x00u
#define LCD_LINE_ADDRESS_2            0x40u

/* Display ON/OFF Control defines */
#define DON                           0b00001111  /* Display on      */
#define DOFF                          0b00001011  /* Display off     */
#define CURSOR_ON                     0b00001111  /* Cursor on       */
#define CURSOR_OFF                    0b00001101  /* Cursor off      */
#define BLINK_ON                      0b00001111  /* Cursor Blink    */
#define BLINK_OFF                     0b00001110  /* Cursor No Blink */

/* Cursor or Display Shift defines */
#define SHIFT_CUR_LEFT                0b00010011  /* Cursor shifts to the left   */
#define SHIFT_CUR_RIGHT               0b00010111  /* Cursor shifts to the right  */
#define SHIFT_DISP_LEFT               0b00011011  /* Display shifts to the left  */
#define SHIFT_DISP_RIGHT              0b00011111  /* Display shifts to the right */

/* Function Set defines */
#define FOUR_BIT                      0b00101111  /* 4-bit Interface               */
#define EIGHT_BIT                     0b00111111  /* 8-bit Interface               */
#define LINE_5X7                      0b00110011  /* 5x7 characters, single line   */
#define LINE_5X10                     0b00110111  /* 5x10 characters               */
#define LINES_5X7                     0b00111011  /* 5x7 characters, multiple line */

// Rev1 additional WH Tan
// Addtional define to support display mode
#define DISP_FLIP_NONE                0b00111100  /* No flip                             */
#define DISP_FLIP_VERTICAL            0b00111101    /* Flip both vertically & horizontally */
#define DISP_FLIP_HORIZONTAL          0b00111110    /* Flip horizontally                   */
#define DISP_FLIP_BOTH                0b00111111    /* Flip vertically                     */
// End Rev1

// Rev1 additional WH Tan
// Addtional define to support entry mode & shift mode
#define ENTRY_CURSOR_DEC               0b00000101    /* Entry cause cursor move to left  */
#define ENTRY_CURSOR_INC               0b00000111    /* Entry cause cursor move to right */
#define ENTRY_DISPLAY_SHIFT            0b00000111     /* Entry cause the display to shift */
#define ENTRY_DISPLAY_NO_SHIFT         0b00000110    /* Entry cuase no shift             */

// Address defines
// 4 lines X 20 characters LCD
#ifdef LCD_4X20
#define LINE0                          0x00
#define LINE1                          0x40
#define LINE2                          0x14
#define LINE3                          0x54
#endif

// 2 lines X 20 characters LCD
#ifdef LCD_2X20
#define LINE0                           0x00
#define LINE1                           0x40
#else

// Use generic address
#define LINE0                           0x00
#define LINE1                           0x40
#define LINE2                           0x14
#define LINE3                           0x54
#endif

#define LCD_COL_COUNT                   16

// LCD commands
#define LCD_CMD_CLEAR                   0x01
#define LCD_CMD_CURSOR_HOME             0x02
#define LCD_CMD_ENTRY_MODE_SET          0x04
#define LCD_CMD_ON_OFF_CTRL             0x08
#define LCD_CMD_SHIFT                   0x10
#define LCD_CMD_FNCT_SET                0x20
#define LCD_CMD_CGRAM_ADDR_SET          0x40
#define LCD_CMD_DDRAM_ADDR_SET          0x80

// Entry Mode Set
//I/D: Increments (I/D = 1) or decrements (I/D = 0) the DDRAM address by 1 when a character code is written into or read from DDRAM.
#define LCD_CMD_ENTRY_MODE_INCREMENT    0x02
#define LCD_CMD_ENTRY_MODE_DECREMENT    0x00
//S: Shifts the entire display either to the right (I/D = 0) or to the left (I/D = 1) when S is 1. The display does not shift if S is 0.
#define LCD_CMD_ENTRY_MODE_SHIFT        0x01

// Display On/Off Control
// D: The display is on when D is 1 and off when D is 0. When off, the display data remains in DDRAM, but can be displayed instantly by setting D to 1.
#define LCD_CMD_ON_OFF_CTRL_DISPLAY_ON  0x04
#define LCD_CMD_ON_OFF_CTRL_DISPLAY_OFF 0x00
// C: The cursor is displayed when C is 1 and not displayed when C is 0. 
#define LCD_CMD_ON_OFF_CTRL_DISPLAY     0x04
// B: The character indicated by the cursor blinks when B is 1
#define LCD_CMD_ON_OFF_CTRL_BLINK       0x01

// Cursor or Display Shift
#define LCD_CMD_SHIFT_DISPLAY_SHIFT     0x08
#define LCD_CMD_SHIFT_CURSOR_MOVE       0x00
#define LCD_CMD_SHIFT_SHIFT_TO_RIGHT    0x04
#define LCD_CMD_SHIFT_SHIFT_TO_LEFT     0x00

// Function set
// DL: Sets the interface data length. Data is sent or received in 8-bit lengths (DB7 to DB0) when DL is 1, and in 4-bit lengths (DB7 to DB4) when DL is 0.
#define LCD_CMD_FNCT_SET_8_BITS         0x10
#define LCD_CMD_FNCT_SET_4_BITS         0x00
// N: Sets the number of display lines.
#define LCD_CMD_FNCT_SET_DISP_LINE_2    0x08
#define LCD_CMD_FNCT_SET_DISP_LINE_1    0x00
// F: Sets the character font
#define LCD_CMD_FNCT_SET_FONT_5_X_10    0x04
#define LCD_CMD_FNCT_SET_FONT_5_X_8     0x00

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/
#define LCD_DATA_WRITE(DATA_NIBBLE)     pinLCD_DB4 = DATA_NIBBLE;        \
                                        pinLCD_DB5 = DATA_NIBBLE >> 1;   \
                                        pinLCD_DB6 = DATA_NIBBLE >> 2;   \
                                        pinLCD_DB7 = DATA_NIBBLE >> 3;        

#define INIT_DELAY_MS                   20u
#define CFG_FNCT_DELAY_MS               5u
#define CLEAR_LCD_DELAY_US              1600u
#define EXEC_DELAY_US                   50u

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
typedef enum
{
  COMMAND = 0,
  DATA,
}LCD_REGISTER_TYPE;

/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
const U8 LCD_INIT_STRING[4] = 
{
  LCD_CMD_FNCT_SET | LCD_CMD_FNCT_SET_DISP_LINE_2,        // Func set: 4-bit, 2 lines, 5x8 dots 
  LCD_CMD_ON_OFF_CTRL | LCD_CMD_ON_OFF_CTRL_DISPLAY_ON,   // Display on             
  LCD_CMD_CLEAR,                                          // Clear display 
  LCD_CMD_ENTRY_MODE_SET| LCD_CMD_ENTRY_MODE_INCREMENT    // Increment cursor 
};

U16 u16Nibble_Temp;

/*----------------------------------------------------------------------------*/
/* Constant local data                                                        */
/*----------------------------------------------------------------------------*/
const U8 DegreeChar[8] = 
{
  0b00110,
  0b01001,
  0b01001,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

const U8 EmptyHeart[8] = 
{
  0b01010,
  0b10101,
  0b10001,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};

const U8 FullHeart[8] = 
{
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000,
  0b00000
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
void LCDSendNibble(U8 u8Nibble);
void LCDSendByte(U8 u8ByteToLcd, LCD_REGISTER_TYPE type);
static void Lcd_DefineChar(const U8 ptr[], U8 location);

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   I N T E R F A C E   F U N C T I O N S                    */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Name:    IF_LCDInit 
 * Purpose: init LCD
 * Input: none
 * Output:none
 */
/******************************************************************************/
void IF_LCDInit(void)
{
  U16 u16InitCounter;
  
  pinLCD_RS = 0;
  pinLCD_E =0;
  delay_ms(INIT_DELAY_MS);
  
  // First send the HIGH nibble of the Function set
  LCDSendNibble(3); // Function set - Interface defaults to 8-bit mode
  delay_ms(CFG_FNCT_DELAY_MS);
  LCDSendNibble(3); // Function set - Interface defaults to 8-bit mode
  delay_ms(CFG_FNCT_DELAY_MS);
  LCDSendNibble(3); // Function set - Interface defaults to 8-bit mode
  delay_ms(CFG_FNCT_DELAY_MS);
  LCDSendNibble(2); // Now set the interface to 4-bit mode

  for(u16InitCounter=0; u16InitCounter <= (sizeof(LCD_INIT_STRING)/sizeof(U8)); u16InitCounter++)
  {
    LCDSendByte(LCD_INIT_STRING[u16InitCounter], COMMAND);
  }
  
  delay_ms(INIT_DELAY_MS);
  Lcd_DefineChar(DegreeChar, LCD_DEGREE_SIGN_IDX);
  Lcd_DefineChar(EmptyHeart, LCD_EMPTY_HEART);
  Lcd_DefineChar(FullHeart,  LCD_FULL_HEART);
}
/******************************************************************************/
/*
 * Name:    IF_LCDPutc
 * Purpose: put character to lcd
 * Input: U8 u8CharToLcd
 * Output:none
 *  
 * The following have special meaning:  
 * \f  Clear display                   
 * \n  Go to start of second line  
 * \b  Move back one position  
 */
/******************************************************************************/
void IF_LCDPutc(U8 u8CharToLcd)
{
  switch(u8CharToLcd)
  {
    case '\f':     
      LCDSendByte(LCD_CMD_CLEAR, COMMAND);
      delay_us(CLEAR_LCD_DELAY_US);
    break;
    case '\n':     
      IF_LCDGotoXY(1,2);
    break;    
    case '\b':     
      LCDSendByte(LCD_CMD_SHIFT, COMMAND);
    break;
    break;
    default:    
      LCDSendByte(u8CharToLcd, DATA);
    break;
  }
}

/******************************************************************************/
/*
 * Name:    IF_LCDPutSpecialChar
 * Purpose: 
 * Input: 
 * Output:none
 */
/******************************************************************************/
void IF_LCDPutSpecialChar(U8 X, U8 Y, U8 CharIdx)
{
  switch(CharIdx)
  {
    case LCD_DEGREE_SIGN_IDX:
      Lcd_DefineChar(DegreeChar, LCD_DEGREE_SIGN_IDX);
      IF_LCDGotoXY(X, Y);
      LCDSendByte(LCD_DEGREE_SIGN_IDX, DATA);
    default:
      
      break;
  }
}

/******************************************************************************/
/*
 * Name:    IF_LCDGotoXY()
 * Purpose: goto xy lcd.Set write position on LCD (upper left is 1,1)  
 * Input: U8 x,U8 y
 * Output:none
 */
/******************************************************************************/
void IF_LCDGotoXY(U8 x,U8 y)
{
  U8 u8Addr = LCD_LINE_ADDRESS_1;
  
  if(x > 0 && y > 0)
  {
    if(y == 1)
      u8Addr = LCD_LINE_ADDRESS_1;
    else if(y == 2)
      u8Addr = LCD_LINE_ADDRESS_2;
    else
      mAssert(cFalse);
    
    u8Addr += x - 1;
    u8Addr |= LCD_CMD_DDRAM_ADDR_SET;
  }

  LCDSendByte(u8Addr, COMMAND);
}
/******************************************************************************/
/*
 * Name:    IF_LCDPuts
 * Purpose: put string to lcd
 * Input: U8 *u8StrToLcd
 * Output:none
 */
/******************************************************************************/
void IF_LCDPuts(const char *u8StrToLcd)
{
  if(NULL != u8StrToLcd)
  {
    while(*u8StrToLcd)
    {
      LCDSendByte(*u8StrToLcd, DATA);
      u8StrToLcd++;
    }
  }
  else
  {
    mAssert(cFalse);
  }
}
/******************************************************************************/
/*
 * Name:  
 * Purpose: Display unsigned number
 * Input: Unsigned int
 * Output: none
 */
/******************************************************************************/
void IF_LCDPutn(U32 t)
{
  unsigned char t1,i,wrote;
  U32 k;
  U32 c;
  
  c = t;
  wrote = 0;
  for (i=4; i>=1; i--)
  {
    switch(i)
    {
      case 4: k=10000;
      break;
      case 3: k=1000;
      break;
      case 2: k=100;
      break;
      case 1: k=10;
    }
    t1 = c / k;
    if((wrote) || (t1!=0))
    {
      IF_LCDPutc(t1+'0');
      wrote=  1;
    }
    c -= (t1 * k);
  }
  
  IF_LCDPutc(c+'0');
}
/******************************************************************************/
/*
 * Purpose: Display Current System state in upper right display position
 * Inputs:  none
 * Output:  none
 */
/******************************************************************************/
void IF_LCD_UpdateState(U16 u16CurrentState)
{
  IF_LCDGotoXY(15,1);
  IF_LCDPutn(u16CurrentState);
}

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                       L O C A L   F U N C T I O N S                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*
 * Name: LCDSedndNibble  
 * Purpose: Send Nibble to lcd
 * Input: input param is byte
 * Output:none
 */
/******************************************************************************/
void LCDSendNibble(U8 u8Nibble)
{
  LCD_DATA_WRITE(u8Nibble);
  
  pinLCD_E = 1;
  delay_us(EXEC_DELAY_US);
  pinLCD_E = 0;
  delay_us(EXEC_DELAY_US);
}
/******************************************************************************/
/*
 * Name:    LCDSedndByte 
 * Purpose: Send byte to lcd
 * Input: input param is byte
 * Output:none
 */
/******************************************************************************/
void LCDSendByte(U8 u8ByteToLcd, LCD_REGISTER_TYPE type)
{
  if(type == COMMAND)
  {
    pinLCD_RS = 0;
  }
  else
  {
    pinLCD_RS = 1;
  }
  
  delay_us(EXEC_DELAY_US);

  LCDSendNibble(u8ByteToLcd >> 4);
  LCDSendNibble(u8ByteToLcd & 0xF);
}

/******************************************************************************/
/*
 * Name:   
 * Purpose: 
 * Input: 
 * Output:
 */
/******************************************************************************/
static void Lcd_DefineChar(const U8 ptr[], U8 location)
{
  U8 i;
  U8 command;
  
  if(location < 8)
  {
    command = (LCD_CMD_CGRAM_ADDR_SET + (location * 8));	// write to CG ram
    
    LCDSendByte(command, COMMAND);
    
    for (i = 0; i < 8; i++)
    {
      LCDSendByte(ptr[i], DATA);
    }
  }
}

void LCD_printf(char *format, ...) 
{
//  char buf[LCD_COL_COUNT + 1];
//  va_list args;
//
//  va_start(args, format);
//  sprintf(buf, format, args);
//  va_end(args);
//  
//  IF_LCDPuts(buf);
}

