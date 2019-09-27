/*
 * DIO.c
 *
 *  Created on: 9 ,24, 2019
 *      Author: Ya3koob
 */
#include "DIO.h"

/************************************
  * Function Name:DIO_INIT
  * Use:to initialize all required pins (check configuration files)
  * Input:void
  * Return:status(OK,NOK)
 ************************************
  */

uint8_t DIO_init (void)
{
	uint8_t retval = OK;
	uint8_t loop_index = 0;

	if (NUM_OF_PINS>MAX_NUM_OF_PINS) return retval=NOK; //check number of pins



	for(loop_index = 0;loop_index<NUM_OF_PINS;loop_index++)
	{

	if( !(DIO_cnfg_arr[loop_index].PIN>=PIN0 && DIO_cnfg_arr[loop_index].PIN<=PIN7) )
			return retval=NOK;                  //check pin entered

	if(DIO_cnfg_arr[loop_index].DIR == OUTPUT) // check direction

	{
		switch(DIO_cnfg_arr[loop_index].PORT)  // if output check port

		{
		case PORT_A:
			set_bit(DDRA_REG,DIO_cnfg_arr[loop_index].PIN); // set direction as o/p
			break;

		case PORT_B:
			set_bit(DDRB_REG,DIO_cnfg_arr[loop_index].PIN);
			break;

		case PORT_C:
			set_bit(DDRC_REG,DIO_cnfg_arr[loop_index].PIN);
			break;

		case PORT_D:
			set_bit(DDRD_REG,DIO_cnfg_arr[loop_index].PIN);
			break;
		default :
			retval =NOK; // not PORTA,B,C,D
		}

	}
	else if (DIO_cnfg_arr[loop_index].DIR == INPUT)

	{



		switch(DIO_cnfg_arr[loop_index].PORT)

		{
		case PORT_A:

			clr_bit(DDRA_REG,DIO_cnfg_arr[loop_index].PIN); //set direction as i/p

			if (DIO_cnfg_arr[loop_index].RES == PULLUP)  // set res type (pull up or ext)
				set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else {
					return retval=NOK;                 // not pull up or external
			}


			break;

		case PORT_B:

			clr_bit(DDRB_REG,DIO_cnfg_arr[loop_index].PIN);

			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTB_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTB_REG,DIO_cnfg_arr[loop_index].PIN);
			else {

				return retval=NOK;
			}			break;

		case PORT_C:

			clr_bit(DDRC_REG,DIO_cnfg_arr[loop_index].PIN);

			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTC_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTC_REG,DIO_cnfg_arr[loop_index].PIN);
			else {

				return retval=NOK;
			}			break;

		case PORT_D:

			clr_bit(DDRD_REG,DIO_cnfg_arr[loop_index].PIN);

			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTD_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTD_REG,DIO_cnfg_arr[loop_index].PIN);
			else {

				return retval=NOK;
			}			break;
		default :
			retval =NOK;


		}
	}
	else // not input or output
	{
		retval =NOK;

	}



	if(DIO_cnfg_arr[loop_index].OUT == HIGH)
	{switch(DIO_cnfg_arr[loop_index].PORT)

	{
	case PORT_A:
		set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
		break;

	case PORT_B:
		set_bit(PORTB_REG,DIO_cnfg_arr[loop_index].PIN);
		break;

	case PORT_C:
		set_bit(PORTC_REG,DIO_cnfg_arr[loop_index].PIN);
		break;

	case PORT_D:
		set_bit(PORTD_REG,DIO_cnfg_arr[loop_index].PIN);
		break;
	default :
		retval =NOK;


	}

	}
	else if (DIO_cnfg_arr[loop_index].OUT==LOW)
	{
		switch(DIO_cnfg_arr[loop_index].PORT)

		{
		case PORT_A:
			clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);


			break;

		case PORT_B:
			clr_bit(PORTB_REG,DIO_cnfg_arr[loop_index].PIN);

			break;

		case PORT_C:
			clr_bit(PORTC_REG,DIO_cnfg_arr[loop_index].PIN);


			break;

		case PORT_D:
			clr_bit(PORTD_REG,DIO_cnfg_arr[loop_index].PIN);


			break;
		default :
			retval =NOK;

		}
	}
	else
	{
		retval =NOK;

	}
	}
	return retval;
}


/************************************
  * Function Name:DIO_set_pin_direction
  * use:to set certain direction of a pin (i.e Output/Input)
  * Input:port_id,pin_number,value
  * Return:status(OK,NOK)
 ************************************
  */

