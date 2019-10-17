#ifndef __TONES_H__ // HEADER GUARD
#define __TONES_H__

#define PRESC 44164 // The prescaled divider used (14MHz/13672 = 1024)


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

#endif
