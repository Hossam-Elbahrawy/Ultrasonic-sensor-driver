
/*
 * LCD.c
 *
 * Author : Hossam Elbahrawy
 */
#include "LCD.h"

/*
*Function name 	: lcd_init
*Parameters	    : void
*return		   		: void
*purpose       	: initialize LCD pins as output
*				 		and seting up the operation mode(4-bit)
*						default setting (cursor on)
*/
void lcd_init(void)
{

	DATA_DDR = (1<<LCD_D7) | (1<<LCD_D6) | (1<<LCD_D5)| (1<<LCD_D4);
	CTL_DDR |= (1<<LCD_EN)|(1<<LCD_RW)|(1<<LCD_RS);

	DATA_BUS = (0<<LCD_D7)|(0<<LCD_D6)|(1<<LCD_D5)|(0<<LCD_D4);
	CTL_BUS|= (1<<LCD_EN)|(0<<LCD_RW)|(0<<LCD_RS);

	_delay_ms(5);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(5);

	lcd_send_command(LCD_CMD_4BIT_2ROW_5X7);
	_delay_ms(5);
	lcd_send_command(LCD_CMD_DISPLAY_CURSOR_BLINK);
	_delay_ms(5);
	lcd_send_command(0x80);

}

/*
*Function name 	: lcd_send_command
*Parameters	    : uint8_t command
*return		   		: void
*purpose       	: sending a command to LCD by sending
*				 		the first nibble then the second nibble
*						enabling and disabling the LCD in between
*/
void lcd_send_command (uint8_t command)
{
	DATA_BUS=((command&0b11110000));
	CTL_BUS &=~(1<<LCD_RS);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(5);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(5);
	DATA_BUS=((command&0b00001111)<<4);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(5);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(5);
}

/*
*Function name 	: lcd_write_word
*Parameters	    : uint8_t word[20]
*return		   		: void
*purpose       	: printing a full word to the
*				 		LCD (Maximun 20 characters)
*/
void lcd_write_word(uint8_t word[20])
{
	int i=0;
	while(word[i]!='\0')
	{
		lcd_write_character(word[i]);
		i++;
	}
}

/*
*Function name 	: lcd_write_character
*Parameters	    : uint8_t character
*return		   		: void
*purpose       	: sending one characterto LCD by sending
*				 		 the first nibble first then the second nibble
*						 enabling and disabling the LCD in between
*/
void lcd_write_character(uint8_t character)
{

	DATA_BUS=((character & 0b11110000));
	CTL_BUS|=(1<<LCD_RS);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(5);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(5);
	DATA_BUS=((character & 0b00001111)<<4);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(5);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(5);
}

/*
*Function name 	: lcd_clear
*Parameters	    : void
*return		   		: void
*purpose       	: Clearing the lcd screen by sending
*				 	the LCD_CMD_CLEAR_DISPLAY command to LCD
*/
void lcd_clear(void)
{
	lcd_send_command(LCD_CMD_CLEAR_DISPLAY);
	_delay_ms(5);
}
void lcd_goto_xy (uint8_t line,uint8_t pos)				//line = 0 or 1
{
	lcd_send_command((0x80|(line<<6))+pos);
	_delay_us (50);
}
