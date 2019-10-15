#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "timer.h"

//#define PRESCALER 
#define PRESCALER 0xA000000     // Prescaler for the timer (1024)
#define TIMER_TOP_VALUE 13672   // One second interrupts


/** Initialize timer **/
void timer_init()
{
  	timer_enable_clock();
  	timer_set_prescaler();
  	timer_set_period();
	timer_enable_interrupt();
	timer_start();
}		

void timer_enable_clock()
{
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_TIMER1;	// Enable timer1 clock
}


void timer_set_prescaler()
{
	
	*TIMER1_CTRL |= PRESCALER; // Set prescaler
}

void timer_set_period()
{
	//*TIMER1_TOP  = 0xFFFF;	// Write the top value
	*TIMER1_TOP  = TIMER_TOP_VALUE;	// Write the top value	
}

void timer_enable_interrupt()
{
	*TIMER1_IEN  = 0x1;		// Enable timer interrupt generation
	*ISER0 = 0x1802;		// Enable timer interrupts
}	

void timer_start()
{
	*TIMER1_CMD  = 0x01;		// Start the timer
}
