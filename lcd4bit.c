/*
 * lcd4bit.c
 *
 *  Created on: 25-Jun-2019
 *      Author: 
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd4bit.h"
#define DL _delay_ms(10)


int main(void)
{
	lcd_init();
	int count;
	//lcd_string(" Sad");
	start:
	lcd_cmd(0x85);
	lcd_string("E Spin ");

	for(count=0 ; count<10 ; count++)
	{
	lcd_cmd(0x1c);
	_delay_ms(1000);
	}

	goto start;
	return 0;

}

