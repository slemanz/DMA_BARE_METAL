#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "stm32f401xx.h"

#define DMA1EN                      (1U << 21) 
#define DMA2EN                      (1U << 22) 

// symbolic names
#define DMA_S_EN                    (1U << 0)
#define CHSEL4                      (1U << 27)
#define DMA_MEM_INC                 (1U << 10)
#define DMA_DIR_MEM_TO_PERIPH       (1U << 16)
#define DMA_CR_TCIE                 (1U << 14)
#define DMA_CR_EN                   (1U << 0)


#define DMA1_Stream6_IRQn           (17)


void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);


void NVIC_EnableIRQ(uint32_t IRQNumber);

#endif