/*
 * DIO_cnfg.h
 *
 * Created: 23 , 9 , 2019
 *  Author: Ya3koob
 */


#ifndef DIO_CNFG_H_
#define DIO_CNFG_H_

#define NUM_OF_PINS 1

#include "std_types.h"

typedef struct
{
	uint8_t PORT;
	uint8_t PIN;
	uint8_t DIR;
	uint8_t OUT;
	uint8_t RES;
}DIO_cnfg_pin;

extern DIO_cnfg_pin DIO_cnfg_arr[NUM_OF_PINS];



#endif /* DIO_CNFG_H_ */
