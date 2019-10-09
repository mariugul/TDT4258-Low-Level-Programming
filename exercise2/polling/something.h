#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "timer.h"

/** Initialize timer **/
void timer_init(uint16_t period)
{
  *CMU_HFPERCLKEN0 = 0x06;	// Enable clock to timer
  *TIMER1_TOP = period;		// Write the period
  *TIMER1_IEN = 0x01;		// Enable timer interrupt
  *TIMER1_CMD = 0x01;		// Start the timer 
  *ISER0 = 0x12;			// ??? 
}		