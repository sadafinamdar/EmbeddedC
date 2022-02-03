/*
 * metrosystem.c
 *
 *  Created on: 25-Jun-2019
 *      Author: 
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd4bit.h"
#include "stepper.h"
#define DL _delay_ms(10)

int main(void)
{
	DDRA = 0x00;
	DDRC = 0xff;
	lcd_init();
	while(1)
	{
		if ( (PINA & (0b00000001))== 0)
		{


			lcd_string("Departed from ");
			lcd_cmd(0xc0);
			lcd_string("Panvel");
			_delay_ms(1000);
			stepper_func();
			_delay_ms(3000);
		}
	}

}
