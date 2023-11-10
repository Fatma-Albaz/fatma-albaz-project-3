/*
 * adc.c
 *
 *  Created on: Oct 9, 2023
 *      Author: fatma albaz
 */
#include "adc.h"
#include "common_macros.h"
#include "adc_private.h"
/*
 * this function is used to initialize the ADC in our MCU
 * it takes a structure as input of type ADC_ConfigType
 * which contains the reference voltage and the prescaler
 * this is a configurable function to polling method
 */
void ADC_init (const ADC_ConfigType * config_ptr){
	ADMUX =((config_ptr->ref_volt)<<6);/*VREF value selection*/
	ADMUX &= 0xE0;/*choose channel o as initialization*/
	SET_BIT(ADCSRA,ADEN);/*ADC enable*/
	CLEAR_BIT(ADCSRA,ADIE);/*disable interrupts"polling method"*/
	ADCSRA= ((ADCSRA&~0x07)|((config_ptr->prescaler)&0x07));/*prescaler selection*/
	CLEAR_BIT(ADC,ADLAR);/*adjust data right*/
}
/*
 * this function is responsible on selecting the analog channel
 * to be converted by the ADC
 * the polling method depends on waiting for the flag to be set by 1
 * when the flag is set we will clear it and return the converted value
 * stored in the ADC register
 */
uint16 ADC_readChannel (uint8 ch_num){
	ADMUX = ((ADMUX&0xE0)|(ch_num&0x1F));/*insert channel*/
	SET_BIT(ADCSRA,ADSC);/*start conversion */
	/*polling method */
	while (GET_BIT(ADCSRA,ADIF)==0){
		/*empty loop*/
	}
	SET_BIT(ADCSRA,ADIF);/*clear flag*/
	return ADC;/*return data after conversion*/
}


