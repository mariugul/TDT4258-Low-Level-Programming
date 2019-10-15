#ifndef __MELODIES_H__ // HEADER GUARD
#define __MELODIES_H__

#include "tones.h"


/* Start melody */
int start_melody[] = {TONE_G5, TONE_D5, TONE_A4, TONE_G5, TONE_D5, TONE_A4, 0};


/* Scoring melody */
int melodies_score[3][2] = {
    {TONE_C5, 44164/10},
    {TONE_G5, 44164/5},
    {0,0}
};       


// Keep track of current song with global buffer
//int song_buff[3][2] = {};
//song_buff = &melodies_score[0][0];


// START_MELODY
// SCORE
// HIT
// GAME OVER
// 

#endif
