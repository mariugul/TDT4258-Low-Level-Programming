#include "low_energy.h"


void sleep()        // Go to deepsleep mode
{
    __asm__("wfi;");    
}
