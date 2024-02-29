/*
 * gpio.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Lenovo
 */

#include "MCAL_Drivers/gpio.h"
#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

void GPIO_Init(uint8_t Port, uint8_t Pin, uint8_t Direction, uint8_t Mode) {
	uint8_t LocalPortValue = Port;
	uint8_t LocalPinValue;
	uint8_t LocalDirectionValue = Direction;
	uint8_t LocalModeValue = Mode;

	//variable to decide to work on on CRL or CRH
	uint8_t CR_LOW_or_High;

	// to get position for the pin in the register
	uint8_t PinPos;
	// decide if it is CRL or CRH
	if (Pin > 7 && Pin <= 15)
	{
		// CRH
		LocalPinValue = Pin - 8;
		CR_LOW_or_High = 1; //CRH
	}
	else
	{
		//CRL
		LocalPinValue = Pin;
		CR_LOW_or_High = 0; //CRL
	}
	//get pin position for the pin in the register
	PinPos = LocalPinValue << 2;

	if (CR_LOW_or_High)
	{ //CRH
		if (LocalPortValue >= 0 && LocalPortValue <= 3)
		{
			switch (LocalPortValue)
			{
			case PORTA:
				GPIOA->CRH &= ~(0xFUL << PinPos);
				GPIOA->CRH |= LocalDirectionValue << PinPos;
				GPIOA->CRH |= LocalModeValue << (PinPos + 2);
				break;
			case PORTB:
				GPIOB->CRH &= ~(0xFUL << PinPos);
				GPIOB->CRH |= LocalDirectionValue << PinPos;
				GPIOB->CRH |= LocalModeValue << (PinPos + 2);
				break;
			case PORTC:
				GPIOC->CRH &= ~(0xFUL << PinPos);
				GPIOC->CRH |= LocalDirectionValue << PinPos;
				GPIOC->CRH |= LocalModeValue << (PinPos + 2);
				break;
			}
		}
	}
	else
	{
		if (LocalPortValue >= 0 && LocalPortValue <= 3)
		{
			switch (LocalPortValue)
			{
			case PORTA:
				GPIOA->CRL &= ~(0xFUL << PinPos);
				GPIOA->CRL |= LocalDirectionValue << PinPos;
				GPIOA->CRL |= LocalModeValue << (PinPos + 2);
				break;
			case PORTB:
				GPIOB->CRL &= ~(0xFUL << PinPos);
				GPIOB->CRL |= LocalDirectionValue << PinPos;
				GPIOB->CRL |= LocalModeValue << (PinPos + 2);
				break;
			case PORTC:
				GPIOC->CRL &= ~(0xFUL << PinPos);
				GPIOC->CRL |= LocalDirectionValue << PinPos;
				GPIOC->CRL |= LocalModeValue << (PinPos + 2);
				break;

			}

		}
	}
}
uint8_t GPIO_ReadPinValue(uint8_t Port, uint8_t Pin) {
	uint8_t RetValue;
	if (Port >= 0 && Port <= 3) {
		switch (Port) {
		case PORTA:
			RetValue = 0x1 & (GPIOA->IDR >> Pin);
			break;
		case PORTB:
			RetValue = 0x1 & (GPIOB->IDR >> Pin);
			break;
		case PORTC:
			RetValue = 0x1 & (GPIOC->IDR >> Pin);
			break;
		}
	}
	return RetValue;
}
void GPIO_WritePinValue(uint8_t Port, uint8_t Pin, uint8_t State)
{
	if (Port >= 0 && Port <= 3)
	{
		switch (Port)
		{
		case PORTA:
			GPIOA->ODR &= ~(1 << Pin);
			GPIOA->ODR |= (uint32_t)(State << Pin);
			break;
		case PORTB:
			GPIOB->ODR &= ~(1 << Pin);
			GPIOB->ODR |= (uint32_t)(State << Pin);
			break;
		case PORTC:
			GPIOC->ODR &= ~(1 << Pin);
			GPIOC->ODR |= (uint32_t)(State << Pin);
			break;
		}
	}
}
void GPIO_TogglePin(uint8_t Port, uint8_t Pin)
{

	if (Port >= 0 && Port <= 3)
		{
			switch (Port)
			{
			case PORTA:
				TOGGLE_BIT(GPIOA->ODR,Pin);
				break;
			case PORTB:
				TOGGLE_BIT(GPIOB->ODR,Pin);
				break;
			case PORTC:
				TOGGLE_BIT(GPIOC->ODR,Pin);
				break;
			}
		}
}
void GPIO_LockPin(uint8_t Port, uint8_t Pin)
{
	if (Port >= 0 && Port <= 3)
	{
		switch (Port)
		{
		case PORTA:
			SET_BIT(GPIOA->LCKR, 16);
			break;
		case PORTB:
			SET_BIT(GPIOB->LCKR, 16);
			break;
		case PORTC:
			SET_BIT(GPIOC->LCKR, 16);
			break;
		}
	}
}
