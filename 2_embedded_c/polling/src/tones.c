#include "../inc/tones.h"

// Size of arrays

int point_scored_sound_size = 3;
int end_game_sound_size = 4;
int end_game2_sound_size = 7;
int track1_sound_size = 24;

// Score melody
int point_scored_sound[] = {
    TONE_C5,
    TONE_G5,
    0
};

int point_scored_time[] = {
    44164 / 10,
    44164 / 7,
    0
};

// End game sound
int end_game_sound[] = {
    TONE_G3,
    TONE_D4,
    TONE_B3,
    0
};
int end_game_time[] = {
    44164 / 10,
    44164 / 10,
    44164 / 5,
    0
};

// End game sound 2
int end_game2_sound[] = {
    TONE_C5,
    TONE_F5,
    TONE_C5,
    TONE_A4,
    TONE_C5,
    TONE_F4,
    0
};
int end_game2_time[] = {
    44164 / 10,
    44164 / 10,
    44164 / 10,
    44164 / 10,
    44164 / 10,
    44164 / 7,
    0
};

// Track 1
int track1_sound[] = {
    TONE_C5S,
    TONE_E5,
    TONE_F5S,
    TONE_E5,
    TONE_F5S,
    TONE_G5S,
    TONE_C5S,
    TONE_E5,
    TONE_F5S,
    TONE_A5,
    TONE_G5S,
    TONE_F5S,
    TONE_C5S,
    TONE_E5,
    TONE_F5S,
    TONE_E5,
    TONE_F5S,
    TONE_G5S,
    TONE_C5S,
    TONE_E5,
    TONE_F5S,
    TONE_C6S,
    TONE_C6,
    0
};
int track1_time[] = {
    44164 / 4,
    44164 / 4,
    44164 / 4,
    44164 / 7,
    44164 / 7,
    44164 / 7,
    44164 / 4,
    44164 / 4,
    44164 / 4,
    44164 / 7,
    44164 / 7,
    44164 / 7,
    44164 / 4,
    44164 / 4,
    44164 / 4,
    44164 / 7,
    44164 / 7,
    44164 / 7,
    44164 / 4,
    44164 / 4,
    44164 / 4,
    44164 / 7,
    44164 / 7,
    0
};
