/*
 * adc.h
 *
 *  Created on: Oct 9, 2023
 *      Author: fatma albaz
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
/****************************************************************************************
 * 										Definitions										*
 ****************************************************************************************/

#define ADC_MAX_VALUE        1023
#define ADC_REF_VOLT_VALUE   2.56


/****************************************************************************************
 * 									Data types declarations								*
 ****************************************************************************************/
typedef enum{
	ADC_PrescalerBy2,
	ADC_PrescalerBy2SecOp,
	ADC_PrescalerBy4,
	ADC_PrescalerBy8,
	ADC_PrescalerBy16,
	ADC_PrescalerBy32,
	ADC_PrescalerBy64,
	ADC_PrescalerBy128
}ADC_Prescaler;

typedef enum{
	ADC_ExternalAREF, ADC_ExternalAVCC, ADC_InternalAREF=3
}ADC_ReferenceVolatge;

typedef enum{
	ADC_FreeRummingMode,
	ADC_AnalogComparator,
	ADC_ExternalInterruptRequest0,
	ADC_TimerCounter0CompareMatch,
	ADC_TimerCounter0Overflow,
	ADC_TimerCounter1CompareMatchB,
	ADC_TimerCounter1Overflow,
	ADC_TimerCounter1CaptureMatch
}ADC_AutoTriggerSource;

typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/****************************************************************************************
 * 									Function prototypes									*
 ****************************************************************************************/
/*
 * this function is used to initialize the ADC in our MCU
 * it takes a structure as input of type ADC_ConfigType
 * which contains the reference voltage and the prescaler
 * this is a configurable function to polling method
 */
void ADC_init (const ADC_ConfigType * config_ptr);
/*
 * this function is responsible on selecting the analog channel
 * to be converted by the ADC
 * the polling method depends on waiting for the flag to be set by 1
 * when the flag is set we will clear it and return the converted value
 * stored in the ADC register
 */
uint16 ADC_readChannel (uint8 ch_num);

#endif /* ADC_H_ */
