/*
 * USART.h
 *
 *  Created on: Feb 12, 2024
 *      Author: Lenovo
 */

#ifndef MCAL_DRIVERS_USART_H_
#define MCAL_DRIVERS_USART_H_



#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

#define TIME_OUT	20

typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_TypeDef;

#define USART1_Base (0x40013800)
#define USART2_Base (0x40004400)
#define USART3_Base (0x40004800)

#define USART1 ((USART_TypeDef *)USART1_Base)
#define USART2 ((USART_TypeDef *)USART2_Base)
#define USART3 ((USART_TypeDef *)USART3_Base)


typedef enum
{
	USART_ID_1 ,
	USART_ID_2,
	USART_ID_3,
}USART_Num;
/*
 * Word Length
 */
#define Word_Length_8	0
#define Word_Length_9	1
#define Word_Length	Word_Length_8
/*
 * Parity control
 */
#define Parity_Control_Enable	1
#define Parity_Control_Disable	0
#define Parity_Control	Parity_Control_Disable
/*
 * Parity Selection
 */
#define Even_Parity		0
#define Odd_Parity		1
#define Parity_Select	Even_Parity
/*
 * Stop bits
 */
#define Stop_Bit_1		0
#define Stop_Bit_2		1
#define Stop_Bit		Stop_Bit_1


void USART_Init(USART_Num usart_num);
//Synch
void USART_TransmitByteSynch(USART_Num usart_num, uint8_t Data);
void USART_TransmitStringSynch(USART_Num usart_num, uint8_t Data[]);
uint8_t USART_RecieveByteSynch(USART_Num usart_num);
void USART_RecieveStringSynch(USART_Num usart_num, uint8_t *RecievedString);
//Asycnh
void USART_TransmitByteAsynch(USART_Num usart_num, uint8_t Data);
void USART_TransmitStringAsynch(USART_Num usart_num, uint8_t Data[]);
uint8_t USART_RecieveByteAsynch(USART_Num usart_num);
void USASRT1_SetCallBack(void(*pf)(void));
void USASRT2_SetCallBack(void(*pf)(void));
void USASRT1_SetCallBack(void(*pf)(void));

#endif /* MCAL_DRIVERS_USART_H_ */
