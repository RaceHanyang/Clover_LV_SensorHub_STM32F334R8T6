/*
 * GAS_Can.c
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * Based on: https://github.com/Suprhimp/STM32F405R_Cooling_Control/commit/af8879014d1c74125f3ed3faa8b0d2abffbf2ea5
 * */

#include "GAS_Can.h"

CAN_TxHeaderTypeDef canTxHeader_ADC;
CAN_TxHeaderTypeDef canTxHeader_WSS;

stm32_msgADC_t stm32_msgADC;
stm32_msgWSS_t stm32_msgWSS;
uint32_t TxMailBox;

#ifdef __THIS_SENSORHUB_IS_FOR_FRONT__
uint32_t STM32_msgADC_ID = 0x00334F01;
uint32_t STM32_msgWSS_ID = 0x00334F02;
#endif

#ifdef __THIS_SENSORHUB_IS_FOR_REAR__
uint32_t STM32_msgADC_ID = 0x00334B01;
uint32_t STM32_msgWSS_ID = 0x00334B02;
#endif

void GAS_Can_txSetting(void)
{
	canTxHeader_ADC.ExtId = STM32_msgADC_ID;
	canTxHeader_ADC.IDE = CAN_ID_EXT;
	canTxHeader_ADC.RTR = CAN_RTR_DATA;
	canTxHeader_ADC.DLC = 8;

	canTxHeader_WSS.ExtId = STM32_msgWSS_ID;
	canTxHeader_WSS.IDE = CAN_ID_EXT;
	canTxHeader_WSS.RTR = CAN_RTR_DATA;
	canTxHeader_WSS.DLC = 8;
}

void GAS_Can_rxSetting(void)
{
	//No rx required.
}

void GAS_Can_init(void)
{
	GAS_Can_txSetting();
	GAS_Can_rxSetting();
	if(HAL_CAN_Start(&hcan) != HAL_OK) {
		Error_Handler();
	}
}

void GAS_Can_sendMessage()
{
	TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);
	HAL_CAN_AddTxMessage(&hcan, &canTxHeader_WSS, &stm32_msgWSS.TxData[0], &TxMailBox);

	TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);
	HAL_CAN_AddTxMessage(&hcan, &canTxHeader_ADC, &stm32_msgADC.TxData[0], &TxMailBox);
}
