#include "dac.h"
#include "efm32gg.h"
#include "gpio.h"
#include "interrupt.h"
#include "low_energy.h"
#include "timer.h"
#include <stdbool.h>
#include <stdint.h>

int main(void)
{
    // Initialize
    gpio_init();
    dac_init();
    //nvic_init();
    timer_init();
    //low_energy_init();

    // Prototype

    // Loop
    while (true) {
        
    }

    return 0;
}
