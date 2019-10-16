#ifndef __MELODIES_H__ // HEADER GUARD
#define __MELODIES_H__

#include "tones.h"

extern int *song_ptr; // Pointing to the selected song


void melodies_select(); // Select what melody to play
int  melodies_bpm(int bpm); //Calculate the duration of ONE beat



/********** MELODIES ***********/

/* Scoring melody */    
int const b = 44164*60/120; // Choose the BPM of the song
int melodies_score[3][2] = {
    {TONE_C5, 1*b},
    {TONE_G5, 2*b},
    {0,0}
};       


#endif
