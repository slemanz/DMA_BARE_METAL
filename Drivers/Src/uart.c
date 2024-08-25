#include "stm32f401xx.h"

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);

void uart2_init(void)
{
    // configure uart module:
    // enable clock
    UART1_PCLK_EN();

    // configure baudrate
    UART2->BRR = compute_uart_div(16000000, 9600);

    // configure the transfer direction
    UART2->CR1 = CR1_TE;

}

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}