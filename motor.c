/*
 * motor.c
 *
 *  Created on: 18-Jun-2019
 *      Author: 
 */
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	while(1)
	{
	DDRD = 0b11111111;
	PORTD = 0b00000001;
	_delay_ms(500);
	PORTD = 0b00000010;
	_delay_ms(500);
	}
}
