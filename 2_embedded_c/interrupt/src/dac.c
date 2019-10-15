#include <stdbool.h>
#include "../inc/efm32gg.h"
#include "../inc/dac.h"

void dac_init()
{
  *CMU_HFPERCLKEN0 |= 0x20000;
  *DAC0_CTRL       |= 0x50010;
  *DAC0_CH0CTRL    |= 0x01;
  *DAC0_CH1CTRL    |= 0x01;
}

void dac_square_wave(uint8_t volume)
{
    static bool state = true;

    if (state){
        *DAC0_CH0DATA = volume;
        *DAC0_CH1DATA = volume;
        state = false;
    }
    else{
        *DAC0_CH0DATA = 0x00;
        *DAC0_CH1DATA = 0x00;
        state = true;
    }
}

void dac_map_to_sound()
{
    *DAC0_CH0DATA = *GPIO_PC_DIN;   // Map button values to DAC
    *DAC0_CH1DATA = *GPIO_PC_DIN;
}