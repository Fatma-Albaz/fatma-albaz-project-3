/*
 * lm35.c
 *
 *  Created on: Oct 10, 2023
 *      Author: fatma albaz
 */

#include "lm35_sensor.h"
#include "adc.h"
/****************************************************************************************
 * 									Function declarations								*
 ****************************************************************************************/
/*
 *this function is used to initiate the ADC used by the sensor
 *it calls the ADC_init function and passed the required structure
 *to select the configuration (voltage and prescaler).
 */
void LM35_init(void){
	ADC_ConfigType configuration={ADC_InternalAREF,ADC_PrescalerBy8};/*initial structure for the ADC*/
	ADC_init(&configuration);
}
/*
 * this function gets the digital value from the ADC
 * the LM35 temperature sensor will give continuous analog output
 * corresponding to the temperature sensed by it. This analog signal
 * is given to the ADC, which converts the analog values to digital values.
 * The digital output of the ADC is equivalent to sensed analog voltage.
 * In order to get the temperature from the sensed analog voltage, we need to perform some
 * calculations in the programming for the MCU.
 */
uint8 LM35_getTemperature(void){
	/* Read ADC channel where the temperature sensor is connected */
	uint8  temp=0;
	uint16 digital_temperature= ADC_readChannel(SENSOR_CHANNEL_ID);
	/* Calculate the temperature from the ADC value*/
	temp= (uint8)(((uint32)digital_temperature*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAX_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp;
}
