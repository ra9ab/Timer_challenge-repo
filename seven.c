/*
 * seven_seg.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Yaakoub
 */
#include "DIO.h"
#include "seven.h"

uint8_t SEVEN(uint8_t num,uint8_t port_id)
{
	uint8_t retval=OK;


		switch (num)
		{
		case 0:
			DIO_write_port_value(port_id,0b11000000);

			break;
		case 1:
			DIO_write_port_value(port_id,0b11111001);

			break;
		case 2:
			DIO_write_port_value(port_id,0b10100100);

			break;
		case 3:
			DIO_write_port_value(port_id,0b10110000);

			break;
		case 4:
			DIO_write_port_value(port_id,0b10011001);

			break;
		case 5:
			DIO_write_port_value(port_id,0b10010010);

			break;
		case 6:
			DIO_write_port_value(port_id,0b10000010);

			break;
		case 7:
			DIO_write_port_value(port_id,0b11111000);

			break;
		case 8:
			DIO_write_port_value(port_id,0b10000000);

			break;
		case 9:
			DIO_write_port_value(port_id,0b10010000);

			break;
		default:
			retval=NOK;

		}


	return retval;
}

