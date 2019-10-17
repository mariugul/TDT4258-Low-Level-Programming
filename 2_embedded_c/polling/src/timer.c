#include "../inc/timer.h"
#include "../inc/efm32gg.h"
#include <stdbool.h>
#include <stdint.h>

#define PRESCALER 0x00 //Prescaler for the timer (1024)
//#define TIMER_TOP_VALUE 13672/4 // One second interrupts
#define TIMER_TOP_VALUE 0xFFFF 


/** Initialize timer **/
void timer_init()
{
    timer_enable_clock();
    timer_set_prescaler();
    timer_set_period();
    //timer_enable_interrupt();
    timer_start();
}

void timer_enable_clock()
{
    *CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_TIMER1; // Enable timer1 clock
}

void timer_set_prescaler()
{

    *TIMER1_CTRL |= PRESCALER; // Set prescaler
}

void timer_set_period()
{
    *TIMER1_TOP = TIMER_TOP_VALUE; // Write the top value
}

void timer_enable_interrupt()
{
    *TIMER1_IEN = 0x1; // Enable timer interrupt generation
    *ISER0 |= 0x1802; // Enable timer interrupts (and others)
}

void timer_start()
{
    *TIMER1_CMD = 0x01; // Start the timer
}

void timer_stop()
{
    *TIMER1_CMD = 0x00; // Stop the timer
}

int timer_frequency(int freq)
{

}
