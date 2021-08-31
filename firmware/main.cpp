#include "ch.hpp"
#include "hal.h"

int main()
{
    halInit();
    chibios_rt::System::init();



    while (1);

    return 0;
}
