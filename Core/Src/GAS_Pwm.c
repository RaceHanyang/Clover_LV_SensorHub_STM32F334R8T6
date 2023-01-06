/*
 * GAS_Pwm.c
 *
 * Created: Jan 5th, 2023
 * Author: Terry
 * yoonsb@hanyang.ac.kr
 *
 * ref: https://www.youtube.com/watch?v=P6211ic2N_s
 * */

#include "tim.h"

#include "GAS_Pwm.h"
SensorHubPWM_t SensorHubPWM;

const double dutyLowerBound = 0.0;
const double dutyUpperBound = 1.0;

void HAL_TIM_IC_Capture_Callback(TIM_HandleTypeDef *htim)
{
#ifdef __USE_TIM1__
	if(htim->Instance == TIM1) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval1 > 0) {
				SensorHubPWM.DutyRatio1 = ((double)SensorHubPWM.DutyCycle1) /SensorHubPWM.Interval1;
			}
		}
	}
#endif
#ifdef __USE_TIM2__
	if(htim->Instance == TIM2) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval2 > 0) {
				SensorHubPWM.DutyRatio2 = ((double)SensorHubPWM.DutyCycle2) /SensorHubPWM.Interval2;
			}
		}
	}
#endif
#ifdef __USE_TIM3__
	if(htim->Instance == TIM3) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval3 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle3 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval3 > 0) {
				SensorHubPWM.DutyRatio3 = ((double)SensorHubPWM.DutyCycle3) /SensorHubPWM.Interval3;
			}
		}
	}
#endif
#ifdef __USE_TIM15__
	if(htim->Instance == TIM15) {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) {
			SensorHubPWM.Interval15 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
			SensorHubPWM.DutyCycle15 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
			if(SensorHubPWM.Interval15 > 0) {
				SensorHubPWM.DutyRatio15 = ((double)SensorHubPWM.DutyCycle15) /SensorHubPWM.Interval15;
			}
		}
	}
#endif
}

/*
 * Quite a surprise, stock HAL does not provide a function to look up the clock frequency for timer peripherals.
 * This is a user implemented function that returns "APB1 timer clocks (MHz)" field set on the .ioc configuration.
 * TIM 2,3,6,7 run on this clock.
 * Checkout associated JIRA project for design intentions.
 * */
uint32_t PCLK1TIM(void) {
	uint32_t PCLK1 = HAL_RCC_GetPCLK1Freq();

	if((RCC->CFGR & RCC_CFGR_PPRE1) == 0)
	{
		return PCLK1;
	}
	else
	{
		return (2 * PCLK1);
	}
}

/*
 * Ditto.
 * TIM 15, 16, 17 run on this clock.
 * */
uint32_t PCLK2TIM(void) {
	uint32_t PCLK2 = HAL_RCC_GetPCLK2Freq();

	if((RCC->CFGR & RCC_CFGR_PPRE2) == 0)
	{
		return PCLK2;
	}
	else
	{
		return (2 * PCLK2);
	}
}

#ifdef __USE_TIM2__
/*
 * TIM2 - 32bit Counter.
 *
 * htim2.Init.Prescaler technically means the initial value, therefore it is not necessarily the same with the TIM2_PSC register.
 * i.e., if TIM2_PSC alters, this function might not work as expected.
 * This is not the case here, so actually this is not going to bring any issue, but I am pretty unsatisfied with this decision as it kind of looks to be a trick that is not legit.
 *
 * LL_TIM_GetPrescaler seems to provide the exactly desired value, that is, the TIMx_PSC in effect, but this method belongs to low-layer files, not HAL.
 * But I do not want to harm the level of abstraction for this project, so I am now just settling with this design.
 * */
uint16_t TickToRPM_TIM2(uint32_t Interval)
{
	return (2.5/(((double)Interval * (htim2.Init.Prescaler+1))/PCLK1TIM()));
}
#endif

#ifdef __USE_TIM3__
/*
 * TIM3 - 16bit Counter.
 *
 * Ditto
 * */
uint16_t TickToRPM_TIM3(uint16_t Interval)
{
	return (2.5/(((double)Interval * (htim3.Init.Prescaler+1))/PCLK1TIM()));
}
#endif
