/*
 * CortexM3_SCB.h
 *
 *  Created on: Jan 29, 2024
 *      Author: Lenovo
 */

#ifndef CORTEXM3_CORTEXM3_SCB_H_
#define CORTEXM3_CORTEXM3_SCB_H_

#include "Common/Std_Types.h"
#include "Common/BIT_Math.h"

typedef struct
{
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCRS;
	volatile uint32_t CFSR;
}SCB_Type;

#define SCB_BASE	(0xE000ED00UL)
#define SCB			((SCB_Type*)SCB_BASE)

void SCB_SetGroupPriority(uint32_t PriorityGroup);
uint32_t SCB_GetPriorityGroup(void);


#define SCB_AIRCR_PRIGROUP_POS	8U
#define SCB_AIRCR_VECT_POS	16U

#define SCB_AIRCR_PRIGROUP_MASK		(7UL<<SCB_AIRCR_PRIGROUP_POS)
#define SCB_AIRCR_VECT_MASK			(0xFFFFUL<<SCB_AIRCR_VECT_POS)

#endif /* CORTEXM3_CORTEXM3_SCB_H_ */
