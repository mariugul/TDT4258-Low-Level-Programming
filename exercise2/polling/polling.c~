#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "timer.h"
#include "gpio.h"
#include "dac.h"
#include "interrupt.h"

#define  SAMPLE_PERIOD   100	// The period between sound samples, in clock cycles
#define	 PERIOD 		 10 



int main (void)
{
	// Initialize
	gpio_init();        	
  	dac_init ();         	
 	nvic_init();			
	timer_init(PERIOD);		

	// Loop
	while (true)
    {
      *DAC0_CH0DATA = 130;	// What happens here?
      *DAC0_CH1DATA = 130;
    }

	
	return 0;
}

 
 
 
 
 
 
 
 
 
 /*
 * TODO calculate the appropriate sample period for the sound wave(s) you 
 * want to generate. The core clock (which the timer clock is derived
 * from) runs at 14 MHz by default. Also remember that the timer counter
 * registers are 16 bits. 
 */

