/*
 * seven_seg.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Yaakoub
 */
#include "DIO.h"
#include "reg.h"
#include "DIO_cnfg.h"
#include "seven.h"

uint8_t SEVEN(uint8_t num,uint8_t port_id)
{
	uint8_t retval=OK;
	switch (port_id)
	{
	case PORT_A:
		switch (num)
		{
		case 0:
			PORTA_REG=0b11000000;

			break;
		case 1:
			PORTA_REG=0b11111001;

			break;
		case 2:
			PORTA_REG=0b10100100;

			break;
		case 3:
			PORTA_REG=0b10110000;

			break;
		case 4:
			PORTA_REG=0b10011001;

			break;
		case 5:
			PORTA_REG=0b10010010;

			break;
		case 6:
			PORTA_REG=0b10000010;

			break;
		case 7:
			PORTA_REG=0b11111000;

			break;
		case 8:
			PORTA_REG=0b10000000;

			break;
		case 9:
			PORTA_REG=0b10011001;

			break;


		}




		break;

		case PORT_B:
			switch (num)
			{
			case 0:
				PORTB_REG=0b11000000;

				break;
			case 1:
				PORTB_REG=0b11111001;

				break;
			case 2:
				PORTB_REG=0b10100100;

				break;
			case 3:
				PORTB_REG=0b10110000;

				break;
			case 4:
				PORTB_REG=0b10011001;

				break;
			case 5:
				PORTB_REG=0b10010010;

				break;
			case 6:
				PORTB_REG=0b10000010;

				break;
			case 7:
				PORTB_REG=0b11111000;

				break;
			case 8:
				PORTB_REG=0b10000000;

				break;
			case 9:
				PORTB_REG=0b10011001;

				break;


			}
			break;

			case PORT_C:
				switch (num)
				{
				case 0:
					PORTC_REG=0b11000000;

					break;
				case 1:
					PORTC_REG=0b11111001;

					break;
				case 2:
					PORTC_REG=0b10100100;

					break;
				case 3:
					PORTC_REG=0b10110000;

					break;
				case 4:
					PORTC_REG=0b10011001;

					break;
				case 5:
					PORTC_REG=0b10010010;

					break;
				case 6:
					PORTC_REG=0b10000010;

					break;
				case 7:
					PORTC_REG=0b11111000;

					break;
				case 8:
					PORTC_REG=0b10000000;

					break;
				case 9:
					PORTC_REG=0b10011001;

					break;


				}
				break;

				case PORT_D:
					switch (num)
					{
					case 0:
					PORTD_REG=0b11000000;

						break;
					case 1:
						PORTD_REG=0b11111001;

						break;
					case 2:
						PORTD_REG=0b10100100;

						break;
					case 3:
						PORTD_REG=0b10110000;

						break;
					case 4:
						PORTD_REG=0b10011001;

						break;
					case 5:
						PORTD_REG=0b10010010;

						break;
					case 6:
						PORTD_REG=0b10000010;

						break;
					case 7:
						PORTD_REG=0b11111000;

						break;
					case 8:
						PORTD_REG=0b10000000;

						break;
					case 9:
						PORTD_REG=0b10010000;

						break;


					}
					break;
					default :
						retval =NOK;

	}
	return retval;
}




