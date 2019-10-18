#ifndef __TONES_H__ // HEADER GUARD
#define __TONES_H__

#include <stdio.h>

#define PRESC 44164 // The prescaled divider used (14MHz/13672 = 1024)

// Tones - The "S" means sharp "#". Ex: A4S represents "A4#"
#define TONE_A4 PRESC / 440 / 2
#define TONE_A4S PRESC / 466 / 2
#define TONE_A5 PRESC / 880 / 2
#define TONE_B4 PRESC / 494 / 2
#define TONE_C5 PRESC / 523 / 2
#define TONE_C5S PRESC / 554 / 2
#define TONE_C6 PRESC / 1046 / 2
#define TONE_C6S PRESC / 1109 / 2
#define TONE_D5 PRESC / 587 / 2
#define TONE_D5S PRESC / 622 / 2
#define TONE_E5 PRESC / 659 / 2
#define TONE_F4 PRESC / 349 / 2
#define TONE_F5 PRESC / 698 / 2
#define TONE_F5S PRESC / 740 / 2
#define TONE_G5 PRESC / 784 / 2
#define TONE_G5S PRESC / 831 / 2
#define TONE_G3 PRESC / 196 / 2
#define TONE_D4 PRESC / 294 / 2
#define TONE_B3 PRESC / 247 / 2

extern int point_scored_sound_size;
extern int end_game_sound_size;
extern int end_game2_sound_size;
extern int track1_sound_size;

extern int point_scored_sound[];
extern int point_scored_time[];

extern int end_game_sound[];
extern int end_game_time[];

extern int end_game2_sound[];
extern int end_game2_time[];

extern int track1_sound[];
extern int track1_time[];

#endif