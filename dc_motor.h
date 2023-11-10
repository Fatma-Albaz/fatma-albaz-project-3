/*
 * dc_motor.h
 *
 *  Created on: Oct 13, 2023
 *      Author: fatma albaz
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"
/********************************************************************************************
 * 										definitions											*
 ********************************************************************************************/
#define DC_MOTOR_PIN0           PIN0_ID
#define DC_MOTOR_PIN1			PIN1_ID

#define DC_MOTOR_PORT_ID        PORTB_ID

typedef enum{
	DC_MotorStop,DC_MotorCW,DC_MotorCCW
}DcMotor_State;

void DcMotor_init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
