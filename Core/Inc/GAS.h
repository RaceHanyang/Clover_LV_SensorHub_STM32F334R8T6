/*
 * GAS.h
 *
 *  Created on: 2023. 6. 26.
 *      Author: Terry
 */

#ifndef INC_GAS_H_
#define INC_GAS_H_

#include <stdbool.h>

#define GAS_INLINE static inline __attribute__((always_inline))
/***************Macros****************/

/*
 * Macro: Static inline function
 */
#define GAS_INLINE static inline __attribute__((always_inline))

/*********Function Prototypes*********/

/*
 * [Function] GAS_getHclkClk()
 * Return: [uint32_t] HCLK frequency in Hz
 */
extern uint32_t GAS_getHclkClk(void);

/******Inline function definition*****/

/*
 * [Function] GAS_getSystemCoreClock()
 * Return: [uint32_t] System core clock (=HCLK clock) speed in Hz
 * Note:
 * An alias for GAS_getHclkClk().
 */
GAS_INLINE uint32_t GAS_getSystemCoreClock(void)
{
	return GAS_getHclkClk();
}

#endif /* INC_GAS_H_ */
