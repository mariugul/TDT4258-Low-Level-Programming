#ifndef __MELODIES_H__ // HEADER GUARD
#define __MELODIES_H__

#include "tones.h"

// Global variable
extern int *song_ptr; // Pointing to the selected song

// Songs
extern int score_sound[][2];
extern int hit_sound[][2];
extern int end_game_sound[][2];
extern int start_up_melody[][2];

// Functions
void melodies_init();            // Play star tup melody
void melodies_select(int *song); // Select what melody to play
int melodies_bpm(int bpm);       //Calculate the duration of ONE beat

#endif