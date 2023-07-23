/*
 * GAS_Adc.h
 *
 *  Created on: Mar 04, 2023
 *      Author: InitusNovus
 */

#ifndef GAS_ADC_H_
#define GAS_ADC_H_

#include <stdint.h>
#include "stm32f334x8.h"
#include "stm32f3xx_hal.h"
#include "adc.h"
#include "GAS_BuildConfig.h"

typedef struct
{
	ADC_HandleTypeDef *hadc;
	uint32_t dataLength;
	volatile uint32_t *data;
}GAS_Adc_adc_t;


typedef struct{
#ifdef __USE_ADC1__
	uint16_t ADC1_IN1;
	uint16_t ADC1_IN2;
	uint16_t ADC1_IN3;
	uint16_t ADC1_IN4;
#endif

#ifdef __USE_ADC2__
	uint16_t ADC2_IN1;
	uint16_t ADC2_IN2;
	uint16_t ADC2_IN3;
	uint16_t ADC2_IN4;
#endif
}SensorHubADC_t;

#ifdef __USE_ADC1__
extern GAS_Adc_adc_t GAS_Adc_adc1;
#endif
#ifdef __USE_ADC2__
extern GAS_Adc_adc_t GAS_Adc_adc2;
#endif
void GAS_Adc_init(void);

extern SensorHubADC_t SensorHubADC;

#endif//GAS_ADC_H_
