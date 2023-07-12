/*
 * GAS_Scheduler.h
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * Based on: https://github.com/Suprhimp/STM32F405R_Cooling_Control/commit/af8879014d1c74125f3ed3faa8b0d2abffbf2ea5
 * */

//#include <GAS_Vadc.h>
//
//#ifdef __USE_ADC1__
//uint32_t NumberOfADC1 = 4;
//volatile uint32_t ValueOfADC1[4];
//#endif
//
//#ifdef __USE_ADC2__
//uint32_t NumberOfADC2 = 4;
//volatile uint32_t ValueOfADC2[4];
//#endif
//
//SensorHubADC_t SensorHubADC;
//
//void GAS_Vadc_init(void)
//{
//#ifdef __USE_ADC1__
//	if(HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ValueOfADC1, NumberOfADC1) != HAL_OK)
//	{
//		Error_Handler();
//	}
//#endif
//
//#ifdef __USE_ADC2__
//
//	if(HAL_ADC_Start_DMA(&hadc2, (uint32_t*)ValueOfADC2, NumberOfADC2) != HAL_OK)
//	{
//		Error_Handler();
//	}
//#endif
//}
//
//static uint16_t calcDelta(float ADCVal)
//{
//	return 0;
//	//expression here.
//}
//
//void GAS_Vadc_getValue(void)
//{
//#ifdef __USE_ADC1__
//	SensorHubADC.ADC1_IN1 = ValueOfADC1[0];
//	SensorHubADC.ADC1_IN2 = ValueOfADC1[1];
//	SensorHubADC.ADC1_IN3 = ValueOfADC1[2];
//	SensorHubADC.ADC1_IN4 = ValueOfADC1[3];
//#endif
//
//#ifdef __USE_ADC2__
//	SensorHubADC.ADC2_IN1 = ValueOfADC2[0];
//	SensorHubADC.ADC2_IN2 = ValueOfADC2[1];
//	SensorHubADC.ADC2_IN3 = ValueOfADC2[2];
//	SensorHubADC.ADC2_IN4 = ValueOfADC2[3];
//#endif
//}
