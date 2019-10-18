#ifndef __TONES_H__ // HEADER GUARD
#define __TONES_H__

#define ONESEC 44164/4 // One second worth of counts in the timer
#define BPM 172

// Bars
#define PAUSE  ONESEC/64
#define SIXTH  ONESEC/16
#define EIGHTH ONESEC/8
#define FOURTH ONESEC/4
#define HALF   ONESEC/2
#define ONE    ONESEC
#define TWO    ONESEC*2
#define THIRD  ONESEC*3
#define FOUR   ONESEC*4
#define SIX    ONESEC*6
#define EIGHT  ONESEC*8

// Tones - The "S" means sharp "#". Ex: CS4 represents "C#4"
#define PRESC 44164/2 // The prescaled divider used (14MHz/13672 = 1024)
                      // Divided by 2 because the frequency making function is toggling only half the time.

// Third harmonic
#define C3  PRESC/131
#define CS3 PRESC/139
#define D3  PRESC/147
#define DS3 PRESC/156
#define E3  PRESC/165
#define F3  PRESC/175
#define FS3 PRESC/185
#define G3  PRESC/196
#define GS3 PRESC/208
#define A3  PRESC/220
#define AS3 PRESC/233
#define B3  PRESC/247

// Fourth harmonic
#define C4  PRESC / 262
#define CS4 PRESC / 277
#define D4  PRESC / 294
#define DS4 PRESC / 311
#define E4  PRESC / 330
#define F4  PRESC / 349
#define FS4 PRESC / 370
#define G4  PRESC / 392
#define GS4 PRESC / 415
#define A4  PRESC / 440 
#define AS4 PRESC / 466 
#define B4  PRESC / 494 

// Fifth harmonic
#define C5  PRESC / 523 
#define CS5 PRESC / 554 
#define D5  PRESC / 587 
#define DS5 PRESC / 622 
#define E5  PRESC / 659 
#define F5  PRESC / 698 
#define FS5 PRESC / 740 
#define G5  PRESC / 784 
#define GS5 PRESC / 831 
#define A5  PRESC / 880 
#define AS5 PRESC / 932
#define B5  PRESC / 988

#endif
