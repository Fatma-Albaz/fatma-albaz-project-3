/*
 * pwm_timer0_private.h
 *
 *  Created on: Oct 13, 2023
 *      Author: fatma albaz
 */

#ifndef PWM_TIMER0_PRIVATE_H_
#define PWM_TIMER0_PRIVATE_H_
#include "std_types.h"
/********************************************************************************************
 * 									Registers definitions									*
 ********************************************************************************************/
#define OCR0  (*(volatile uint8 *const)0x005C)
#define TCCR0 (*(volatile uint8 *const)0x0053)
#define TCNT0 (*(volatile uint8 *const)0x0052)

#define CS00            0
#define CS01            1
#define CS02            2
#define WGM01           3
#define COM00           4
#define COM01           5
#define WGM00           6
#define FOC0            7
#endif /* PWM_TIMER0_PRIVATE_H_ */
