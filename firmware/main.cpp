#include "ch.hpp"
#include "hal.h"

#include "switch_sense.h"

void InitCan();

int main()
{
    halInit();
    chibios_rt::System::init();

    InitCan();
    InitSwitchSense();

    while (1);

    return 0;
}