uint8_t DIO_set_pin_direction(uint8_t port_id,uint8_t pin_number,uint8_t direction)
{

	uint8_t retval = OK;

	if( !(pin_number>=PIN0 && pin_number<=PIN7) )

		return retval=NOK;

	if(direction==OUTPUT)
	{

		switch (port_id)
		{
		case PORT_A:
			set_bit(DDRA_REG,pin_number);
			break;

		case PORT_B:
			set_bit(DDRB_REG,pin_number);
			break;

		case PORT_C:
			set_bit(DDRC_REG,pin_number);
			break;

		case PORT_D:
			set_bit(DDRD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}

	}
	else if (direction ==INPUT)
	{
		switch (port_id)
		{
		case PORT_A:
			clr_bit(DDRA_REG,pin_number);
			break;

		case PORT_B:
			clr_bit(DDRB_REG,pin_number);
			break;

		case PORT_C:
			clr_bit(DDRC_REG,pin_number);
			break;

		case PORT_D:
			clr_bit(DDRD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}

	}
	else
	{
		retval =NOK;
	}
	return retval;

}

/************************************
  * Function Name:DIO_write_pin_value
  * use:to write digital value(0,1) on certain pin
  * Input:port_id,pin_number,value
  * Return:status(OK,NOK)
 ************************************
  */

uint8_t DIO_write_pin_value(uint8_t port_id,uint8_t pin_number,uint8_t value)
{

	uint8_t retval = OK;

	if( !(pin_number>=PIN0 && pin_number<=PIN7) )

		return retval=NOK;


	if( value==HIGH )
	{

		switch (port_id)
		{
		case PORT_A:

			set_bit(PORTA_REG,pin_number);


			break;

		case PORT_B:
			set_bit(PORTB_REG,pin_number);
			break;

		case PORT_C:
			set_bit(PORTC_REG,pin_number);
			break;

		case PORT_D:
			set_bit(PORTD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}
	}


	else if (value==LOW)
	{

		switch (port_id)
		{
		case PORT_A:
			clr_bit(PORTA_REG,pin_number);
			break;

		case PORT_B:
			clr_bit(PORTB_REG,pin_number);
			break;

		case PORT_C:
			clr_bit(PORTC_REG,pin_number);
			break;

		case PORT_D:
			clr_bit(PORTD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}

	}
	else
	{
		retval =NOK;

	}
	return retval;
}
/************************************
  * Function Name:DIO_read_pin_value
  * use:to read a digital value(0,1) from certain pin
  * Input:port_id,pin_number,pointer to put got value in.
  * Return:status(OK,NOK)
 ************************************
  */
uint8_t  DIO_read_pin_value(uint8_t port_id,uint8_t pin_number,uint8_t* got)
{
	uint8_t retval = OK;

	if(! (pin_number>=PIN0 && pin_number<=PIN7) )

		return retval=NOK;



	switch (port_id)
	{
	case PORT_A:
		*got=get_bit(PINA_REG,pin_number);
		break;

	case PORT_B:
		*got=get_bit(PINB_REG,pin_number);
		break;

	case PORT_C:
		*got=get_bit(PINC_REG,pin_number);
		break;

	case PORT_D:
		*got=get_bit(PIND_REG,pin_number);
		break;
	default :
		retval=NOK;
	}
	return retval;

}

/************************************
  * Function Name:DIO_set_port_direction
  * use:to set certain direction of a pin (i.e Output/Input )
  * Input:port_id,value that express direction (i.e 0x0f)
  * Return:status(OK,NOK)
 ************************************
  */
uint8_t DIO_set_port_direction(uint8_t port_id,uint8_t value)
{
	uint8_t retval = OK;


	if(! (value>=0 && value<=255) )

		return retval=NOK;

	switch (port_id)
	{
	case PORT_A:
		DDRA_REG=value;
		break;

	case PORT_B:
		DDRB_REG=value;
		break;

	case PORT_C:
		DDRC_REG=value;
		break;

	case PORT_D:
		DDRD_REG=value;
		break;
	default:
		retval=NOK;
	}
	return retval;

}
/************************************
  * Function Name:DIO_write_pin_value
  * use:to write digital value(0,1) on the port (i.e 0xff all output)
  * Input:port_id,pin_number,value
  * Return:status(OK,NOK)
 ************************************
  */
uint8_t DIO_write_port_value(uint8_t port_id,uint8_t value)
{
	uint8_t retval = OK;


	if(! (value>=0 && value<=255) )

		return retval=NOK;

	switch (port_id)
	{
	case PORT_A:
		PORTA_REG=value;
		break;

	case PORT_B:
		PORTB_REG=value;
		break;

	case PORT_C:
		PORTC_REG=value;
		break;

	case PORT_D:
		PORTD_REG=value;
		break;
	default:
		retval=NOK;
	}
	return retval;
}
/************************************
  * Function Name:DIO_read_port_value
  * use:to read a digital value(0,1) from certain pin
  * Input:port_id,,pointer to put got value in.
  * Return:status(OK,NOK)
 ************************************
  */
uint8_t DIO_read_port_value(uint8_t port_id,uint8_t* got)

{
	uint8_t retval = OK;

	switch (port_id)
	{
	case PORT_A:
		*got=PINA_REG;
		break;

	case PORT_B:
		*got=PINB_REG;
		break;

	case PORT_C:
		*got=PINC_REG;
		break;

	case PORT_D:
		*got=PIND_REG;
		break;
	default:
		retval=NOK;
	}

	return retval;


}

