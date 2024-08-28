#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "stm32f401xx.h"

#define DMA1EN             21
#define DMA2EN             22

#define DMA_S_EN            (1U << 0)


void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);

#endif