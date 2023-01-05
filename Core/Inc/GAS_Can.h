/*T
 * GAS_Can.h
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * Based on: https://github.com/Suprhimp/STM32F405R_Cooling_Control/commit/af8879014d1c74125f3ed3faa8b0d2abffbf2ea5
 * */

#ifndef SRC_GETANDSEND_H_
#define SRC_GETANDSEND_H_

#include "stm32f3xx_hal.h"
#include "can.h"

#include "GAS_BuildConfig.h"
#include "GAS_Pwm.h"
#include "GAS_Vadc.h"
typedef union{
	uint8_t TxData[8];
	struct{
		uint16_t IN1;
		uint16_t IN2;
		uint16_t IN3;
		uint16_t IN4;
	}__attribute__((aligned(1),packed)) B;
}stm32_msgADC_t;

typedef union
{//Max. WS ~2000
	uint8_t TxData[8];
	struct{
		uint16_t WSS1;
		uint16_t WSS2;
		union
		{
			uint8_t U;
			struct
			{
#ifdef __USE_TIM1__
				uint8_t TIM1_ERROR: 1;
#endif
#ifndef __USE_TIM1__
				uint8_t reserved1: 1;
#endif
#ifdef __USE_TIM2__
				uint8_t TIM2_ERROR: 1;
#endif
#ifndef __USE_TIM2__
				uint8_t reserved2: 1;
#endif
#ifdef __USE_TIM3__
				uint8_t TIM3_ERROR: 1;
#endif
#ifndef __USE_TIM3__
				uint8_t reserved3: 1;
#endif
#ifdef __USE_TIM15__
				uint8_t TIM15_ERROR: 1;
#endif
#ifndef __USE_TIM15__
				uint8_t reserved15: 1;
#endif
				uint8_t reserved: 4;
			}S;
		} dutyFlag;
	}__attribute__((aligned(1),packed)) B;
}stm32_msgWSS_t;

#ifdef __USE_ADC1__
extern stm32_msgADC_t stm32_msgADC1;
#endif
#ifdef __USE_ADC2__
extern stm32_msgADC_t stm32_msgADC2;
#endif
extern stm32_msgWSS_t stm32_msgWSS;

extern uint32_t STM32_msgADC1_ID;
extern uint32_t STM32_msgWSS_ID;

extern void GAS_Can_init(void);
extern void GAS_Can_sendMessage();
#endif /* SRC_GETANDSEND_H_ */
