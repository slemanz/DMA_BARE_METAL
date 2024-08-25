#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f401xx.h"

#define CR1_TE          (1U << 3)
#define CR1_UE          (1U << 13)

void uart2_init(void);

#endif