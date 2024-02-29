/*
 * CortexM3_SYSTICK.c
 *
 *  Created on: Feb 1, 2024
 *      Author: Lenovo
 */

#include "CortexM3/CortexM3_SysTick.h"
#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"




static void(*PtrCallBack)(void) = NULL;
uint32_t Mode_status;


void SysTick_Init(void)
{
	//disable counter
	CLR_BIT(SysTick->CSR, 0);

	SysTick->CVR = 0;
	//clock source
#if CLOCK_SOURCE == CLOCK_SOURCE_EXTERNAL_CLOCK // AHB/8
	CLR_BIT(SysTick->CSR,2);
#else//processor clock AHB
	SET_BIT(SysTick->CSR,2);
#endif
	//disable interrupt
	CLR_BIT(SysTick->CSR,1);
}
void SysTick_DisableCounter(void)
{
	CLR_BIT(SysTick->CSR, 0);
	SysTick->RVR = 0;
	SysTick->CVR = 0;
	//disable interrupt
	CLR_BIT(SysTick->CSR,1);
}

void SysTick_WaitBlocking(uint32_t Ticks)
{
	uint32_t Value = Ticks & (uint32_t)SysTick_CVR_RELOAD_MASK;
	SysTick->RVR = Value;
	//enable
	SET_BIT(SysTick->CSR,0);
	//wait for flag
	while(GET_BIT(SysTick->CSR,16) == 0);
	//disable counter
	CLR_BIT(SysTick->CSR,0);
	SysTick->RVR = 0;
	SysTick->CVR = 0;
}
void SysTick_Asynch(uint32_t Mode, uint32_t Ticks)
{
	SysTick_DisableCounter();//to clear any previos config
	uint32_t Value = Ticks & (uint32_t)SysTick_CVR_RELOAD_MASK;
	SysTick->RVR = Value;
	//mode
	Mode_status = Mode;
	//enable int
	SET_BIT(SysTick->CSR,1);
	//enable timer
	SET_BIT(SysTick->CSR,0);
}
void SysTick_SetCallBack(void(*ptrToFun)(void))
{
	PtrCallBack = ptrToFun;
}
void SysTick_Handler(void)
{
	//call the fun
	PtrCallBack();
	if(Mode_status == Single_Interval)
	{
		SysTick->RVR = 0;
		SysTick->CVR = 0;
		CLR_BIT(SysTick->CSR, 0);
		CLR_BIT(SysTick->CSR,1);
	}
}

