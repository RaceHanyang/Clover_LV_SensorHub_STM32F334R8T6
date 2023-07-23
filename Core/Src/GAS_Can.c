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

#ifdef __USE_ADC1__
CAN_TxHeaderTypeDef canTxHeader_ADC1;
stm32_msgADC_t stm32_msgADC1;
#endif
#ifdef __USE_ADC2__
CAN_TxHeaderTypeDef canTxHeader_ADC2;
stm32_msgADC_t stm32_msgADC2;
#endif

CAN_TxHeaderTypeDef canTxHeader_WSS;

stm32_msgWSS_t stm32_msgWSS;
uint32_t TxMailBox;

#ifdef __THIS_SENSORHUB_IS_FOR_FRONT__
#ifdef __USE_ADC1__
uint32_t STM32_msgADC1_ID = 0x00334F01;
#endif
#ifdef __USE_ADC2__
uint32_t STM32_msgADC2_ID = 0x00334F02;
#endif
uint32_t STM32_msgWSS_ID = 0x00334F03;
#endif

#ifdef __THIS_SENSORHUB_IS_FOR_REAR__
#ifdef __USE_ADC1__
uint32_t STM32_msgADC1_ID = 0x00334B01;
#endif
#ifdef __USE_ADC2__
uint32_t STM32_msgADC2_ID = 0x00334B02;
#endif
uint32_t STM32_msgWSS_ID = 0x00334B03;
#endif

void GAS_Can_txSetting(void)
{
#ifdef __USE_ADC1__
	canTxHeader_ADC1.ExtId = STM32_msgADC1_ID;
	canTxHeader_ADC1.IDE = CAN_ID_EXT;
	canTxHeader_ADC1.RTR = CAN_RTR_DATA;
	canTxHeader_ADC1.DLC = 8;
#endif
#ifdef __USE_ADC2__
	canTxHeader_ADC2.ExtId = STM32_msgADC2_ID;
	canTxHeader_ADC2.IDE = CAN_ID_EXT;
	canTxHeader_ADC2.RTR = CAN_RTR_DATA;
	canTxHeader_ADC2.DLC = 8;
#endif
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
	if (HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
		Error_Handler();
	}
}

void GAS_Can_sendMessage()
{
	//Modify them according to GAS_BuildConfig.h
	stm32_msgWSS.B.WSS2_RPM = TickToRPM_TIM15(SensorHubPWM.Interval15);
	stm32_msgWSS.B.WSS1_RPM = TickToRPM_TIM3(SensorHubPWM.Interval3);

#ifdef __USE_TIM1__
	if(SensorHubPWM.DutyRatio1 > dutyUpperBound || SensorHubPWM.DutyRatio1 < dutyLowerBound) {
		stm32_msgWSS.B.dutyFlag.S.TIM1_ERROR = 1;
	} else{
		stm32_msgWSS.B.dutyFlag.S.TIM1_ERROR = 0;
	}
#endif

#ifdef __USE_TIM2__
	if(SensorHubPWM.DutyRatio2 > dutyUpperBound || SensorHubPWM.DutyRatio2 < dutyLowerBound) {
		stm32_msgWSS.B.dutyFlag.S.TIM2_ERROR = 1;
	} else{
		stm32_msgWSS.B.dutyFlag.S.TIM2_ERROR = 0;
	}
#endif

#ifdef __USE_TIM3__
	if(SensorHubPWM.DutyRatio3 > dutyUpperBound || SensorHubPWM.DutyRatio3 < dutyLowerBound) {
		stm32_msgWSS.B.dutyFlag.S.TIM3_ERROR = 1;
	} else{
		stm32_msgWSS.B.dutyFlag.S.TIM3_ERROR = 0;
	}
#endif

#ifdef __USE_TIM15__
	if(SensorHubPWM.DutyRatio15 > dutyUpperBound || SensorHubPWM.DutyRatio15 < dutyLowerBound) {
		stm32_msgWSS.B.dutyFlag.S.TIM15_ERROR = 1;
	} else{
		stm32_msgWSS.B.dutyFlag.S.TIM15_ERROR = 0;
	}
#endif

	TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);
	HAL_CAN_AddTxMessage(&hcan, &canTxHeader_WSS, &stm32_msgWSS.TxData[0], &TxMailBox);
	/*if(TxMailBox > 0) {
		HAL_GPIO_WritePin(GPIOB, LED01_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOB, LED01_Pin, GPIO_PIN_RESET);
	}*/

#ifdef __USE_ADC1__
	stm32_msgADC1.B.IN1 = SensorHubADC.ADC1_IN1;
	stm32_msgADC1.B.IN2 = SensorHubADC.ADC1_IN2;
	stm32_msgADC1.B.IN3 = SensorHubADC.ADC1_IN3;
	stm32_msgADC1.B.IN4 = SensorHubADC.ADC1_IN4;
	TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);
	HAL_CAN_AddTxMessage(&hcan, &canTxHeader_ADC1, &stm32_msgADC1.TxData[0], &TxMailBox);
	/*if(TxMailBox > 0) {
		HAL_GPIO_WritePin(GPIOB, LED02_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOB, LED02_Pin, GPIO_PIN_RESET);
	}*/
#endif

#ifdef __USE_ADC2__
	stm32_msgADC2.B.IN1 = SensorHubADC.ADC2_IN1;
	stm32_msgADC2.B.IN2 = SensorHubADC.ADC2_IN2;
	stm32_msgADC2.B.IN3 = SensorHubADC.ADC2_IN3;
	stm32_msgADC2.B.IN4 = SensorHubADC.ADC2_IN4;
	TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);
	HAL_CAN_AddTxMessage(&hcan, &canTxHeader_ADC2, &stm32_msgADC2.TxData[0], &TxMailBox);
#endif
}
