/*
 * tempfan.c
 *
 *  Created on: 26-Jun-2019
 *      Author: 
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define DL _delay_ms(10);

void lcd_init();
void lcd_cmd(char cmd);
void lcd_data(char data);
void lcd_string(char *str);

void lcd_init()
{
	DDRD = 0xff;
	DDRC |= (1<<0)|(1<<1)|(1<<2);
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0e);
	lcd_cmd(0xc0);
}

void lcd_cmd(char cmd)
{
	PORTD = cmd;
	PORTC |= (1<<2);
	PORTC &= ~ ((1<<1)|(1<<0));
	DL;
	PORTC &= ~ (1<<2);
	DL;
}

void lcd_data(char data)
{
	PORTD = data;
	PORTC |= ((1<<2)|(1<<0));
	PORTC &= ~ (1<<1);
	DL;
	PORTC &= ~(1<<2);
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
{
	int num=0;
	char  str[10];
	lcd_init();
	DDRA = 0b00000000;
	DDRB = 0b11111111;
	ADCSRA = 0x87;
	ADMUX = 0xc0;

			while(1)
			{
				ADCSRA |= (1<<ADSC);
				while( (ADCSRA &(0b00010000))== 0)
					_delay_ms(100);
					num = ADC/4;

					_delay_ms(100);
				itoa(num, str, 10);


				lcd_cmd(0x80);
				lcd_string("Set temp: 35");

				lcd_cmd(0xc0);
				lcd_string("Current temp:");
				lcd_string(str);
				_delay_ms(500);

				if(num <35)
													{

															_delay_ms(1000);
															DDRB = 0b11111111;
															PORTB = 0b00000001;
															_delay_ms(3000);


													}
													if(num >35)
																	{

																			_delay_ms(1000);
																			DDRB = 0b11111111;
																			PORTB = 0b00000100;
																			_delay_ms(3000);


																	}

								if(num==35)
								{
									PORTB =0b00000000;
								}




			}

}

