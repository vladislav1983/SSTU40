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
#define LCD_TYPE            2u
#define LCD_LINE_ADDRESS_1     0x00u
#define LCD_LINE_ADDRESS_2    0x40u

/* Display ON/OFF Control defines */
#define DON         0b00001111  /* Display on      */
#define DOFF        0b00001011  /* Display off     */
#define CURSOR_ON   0b00001111  /* Cursor on       */
#define CURSOR_OFF  0b00001101  /* Cursor off      */
#define BLINK_ON    0b00001111  /* Cursor Blink    */
#define BLINK_OFF   0b00001110  /* Cursor No Blink */

/* Cursor or Display Shift defines */
#define SHIFT_CUR_LEFT    0b00010011  /* Cursor shifts to the left   */
#define SHIFT_CUR_RIGHT   0b00010111  /* Cursor shifts to the right  */
#define SHIFT_DISP_LEFT   0b00011011  /* Display shifts to the left  */
#define SHIFT_DISP_RIGHT  0b00011111  /* Display shifts to the right */

/* Function Set defines */
#define FOUR_BIT   0b00101111  /* 4-bit Interface               */
#define EIGHT_BIT  0b00111111  /* 8-bit Interface               */
#define LINE_5X7   0b00110011  /* 5x7 characters, single line   */
#define LINE_5X10  0b00110111  /* 5x10 characters               */
#define LINES_5X7  0b00111011  /* 5x7 characters, multiple line */

// Rev1 additional WH Tan
// Addtional define to support display mode
#define DISP_FLIP_NONE            0b00111100  /* No flip                             */
#define DISP_FLIP_VERTICAL        0b00111101    /* Flip both vertically & horizontally */
#define DISP_FLIP_HORIZONTAL    0b00111110    /* Flip horizontally                   */
#define DISP_FLIP_BOTH            0b00111111    /* Flip vertically                     */
// End Rev1

// Rev1 additional WH Tan
// Addtional define to support entry mode & shift mode
#define ENTRY_CURSOR_DEC          0b00000101    /* Entry cause cursor move to left  */
#define ENTRY_CURSOR_INC        0b00000111    /* Entry cause cursor move to right */
#define ENTRY_DISPLAY_SHIFT        0b00000111     /* Entry cause the display to shift */
#define ENTRY_DISPLAY_NO_SHIFT  0b00000110    /* Entry cuase no shift             */

// Address defines
// 4 lines X 20 characters LCD
#ifdef LCD_4X20
#define LINE0    0x00
#define LINE1    0x40
#define    LINE2    0x14
#define LINE3    0x54
#endif

// 2 lines X 20 characters LCD
#ifdef LCD_2X20
#define LINE0    0x00
#define LINE1    0x40
#else

// Use generic address
#define LINE0    0x00
#define LINE1    0x40
#define    LINE2    0x14
#define LINE3    0x54
#endif

#define LCD_COL_COUNT 16

/*----------------------------------------------------------------------------*/
/* Local macros                                                               */
/*----------------------------------------------------------------------------*/
#define LCD_DATA_WRITE(DATA_NIBBLE)        pinLCD_DB4 = DATA_NIBBLE;        \
                                        pinLCD_DB5 = DATA_NIBBLE >> 1;    \
                                        pinLCD_DB6 = DATA_NIBBLE >> 2;    \
                                        pinLCD_DB7 = DATA_NIBBLE >> 3;        

/*----------------------------------------------------------------------------*/
/* Local types                                                                */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Local data                                                                 */
/*----------------------------------------------------------------------------*/
const U8 LCD_INIT_STRING[4] = 
    {
    0x20 | (LCD_TYPE << 2), // Func set: 4-bit, 2 lines, 5x8 dots 
    0xc,                    // Display on             
     1,                        // Clear display 
     6                        // Increment cursor 
     };

U16 u16Nibble_Temp;
static char lcd_buffer[LCD_COL_COUNT + 1];

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
void LCDSendNibble(U8 u8Nibble);
void LCDSendByte(U8 u8ByteToLcd,U8 u8Adress);

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
    delay_ms(15);
    
    for(u16InitCounter=1;u16InitCounter<=3;++u16InitCounter)
    {
        LCDSendNibble(3);
        delay_ms(5);
    }//end for
    
    LCDSendNibble(2);
    
    for(u16InitCounter=0;u16InitCounter<=3;++u16InitCounter)
    {
        LCDSendByte(LCD_INIT_STRING[u16InitCounter],0);    
    }//end for
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
    case '\f':     LCDSendByte(1,0);
                delay_us(120);
                break;
    
    case '\n':     IF_LCDGotoXY(1,2);
                break;    
    case '\b':     LCDSendByte(0x10,0);
                break;        
    default:    LCDSendByte(u8CharToLcd,1);

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
    U8 u8Addr;
    
    if(y!=1)
    {
        u8Addr = LCD_LINE_ADDRESS_2;
    }//end if
    else
    u8Addr = 0;
    
    u8Addr+=x-1;
    LCDSendByte(0x80|u8Addr,0);
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
    //U16 u16CharCount;
    
    //u16CharCount = strlen(u8StrToLcd);
    while(*u8StrToLcd)
    {
        LCDSendByte(*u8StrToLcd,1);
        u8StrToLcd++;
    //u16CharCount--;
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
    for (i=4;i>=1;i--)
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
    Nop();
    pinLCD_E = 1;
    delay_us(3);
    pinLCD_E = 0;

}
/******************************************************************************/
/*
 * Name:    LCDSedndByte 
 * Purpose: Send byte to lcd
 * Input: input param is byte
 * Output:none
*/
/******************************************************************************/
void LCDSendByte(U8 u8ByteToLcd,U8 u8Adress)
{
    pinLCD_RS = 0;
    delay_us(10);
    pinLCD_RS = u8Adress;
    Nop();
    Nop();
    pinLCD_E = 0;
    LCDSendNibble(u8ByteToLcd >> 4);
    LCDSendNibble(u8ByteToLcd & 0xF);
}

void LCD_printf(char *format, ...) 
{
//  va_list args;
//
//  va_start(args, format);
//  vsnprintf(lcd_buffer, LCD_COL_COUNT + 1, format, args);
//  va_end(args);

  IF_LCDPuts(lcd_buffer);
}

