/*
 * GAS_Scheduler.c
 *
 * Created on: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * Based on: https://github.com/Suprhimp/STM32F405R_Cooling_Control/commit/af8879014d1c74125f3ed3faa8b0d2abffbf2ea5
 * */

#include "GAS_Scheduler.h"

#define False 0
#define True 1

volatile int gTimerCnt;
Scheduler_task gTask;

void GAS_Scheduler_init(void);
void GAS_Scheduler_taskCounter_1ms(void);
void GAS_Scheduler_taskCounter_10ms(void);
void GAS_Scheduler_taskCounter_100ms(void);
void GAS_Scheduler_taskCounter_1000ms(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void GAS_Scheduler(void);

void GAS_Scheduler_init(void)
{
	SysTick_Config(SystemCoreClock/1000);
	GAS_Vadc_init();
}

void GAS_Scheduler_taskCounter_1ms(void)
{

}

void GAS_Scheduler_taskCounter_10ms(void)
{

}

void GAS_Scheduler_taskCounter_100ms(void)
{

}

void GAS_Scheduler_taskCounter_1000ms(void)
{

}

void HAL_SYSTICK_Callback(void)
{
	gTimerCnt++;
	gTask.flag_1ms = True;
	if(gTimerCnt % 10 == 0)
	{
		gTask.flag_10ms = True;
	}
	if(gTimerCnt % 100 == 0)
	{
		gTask.flag_100ms = True;
	}
	if(gTimerCnt % 10 == 0)
	{
		gTask.flag_1000ms = True;
	}
}

void GAS_Scheduler(void)
{
	if(gTask.flag_1ms == True)
	{
		gTask.flag_1ms = False;
		GAS_Scheduler_taskCounter_1ms();
	}

	if(gTask.flag_10ms == True)
	{
		gTask.flag_10ms = False;
		GAS_Scheduler_taskCounter_10ms();
	}

	if(gTask.flag_100ms == True)
	{
		gTask.flag_100ms = False;
		GAS_Scheduler_taskCounter_100ms();
	}

	if(gTask.flag_1000ms == True)
	{
		gTask.flag_1000ms = False;
		GAS_Scheduler_taskCounter_1000ms();
	}
}
