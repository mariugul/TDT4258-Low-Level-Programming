#ifndef __GPIO_H__		// HEADER GUARD
#define __GPIO_H__


void gpio_init();					// Initialize GPIO pins
void gpio_leds_on();				// Turn all leds on
void gpio_leds_off();				// Turn all leds off
void gpio_leds_toggle();            // Toggle LEDs
void gpio_enable_clock();			// Enable the clock
void gpio_set_drive(uint8_t drive);	// Set the drive strength for leds
void gpio_set_pins();				// Set the input and outputs for GPIOs
void gpio_map_to_led();             // Maps the button values directly to the led register 
void gpio_enable_interrupt();		// Enable interrupts
//void set_bit(uint32_t *register, uint8_t bit);
//void clear_but(uint32_t *register, uint8_t bit);

#define mask1 0x01
#define button1()(*GPIO_PC_DIN & mask1 == 0)

if(button1)
    sound1;
if(button2)
    sound2;

#endif
