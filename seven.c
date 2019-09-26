/*
 * seven.c
 *
 *  Created on: May 4, 2019
 *      Author: free bytes
 */
#include<avr/delay.h>
#include "seven.h"
#include "reg.h"
#include "DIO.h"
void main(void)
{
	/*
	DDRA=0xff;
	DDRD=0xff;
	s8 x=5;
	PORTD=0b10010010;

	// volt for common in 7 seg not from 5v for safety wise
while(1)

{

PORTA=0b10010000; //9
_delay_ms(1000);
PORTA=0b10000000; //8
_delay_ms(1000);
PORTA=0b11111000; //7
_delay_ms(1000);
PORTA=0b10000010; //6
_delay_ms(1000);
PORTA=0b10010010; //5
_delay_ms(1000);
PORTA=0b10011001; //4
_delay_ms(1000);
PORTA=0b10110000; //3
_delay_ms(1000);
PORTA=0b10100100; //2
_delay_ms(1000);
PORTA=0b11111001; //1
_delay_ms(1000);
PORTA=0b11000000; //0
_delay_ms(1000);
x--;
if(x==-1)
{
	_delay_ms(10000);
	x=5;
	PORTD=0b10010010;
}


switch(x)
{
case 0:
	PORTD=0b11000000;

	break;
case 1:
	PORTD=0b11111001;

	break;
case 2:
	PORTD=0b10100100;

	break;
case 3:
	PORTD=0b10110000;

	break;
case 4:
	PORTD=0b10011001;

	break;

}


	}
	*/
	DIO_set_port_direction(PORT_D,0xff);
	while(1)
	{
		for(uint8_t i=0;i<10;i++)
	{

		SEVEN(i,PORT_D);
		_delay_ms(500);

	}
	}
}


