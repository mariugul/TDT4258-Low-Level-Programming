#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "interrupt.h"
#include "gpio.h"
#include "timer.h"


void nvic_init()			// Enable interrupts
{
	/*
   * TODO use the NVIC ISERx registers to enable handling of
   * interrupt(s) remember two things are necessary for interrupt
   * handling: - the peripheral must generate an interrupt signal - the
   * NVIC must be configured to make the CPU handle the signal You will
   * need TIMER1, GPIO odd and GPIO even interrupt handling for this
  / * assignment. 
   */
   
}


/*
 * TIMER1 interrupt handler 
 */
void __attribute__ ((interrupt)) TIMER1_IRQHandler ()
{
	static bool state = false;
	if(state)
	{	
		gpio_leds_on();
		state = false;
	}
	else
	{
		gpio_leds_off();
		state = true;
	}
	

	*TIMER1_IFC = 0x1;				// Clear the interrupt flag
}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler ()
{
  /*
   * TODO handle button pressed event, remember to clear pending
   * interrupt 
   */
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler ()
{
  /*
   * TODO handle button pressed event, remember to clear pending
   * interrupt 
   */
}
