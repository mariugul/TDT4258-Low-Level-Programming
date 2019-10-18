#include "../inc/interrupt.h"
#include "../inc/dac.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/melodies.h"
#include "../inc/timer.h"
#include "../inc/tones.h"
#include <stdbool.h>
#include <stdint.h>

// PUT THESE DEFINES IN SEPERATE FILE (maybe)
#define MAX_VOL 0xF
#define STD_VOL 0x9
#define LOW_VOL 0x4

// Button states
#define BUTTON1 (1 << 0)
#define BUTTON2 (1 << 1)
#define BUTTON3 (1 << 2)
#define BUTTON4 (1 << 3)
#define BUTTON5 (1 << 4)
#define BUTTON6 (1 << 5)
#define BUTTON7 (1 << 6)
#define BUTTON8 (1 << 7)

// variables for timer interrupt handler
bool song_finish = false;

void interrupt_init() // Enable interrupts
{
    //*ISER0 |= 0x802;
}

/*
 * TIMER1 interrupt handler 
 */
void __attribute__((interrupt)) TIMER1_IRQHandler()
{
    // Counter variables
    static int tone_selection = 0;
    static int tone_length = 1;
    static int count = 0;
    static int iterations = 0;

    // Increment
    if (!song_finish) {
        count++;
        iterations++;
    }

    // Sets the length of the tones
    if (iterations >= (*(song_ptr + tone_length)) && !song_finish) {
        tone_length += 2;
        tone_selection += 2;
        iterations = 0;
    }

    // Sets the tones
    if (count >= (*(song_ptr + tone_selection)) && !song_finish) {
        count = 0;

        // Generate soundwave
        if (*(song_ptr + tone_length) != -1) {
            dac_square_wave(STD_VOL);
        } else {
            // Reset pointing location
            tone_selection = 0;
            tone_length = 1;
            count = 0;
            iterations = 0;
            song_finish = true;
        }
    }

    TIF_clear(); // Clear timer interrupt flag
}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__((interrupt)) GPIO_EVEN_IRQHandler()
{
    gpio_handler();
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__((interrupt)) GPIO_ODD_IRQHandler()
{
    gpio_handler();
}

/*
 * LOW ENERGY TIMER interrupt handler
 */
void __attribute__((interrupt)) LETIMER0_IRQHandler()
{

    gpio_leds_on();
    LEIF_clear();
}

/* 
 * Handles the GPIO interrupt calls
 */
void gpio_handler()
{
    gpio_map_to_led();

    // Button 1
    if ((*GPIO_PC_DIN & BUTTON1) == 0)
        melodies_play((int*)score_sound);

    // Button 2
    else if ((*GPIO_PC_DIN & BUTTON2) == 0)
        melodies_play((int*)end_game_sound);

    // Button 3
    else if ((*GPIO_PC_DIN & BUTTON3) == 0)
        melodies_play((int*)hit_sound);

    // Button 4
    else if ((*GPIO_PC_DIN & BUTTON4) == 0)
        melodies_play((int*)score_sound);

    // Button 5
    else if ((*GPIO_PC_DIN & BUTTON5) == 0)
        melodies_play((int*)score_sound);

    // Button 6
    else if ((*GPIO_PC_DIN & BUTTON6) == 0)
        melodies_play((int*)score_sound);

    // Button 7
    else if ((*GPIO_PC_DIN & BUTTON7) == 0)
        melodies_play((int*)score_sound);

    // Button 8
    else if ((*GPIO_PC_DIN & BUTTON8) == 0)
        melodies_play((int*)start_up_melody);

    GIF_clear(); // Clear interrupt flag
}

/* 
 * Clear Timer interrupt flag
*/
void TIF_clear()
{
    *TIMER1_IFC = 0x1; // Clear the interrupt flag
}

/*
 * Clear GPIO interrupt flag
 */
void GIF_clear()
{
    *GPIO_IFC = 0xff;
}

/*
 * Clear Low Energy Interrupt Flag
 */
void LEIF_clear()
{
    *LETIMER0_IFC = 0x8;
}