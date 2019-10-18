#include "../inc/gpio.h"
#include "../inc/efm32gg.h"
#include <stdbool.h>
#include <stdint.h>

// LED VALUES
#define LEDS_OFF 0xFF00
#define LEDS_ON 0x00FF

// DRIVE STRENGTHS
#define STANDARD_DRIVE 0x00
#define LOWEST_DRIVE 0x01
#define LOW_DRIVE 0x03
#define HIGH_DRIVE 0x02

/** Sets up the GPIO functionality */
void gpio_init()
{
    gpio_enable_clock();
    gpio_set_drive(STANDARD_DRIVE);
    gpio_set_pins();
    gpio_enable_interrupt();
    gpio_leds_off();
}

/** Turn leds on */
void gpio_leds_on()
{
    *GPIO_PA_DOUT = LEDS_ON; // Turns leds on
}

/** Turn leds off */
void gpio_leds_off()
{
    *GPIO_PA_DOUT = LEDS_OFF; // Turns leds off
}

void gpio_leds_toggle()
{
    *GPIO_PA_DOUT ^= (LEDS_ON << 8);
}

/** Enable the GPIO clock */
void gpio_enable_clock()
{
    *CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO; // Enable GPIO clock
}

/** Set the drive strength for the leds */
void gpio_set_drive(int drive)
{
    *GPIO_PA_CTRL = drive; // Set high drive strength
}

/** Set input and output pins */
void gpio_set_pins()
{
    *GPIO_PA_MODEH = 0x55555555; // Set pins A8-15 as output
    *GPIO_PC_MODEL = 0x33333333; // Set pins C0-7 as input
    *GPIO_PC_DOUT = 0xFF; // Enable internal pull-up
}

/** Maps the button values directly to the led register */
void gpio_map_to_led()
{
    *GPIO_PA_DOUT = (*GPIO_PC_DIN << 8); // Map button values to LED values
}

/* Maybe move this to interrupt.c? 
   It uses the GPIO register so it
   might make sense to keep it here */

/** Enable GPIO interrupts */
void gpio_enable_interrupt()
{
    *GPIO_EXTIPSELL = 0x22222222;
    *GPIO_EXTIFALL = 0xFF; // Interrupt on falling edge
    *GPIO_EXTIRISE = 0xFF; // Interrupt on rising edge
    *GPIO_IEN = 0x00FF; // Interrupt enable
    *GPIO_IFC = 0xFF; // Clear interrupt flag
}
