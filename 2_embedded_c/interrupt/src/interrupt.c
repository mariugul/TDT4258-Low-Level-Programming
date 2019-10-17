#include "../inc/interrupt.h"
#include "../inc/dac.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/melodies.h" // To play the melodies in the interrupt handler
#include "../inc/timer.h"
#include "../inc/tones.h"
#include <stdbool.h>
#include <stdint.h>

// PUT THESE DEFINES IN SEPERATE FILE (maybe)
#define MAX_VOL 0xF
#define STD_VOL 0x9
#define LOW_VOL 0x4

// Button states
#define BUTTON1 (1<<0)
#define BUTTON2 (1<<1)
#define BUTTON3 (1<<2)
#define BUTTON4 (1<<3)
#define BUTTON5 (1<<4)
#define BUTTON6 (1<<5)
#define BUTTON7 (1<<6)
#define BUTTON8 (1<<7)

// variables for timer interrupt handler
bool song_finish = false;

void nvic_init() // Enable interrupts
{
    //*ISER0 |= 0x1802;
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
    if(!song_finish)
    {
        count++;
        iterations++;
    }

    // Sets the length of the tones
    if (iterations >= (*(song_ptr + tone_length)) && !song_finish) { // > 44 000
        tone_length += 2;
        tone_selection += 2;
        iterations = 0;
    }

    // Sets the tones
    if (count >= (*(song_ptr + tone_selection)) && !song_finish) { // > 33
        count = 0;

        // TEST
        if (*(song_ptr + tone_length) != 0)
        {
            dac_square_wave(LOW_VOL);
            //gpio_leds_off();
        }
        else {
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
    // Counter variables
    static int tone_selection = 0;
    static int tone_length = 1;
    static int count = 0;
    static int iterations = 0;

    // Sets the length of the tones
    if (iterations >= (*(song_ptr + tone_length))) {
        tone_length += 2;
        tone_selection += 2;
        iterations = 0;
    }

    // Sets the tones
    if (count >= (*(song_ptr + tone_selection))) {
        count = 0;

        // TEST
        if ((*(song_ptr + tone_selection)) != 0)
            dac_square_wave(LOW_VOL);
        //--------------------------------------------
        /*
        if ((*(song_ptr + tone_selection)) == 0) // When the end of array is reached
            timer_stop(); // Song finished
        else
            dac_square_wave(LOW_VOL); // Produce square wave
        */
    }

    count++;
    iterations++;

    LEIF_clear();
}

/* 
 * Handles the GPIO interrupt calls
 */
void gpio_handler()
{
    //gpio_leds_toggle();

    //*PC_DIN      MASK
    //00000001 & 00000001

    // Button 1
    if ((*GPIO_PC_DIN & BUTTON1) == 0) 
    {
        gpio_leds_toggle();
        melodies_play(score_sound);
    }

    // Button 2
    else if ((*GPIO_PC_DIN & BUTTON2) == 0)
        melodies_play(score_sound);

    // Button 3
    else if ((*GPIO_PC_DIN & BUTTON3) == 0)
        melodies_play(score_sound);

    // Button 4
    else if ((*GPIO_PC_DIN & BUTTON4) == 0)
        melodies_play(score_sound);

    // Button 5
    else if ((*GPIO_PC_DIN & BUTTON5) == 0)
        melodies_play(score_sound);

    // Button 6
    else if ((*GPIO_PC_DIN & BUTTON6) == 0)
        melodies_play(score_sound);

    // Button 7
    else if ((*GPIO_PC_DIN & BUTTON7) == 0)
        melodies_play(score_sound);

    // Button 8
    else if ((*GPIO_PC_DIN & BUTTON8) == 0)
        melodies_play(score_sound);

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
    *LETIMER0_IFC = 1;
}