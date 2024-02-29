/*
 * CortexM3_NVIC.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Lenovo
 */

#include "CortexM3/CortexM3_NVIC.h"

/*
 * Enable INT
 */
void NVIC_EnableIRQ(IRQn_Type IRQn) {
	uint32_t Reg_Num = IRQn >> 5;
	uint32_t Bit_Num = IRQn % 32;
	if ((uint32_t) (IRQn) >= 0)
	{
		NVIC->ISER[(uint32_t)Reg_Num] = (uint32_t)(1UL << ((uint32_t)Bit_Num));
	}
}
/*
 * Disbale INT
 */
void NVIC_DisableIRQ(IRQn_Type IRQn) {
	uint32_t Reg_Num = IRQn >> 5;
	uint32_t Bit_Num = IRQn % 32;
	if ((uint32_t) (IRQn) >= 0)
	{
		NVIC->ICER[(uint32_t)Reg_Num] = (uint32_t)(1UL << ((uint32_t)Bit_Num));
	}
}
/*
 * Fire(trigger) INT
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn) {
	uint32_t Reg_Num = IRQn >> 5;
	uint32_t Bit_Num = IRQn % 32;
	if ((uint32_t) (IRQn) >= 0)
	{
		NVIC->ISPR[(uint32_t)Reg_Num] = (uint32_t)(1UL << ((uint32_t)Bit_Num));
	}
}
/*
 * Clear INT
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn) {
	uint32_t Reg_Num = IRQn >> 5;
	uint32_t Bit_Num = IRQn % 32;
	if ((uint32_t) (IRQn) >= 0)
	{
		 NVIC->ICPR[(uint32_t)Reg_Num] = (uint32_t)(1UL << ((uint32_t)Bit_Num));
	}
}
/*
 * Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
 */
uint32_t NVIC_GetActive(IRQn_Type IRQn) {
	if ((uint32_t) (IRQn) >= 0)
	{
		return((uint32_t)(((NVIC->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
	}
	else
	{
		return (0U);
	}
}
/*
 * Set Priority for specific INT
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
	if ((uint32_t) (IRQn) >= 0)
	{
		NVIC->IP[((uint32_t) IRQn)] = (uint8_t) ((priority << (8U - NVIC_PRIO_BITS)) & (uint32_t) 0xFFUL);
	}
}
/*
 * Get Priority for specific INT
 */
uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{
	if ((uint32_t)(IRQn) >= 0)
	  {
	    return(((uint32_t)NVIC->IP[((uint32_t)IRQn)] >> (8U - NVIC_PRIO_BITS)));
	  }
}
