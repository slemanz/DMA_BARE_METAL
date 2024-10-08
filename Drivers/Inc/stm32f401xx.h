#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

// this header file describes the microcontroller
#include <stdint.h>
#define __vo volatile


/*******************START: Processor Specific Details *************************/
/*
 * 	ARM-Cortex Mx Processor NVIC ISERx register addresses
 */

#define NVIC_ISER0 						((__vo uint32_t*)0xE000E100UL)
#define NVIC_ISER1 						((__vo uint32_t*)0xE000E104UL)
#define NVIC_ISER2 						((__vo uint32_t*)0xE000E108UL)
#define NVIC_ISER3 						((__vo uint32_t*)0xE000E10CUL)

/*
 * 	ARM-Cortex Mx Processor NVIC ISERx register addresses
 */

#define NVIC_ICER0 						((__vo uint32_t*)0xE000E180UL)
#define NVIC_ICER1 						((__vo uint32_t*)0xE000E184UL)
#define NVIC_ICER2 						((__vo uint32_t*)0xE000E188UL)
#define NVIC_ICER3 						((__vo uint32_t*)0xE000E18CUL)

/*
 * ARm Cortex Mx Processor Priority Regesiter Address Calculation
 */

#define NVIC_PR_BASE_ADDR	((__vo uint32_t*)0xE000E400UL)

#define NO_PR_BITS_IMPLEMENTED 		4



/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U
#define ROM_BASEADDR						0x1FFF 0000 	/* system memory */
#define SRAM1 								SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASE							0x40000000U
#define APB1PERIPH_BASE						PERIPH_BASE
#define APB2PERIPH_BASE						0x40010000U
#define AHB1PERIPH_BASE						0x40020000U
#define AHB2PERIPH_BASE						0x50000000U


