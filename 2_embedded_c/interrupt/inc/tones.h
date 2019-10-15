#ifndef __TONES_H__ // HEADER GUARD
#define __TONES_H__

#define PRESC 44164 // The prescaled divider used (14MHz/13672 = 1024)

// These are not correct

/*
#define TONE_A2 PRESC / 440
#define TONE_B2 PRESC / 494
#define TONE_C3 PRESC / 523
#define TONE_D3 PRESC / 587
#define TONE_E3 PRESC / 659
#define TONE_F3 PRESC / 698
#define TONE_G3 PRESC / 784

#define TONE_A3 PRESC / 440
#define TONE_B3 PRESC / 494
#define TONE_C4 PRESC / 523
#define TONE_D4 PRESC / 587
#define TONE_E4 PRESC / 659
#define TONE_F4 PRESC / 698
#define TONE_G4 PRESC / 784
*/

// These are correct
#define TONE_A4 PRESC / 440 / 2
#define TONE_A4S PRESC / 466 / 2
#define TONE_B4 PRESC / 494 / 2
#define TONE_C5 PRESC / 523 / 2
#define TONE_C5S PRESC / 554 / 2
#define TONE_D5 PRESC / 587 / 2
#define TONE_D5S PRESC / 622 / 2
#define TONE_E5 PRESC / 659 / 2
#define TONE_F5 PRESC / 698 / 2
#define TONE_F5S PRESC / 740 / 2
#define TONE_G5 PRESC / 784 / 2
#define TONE_G5S PRESC / 831 / 2

int tone[] = {TONE_C5, TONE_G5,  0};
int time[] = {44164/10, 44164/5};

#endif
