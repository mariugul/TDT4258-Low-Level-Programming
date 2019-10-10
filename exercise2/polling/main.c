#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "timer.h"
#include "gpio.h"
#include "dac.h"
#include "interrupt.h"
#include "low_energy.h"

#define  SAMPLE_PERIOD   100	// The period between sound samples, in clock cycles
#define	 PRESCALER 		 13672 


int main (void)
{
	// Initialize
	gpio_init();        	
  	//dac_init ();         	
 	nvic_init();			
	timer_init();
    //low_energy_init();

    // Prototype		
    //gpio_leds_off();
	
	// Loop
	while (true)
    {  
        gpio_map_to_led();
        
        //sleep();
    }
	
	return 0;
}

 
 

