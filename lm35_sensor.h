/*
 * lm35.h
 *
 *  Created on: Oct 10, 2023
 *      Author: fatma albaz
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "std_types.h"
/****************************************************************************************
 * 									Definitions										*
 ****************************************************************************************/

#define SENSOR_CHANNEL_ID			2
#define SENSOR_MAX_VOLT_VALUE       1.5
#define SENSOR_MAX_TEMPERATURE      150

/****************************************************************************************
 * 									Function prototypes									*
 ****************************************************************************************/
/*
 *this function is used to initiate the ADC used by the sensor
 *it calls the ADC_init function and passed the required structure
 *to select the configuration (voltage and prescaler).
 */
void LM35_init(void);
/*
 * this function gets the digital value from the ADC
 * the LM35 temperature sensor will give continuous analog output
 * corresponding to the temperature sensed by it. This analog signal
 * is given to the ADC, which converts the analog values to digital values.
 * The digital output of the ADC is equivalent to sensed analog voltage.
 * In order to get the temperature from the sensed analog voltage, we need to perform some
 * calculations in the programming for the MCU.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
