/*
 * visitor.c
 *
 *  Created on: 19-Jun-2019
 *      Author: 
 */

#include<avr/io.h>
#include<util/delay.h>
#include<stdlib.h>
#define DL _delay_ms(10);
void lcd_init();
void lcd_cmd(char cmd);
void lcd_data(char data);
void lcd_string(char *str);

void lcd_init()
{
	DDRB = 0xff;
	DDRA |= (1<<0)|(1<<1)|(1<<2);
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0e);
	lcd_cmd(0xc0);
}

void lcd_cmd(char cmd)
{
	PORTB = cmd;
	PORTA |= (1<<2);
	PORTA &= ~ ((1<<1)|(1<<0));
	DL;
	PORTA &= ~ (1<<2);
	DL;
}

void lcd_data(char data)
{
	PORTB = data;
	PORTA |= ((1<<2)|(1<<0));
	PORTA &= ~ (1<<1);
	DL;
	PORTA &= ~(1<<2);
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

int main(void)
{	int count=0;
char c[10];
	int visitor;
	DDRD = 0b00000000;
	DDRC = 0b11111111;

	lcd_init();
	lcd_cmd(0x80);
	while(1)
	{
	if ( (PIND &(0b00000001)) == 0)
	{	PORTC = 0b00000001;
	_delay_ms(1000);
		count ++;
		if(count < 1)
				{
					lcd_cmd(0x01);
					lcd_string("No visitors");
					count = 0;

				}
		else
		{
		itoa(count, c, 10);
		lcd_cmd(0x01);
	    lcd_string(c);
	   //	lcd_data(visitor);
		}
	}

	 if ((PIND &(0b00000010))== 0)
	{	PORTC = 0b00000010;
	_delay_ms(1000);
		count --;
		if(count < 1)
		{
			lcd_cmd(0x01);
			lcd_string("No visitors");
			count = 0;

		}
		else{
		 itoa(count, c, 10);
			lcd_cmd(0x01);
			lcd_string(c);
			//lcd_data(visitor);
		}
	}

	}

}
