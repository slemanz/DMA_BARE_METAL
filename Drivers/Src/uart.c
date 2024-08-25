#include "stm32f401xx.h"

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate);

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate)
{
    return ((PeriphClk + (BaudRate/2U))/BaudRate);
}

void uart2_init(void)
{
    // configure uart module:
    // enable clock
    UART2_PCLK_EN();

    // configure baudrate
    UART2->BRR = compute_uart_div(16000000, 9600);

    // configure the transfer direction
    UART2->CR1 = CR1_TE;

    // enable uart module
    UART2->CR1 |= CR1_UE;

}

void uart2_tx(uint8_t ch)
{
    while(!(UART2->SR & SR_TXE));
    UART2->DR = ch;
}

void uart2_tx_string(uint8_t *ch, uint32_t Len)
{
    for(uint32_t i = 0; i < Len; i++)
    {
        if(ch[i] != '\0') uart2_tx(ch[i]);
    }
}