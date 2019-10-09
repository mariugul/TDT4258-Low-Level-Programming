#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "gpio.h"

// LED VALUES
#define LEDS_OFF 		0xFF00
#define LEDS_ON  		0x00FF

// DRIVE STRENGTHS
#define STANDARD_DRIVE	0x00
#define LOWEST_DRIVE	0x01
#define LOW_DRIVE		0x03
#define HIGH_DRIVE		0x02

/*
 * function to set up GPIO mode and interrupts
 */
void gpio_init()
{
	gpio_enable_clock();
  	gpio_set_drive();
  	gpio_set_pins();
  	gpio_enable_interrupt();
	gpio_leds_off();
}

void gpio_leds_on()
{
	*GPIO_PA_DOUT = LEDS_ON;					// Turns leds on
}

void gpio_leds_off()
{
	*GPIO_PA_DOUT = LEDS_OFF;					// Turns leds off
}

void gpio_enable_clock()
{
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;	// Enable GPIO clock
}

void gpio_set_drive()
{
	*GPIO_PA_CTRL   = 2;			// Set high drive strength 
}

void gpio_set_pins()
{
	*GPIO_PA_MODEH  = 0x55555555;	// Set pins A8-15 as output 
  	*GPIO_PC_MODEL  = 0x33333333;   // Set pins C0-7 as input 
  	*GPIO_PC_DOUT   = 0xFF; 		// Enable internal pull-up
}


/* Maybe move this to interrupt.c? 
   It uses the GPIO register so it
   might make sense to keep it here */
void gpio_enable_interrupt()
{
	*GPIO_EXTIPSELL = 0x22222222;
  	*GPIO_EXTIFALL  = 0xFF;  		// Interrupt on falling edge 
    //*GPIO_EXTIRISE = 0xFF; 		// Interrupt on rising edge 
    *GPIO_IEN       = 0x00FF;		// Does what?
    *GPIO_IFC       = 0xFF;			// Does what? Set interrupt flag?
}














