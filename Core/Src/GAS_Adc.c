/*
 * GAS_Adc.c
 *
 *  Created on: Jul 21, 2023
 *  Author: Terry
 *  yoonsb@hanyang.ac.kr
 *
 */


#include "GAS_Adc.h"
#include <stdlib.h>


#ifdef __USE_ADC1__
GAS_Adc_adc_t GAS_Adc_adc1;
#endif
#ifdef __USE_ADC2__
GAS_Adc_adc_t GAS_Adc_adc2;
#endif
static void GAS_Adc_initErrorTrap(void);
static void GAS_Adc_startAdc(GAS_Adc_adc_t *adc);

SensorHubADC_t SensorHubADC;

void GAS_Adc_init(void)
{

#ifdef __USE_ADC1__
		GAS_Adc_adc_t *adc1 = &GAS_Adc_adc1;

		adc1->hadc = &hadc1;

		adc1->dataLength = ((adc1->hadc->Instance->SQR1)>>20U);
		adc1->data = (uint32_t*)malloc(adc1->dataLength*sizeof(uint32_t));

		GAS_Adc_startAdc(adc1);

#endif
#ifdef __USE_ADC2__
		GAS_Adc_adc_t *adc2 = &GAS_Adc_adc2;

		adc2->hadc = &hadc2;

		adc2->dataLength = ((adc2->hadc->Instance->SQR1)>>20U);
		adc2->data = (uint32_t*)malloc(adc2->dataLength*sizeof(uint32_t));

		GAS_Adc_startAdc(adc2);
#endif;
}



//TODO: Non DMA functions
static void GAS_Adc_startAdc(GAS_Adc_adc_t *adc)
{
	if(HAL_ADC_Start_DMA(adc->hadc, adc->data, adc->dataLength) != HAL_OK)
	{
		GAS_Adc_initErrorTrap();
	}
}

static void GAS_Adc_initErrorTrap(void)
{
	__disable_irq();
	while(1);
}

void GAS_Adc_getValue(void)
{
#ifdef __USE_ADC1__
	SensorHubADC.ADC1_IN1 = GAS_Adc_adc1.data[0];
	SensorHubADC.ADC1_IN2 = GAS_Adc_adc1.data[1];
	SensorHubADC.ADC1_IN3 = GAS_Adc_adc1.data[2];
	SensorHubADC.ADC1_IN4 = GAS_Adc_adc1.data[3];
#endif

#ifdef __USE_ADC2__
	SensorHubADC.ADC2_IN1 = GAS_Adc_adc2.data[0];
	SensorHubADC.ADC2_IN2 = GAS_Adc_adc2.data[1];
	SensorHubADC.ADC2_IN3 = GAS_Adc_adc2.data[2];
	SensorHubADC.ADC2_IN4 = GAS_Adc_adc2.data[3];
#endif
}
