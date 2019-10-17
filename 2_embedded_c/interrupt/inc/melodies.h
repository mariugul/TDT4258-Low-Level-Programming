#ifndef __MELODIES_H__ // HEADER GUARD
#define __MELODIES_H__

#include "tones.h"

// Global variable
extern int *song_ptr; // Pointing to the selected song

// Songs
extern int score_sound[3][2];
extern int hit_sound[3][2];

// Functions
void melodies_init();            // Play star tup melody
void melodies_select(int *song); // Select what melody to play
int melodies_bpm(int bpm);       //Calculate the duration of ONE beat
int *melodies_song_ptr();        // Return the song pointer

// Song pointers
extern int *pointers[2];

#endif