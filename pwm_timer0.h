/*
 * pwm_timer0.h
 *
 *  Created on: Oct 13, 2023
 *      Author: fatma albaz
 */

#ifndef PWM_TIMER0_H_
#define PWM_TIMER0_H_
#include "std_types.h"
/************************************************************************************************
 * 										Function prototypes										*
 ************************************************************************************************/
/*
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * the range is adjusted to be from 0:100 for the duty cycle
 * 100       :      255
 * duty_cycle:      OCR0 value?!
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_TIMER0_H_ */
