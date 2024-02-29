/*
 * STM32F103C8T6.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Lenovo
 */

#include "MCAL_Drivers/STM32F103C8T6_RCC.h"
#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

void RCC_GPIOx_Clk_ENABLE(uint32_t GPIOx)
{
	if(GPIOx >= 2 && GPIOx <= 8)
	{
		SET_BIT(RCC->APB2ENR,GPIOx);
	}
}
void RCC_GPIOx_Clk_DISABLE(uint32_t GPIOx)
{
	if(GPIOx >= 2 && GPIOx <= 8)
	{
		CLR_BIT(RCC->APB2ENR,GPIOx);
	}
}

void RCC_EnableHSI(void)
{
		//enable HSI only for the moment
		SET_BIT(RCC->CR,0);
		while(GET_BIT(RCC->CR,1) == 0);
		//clear flag
		CLR_BIT(RCC->CIR,18);
		//select HSI as system clock
		CLR_BIT(RCC->CFGR,0);
		CLR_BIT(RCC->CFGR,1);
}
void RCC_EnableHSE(void)
{
	//enable HSE
	SET_BIT(RCC->CR, 16);
	//wait for flag
	while(GET_BIT(RCC->CR, 17) == 0);
	//clear flag
	CLR_BIT(RCC->CIR,19);
	//select HSE
	SET_BIT(RCC->CFGR,0);
	CLR_BIT(RCC->CFGR,1);
}
void RCC_EnablePLL(uint8_t CLK_Source, uint8_t PLLVal)
{
	//enable PLL
	SET_BIT(RCC->CR,24);
	//wait flag
	while(GET_BIT(RCC->CR,25) == 0);
	//clear
	SET_BIT(RCC->CIR,20);
	/*
	 * clk soruce
	 * 			 1)HSI/2
	 * 			 2)HSE/2
	 * 			 3)HSE
	 *
	 */
	switch(CLK_Source)
	{
		case HSI_2 :
			CLR_BIT(RCC->CFGR,16);
			break;
		case HSE_2:
		//If PLL CLK source is half HSE.
		SET_BIT(RCC -> CFGR, 16); //HSE oscillator clock selected as PLL input clock.
		SET_BIT(RCC -> CFGR, 17); //HSE clock divided by 2.
		break;
		case HSE:
		//If PLL CLK source is HSE.
		SET_BIT(RCC -> CFGR, 16); //HSE oscillator clock selected as PLL input clock.
		CLR_BIT(RCC->CFGR, 17); //HSE clock not divided.
		break;
	}
	RCC -> CFGR = ((RCC -> CFGR) & 0xFFC3FFFF) | (PLLVal << 18);
}

/*
 * AHB_DIV1
 * AHB_DIV2
 * AHB_DIV4
 * AHB_DIV8
 * AHB_DIV16
 * AHB_DIV64
 * AHB_DIV128
 * AHB_DIV256
 * AHB_DIV512
 */
void RCC_EnablePeriphalClk(uint8_t BusName,uint8_t Periphal)
{
	switch(BusName)
	{
	case AHB_BUS :
		SET_BIT(RCC->AHBENR,Periphal);
		break;
	case APB1_BUS :
		SET_BIT(RCC->APB1ENR,Periphal);
		break;
	case APB2_BUS :
		SET_BIT(RCC->APB2ENR,Periphal);
		break;
	}
}
void RCC_DisablePeriphalClk(uint8_t BusName,uint8_t Periphal)
{
	switch(BusName)
		{
		case AHB_BUS :
			CLR_BIT(RCC->AHBENR,Periphal);
			break;
		case APB1_BUS :
			CLR_BIT(RCC->APB1ENR,Periphal);
			break;
		case APB2_BUS :
			CLR_BIT(RCC->APB2ENR,Periphal);
			break;
		}
}
void RCC_AHB_PreScalar(uint32_t PrescalarValue)
{
	MODIFY_REG(RCC->CFGR, AHB_PreScalar_MASK,PrescalarValue);
}
void RCC_APB1_PreScalar(uint32_t PrescalarValue)
{
	MODIFY_REG(RCC->CFGR, APB1_PreScalar_MASK,PrescalarValue);
}
void RCC_APB2_PreScalar(uint32_t PrescalarValue)
{
	MODIFY_REG(RCC->CFGR, APB2_PreScalar_MASK,PrescalarValue);
}
