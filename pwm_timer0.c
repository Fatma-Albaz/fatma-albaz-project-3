/*
 * pwm_timer0.c
 *
 *  Created on: Oct 13, 2023
 *      Author: fatma albaz
 */

#include "gpio.h"
#include "pwm_timer0.h"
#include "pwm_timer0_private.h"
#include "common_macros.h"
/************************************************************************************************
 * 										Function declarations									*
 ************************************************************************************************/
/*
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * the range is adjusted to be from 0:100 for the duty cycle
 * 100       :      255
 * duty_cycle:      OCR0 value?!
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;
	duty_cycle=(uint8)(((float32)duty_cycle*255)/100);/*to make the range from 0:100*/
	OCR0= duty_cycle;
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);/*set OC0 pin as output */
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);/*PWM, Fast PWM mode*/
	SET_BIT(TCCR0,COM01);/*PWM, Non inverting mode*/
	SET_BIT(TCCR0,CS01);/*prescaler 8*/
}
