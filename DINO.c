/*
 * DINO.c
 *
 *  Created on: 30-Jul-2019
 *      Author: 
 */
#include<avr/io.h>
#include<util/delay.h>
#define DL _delay_ms(10);
#include<stdlib.h>
void lcd_init();
void lcd_cmd(char cmd);
void lcd_data(char data);
void lcd_string(char *str);

void lcd_init()
{
	DDRD = 0xff;
	DDRC |= (1<<0)|(1<<1)|(1<<2);
	lcd_cmd(0x38);//2 lines, 5x8 matrix, 8-bit mode
	lcd_cmd(0x01);// Clear the display screen
	lcd_cmd(0x0e); // Display on, cursor blinking
	lcd_cmd(0xc0); //  Force the cursor to the beginning of the 2nd line
}

void lcd_cmd(char cmd)
{
	PORTD = cmd;
	PORTC |= (1<<2);// enable high
	PORTC &= ~ ((1<<1)|(1<<0));
	DL;
	PORTC &= ~ (1<<2);// enable low
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
{	DDRA = 0x00;
    int flag=0;
	int count;
	int score=0;
	char c[10];
	lcd_init();

	//lcd_string("My name is");
	start:
	lcd_cmd(0xc6);
	lcd_string("^_^ ");
	lcd_cmd(0xc0);
	//lcd_string(":* ");


	for(count=0 ; count<16 ; count++)
	{


	lcd_cmd(0x14);
	_delay_ms(250);
	if(count==4 && (PINA &(0b00000001))==0)
	{
		lcd_cmd(0x85);
		flag=1;
		score++;
	}
	else if(count==4 && (PINA &(0b00000001))!=0)
	{
		lcd_cmd(0x01);
		itoa(score, c ,10);
		lcd_string("GAME OVER!");
		lcd_cmd(0xc0);
		lcd_string("SCORE : ");
		lcd_string(c);

		_delay_ms(2000);
		score = 0;
		lcd_cmd(0x01);
		lcd_string("NEW GAME");
		_delay_ms(500);
		lcd_cmd(0x01);
		goto start;
	}
	if(count==7 && flag==1)
	{
		lcd_cmd(0xc8);
	}
	}

	goto start;

	return 0;

}