/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define GPIOA_BASEADDR						(AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASEADDR						(AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASEADDR						(AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASEADDR						(AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASEADDR						(AHB1PERIPH_BASE + 0x1000U)
#define GPIOH_BASEADDR						(AHB1PERIPH_BASE + 0x1C00U)

#define RCC_BASEADDR						(AHB1PERIPH_BASE + 0x3800U)
#define DMA1_BASEADDR           			(AHB1PERIPH_BASE + 0x6000)
#define DMA2_BASEADDR             			(AHB1PERIPH_BASE + 0x6400)

#define DMA1_Stream0_BASEADDR     			(DMA1_BASEADDR + 0x010)
#define DMA1_Stream1_BASEADDR     			(DMA1_BASEADDR + 0x028)
#define DMA1_Stream2_BASEADDR     			(DMA1_BASEADDR + 0x040)
#define DMA1_Stream3_BASEADDR     			(DMA1_BASEADDR + 0x058)
#define DMA1_Stream4_BASEADDR     			(DMA1_BASEADDR + 0x070)
#define DMA1_Stream5_BASEADDR     			(DMA1_BASEADDR + 0x088)
#define DMA1_Stream6_BASEADDR     			(DMA1_BASEADDR + 0x0A0)
#define DMA1_Stream7_BASEADDR     			(DMA1_BASEADDR + 0x0B8)

#define DMA2_Stream0_BASEADDR     			(DMA2_BASEADDR + 0x010)
#define DMA2_Stream1_BASEADDR     			(DMA2_BASEADDR + 0x028)
#define DMA2_Stream2_BASEADDR     			(DMA2_BASEADDR + 0x040)
#define DMA2_Stream3_BASEADDR     			(DMA2_BASEADDR + 0x058)
#define DMA2_Stream4_BASEADDR     			(DMA2_BASEADDR + 0x070)
#define DMA2_Stream5_BASEADDR     			(DMA2_BASEADDR + 0x088)
#define DMA2_Stream6_BASEADDR     			(DMA2_BASEADDR + 0x0A0)
#define DMA2_Stream7_BASEADDR     			(DMA2_BASEADDR + 0x0B8)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 */

#define I2C1_BASEADDR						(APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASEADDR						(APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASEADDR						(APB1PERIPH_BASE + 0x5C00U)

#define SPI2_BASEADDR						(APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASEADDR						(APB1PERIPH_BASE + 0x3C00U)

#define USART2_BASEADDR						(APB1PERIPH_BASE + 0x4400U)


/*
 * Base addresses of peripherals which are hanging on APB2 bus
 */

#define EXTI_BASEADDR						(APB2PERIPH_BASE + 0x3C00U)
#define SYSCFG_BASEADDR						(APB2PERIPH_BASE + 0x3800U)

#define SPI1_BASEADDR						(APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASEADDR						(APB2PERIPH_BASE + 0x3400U)

#define USART1_BASEADDR						(APB2PERIPH_BASE + 0x1000U)
#define USART6_BASEADDR						(APB2PERIPH_BASE + 0x1400U)

/*
 *  Base adress of systick	and timers
 */

#define SCS_BASE            				(0xE000E000UL)
#define SYSTICK_BASEADDR					(SCS_BASE + 0x0010UL)

#define TIM2_BASEADDR						(APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASEADDR						(APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASEADDR						(APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASEADDR						(APB1PERIPH_BASE + 0x0C00UL)


/*******************peripheral register definition structures*******************/

typedef struct
{
	__vo uint32_t MODER; /* configure the mode of pin 			address offset: 0x00 */
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR; 			// 0x00
	__vo uint32_t PLLCFGR;		// 0x04
	__vo uint32_t CFGR;			//0x08
	__vo uint32_t CIR;			// 0x0C
	__vo uint32_t AHB1RSTR;		// 0x10
	__vo uint32_t AHB2RSTR;		// 0x14
	__vo uint32_t reserved[2];
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t reserved1[2];
	__vo uint32_t AHB1ENR;		//
	__vo uint32_t AHB2ENR;
	__vo uint32_t reserved2[2];
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t reserved3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t reserved4[2];
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t reserved5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t reserved6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t DCKCFGR;
}RCC_RegDef_t;

typedef struct{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t reserved[2];
	__vo uint32_t CMPCR;
}SYSCFG_RegDef_t;

typedef struct{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;

typedef struct
{
  __vo uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __vo uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __vo uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __vo uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
}SysTick_RegDef_t;

typedef struct
{
	__vo uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  	__vo uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
	__vo uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
	__vo uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
	__vo uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
	__vo uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
	__vo uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
	__vo uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
	__vo uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
	__vo uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
	__vo uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
	__vo uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
	__vo uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
	__vo uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
	__vo uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
	__vo uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
	__vo uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
	__vo uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
	__vo uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
	__vo uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
	__vo uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
}TIM_RegDef_t;

typedef struct{
  	__vo uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  	__vo uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  	__vo uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  	__vo uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  	__vo uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  	__vo uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  	__vo uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} UART_RegDef_t;

typedef struct{
	__vo uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
	__vo uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
	__vo uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	__vo uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_RegDef_t;

typedef struct
{
  __vo uint32_t CR;     /*!< DMA stream x configuration register      */
  __vo uint32_t NDTR;   /*!< DMA stream x number of data register     */
  __vo uint32_t PAR;    /*!< DMA stream x peripheral address register */
  __vo uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
  __vo uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
  __vo uint32_t FCR;    /*!< DMA stream x FIFO control register       */
} DMA_Stream_RegDef_t;


/*
 * 	peripheral definitions (Peripheral base address typecasted to xxx_RegDef_t)
 */

#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD			((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE			((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH			((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC				((RCC_RegDef_t*)RCC_BASEADDR)

#define SYSCFG			((SYSCFG_RegDef_t*)SYSCFG_BASEADDR	)

#define EXTI			((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SysTick         ((SysTick_RegDef_t*)SYSTICK_BASEADDR) 

#define TIM2			((TIM_RegDef_t*)TIM2_BASEADDR)
#define TIM3			((TIM_RegDef_t*)TIM3_BASEADDR)
#define TIM4			((TIM_RegDef_t*)TIM4_BASEADDR)
#define TIM5			((TIM_RegDef_t*)TIM5_BASEADDR)

#define UART1			((UART_RegDef_t*)USART1_BASEADDR)
#define UART2			((UART_RegDef_t*)USART2_BASEADDR)
#define UART6			((UART_RegDef_t*)USART6_BASEADDR)

#define DMA1			((DMA_RegDef_t*)DMA1_BASEADDR)
#define DMA2			((DMA_RegDef_t*)DMA2_BASEADDR)

#define DMA1_Stream0	((DMA_Stream_RegDef_t*)DMA1_Stream0_BASEADDR)
#define DMA1_Stream1	((DMA_Stream_RegDef_t*)DMA1_Stream1_BASEADDR)
#define DMA1_Stream2	((DMA_Stream_RegDef_t*)DMA1_Stream2_BASEADDR)
#define DMA1_Stream3	((DMA_Stream_RegDef_t*)DMA1_Stream3_BASEADDR)
#define DMA1_Stream4	((DMA_Stream_RegDef_t*)DMA1_Stream4_BASEADDR)
#define DMA1_Stream5	((DMA_Stream_RegDef_t*)DMA1_Stream5_BASEADDR)
#define DMA1_Stream6	((DMA_Stream_RegDef_t*)DMA1_Stream6_BASEADDR)
#define DMA1_Stream7	((DMA_Stream_RegDef_t*)DMA1_Stream7_BASEADDR)

#define DMA2_Stream0	((DMA_Stream_RegDef_t*)DMA2_Stream0_BASEADDR)
#define DMA2_Stream1	((DMA_Stream_RegDef_t*)DMA2_Stream1_BASEADDR)
#define DMA2_Stream2	((DMA_Stream_RegDef_t*)DMA2_Stream2_BASEADDR)
#define DMA2_Stream3	((DMA_Stream_RegDef_t*)DMA2_Stream3_BASEADDR)
#define DMA2_Stream4	((DMA_Stream_RegDef_t*)DMA2_Stream4_BASEADDR)
#define DMA2_Stream5	((DMA_Stream_RegDef_t*)DMA2_Stream5_BASEADDR)
#define DMA2_Stream6	((DMA_Stream_RegDef_t*)DMA2_Stream6_BASEADDR)
#define DMA2_Stream7	((DMA_Stream_RegDef_t*)DMA2_Stream7_BASEADDR)

/*
 * Clock enable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))


/*
 * Clock enable macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()		(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()		(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()		(RCC->APB1ENR |= (1 << 23))


/*
 * Clock enable macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()		(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()		(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()		(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()		(RCC->APB2ENR |= (1 << 13))

/*
 * Clock enable macros for USARTx peripherals
 */

#define UART1_PCLK_EN()		(RCC->APB2ENR |= (1 << 4))
#define UART2_PCLK_EN()		(RCC->APB1ENR |= (1 << 17))
#define UART6_PCLK_EN()		(RCC->APB2ENR |= (1 << 5))


/*
 * Clock enable macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_EN()		(RCC->APB2ENR |= (1 << 14))

/*
 * Clock enable macros for TIMx peripherals
 */

#define TIM2_PCLK_EN()		(RCC->APB1ENR |= (1 << 0))
#define TIM3_PCLK_EN()		(RCC->APB1ENR |= (1 << 1))
#define TIM4_PCLK_EN()		(RCC->APB1ENR |= (1 << 2))
#define TIM5_PCLK_EN()		(RCC->APB1ENR |= (1 << 3))


/*
 * Clock disable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 7))


/*
 * Clock disable macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 23))


/*
 * Clock disable macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 13))

/*
 * Clock disable macros for USARTx peripherals
 */

#define UART1_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 4))
#define UART2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 17))
#define UART6_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 5))


/*
 * Clock disable macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 14))

/*
 * Clock enable macros for TIMx peripherals
 */

#define TIM2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 0))
#define TIM3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 1))
#define TIM4_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 2))
#define TIM5_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 3))

/*
 * 	Macros to reset GPIOx peripherals
 */

#define GPIOA_REG_RESET()		do{RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0);}while(0)
#define GPIOB_REG_RESET()		do{RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1);}while(0)
#define GPIOC_REG_RESET()		do{RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2);}while(0)
#define GPIOD_REG_RESET()		do{RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3);}while(0)
#define GPIOE_REG_RESET()		do{RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4);}while(0)
#define GPIOH_REG_RESET()		do{RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7);}while(0)


/*
 *  Macro to give the code of a port
 */

#define GPIO_BASEADDR_TO_CODE(x)	  ( (x == GPIOA) ? 0 :\
										(x == GPIOB) ? 1 :\
										(x == GPIOC) ? 2 :\
										(x == GPIOD) ? 3 :\
										(x == GPIOE) ? 4 :\
										(x == GPIOH) ? 7 : 0 )



/*
 * some generic macros
 */

#define ENABLE 						1
#define	DISABLE 					0
#define SET							ENABLE
#define RESET						DISABLE
#define GPIO_PIN_SET				SET
#define GPIO_PIN_RESET				RESET


/*
 * IRQ numbers macros - the positions
 * IRQ (Interrupt Request)
 */

#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI3 		8
#define IRQ_NO_EXTI4 		9
#define IRQ_NO_EXTI5 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40

/*
 * IRQ Priority levels
 */

#define NVIC_IRQ_PRI0		0
#define NVIC_IRQ_PRI15		15


/*
 * Drivers includes
 */

#include "gpio.h"
#include "systick.h"
#include "timer.h"
#include "uart.h"
#include "dma.h"

#endif