/*
 * EXTI.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Lenovo
 */

#ifndef MCAL_DRIVERS_EXTI_H_
#define MCAL_DRIVERS_EXTI_H_

#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"





typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;


typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
}AFIO_TypeDef_EXTI;

#define EXTI_BASE	(0x40010400)
#define EXTI		((EXTI_TypeDef *)EXTI_BASE)

#define AFIO_BASE	(0x40010000)
#define AFIO		((AFIO_TypeDef_EXTI *)AFIO_BASE)



typedef enum
{
	EXTI_LINE0 = 0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15,
}Int_Line;

typedef enum
{
	EXTI_Rising_Edge,
	EXTI_Falling_Edge,
	EXTI_Level_Edge
}Edge_Type;


typedef enum
{
	EXTI_PORTA = 0,
	EXTI_PORTB ,
	EXTI_PORTC ,

}EXTI_PORTS;


void EXTI_EnableIntLine(Int_Line IntLine);
void EXTI_DisableIntLine(Int_Line IntLine);
void EXTI_SoftwareEnableInt(Int_Line IntLine);
void EXTI_SetEdge(Int_Line IntLine, Edge_Type Edge);
void EXTI_SetMapping(Int_Line IntLine,EXTI_PORTS Port);
void EXTI_SetCallBack(Int_Line IntLine,void(*pf)(void));

#endif /* MCAL_DRIVERS_EXTI_H_ */
