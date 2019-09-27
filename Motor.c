/*
 * Motor.h
 *
 *  Created on: Sep 27, 2019
 *
 *      Author: Ya3koob
 */
#include "DIO.h"
void motor_forward(void)
{
	DIO_write_pin_value(PORT_C,PIN0,LOW);
	DIO_write_pin_value(PORT_C,PIN1,HIGH);
}
void motor_stop(void)
{
	DIO_write_pin_value(PORT_C,PIN0,LOW);
	DIO_write_pin_value(PORT_C,PIN1,LOW);
}
void motor_back(void)
{
	DIO_write_pin_value(PORT_C,PIN0,HIGH);
	DIO_write_pin_value(PORT_C,PIN1,LOW);
}

