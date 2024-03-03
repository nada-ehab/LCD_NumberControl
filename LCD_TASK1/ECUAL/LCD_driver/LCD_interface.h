
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*******************************************************************************************/
/*********************************macros****************************************************/
/*******************************************************************************************/

/*********/
/*#if      CLCD_MODE ==  4
#define  4BITS_MODE    0x28
#if      CLCD_MODE ==  8
#define  8BITS_MODE    0x38*/

/*******************************************************************************************/
#define ROW1  1
#define ROW2  2

#define LCD_PIN_1   1
#define LCD_PIN_2   2
#define LCD_PIN_3   3
#define LCD_PIN_4   4
#define LCD_PIN_5   5
#define LCD_PIN_6   6
#define LCD_PIN_7   7
#define LCD_PIN_8   8
#define LCD_PIN_9   9
#define LCD_PIN_10  10
#define LCD_PIN_11  11
#define LCD_PIN_12  12
#define LCD_PIN_13  13
#define LCD_PIN_14  14
#define LCD_PIN_15  15
#define LCD_PIN_16  16
/*******************************************************************************************/

/*4bit mode commands*/

#define LCD_functionReset     0x30
#define LCD_functionSet2      0x20
#define LCD_FunctionSet3      0x80
#define LCD_Displaycontrol    0x38
#define LCD_Displayclear      0x10
#define LCD_EntryModeSet      0x60

/******************************function declaration***********************************/

void CLCD_init_lcd       (void);

void CLCD_send_command   (uint8_t get_command);

void CLCD_send_data      (uint8_t get_data);

void CLCD_SendString     (const uint8_t *ptr_string);

void CLCD_ClearScreen    (void);

void CLCD_voidSendString  ( const uint8_t * Copy_u8ptrString );

void LCD_SendIntegarNumber(uint16_t IntegerNumber);

#endif

