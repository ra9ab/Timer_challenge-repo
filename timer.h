/*
 * sprint_timer.h
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */

#ifndef TIMER_H_
#define TIMER_H_


#include "timer_conf.h"



#define OK  50
#define NOK 51

#define NORMAL 	      62
#define COMPER        63
#define FAST_PWM      64
#define PHASE_CORRECT 65


#define YES   10
#define NO    11

#define NOT_USED  20
#define USED      21


#define OC0       30
#define OC2       31
#define OC1A      32
#define OC1B      33
#define OC1AB     34


#define prescaler_1      1
#define prescaler_8      2
#define prescaler_64     3
#define prescaler_256    4
#define prescaler_1024   5

#define prescaler_mask  7
#define NP   0xff

/*APIS*/
uint8_t Timer_init(void);
uint8_t Timer_SetPreLoad(uint8_t Preload_Val, uint8_t TimerId);
uint8_t Timer_SetCompareVal(uint8_t cmp_Val, uint8_t TimerId);
uint8_t Timer_PWM(uint8_t TimerId ,uint8_t duty_cycle);


#endif /* TIMER_H_ */
