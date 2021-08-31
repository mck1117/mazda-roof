#include "ch.hpp"
#include "hal.h"

void initCan();

int main()
{
    halInit();
    chibios_rt::System::init();

    initCan();

    while (1);

    return 0;
}
