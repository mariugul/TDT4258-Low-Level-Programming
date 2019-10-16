#include "../inc/meldodies.h"
#include "../inc/timer.h"

int *song_ptr; // Extern pointer for song selection

/** Select what melody to play*/
void melodies_select(int *song)
{
    song_ptr = song; // Point to point to the selected song
    timer_start(); // Start the timer so the song plays
}

/** Calculate the duration of ONE beat*/
int melodies_bpm(int bpm)
{   
    int bpm_calc;

    // entering the BPM it returns the duration of one BEAT
    bpm_calc= 44164*60/bpm;

    return bpm_calc;
}


