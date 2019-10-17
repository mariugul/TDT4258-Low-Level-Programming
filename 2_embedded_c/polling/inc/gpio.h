#ifndef __GPIO_H__		// HEADER GUARD
#define __GPIO_H__

#define BUTTON1 (1<<0)
#define BUTTON2 (1<<1)
#define BUTTON3 (1<<2)
#define BUTTON4 (1<<3)
#define BUTTON5 (1<<4)
#define BUTTON6 (1<<5)
#define BUTTON7 (1<<6)
#define BUTTON8 (1<<7)

void gpio_init();					// Initialize GPIO pins
void gpio_leds_on();				// Turn all leds on
void gpio_leds_off();				// Turn all leds off
void gpio_leds_toggle();            // Toggle LEDs
void gpio_enable_clock();			// Enable the clock
void gpio_set_drive(uint8_t drive);	// Set the drive strength for leds
void gpio_set_pins();				// Set the input and outputs for GPIOs
void gpio_map_to_led();             // Maps the button values directly to the led register 
void gpio_enable_interrupt();		// Enable interrupts



#endif
