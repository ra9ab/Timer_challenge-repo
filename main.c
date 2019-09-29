/*
 * main.c
 *
 *  Created on: 22 Sep 2019
 *      Author: RGB & Yaakoub
 */
#include "avr/interrupt.h"
#include "timer.h"
#include "DIO.h"
#include "timer_service.h"
#include "motor.h"
#include "seven.h"

static uint8_t val = 0 ;
uint8_t pwm_flag = 1 ;
uint8_t retvalue ;
void main ()
{
	  uint8_t loop_counter=0;

    /*Enter you duty_cycle*/
	val = pwm_generation_fnc(90);

      retvalue= DIO_init();
      retvalue= Timer_init();
      set_bit(Interrupt_SREG_REGISTER,7);


		while(1)
		{

			{
				for(loop_counter=0;loop_counter<10;loop_counter++)
				{

					motor_forward();
					SEVEN(loop_counter,PORT_D);
					timer0_delay_s(1);

				}

				SEVEN(9,PORT_D);
				motor_stop();
				timer0_delay_ms(1000);

				for(loop_counter=9;loop_counter>0;loop_counter--)

				{
					SEVEN(loop_counter,PORT_D);
					motor_back();
					timer0_delay_ms(1000);

				}
				SEVEN(0,PORT_D);
				motor_stop();
				timer0_delay_ms(1000);
			}

		}

}


                                  /*ISR*/

ISR(TIMER2_OVF_vect)
{
if(pwm_flag==0)
{
	retvalue=set_preload(2,val);
	DIO_write_pin_value(PORT_B,PIN1,HIGH);
	pwm_flag=1;
}
else if (pwm_flag==1)
{
	retvalue=set_preload(2,255-val);
	DIO_write_pin_value(PORT_B,PIN1,LOW);
	pwm_flag=0;
}

}

