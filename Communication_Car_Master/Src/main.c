/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
		/*********************Core Periphelarls Begins********************/
#include "CortexM3/CortexM3_NVIC.h"
#include "CortexM3/CortexM3_SCB.h"
#include "CortexM3/CortexM3_SysTick.h"
			/*********************Core Periphelarls Ends********************/

			/*********************MCAL Begins********************/
#include "MCAL_Drivers/EXTI.h"
#include "MCAL_Drivers/gpio.h"
#include "MCAL_Drivers/STM32F103C8T6_RCC.h"
#include "MCAL_Drivers/USART.h"
			/*********************MCAL Ends********************/

			/**********************Common Library***********************/
#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"





//EXTI0
void app_one(void);

//EXTI1
void app_two(void);

int main(void)
{
	//Clock Configuration
	RCC_EnableHSE();
	RCC_EnablePeriphalClk(APB2_BUS, GPIOA_EN);
	RCC_EnablePeriphalClk(APB2_BUS, GPIOB_EN);
	RCC_EnablePeriphalClk(APB2_BUS, GPIOC_EN);
	RCC_EnablePeriphalClk(APB2_BUS, USART1_EN);
	RCC_EnablePeriphalClk(APB2_BUS, AFIO_EN);

	//Push Button
	GPIO_Init(PORTB, PIN0, INPUT, INPUT_PULL);
	GPIO_Init(PORTB, PIN1, INPUT, INPUT_PULL);

	//USART PINS INIT
	GPIO_Init(PORTA, PIN9, OUTPUT_10MHZ, OUTPUT_ALF_PUSH_PULL);
	GPIO_Init(PORTA, PIN10, INPUT, INPUT_PULL);

	//EXTI0
	EXTI_SetEdge(EXTI_LINE0, EXTI_Rising_Edge);
	EXTI_SetMapping(EXTI_LINE0, PORTB);
	EXTI_SetCallBack(EXTI_LINE0, &app_one);
	NVIC_EnableIRQ(EXTI0_IRQn);
	EXTI_EnableIntLine(EXTI_LINE0);

	//EXTI1
	EXTI_SetEdge(EXTI_LINE1, EXTI_Rising_Edge);
	EXTI_SetMapping(EXTI_LINE1, PORTB);
	EXTI_SetCallBack(EXTI_LINE1, &app_two);
	NVIC_EnableIRQ(EXTI1_IRQn);
	EXTI_EnableIntLine(EXTI_LINE1);

	//USART
	USART_Init(USART_ID_1);

	while(1)
	{

	}
}
void app_one(void)
{

	USART_TransmitByteSynch(USART_ID_1, 'a');
}
void app_two(void)
{
	USART_TransmitByteSynch(USART_ID_1, 'b');
}


