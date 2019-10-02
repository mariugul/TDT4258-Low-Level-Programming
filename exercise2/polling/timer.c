#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
//#include "timer.h"


/** Initialize timer **/
void timer_init(uint16_t period)
{
    *CMU_HFPERCLKEN0 = 0x06;    // Enable clock to timer
	*TIMER1_TOP = period;       // Write the period
	*TIMER1_IEN = 0x01;         // Enable timer interrupt
	*TIMER1_CMD = 0x01;         // Start the timer 
	/*
	 * TODO enable and set up the timer
	 * 
	 * 1. Enable clock to timer by setting bit 6 in CMU_HFPERCLKEN0 
     * 2. Write the period to register TIMER1_TOP 
     * 3. Enable timer interrupt generation by writing 1 to TIMER1_IEN.
     * 4. Start the timer by writing 1 to TIMER1_CMD.
	 * This will cause a timer interrupt to be generated every (period)
	 * cycles. Remember to configure the NVIC as well, otherwise the
	 * interrupt handler will not be invoked. 
	 */
	
}
