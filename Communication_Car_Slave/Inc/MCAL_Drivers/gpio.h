/*
 * gpio.h
 *
 *  Created on: Feb 4, 2024
 *      Author: Lenovo
 */

#ifndef MCAL_DRIVERS_GPIO_H_
#define MCAL_DRIVERS_GPIO_H_


#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
}GPIO_TypeDef;

#define GPIOA_BASE		(0x40010800UL)
#define GPIOB_BASE		(0x40010C00UL)
#define GPIOC_BASE		(0x40011000UL)


#define GPIOA			((GPIO_TypeDef*)(GPIOA_BASE))
#define GPIOB			((GPIO_TypeDef*)(GPIOB_BASE))
#define GPIOC			((GPIO_TypeDef*)(GPIOC_BASE))


















/*
 * PORTS
 */
#define PORTA 	0
#define PORTB 	1
#define PORTC 	2
/*
 * PINS
 */
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15
/*
 * DIRCETION :
 * 					INPUT
 * 					OUTPUT with different speeds
 */
#define INPUT	 		00
#define OUTPUT_10MHZ	01
#define OUTPUT_2MHZ		10
#define OUTPUT_50MHZ	11
/*
 * OUTPUT MODE :
 * 				PUSH PULL
 * 				OPEN Drain
 * 				Alternative functions with push pull
 * 				Alternative functions with open drain
 */
#define OUTPUT_PUSH_PULL		00
#define OUTPUT_OPEN_DRAIN		01
#define OUTPUT_ALF_PUSH_PULL	10
#define OUTPUT_ALF_OPEN_DRAIN	11
/*
 * INPUT MODE :
 * 				ANALOG
 * 				FLoating
 * 				PULL up or PULL down
 * 				reserved
 */
#define INPUT_ANALOG		00
#define INPUT_FLOATING		01
#define INPUT_PULL			10
#define INPUT_RESERVED		11

/*
 * State to write
 * 					HIGH
 * 					LOW
 */
#define PIN_HIGH 	1
#define PIN_LOW		0

void GPIO_Init(uint8_t Port, uint8_t Pin, uint8_t Direction, uint8_t Mode);
uint8_t GPIO_ReadPinValue(uint8_t Port, uint8_t Pin);
void GPIO_WritePinValue(uint8_t Port, uint8_t Pin, uint8_t State);
void GPIO_TogglePin(uint8_t Port, uint8_t Pin);
void GPIO_LockPin(uint8_t Port, uint8_t Pin);
#endif /* MCAL_DRIVERS_GPIO_H_ */
