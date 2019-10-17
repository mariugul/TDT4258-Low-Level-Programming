#include "../inc/interrupt.h"
#include "../inc/dac.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/timer.h"
#include "../inc/tones.h"
#include <stdbool.h>
#include <stdint.h>
//#include "melodies.h"

// PUT THESE DEFINES IN SEPERATE FILE
#define MAX_VOL 0xF
#define STD_VOL 0x9
#define LOW_VOL 0x4

void nvic_init() // Enable interrupts
{
    //*ISER0 |= 0x1802;
}

/*
 * TIMER1 interrupt handler 
 */
void __attribute__((interrupt)) TIMER1_IRQHandler()
{
    //gpio_leds_toggle();
/*
    static int count = 0;
    static int i = 0;
    static int iterations = 0;

    if (iterations == time[i]) {
        i++;
        iterations = 0;
    }

    if (count >= tone[i]) {
        count = 0;
        if (tone[i] == 0)
            timer_stop();
        else
            dac_square_wave(LOW_VOL);
    }

    count++;
    iterations++;
    */
    interrupt_clear();

}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__((interrupt)) GPIO_EVEN_IRQHandler()
{
    gpio_map_to_led();
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__((interrupt)) GPIO_ODD_IRQHandler()
{
    gpio_map_to_led();
}

void interrupt_clear()
{
    *TIMER1_IFC = 0x1; // Clear the interrupt flag
}