/*
 * GAS_Scheduler.h
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * Based on: https://github.com/Suprhimp/STM32F405R_Cooling_Control/commit/af8879014d1c74125f3ed3faa8b0d2abffbf2ea5
 * */

#ifndef INC_GAS_SCHEDULER_H_
#define INC_GAS_SCHEDULER_H_

#include "stm32f3xx_hal.h"
#include "GAS_BuildConfig.h"

typedef struct{
	volatile uint8_t flag_1ms;
	volatile uint8_t flag_10ms;
	volatile uint8_t flag_100ms;
	volatile uint8_t flag_1000ms;
}Scheduler_task;

extern Scheduler_task gTask;

extern void GAS_Scheduler_init(void);
extern void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
extern void GAS_Scheduler(void);
#endif /* INC_GAS_SCHEDULER_H_ */
