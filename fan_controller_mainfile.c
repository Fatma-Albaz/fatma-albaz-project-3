/*
 * fan_controller_mainfile.c
 *
 *  Created on: Oct 13, 2023
 *      Author: fatma albaz
 */

#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
/*
 * this function in used to display the temperature reading
 * from the temperature sensor and adjusting the place for
 * it at row 1
 * the cursor adjustment is to avoid values overwriting on LCD
 * and fix the display position
 */
void LCD_DiplayTemp (uint8 sensed_value);
/*
 * The aim of this project is to design a temperature-controlled fan using ATmega32
 * MCU, in which the fan is automatically turned ON or OFF according to the
 * temperature. Use ATmega32 MCU with frequency 1Mhz.
 */
int main (void){
	uint8 sensed_value=0;
	/*
	 * calling initial functions for the created drivers
	 * LCD
	 * ADC
	 * DC_motor.
	 */
	LCD_init();
	LM35_init();
	DcMotor_init();
	/*
	 * infinite loop
	 */
	for(;;){
		/*get the sensor temperature value*/
		sensed_value=LM35_getTemperature();
		/* Display the temperature value every time at same position */
		LCD_DiplayTemp(sensed_value);
		/*
		 * Checking on the temperature to control the fan
		 */
		LCD_moveCursor(0,0);
		if (sensed_value<30){
			/*
			 * a. If the temperature is less than 30C turn off the fan.
			 */
			DcMotor_Rotate(DC_MotorStop,0);
			LCD_displayString("Fan is off     ");
		}
		else if (sensed_value<60){
			DcMotor_Rotate(DC_MotorCW,25);
			LCD_displayString("Fan is On :25% ");
		}
		else if (sensed_value<90){
			/*
			 * b. If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed.
			 */
			DcMotor_Rotate(DC_MotorCW,50);
			LCD_displayString("Fan is On :50% ");
		}
		else if (sensed_value<120){
			/*
			 * c. If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed
			 */
			DcMotor_Rotate(DC_MotorCW,75);
			LCD_displayString("Fan is On :75% ");
		}
		else {
			/*
			 * d. If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.
			 */
			DcMotor_Rotate(DC_MotorCW,100);
			LCD_displayString("Fan is On :100%");
		}
	}
	return 0;
}
/*
 * this function in used to display the temperature reading
 * from the temperature sensor and adjusting the place for
 * it at row 1
 * the cursor adjustment is to avoid values overwriting on LCD
 * and fix the display position
 */
void LCD_DiplayTemp (uint8 sensed_value){
	LCD_moveCursor(1,0);
	LCD_displayString("temp = ");
	LCD_moveCursor(1,9);
	if(sensed_value >= 100)
	{
		LCD_intToStringDisplay(sensed_value);
	}
	else
	{
		LCD_intToStringDisplay(sensed_value);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayChar(' ');
	}
}
