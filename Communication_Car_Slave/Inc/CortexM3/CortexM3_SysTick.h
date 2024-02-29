/*
 * CortexM3_SYSTICK.h
 *
 *  Created on: Feb 1, 2024
 *      Author: Lenovo
 */

#ifndef CORTEXM3_CORTEXM3_SYSTICK_H_
#define CORTEXM3_CORTEXM3_SYSTICK_H_

#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"

typedef struct
{
	volatile uint32_t CSR;
	volatile uint32_t RVR;
	volatile uint32_t CVR;
	volatile uint32_t CALIB;
}SysTick_TypeDef;

#define SysTick_Base	(0xE000E010)
#define SysTick   		((SysTick_TypeDef *)SysTick_Base)

#define SysTick_CSR_ENABLE_POS		0U
#define SysTick_CSR_ENABLE_MASK		(1UL << SysTick_CSR_ENABLE_POS)

#define SysTick_CSR_TICKINT_POS		1U
#define SysTick_CSR_TICKINT_MASK		(1UL << SysTick_CSR_TICKINT_POS)

#define SysTick_CSR_CLKSOURCE_POS		2U
#define SysTick_CSR_CLKSOURCE_MASK		(1UL << SysTick_CSR_CLKSOURCE_POS)

#define SysTick_CSR_COUNTFLAG_POS		16U
#define SysTick_CSR_COUNTFLAG_MASK		(1UL << SysTick_CSR_COUNTFLAG_POS)


#define SysTick_RVR_RELOAD_POS		0U
#define SysTick_RVR_RELOAD_MASK		(0xFFFFFFUL << SysTick_RVR_RELOAD_POS)

#define SysTick_CVR_RELOAD_POS		0U
#define SysTick_CVR_RELOAD_MASK		(0xFFFFFFUL << SysTick_CVR_RELOAD_POS)

#define SysTick_CALIB_TENMS_POS		0U
#define SysTick_CALIB_TENMS_MASK	(0xFFFFFFUL << SysTick_CALIB_TENMS_POS)

#define SysTick_CALIB_SKEW_POS		30U
#define SysTick_CALIB_SKEW_MASK		(1UL << SysTick_CALIB_SKEW_POS)

#define SysTick_CALIB_NOREF_POS		31U
#define SysTick_CALIB_NOREF_MASK	(1UL << SysTick_CALIB_NOREF_POS)


#define CLOCK_SOURCE_EXTERNAL_CLOCK		0U
#define	CLOCK_SOURCE_PROCESSOR_CLOCK	1U

#define CLOCK_SOURCE	CLOCK_SOURCE_PROCESSOR_CLOCK

#define Single_Interval 	0U
#define Periodic_Interval 	1U


/*
 * Init Seq
 * 			1)program reload value
 * 			2)clear current
 * 			3)program control and status register
 */
void SysTick_Init(void);
void SysTick_DisableCounter(void);
void SysTick_WaitBlocking(uint32_t Ticks);

/*
 * Mode:
 * 		Single_Interval
 * 		Periodic_Interval
 */
void SysTick_Asynch(uint32_t Mode, uint32_t Ticks);
void SysTick_SetCallBack(void(*ptrToFun)(void));

#endif /* CORTEXM3_CORTEXM3_SYSTICK_H_ */
