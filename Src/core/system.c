#include "core/system.h"

static volatile uint64_t ticks = 0;

void SysTick_Handler(void)
{
    ticks++;
}

uint64_t system_get_ticks(void)
{
    return ticks;
}

void systick_setup(void)
{
    systick_set_frequency(SYSTICK_FREQ, CPU_FREQ);
    systick_counter_enable();
    systick_interrupt_enable();
}

void system_setup(void)
{
    systick_setup();
}

