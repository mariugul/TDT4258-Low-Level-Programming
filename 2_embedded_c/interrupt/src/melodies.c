#include "../inc/melodies.h"
#include "../inc/efm32gg.h"
#include "../inc/interrupt.h"
#include "../inc/timer.h"
#include <stdbool.h>
#include <stdint.h>

// Global variable
*song_ptr; // Pointing to the selected song

void melodies_init()
{
    // Play start up melody
    melodies_play(hit_sound);
    //melodies_play(score_sound);
}

/** Select what melody to play */
void melodies_play(int* song)
{
    song_ptr = song; // Point to the selected song
    song_finish = false;
    //timer_start(); // Start the song
}

/** Calculate the duration of ONE beat */
int melodies_bpm(int bpm)
{
    int bpm_calc;

    // Entering the BPM, it returns the duration of one BEAT
    bpm_calc = 44164 * 60 / bpm;

    return bpm_calc;
}

/** Songs */
int score_sound[3][2] = {
    { TONE_C5, 44164 / 4 },
    { TONE_G5, 44164 },
    { 0, 0 }
};

int hit_sound[3][2] = {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 }
};
