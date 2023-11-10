/*
 * dc_motor.c
 *
 *  Created on: Oct 13, 2023
 *      Author: fatma albaz
 */

#include "gpio.h"
#include "dc_motor.h"
#include "pwm_timer0.h"
void DcMotor_init(void){
	/*set DC motor pins direction*/
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_PIN0,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1,PIN_OUTPUT);
	/*make it's initial value as stop*/
	GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN0,DC_MotorStop);
	GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1,DC_MotorStop);
	/*or stop can be by this method
	 * PORTC= (PORTC&~0x02);
	 * or
	 * PORTC= (PORTC&~0x02)|(DC_MotorStop);
	 */
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	PWM_Timer0_Start(speed);
	if (state == DC_MotorStop){
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN0,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1,LOGIC_LOW);
	}
	else if (state == DC_MotorCW){
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN0,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1,LOGIC_LOW);
	}
	else if (state == DC_MotorCCW){
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN0,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID,DC_MOTOR_PIN1,LOGIC_HIGH);
	}
}
