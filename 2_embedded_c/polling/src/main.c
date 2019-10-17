#include "../inc/dac.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/interrupt.h"
#include "../inc/low_energy.h"
#include "../inc/timer.h"
#include "../inc/tones.h"
#include <stdbool.h>
#include <stdint.h>

int current_sound[20];
int current_time[20];

void vector_copy(int n)
{
    if (n == 0) {
        for (int i = 0; i < sizeof(point_scored_sound); i++) {
            current_sound[i] = point_scored_sound[i];
            current_time[i] = point_scored_time[i];
        }
    } else if (n == 1) {
        for (int i = 0; i < sizeof(end_game_sound); i++) {
            current_sound[i] = end_game_sound[i];
            current_time[i] = end_game_time[i];
        }
    }
}

bool track_buttons()
{
    if ((*GPIO_PC_DIN & BUTTON1) == 0) {
        vector_copy(0);
        return true;
    } else if ((*GPIO_PC_DIN & BUTTON2) == 0) {
        vector_copy(1);
        return true;
    }
    return false;
}

int main(void)
{
    // Variables
    bool making_sound = false; //Becomes true when a button is pressed
    int diference; //Clocks happened since the last check
    int reg_new_value;
    int i; //Index pointing at a note of a soundTrack
    int clock_counter_time;
    int clock_counter_fre;
    int reg_old_val;

    // Initialize
    gpio_init();
    dac_init();
    timer_init();

    //Loop:
    while (true) {
        if (track_buttons()) {
            i = 0;
            clock_counter_time = 0;
            clock_counter_fre = 0;
            reg_old_val = *TIMER1_CNT;
            making_sound = true;
        }
        while (making_sound) {
            //Update clock_counter value
            reg_new_value = *TIMER1_CNT;
            diference = reg_new_value - reg_old_val;
            reg_old_val = reg_new_value;
            if (diference < 0)
                diference += 0xFFFF;

            clock_counter_time += diference;
            clock_counter_fre += diference;

            //Checking if we have to change the note to he next one
            if (clock_counter_time >= current_time[i] * 317) {
                i++;
                clock_counter_time = 0;
            }

            //Checking if we have to change wave
            int freq = PRESC / (2 * current_sound[i]); //Frequency of the sounding note
            int barrier = 14000000 / (freq * 2); //Clocks between one change and the nextone

            if (clock_counter_fre >= barrier) {
                clock_counter_fre = 0;
                if (current_time[i] == 0) {
                    making_sound = false;
                } else {
                    dac_square_wave(0x0F);
                }
            }
        }
    }
    return 0;
}
