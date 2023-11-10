/*
 * adc_private.h
 *
 *  Created on: Oct 10, 2023
 *      Author: fatma albaz
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
#include "std_types.h"
/********************************************************************************************************
 * 									ADC Registers definitions											*
 ********************************************************************************************************/
#define ADMUX  		(*(volatile uint8  * const )0x0027)
#define ADCSRA 		(*(volatile uint8  * const )0x0026)
#define ADC    		(*(volatile uint16 * const )0x0024)

#ifndef SFIOR
#define SFIOR   	(*(volatile uint8  * const )0x0050)
#endif

/********************************************************************************************************
 * 									ADC PINS definitions												*
 ********************************************************************************************************/
#define MUX0				0
#define MUX1				1
#define MUX2				2
#define MUX3				3
#define MUX4				4
#define ADLAR				5
#define REFS0				6
#define REFS1				7

#define ADPS0				0
#define ADPS1				1
#define ADPS2				2
#define ADIE				3
#define ADIF				4
#define ADATE				5
#define ADSC				6
#define ADEN				7

#define ADTS0				5
#define ADTS1				6
#define ADTS2				7



#endif /* ADC_PRIVATE_H_ */
