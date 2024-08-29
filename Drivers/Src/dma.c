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
    DMA1_Stream6->CR = CHSEL4;


    /* Enable memory increment */
    DMA1_Stream6->CR |= DMA_MEM_INC;


    /* Configure transfer direction */
    DMA1_Stream6->CR |= DMA_DIR_MEM_TO_PERIPH;


    /* Enable DMA transfer complete interrupt */
    DMA1_Stream6->CR |= DMA_CR_TCIE;


    /* Enable direct mode and disable FIFO */
    DMA1_Stream6->FCR = 0;


    /* Enable DMA1 Stream6 */
    DMA1_Stream6->CR |= DMA_CR_EN;



    /* Enable UART2 transmitter DMA*/
    UART2->CR3 |= UART_CR3_DMAT;


    /* DMA interrupt enable NVIC */
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}

void NVIC_EnableIRQ(uint32_t IRQNumber)
{
    if(IRQNumber <= 31)
    {
        // program ISER0 register
        *NVIC_ISER0 |= (1 << IRQNumber);

    }else if(IRQNumber > 31 && IRQNumber < 64) // 32 to 63
    {
        // program ISER1 register
        *NVIC_ISER1 |= (1 << (IRQNumber % 32));

    }else if(IRQNumber >= 64 && IRQNumber < 96) // 64 to 95
    {
        // program ISER2 register
        *NVIC_ISER2 |= (1 << (IRQNumber % 64));

    }
}