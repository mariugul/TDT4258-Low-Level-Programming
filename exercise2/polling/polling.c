#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "timer.h"
#include "gpio.h"
//#include "dac.h"
#include "interrupt.h"
//#include "low_energy.h"

#define  SAMPLE_PERIOD   100	// The period between sound samples, in clock cycles
#define	 PRESCALER 		 13672 



int main (void)
{
	// Initialize
	gpio_init();        	
  	//dac_init ();         	
 	//nvic_init();			
	timer_init(PRESCALER);		
	
	//gpio_leds_on();
	
	// Loop
	while (true)
    {  
    
    	/*
    	if (global_var == 1)
			gpio_leds_on();
			
		else if (global_var == 0) 
			gpio_leds_off();			
      */
    }
	
	return 0;
}

 
 

