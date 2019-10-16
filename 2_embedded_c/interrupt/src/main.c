#include "../inc/dac.h"
#include "../inc/efm32gg.h"
#include "../inc/gpio.h"
#include "../inc/interrupt.h"
#include "../inc/low_energy.h"
#include "../inc/timer.h"
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

    // PLAY START UP MELODY

    // Loop
    while (true) {
        sleep();       
    }

    return 0;
}
