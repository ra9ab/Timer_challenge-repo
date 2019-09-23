/*
 * sprint_timer_conf.c
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */

#include "timer.h"

	/* Timers configrations */

 TIMER_cnfg_t TIMER_cnfg_arr [MAX_NUM_OF_TIMERS] =
	{
		/* Timer 0 */
		{
			USED,
			NORMAL,
			YES,
			NO,
			0,
			NP,
			prescaler_8,
			NP,
			NP
		},
		/* Timer 1 */
		{
		    USED,
			FAST_PWM,
			NO,
			YES,
			NP,
			128,
			prescaler_8,
			OC1A,
			NP
		},
		/* Timer 2 */
		{
			NOT_USED,
			NP,
			NP,
			NP,
			NP,
			NP,
			NP,
			NP,
			NP
		}
	};





