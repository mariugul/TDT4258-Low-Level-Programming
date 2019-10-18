#include "../inc/melodies.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/interrupt.h"
#include "../inc/timer.h"
#include <stdbool.h>
#include <stdint.h>


// Global variable
int *song_ptr = (int *)no_sound; // Pointing to the selected song

void melodies_init()
{
    // Play start up melody
    //melodies_play((int *)start_up_melody);
}

/** Select what melody to play */
void melodies_play(int *song)
{
    song_ptr = (int *)song; // Point to the selected song
    song_finish = false;
}

/** Calculate the duration of ONE beat */
int melodies_bpm(int bpm)
{
    int bpm_calc;

    // Entering the BPM, it returns the duration of one BEAT
    bpm_calc = 44164 * 60 / bpm;

    return bpm_calc;
}

/** Songs */
int no_sound[][2] = {
    {-1, -1}
};

int score_sound[][2] = {
    {C5, FOURTH},
    {G5, HALF},
    {-1, -1 }
};

int hit_sound[][2] = {
    {B5, FOURTH},
    {0, SIXTH},
    {B5, FOURTH},
    {-1, -1}
};

int end_game_sound[][2] = {
    {G3, HALF},
    {D4, FOURTH},
    {B3, HALF},
    {-1, -1}
};

int start_up_melody[][2] = {
    
    // Intro
    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    
   
    // Melody
    {A4, THIRD}, 
    {C4, THIRD},
    {E4, HALF},
    {F4, HALF},
    {G4, THIRD},
    {C4, THIRD},
    {E4, HALF},
    {F4, HALF},
    {D4, TWO},

        // Interlude
    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

        // Melody 
    {A4, THIRD}, 
    {C4, THIRD},
    {E4, HALF},
    {F4, HALF},
    {G4, THIRD},
    {C4, THIRD},
    {F4, HALF},
    {E4, HALF},
    {D4, TWO},

        // Interlude
    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},

    {E3, HALF}, 
    {F3, HALF},
    {G3, ONE },
    {C3, ONE},
    {0 , PAUSE},
    
    // End
    {A5, THIRD},
    {0, PAUSE},
    {A5, THIRD},
    {0, PAUSE},
    {G5, SIX},

    {D5, THIRD},
    {0, PAUSE},
    {D5, THIRD},
    {0, PAUSE},
    {G5, SIX},

    {0, PAUSE},

    {C5, THIRD},
    {0, PAUSE},
    {C5, THIRD},
    {0, PAUSE},

    {F5, THIRD},
    {E5, THIRD},
    {D5, SIX},
    
    {-1,-1}
};