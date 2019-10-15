#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "interrupt.h"
#include "gpio.h"
#include "timer.h"


void nvic_init()			// Enable interrupts
{
   
}


/*
 * TIMER1 interrupt handler 
 */
void __attribute__ ((interrupt)) TIMER1_IRQHandler ()
{
	static bool state = false;
	static int count = 0;
    count++;
    if(count > 100){
    	state = !state;
    	count = 0;
    }
    //if(count > 20){ 
	if(state)
	{	
		*DAC0_CH0DATA = 0xF; 
		*DAC0_CH1DATA = 0XF;
	//gpio_leds_off();
		//state = false;
	}
	else
	{
		*DAC0_CH0DATA = 0x00; 
		*DAC0_CH1DATA = 0x00;
		//gpio_leds_on();
		//state = true;
	}
	//count = 0;
	//}
	
	
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
