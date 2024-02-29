/*
 * USART.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Lenovo
 */

#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

#include "MCAL_Drivers/USART.h"

static void (*USART1_CallBack)(void) = NULL;
static void (*USART2_CallBack)(void) = NULL;
static void (*USART3_CallBack)(void) = NULL;
/*
 * Precondition:
 * 				Enable Clock for AFIO as it is AFIO
 * 				Enale Clock for USART1
 * 				USART1 for example has TX at PA9 and RX at PA10
 * 					so you need to make PA9 as output,AF
 * 										PA10 as input,pull pull
 * 				cant make it on my own, it is the user responsibility
 */
void USART_Init(USART_Num usart_num) {
	switch (usart_num) {
	case USART_ID_1:
		//Word Length
#if	Word_Length	== Word_Length_8
		CLR_BIT(USART1->CR1, 12);
#else
		SET_BIT(USART1->CR1,12);
	#endif
		//parity control
#if Parity_Control == Parity_Control_Disable
		CLR_BIT(USART1->CR1, 10);
#else
		SET_BIT(USART1->CR1,10);
		//parity selection
			#if Parity_Select == Even_Parity
				CLR_BIT(USART1->CR1,9);
			#else
				SET_BIT(USART1->CR1,9);
			#endif

	#endif
#if Stop_Bit == Stop_Bit_1
		CLR_BIT(USART1->CR2, 12);
		CLR_BIT(USART1->CR2, 13);
#else
			CLR_BIT(USART1->CR2,12);
			SET_BIT(USART1->CR2,13);
	#endif
		//baud rate i will make it 9600 for now
		USART1->BRR = 0x349;
		//enable USART
		SET_BIT(USART1->CR1, 13);
		//enable TX and RX
		SET_BIT(USART1->CR1, 3);
		SET_BIT(USART1->CR1, 2);
		break;
	case USART_ID_2:
		//Word Length
#if	Word_Length	== Word_Length_8
		CLR_BIT(USART2->CR1, 12);
#else
				SET_BIT(USART2->CR1,12);
			#endif
		//parity control
#if Parity_Control == Parity_Control_Disable
		CLR_BIT(USART2->CR1, 10);
#else
				SET_BIT(USART2->CR1,10);
				//parity selection
					#if Parity_Select == Even_Parity
						CLR_BIT(USART2->CR1,9);
					#else
						SET_BIT(USART2->CR1,9);
					#endif

			#endif
#if Stop_Bit == Stop_Bit_1
		CLR_BIT(USART2->CR2, 12);
		CLR_BIT(USART2->CR2, 13);
#else
					CLR_BIT(USART2->CR2,12);
					SET_BIT(USART2->CR2,13);
			#endif
		//baud rate i will make it 9600 for now
		USART2->BRR = 0x349;
		//enable USART
		SET_BIT(USART2->CR1, 13);
		//enable TX and RX
		SET_BIT(USART2->CR1, 3);
		SET_BIT(USART2->CR1, 2);
		break;

		break;
	case USART_ID_3:
		//Word Length
#if	Word_Length	== Word_Length_8
		CLR_BIT(USART3->CR1, 12);
#else
				SET_BIT(USART3->CR1,12);
			#endif
		//parity control
#if Parity_Control == Parity_Control_Disable
		CLR_BIT(USART3->CR1, 10);
#else
				SET_BIT(USART3->CR1,10);
				//parity selection
					#if Parity_Select == Even_Parity
						CLR_BIT(USART3->CR1,9);
					#else
						SET_BIT(USART3->CR1,9);
					#endif

			#endif
#if Stop_Bit == Stop_Bit_1
		CLR_BIT(USART3->CR2, 12);
		CLR_BIT(USART3->CR2, 13);
#else
					CLR_BIT(USART3->CR2,12);
					SET_BIT(USART3->CR2,13);
			#endif
		//baud rate i will make it 9600 for now
		USART3->BRR = 0x349;
		//enable USART
		SET_BIT(USART3->CR1, 13);
		//enable TX and RX
		SET_BIT(USART3->CR1, 3);
		SET_BIT(USART3->CR1, 2);
		break;

	}
}
void USART_TransmitByteSynch(USART_Num usart_num, uint8_t Data) {
	switch (usart_num) {
	case USART_ID_1:
		// Wait for the previous transmission to complete
		while (!(GET_BIT(USART1->SR, 7)))
			;
		// Transmit the data
		USART1->DR = Data;
		// Wait for the transmission to complete
		while (!(GET_BIT(USART1->SR, 6)))
			;
		// Clear the transmission complete flag
		CLR_BIT(USART1->SR, 6);
		break;
	case USART_ID_2:
		// Wait for the previous transmission to complete
		while (!(GET_BIT(USART2->SR, 7)))
			;
		// Transmit the data
		USART2->DR = Data;
		// Wait for the transmission to complete
		while (!(GET_BIT(USART2->SR, 6)))
			;
		// Clear the transmission complete flag
		CLR_BIT(USART2->SR, 6);
		break;
	case USART_ID_3:
		// Wait for the previous transmission to complete
		while (!(GET_BIT(USART3->SR, 7)))
			;
		// Transmit the data
		USART3->DR = Data;
		// Wait for the transmission to complete
		while (!(GET_BIT(USART3->SR, 6)))
			;
		// Clear the transmission complete flag
		CLR_BIT(USART3->SR, 6);
		break;
	}
}
void USART_TransmitStringSynch(USART_Num usart_num, uint8_t *Data) {
	static uint8_t i = 0;
	switch (usart_num) {
	case USART_ID_1:
		while (Data[i] != '\0') {
			USART_TransmitByteSynch(USART_ID_1, Data[i++]);
		}
		break;
	case USART_ID_2:
		while (Data[i] != '\0') {
			USART_TransmitByteSynch(USART_ID_2, Data[i++]);
		}
		break;
	case USART_ID_3:
		while (Data[i] != '\0') {
			USART_TransmitByteSynch(USART_ID_3, Data[i++]);
		}
		break;
	}
}
uint8_t USART_RecieveByteSynch(USART_Num usart_num){
	uint8_t RecievedData;
	switch(usart_num)
	{
	case USART_ID_1:
		while(!(GET_BIT(USART1->SR,5)));
		RecievedData = USART1->DR;
		break;
	case USART_ID_2:
		while(!(GET_BIT(USART2->SR,5)));
		RecievedData = USART2->DR;
			break;
	case USART_ID_3:
		while(!(GET_BIT(USART3->SR,5)));
		RecievedData = USART3->DR;
			break;
	}
	return RecievedData;
}
void USART_RecieveStringSynch(USART_Num usart_num, uint8_t *RecievedString)
{
	uint8_t i =0;
	switch(usart_num)
	{
	case USART_ID_1 :
		RecievedString[i] = USART_RecieveByteSynch(USART_ID_1);
		while(RecievedString[i] != '\r')//new line
		{
			RecievedString[++i] = USART_RecieveByteSynch(USART_ID_1);
		}
		RecievedString[i] = '\0';//null char
		break;
	case USART_ID_2 :
			break;
	case USART_ID_3 :
			break;
	}


}
void USART_TransmitByteAsynch(USART_Num usart_num, uint8_t Data) {
	switch (usart_num) {
	case USART_ID_1:
		// Wait for the previous transmission to complete
		while (!(GET_BIT(USART1->SR, 7)))
			;
		// Transmit the data
		USART1->DR = Data;
		// Wait for the transmission to complete
		while (!(GET_BIT(USART1->SR, 6)))
			;
		// Clear the transmission complete flag
		CLR_BIT(USART1->SR, 6);
		//Enable INT
		SET_BIT(USART1->CR1, 7);
		break;
	case USART_ID_2:
		// Wait for the previous transmission to complete
		while (!(GET_BIT(USART2->SR, 7)))
			;
		// Transmit the data
		USART2->DR = Data;
		// Wait for the transmission to complete
		while (!(GET_BIT(USART2->SR, 6)))
			;
		// Clear the transmission complete flag
		CLR_BIT(USART2->SR, 6);
		//Enable INT
		SET_BIT(USART2->CR1, 7);
		break;
	case USART_ID_3:
		// Wait for the previous transmission to complete
		while (!(GET_BIT(USART3->SR, 7)))
			;
		// Transmit the data
		USART3->DR = Data;
		// Wait for the transmission to complete
		while (!(GET_BIT(USART3->SR, 6)))
			;
		// Clear the transmission complete flag
		CLR_BIT(USART3->SR, 6);
		//Enable INT
		SET_BIT(USART3->CR1, 7);
		break;
	}
}
void USART_TransmitStringAsynch(USART_Num usart_num, uint8_t Data[]) {
	static uint8_t i = 0;
	switch (usart_num) {
	case USART_ID_1:
		while (Data[i] != '\0') {
			USART_TransmitByteAsynch(USART_ID_1, Data[i++]);
		}
		break;
	case USART_ID_2:
		while (Data[i] != '\0') {
			USART_TransmitByteAsynch(USART_ID_2, Data[i++]);
		}
		break;
	case USART_ID_3:
		while (Data[i] != '\0') {
			USART_TransmitByteAsynch(USART_ID_3, Data[i++]);
		}
		break;
	}
}
uint8_t USART_RecieveByteAsynch(USART_Num usart_num)
{
	uint8_t RecievedData;
	switch(usart_num)
	{
	case USART_ID_1 :
		while(!(GET_BIT(USART1->SR,5)));
		RecievedData = USART1->DR;	//Enable INT
		SET_BIT(USART1->CR1, 5);
		break;
	case USART_ID_2:
		while(!(GET_BIT(USART2->SR,5)));
		RecievedData = USART2->DR;	//Enable INT
		SET_BIT(USART2->CR1, 5);
		break;
	case USART_ID_3:
		while(!(GET_BIT(USART3->SR,5)));
		RecievedData = USART3->DR;	//Enable INT
		SET_BIT(USART3->CR1, 5);
		break;
	}
	return RecievedData;
}
void USASRT1_SetCallBack(void(*pf)(void))
{
	SET_BIT(USART1->CR1, 7);
	USART1_CallBack = pf;
}
void USASRT2_SetCallBack(void(*pf)(void))
{
	SET_BIT(USART2->CR1, 7);
	USART2_CallBack = pf;
}
void USASRT3_SetCallBack(void(*pf)(void))
{
	SET_BIT(USART1->CR1, 7);
	USART3_CallBack = pf;
}

void USART1_IRQHandler(void){
	if(USART1_CallBack != NULL)
		{
			USART1_CallBack();
			USART1_CallBack = NULL;//just to make interrupt happens one time if you want peroic call setback in while
		}
}
void USART2_IRQHandler(void){
	if(USART2_CallBack != NULL)
	{
		USART2_CallBack();
		USART2_CallBack = NULL;//just to make interrupt happens one time if you want peroic call setback in while
	}

}
void USART3_IRQHandler(void){
	if(USART3_CallBack != NULL)
		{
			USART3_CallBack();
			USART3_CallBack = NULL;//just to make interrupt happens one time if you want peroic call setback in while
		}
}
