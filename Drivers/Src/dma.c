#include "stm32f401xx.h"

void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len)
{
    /* Enable clock access to DMA */
    RCC->AHB1ENR = DMA1EN;

    /* Disable DMA1 stream6 */
    DMA1_Stream6->CR &= ~DMA_S_EN;


    /* Clear all interrupt flags of stream6 */
    DMA1->HIFCR |= (1U << 16);
    DMA1->HIFCR |= (1U << 18);
    DMA1->HIFCR |= (1U << 19);
    DMA1->HIFCR |= (1U << 20);
    DMA1->HIFCR |= (1U << 21);


    /* Set the destination buffer */
    DMA1_Stream6->PAR = dst;


    /* Set the source buffer */
    DMA1_Stream6->M0AR  = src;


    /* Set length */
    DMA1_Stream6->NDTR = len;


    /* Select Stream6 CH4 */
    /* Enable memory increment */
    /* Configure transfer direction */
    /* Enable direct mode and disable FIFO */
    /* Enable DMA1 Stream6 */
    /* Enable UART2 transmitter DMA*/
    /* DMA interrupt enable NVIC */
}