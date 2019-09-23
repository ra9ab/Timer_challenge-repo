/*
 * sprint_Timer.c
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */
#include "timer.h"
#include "REG.h"
uint8_t  prescaler_fnc (uint8_t timer , uint8_t pre_scaler) ;
uint8_t mode_fnc (uint8_t timer , uint8_t Mode) ;


uint8_t retvalue = OK ;

uint8_t Timer_init(void)
{
	uint8_t loop_index = 0;

	for(loop_index=0;loop_index<MAX_NUM_OF_TIMERS;loop_index++)
	{
		if(TIMER_cnfg_arr[loop_index].used==USED)
		{
			retvalue = prescaler(loop_index,TIMER_cnfg_arr[loop_index].prescaler);
			retvalue = mode_fnc(loop_index,TIMER_cnfg_arr[loop_index].mode);
		}
		else if(TIMER_cnfg_arr[loop_index].used==NOT_USED)
		{

		}
		else
		{
			retvalue=NOK;
		}


	}










	return retvalue ;
}


uint8_t prescaler_fnc (uint8_t timer , uint8_t pre_scaler)
{
	switch (timer)
	{
		case 0 :
			TIMER_TCCR0_REGISTER |= pre_scaler ;
			break ;
		case 1 :
			TIMER_TCCR1B_REGISTER |= pre_scaler ;
			break ;
		case 2 :
			TIMER_TCCR2_REGISTER |= pre_scaler ;
			break ;
		default :
			retvalue = NOK;
			break ;
	}
	return retvalue ;
}

uint8_t mode_fnc (uint8_t timer , uint8_t Mode)
{
	switch (timer)
		{

		}
		return retvalue ;


}

