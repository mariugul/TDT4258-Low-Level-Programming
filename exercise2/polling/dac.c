#include <stdint.h>
#include <stdbool.h>
#include "efm32gg.h"
#include "dac.h"

void dac_init()
{
  *CMU_HFPERCLKEN0 |= 0x20000;
  *DAC0_CTRL       |= 0x50010;
  *DAC0_CH0CTRL    |= 0x01;
  *DAC0_CH1CTRL    |= 0x01;
}
