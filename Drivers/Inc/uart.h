#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f401xx.h"

#define CR1_TE                  (1U << 3)
#define CR1_UE                  (1U << 13)

#define SR_TXE                  (1U << 7)

#define UART_CR3_DMAT           (1U << 7)

void uart2_init(void);
void uart2_tx(uint8_t ch);
void uart2_tx_string(uint8_t *ch, uint32_t Len);

#endif