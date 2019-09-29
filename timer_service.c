/*
 * sprint_service.c
 *
 *  Created on: 20 Sep 2019
 *      Author: Yaakoub
 */
#include "REG.h"
#include "macros.h"
#include "timer_service.h"
#include "timer.h"

void timer0_delay_ms(uint_32 delay_value)
{

	while((delay_value>0))
	{
		while(get_bit(TIMER_TIFR_REGISTER,1)==0); // 1ms

			set_bit(TIMER_TIFR_REGISTER,1);
			delay_value--;


	}
}

void timer0_delay_s(uint_32 delay_value)
{

	while(delay_value>0)
	{
		timer0_delay_ms(1000);
	    delay_value--;
	}

}



