/*
 * lcd4bit.c
 *
 *  Created on: 25-Jun-2019
 *      Author: 
 */
#ifndef lcd4bit
#define lcd4bit
#include <avr/io.h>
#include <util/delay.h>
#define DL _delay_ms(10)

void lcd_init();
void lcd_cmd(char cmd);
void lcd_data(char data);
void lcd_string(char *str);

void lcd_init()
{
	DDRA = 0xff;
	//DDRC |= (1<<0)|(1<<1)|(1<<2);
	lcd_cmd(0x02);
	lcd_cmd(0x28);//2 lines, 5x8 matrix, 4-bit mode
		lcd_cmd(0x01);// Clear the display screen
		lcd_cmd(0x0e); // Display on, cursor blinking
		lcd_cmd(0x80); //  Force the cursor to the beginning of the 2nd line
}

void lcd_cmd (char cmd)
{
	PORTA = (PORTA & 0x0f)|(cmd & 0xf0);// sending upper nibble
	PORTA |= (1<<1);// enable high
		PORTA &= ~ (1<<0);
		DL;
		PORTA &= ~ (1<<1);// enable low
		DL;
		_delay_ms(200);

		PORTA = (PORTA & 0x0f)|(cmd<<4);
		PORTA |= (1<<1);
		DL;
		PORTA &= ~ (1<<1);// enable low
		DL;
}

void lcd_data(char data)
{
	PORTA = (PORTA & 0x0f)|(data & 0xf0);
	PORTA |= ((1<<1)|(1<<0));
		//PORTA &= ~ (1<<1);
		DL;
		PORTA &= ~(1<<1);
		DL;
		PORTA = (PORTA & 0x0f)|(data <<4);
				PORTA |= (1<<1);
				DL;
				PORTA &= ~ (1<<1);// enable low
				DL;
}
void lcd_string(char *str)
{
	while(*str != '\0')
	{
		lcd_data(*str);
		str++;
	}
}
#endif
