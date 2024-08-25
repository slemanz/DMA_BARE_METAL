#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "stm32f401xx.h"

void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);

#endif