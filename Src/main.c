#include "stm32f401xx.h"
#include "core/system.h"

// Define led
#define LED_PORT        GPIOA
#define LED_PIN         GPIO_PIN_NO_3

// Function delay
void delay_cycles(uint32_t cycles)
{
    while (cycles-- > 0) {
        __asm("NOP"); // No operation for delay
    }
}

void gpio_setup(void)
{
    // Set GPIOA pin 3 as output
    GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = LED_PORT;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = LED_PIN;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&GpioLed);
    GPIO_WriteToOutputPin(LED_PORT, LED_PIN, GPIO_PIN_RESET);


    GPIO_Handle_t UartTx;
    UartTx.pGPIOx = GPIOA;
    UartTx.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
    UartTx.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
    UartTx.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    UartTx.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    UartTx.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    UartTx.GPIO_PinConfig.GPIO_PinAltFunMode = GPIO_PIN_ALTFN_7;

    GPIO_Init(&UartTx);
}

static void dma_callback();

int main(void)
 {
    gpio_setup();
    uart2_init(); // tx init
    system_setup();


    uint8_t string[] = "Hello World from dma!\n";

    uint64_t start_time = system_get_ticks();

    while (1)
    {
        if((system_get_ticks() - start_time) >= 2000)
        {
            dma1_stream6_init((uint32_t)string, (uint32_t)&UART2->DR, sizeof(string)); // not best practice, just to understand how dma works
            start_time = system_get_ticks();
        }

        // Do useful work
    }
}

static void dma_callback(void)
{
    GPIOA->ODR |= (1 << 3);
}

// this part seems not to be working
void DMA1_Stream6_IRQHandler(void)
{
    /* Check for transfer complete interrupt */
    if(DMA1->HISR & HISR_TCIF6) 
    {
        /* Clear flag*/
        DMA1->HIFCR |= HIFCR_CTCIF6;

        /* Do something */
        dma_callback();
    }
}