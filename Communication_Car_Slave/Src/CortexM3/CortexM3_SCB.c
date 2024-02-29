/*
 * CortexM3_SCB.c
 *
 *  Created on: Jan 29, 2024
 *      Author: Lenovo
 */

#include "CortexM3/CortexM3_SCB.h"
/*
 * PRIGRPOUP[0b011] > Group_bits [7:4 ] , Sub_bits[None] , Group = 16  , Sub = None
 * PRIGRPOUP[0b100] > Group_bits [7:5 ] , Sub_bits[4   ] , Group = 8   , Sub = 2
 * PRIGRPOUP[0b101] > Group_bits [7:6 ] , Sub_bits[5:4 ] , Group = 4   , Sub = 4
 * PRIGRPOUP[0b110] > Group_bits [7   ] , Sub_bits[6:4 ] , Group = 2   , Sub = 8
 * PRIGRPOUP[0b111] > Group_bits [None] , Sub_bits[7:4 ] , Group = None, Sub = 16
 */
void SCB_SetGroupPriority(uint32_t PriorityGroup)
{
	uint32_t Reg_Value = 0;
	uint32_t PriorityGroupTemp = (PriorityGroup & (uint32_t)0x07UL);
	Reg_Value = SCB->AIRCR;
	Reg_Value &= ~((uint32_t)SCB_AIRCR_PRIGROUP_MASK | SCB_AIRCR_VECT_MASK);
	Reg_Value = (Reg_Value | (uint32_t)0x5FAUL << 16U | PriorityGroupTemp << 8U);
}
uint32_t SCB_GetPriorityGroup(void)
{
	return ((uint32_t)((SCB->AIRCR & SCB_AIRCR_PRIGROUP_MASK) >> SCB_AIRCR_PRIGROUP_POS));
}
