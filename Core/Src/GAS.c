/*
 * GAS.c
 *
 *  Created on: Feb 24, 2023
 *      Author: InitusNovus
 */

#include "stm32f3xx_hal.h"
#include "stm32f334x8.h"
#include "stm32f3xx_hal_rcc.h"

#include "GAS.h"

/*
 * uint32_t GAS_getHclkClk(void)
 * Return: HCLK frequency in Hz
 */
uint32_t GAS_getHclkClk(void)
{
	//Get SYSCLK in Hz.
	uint32_t sysclk_freq = HAL_RCC_GetSysClockFreq();

	//Get AHB prescaler.
	uint32_t ahb_prescaler;
	uint32_t ahbClkDiv;
	uint32_t flash_latency;
	RCC_ClkInitTypeDef clk_init_struct;
	HAL_RCC_GetClockConfig(&clk_init_struct, &flash_latency);

	ahbClkDiv = clk_init_struct.AHBCLKDivider;
	switch(ahbClkDiv)
	{
		case RCC_SYSCLK_DIV1:
			ahb_prescaler = 1; break;
		case RCC_SYSCLK_DIV2:
			ahb_prescaler = 2; break;
		case RCC_SYSCLK_DIV4:
			ahb_prescaler = 4; break;
		case RCC_SYSCLK_DIV8:
			ahb_prescaler = 8; break;
		case RCC_SYSCLK_DIV16:
			ahb_prescaler = 16; break;
		case RCC_SYSCLK_DIV64:
			ahb_prescaler = 64; break;
		case RCC_SYSCLK_DIV128:
			ahb_prescaler = 128; break;
		case RCC_SYSCLK_DIV256:
			ahb_prescaler = 256; break;
		case RCC_SYSCLK_DIV512:
			ahb_prescaler = 512; break;
	}

	uint32_t hclk_freq = sysclk_freq / ahb_prescaler;

	return hclk_freq;
}
