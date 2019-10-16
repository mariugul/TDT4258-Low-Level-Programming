#include "../inc/interrupt.h"
#include "../inc/dac.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/melodies.h"
#include "../inc/timer.h"
#include "../inc/tones.h"
#include <stdbool.h>
#include <stdint.h>

// PUT THESE DEFINES IN SEPERATE FILE
#define MAX_VOL 0xF
#define STD_VOL 0x9
#define LOW_VOL 0x4

int song_buff[100][2];
int *ptr = &song_buff[100][2];

void nvic_init() // Enable interrupts
{
    //*ISER0 |= 0x1802;
}

/*
 * TIMER1 interrupt handler 
 */
void __attribute__((interrupt)) TIMER1_IRQHandler()
{
    // pointer to buffer
    
    

    static int tone_selection = 0;
    static int count = 0;
    static int iterations = 0;

    if (iterations == ptr[tone_selection][1]) {
        tone_selection++;
        iterations = 0;
    }

    if (count >= ptr[tone_selection][0]) {
        count = 0;

        if (*ptr[tone_selection][0] == 0)
            timer_stop();
        else
            dac_square_wave(LOW_VOL);
    }

    count++;
    iterations++;
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