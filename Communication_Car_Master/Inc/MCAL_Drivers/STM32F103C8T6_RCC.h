/*
 * STM32F103C8T6.h
 *
 *  Created on: Jan 30, 2024
 *      Author: Lenovo
 */

#ifndef MCAL_DRIVERS_STM32F103C8T6_RCC_H_
#define MCAL_DRIVERS_STM32F103C8T6_RCC_H_

#include "Common/BIT_Math.h"
#include "Common/Std_Types.h"







typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;


} RCC_TypeDef;

#define RCC_Base (0x40021000)
#define RCC 	 ((RCC_TypeDef* )RCC_Base)


void RCC_GPIOx_Clk_ENABLE(uint32_t GPIOx);
void RCC_GPIOx_Clk_DISABLE(uint32_t GPIOx);


#define RCC_OscType_None		 0x00000000U
#define RCC_OscType_HSE		 	 0x00000001U
#define RCC_OscType_HSI		 	 0x00000002U
#define RCC_OscType_LSE		 	 0x00000004U
#define RCC_OscType_LSI			 0x00000008U

#define RCC_HSE_ON			 	 0x00000001U
#define RCC_HSE_OFF				 0x00000000U

#define RCC_HSI_ON			 	 0x00000001U
#define RCC_HSI_OFF				 0x00000000U

#define RCC_LSE_ON			 	 0x00000001U
#define RCC_LSE_OFF				 0x00000000U

#define RCC_LSI_ON			 	 0x00000001U
#define RCC_LSI_OFF				 0x00000000U

#define RCC_CR_HSEON_POS		(16UL)
#define RCC_CR_HSEON_MASK		(0x1UL << RCC_CR_HSEON_POS)

#define APB2_PreScalar_Pos		 11U
#define APB2_PreScalar_MASK		 0x7UL << APB2_PreScalar_Pos

#define APB1_PreScalar_Pos		 8U
#define APB1_PreScalar_MASK		 0x7UL << APB2_PreScalar_Pos

#define AHB_PreScalar_Pos		 4U
#define AHB_PreScalar_MASK		 0xFUL << APB2_PreScalar_Pos


#define AHB_DIV1		0x00000000U
#define AHB_DIV2		0x00000080U
#define AHB_DIV4		0x00000090U
#define AHB_DIV8		0x000000A0U
#define AHB_DIV16		0x000000B0U
#define AHB_DIV64		0x000000C0U
#define AHB_DIV128		0x000000D0U
#define AHB_DIV256		0x000000E0U
#define AHB_DIV512		0x000000F0U

#define APB2_DIV1		0x00000000U
#define APB2_DIV2		0x00002000U
#define APB2_DIV4		0x00002800U
#define APB2_DIV8		0x00003000U
#define APB2_DIV16		0x00003800U

#define APB1_DIV1		0x00000000U
#define APB1_DIV2		0x00000400U
#define APB1_DIV4		0x00000500U
#define APB1_DIV8		0x00000600U
#define APB1_DIV16		0x00000700U

/*
 * PLL Clock Source
 */
enum
{
	HSI_2,
	HSE_2,
	HSE
};
/*
 * PLL MUL Factor
 */
enum
{
	PLL_input_clock_x2,
	PLL_input_clock_x3,
	PLL_input_clock_x4,
	PLL_input_clock_x5,
	PLL_input_clock_x6,
	PLL_input_clock_x7,
	PLL_input_clock_x8,
	PLL_input_clock_x9,
	PLL_input_clock_x10,
	PLL_input_clock_x11,
	PLL_input_clock_x12,
	PLL_input_clock_x13,
	PLL_input_clock_x14,
	PLL_input_clock_x15,
	PLL_input_clock_x16,
};
/*
 * Bus Name
 */
enum
{
	AHB_BUS,
	APB1_BUS,
	APB2_BUS
};
/*
 * peripheral index for RCC_AHBENR
 * for any peripherals needed to be used in the future, just add
 * its index here
 */
enum
{
	DMA1_EN,
	DMA2_EN,
	SRAM_EN,
	FLITF_EN = 4,
	CRC_EN = 6,
	OTGFS_EN = 12,

};
/*
 * peripheral index for RCC_APB1RSTR
 * for any peripherals needed to be used in the future, just add
 * its index here
 */
enum
{
	TIM2_RST = 0,
	TIM3_RST,
	TIM4_RST,
	TIM5_RST,
	TIM6_RST,
	TIM7_RST,
	WWDG_RST,
};
/*
 * peripheral index for RCC_APB2ENR
 * for any peripherals needed to be used in the future, just add
 * its index here
 */
enum
{
	AFIO_EN,
	GPIOA_EN = 2,
	GPIOB_EN = 3,
	GPIOC_EN = 4,
	GPIOD_EN = 5,
	GPIOE_EN = 6,
	ADC1_EN = 9,
	ADC2_EN = 10,
	TIM1_EN = 11,
	SPI1_EN = 12,
	USART1_EN = 14,
};
enum
{
	TIM2_EN = 0,
	TIM3_EN = 0,
	TIM4_EN = 0,
	TIM5_EN = 0,
	TIM6_EN = 0,
	TIM7_EN = 0,
	WWDG_EN = 11,
	SPI2_EN = 14,
	SPI3_EN = 15,
	USART2_EN = 17,
	USART3_EN = 18,
};
void RCC_EnableHSI(void);
void RCC_EnableHSE(void);
void RCC_EnablePLL(uint8_t CLK_Source, uint8_t PLLVal);
void RCC_EnablePeriphalClk(uint8_t BusName,uint8_t Periphal);
void RCC_DisablePeriphalClk(uint8_t BusName,uint8_t Periphal);
void RCC_AHB_PreScalar(uint32_t PrescalarValue);
void RCC_APB1_PreScalar(uint32_t PrescalarValue);
void RCC_APB2_PreScalar(uint32_t PrescalarValue);

#endif /* MCAL_DRIVERS_STM32F103C8T6_RCC_H_ */
