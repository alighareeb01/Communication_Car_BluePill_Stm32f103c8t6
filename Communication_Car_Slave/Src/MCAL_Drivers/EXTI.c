/*
 * EXTI.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Lenovo
 */


#include "MCAL_Drivers/EXTI.h"
#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

static void (*Pf_callBack[16])(void)={
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
};

void EXTI_EnableIntLine(Int_Line IntLine)
{
	if(IntLine <= 15 && IntLine >= 0)
	{
		SET_BIT(EXTI->IMR, IntLine);
	}
}
void EXTI_DisableIntLine(Int_Line IntLine)
{
	if (IntLine <= 15 && IntLine >= 0)
	{
		CLR_BIT(EXTI->IMR, IntLine);
	}
}
void EXTI_SoftwareEnableInt(Int_Line IntLine)
{
	if (IntLine <= 15 && IntLine >= 0)
	{
		SET_BIT(EXTI->SWIER, IntLine);
	}
}
void EXTI_SetEdge(Int_Line IntLine, Edge_Type Edge)
{
	if(IntLine <= 15 && IntLine >= 0)
	{
		switch (Edge) {
			case EXTI_Rising_Edge:
				SET_BIT(EXTI->RTSR,IntLine);
				CLR_BIT(EXTI->FTSR,IntLine);
				break;
			case EXTI_Falling_Edge :
				CLR_BIT(EXTI->RTSR,IntLine);
				SET_BIT(EXTI->FTSR,IntLine);
				break;
			case EXTI_Level_Edge :
				SET_BIT(EXTI->RTSR,IntLine);
				SET_BIT(EXTI->FTSR,IntLine);
				break;
		}
	}
}
void EXTI_SetMapping(Int_Line IntLine,EXTI_PORTS Port)
{
	if(IntLine <= 15 && IntLine >= 0)
	{
	switch(IntLine)
	{
	case EXTI_LINE0:
		AFIO->EXTICR1 &= ~(0b1111 << 0);
		AFIO->EXTICR1 |= (Port << 0);
		break;
	case EXTI_LINE1:
		AFIO->EXTICR1 &= ~(0b1111 << 4);
		AFIO->EXTICR1 |= (Port << 4);
		break;
	case EXTI_LINE2:
		AFIO->EXTICR1 &= ~(0b1111 << 8);
		AFIO->EXTICR1 |= (Port << 8);
		break;
	case EXTI_LINE3:
		AFIO->EXTICR1 &= ~(0b1111 << 12);
		AFIO->EXTICR1 |= (Port << 12);
		break;
	case EXTI_LINE4:
		AFIO->EXTICR2 &= ~(0b1111 << 0);
		AFIO->EXTICR2 |= (Port << 0);
		break;
	case EXTI_LINE5:
		AFIO->EXTICR2 &= ~(0b1111 << 4);
		AFIO->EXTICR2 |= (Port << 4);
		break;
	case EXTI_LINE6:
		AFIO->EXTICR2 &= ~(0b1111 << 8);
		AFIO->EXTICR2 |= (Port << 8);
		break;
	case EXTI_LINE7:
		AFIO->EXTICR2 &= ~(0b1111 << 12);
		AFIO->EXTICR2 |= (Port << 12);
		break;
	case EXTI_LINE8:
		AFIO->EXTICR3 &= ~(0b1111 << 0);
		AFIO->EXTICR3 |= (Port << 0);
		break;
	case EXTI_LINE9:
		AFIO->EXTICR3 &= ~(0b1111 << 4);
		AFIO->EXTICR3 |= (Port << 4);
		break;
	case EXTI_LINE10:
		AFIO->EXTICR3 &= ~(0b1111 << 8);
		AFIO->EXTICR3 |= (Port << 8);
		break;
	case EXTI_LINE11:
		AFIO->EXTICR3 &= ~(0b1111 << 12);
		AFIO->EXTICR3 |= (Port << 12);
		break;
	case EXTI_LINE12:
		AFIO->EXTICR4 &= ~(0b1111 << 0);
		AFIO->EXTICR4 |= (Port << 0);
		break;
	case EXTI_LINE13:
		AFIO->EXTICR4 &= ~(0b1111 << 0);
		AFIO->EXTICR4 |= (Port << 0);
		break;
	case EXTI_LINE14:
		AFIO->EXTICR4 &= ~(0b1111 << 0);
		AFIO->EXTICR4 |= (Port << 0);
		break;
	case EXTI_LINE15:
		AFIO->EXTICR4 &= ~(0b1111 << 0);
		AFIO->EXTICR4 |= (Port << 0);
		break;
	}
	}
}
void EXTI_SetCallBack(Int_Line IntLine,void(*pf)(void))
{
	if(IntLine <= 15 && IntLine >= 0)
	{
	Pf_callBack[IntLine] = pf;
	}
}


void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR, EXTI_LINE0);
	Pf_callBack[EXTI_LINE0]();

}

void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR, EXTI_LINE1);
	Pf_callBack[EXTI_LINE1]();

}
void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI->PR, EXTI_LINE2);
	Pf_callBack[EXTI_LINE2]();

}
void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI->PR, EXTI_LINE3);
	Pf_callBack[EXTI_LINE3]();

}
void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI->PR, EXTI_LINE4);
	Pf_callBack[EXTI_LINE4]();

}
