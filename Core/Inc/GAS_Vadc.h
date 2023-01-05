/*
 * GAS_Scheduler.h
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * Based on: https://github.com/Suprhimp/STM32F405R_Cooling_Control/commit/af8879014d1c74125f3ed3faa8b0d2abffbf2ea5
 * */

#ifndef INC_GAS_VADC_H_
#define INC_GAS_VADC_H_

#include "GAS_BuildConfig.h"

#include "adc.h"
#include "dma.h"


extern void GAS_Vadc_init(void);
extern void GAS_Vadc_dmaIn(void);
extern void GAS_Vadc_getValue(void);

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

extern SensorHubADC_t SensorHubADC;

#endif /* INC_GAS_VADC_H_ */
