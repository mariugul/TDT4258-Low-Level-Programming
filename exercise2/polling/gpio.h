#ifndef __GPIO_H__		// HEADER GUARD
#define __GPIO_H__


void gpio_init();					// Initialize GPIO pins
void gpio_leds_on();				// Turn all leds on
void gpio_leds_off();				// Turn all leds off
void gpio_enable_clock();			// Enable the clock
void gpio_set_drive(uint8_t drive);	// Set the drive strength for leds
void gpio_set_pins();				// Set the input and outputs for GPIOs
void gpio_map_to_led();             // Maps the button values directly to the led register 
void gpio_enable_interrupt();		// Enable interrupts

#endif
