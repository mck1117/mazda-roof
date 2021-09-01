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

    palSetPadMode(GPIOD, 7, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOG, 10, PAL_MODE_OUTPUT_PUSHPULL);

    while (1)
    {
        auto lastSense = SwitchState::Indeterminite;
        auto currentSense = SwitchState::Indeterminite;

        do
        {
            chThdSleepMilliseconds(100);

            lastSense = currentSense;
            currentSense = SenseSwitch();
        } while (lastSense != currentSense);

        switch (currentSense)
        {
            case SwitchState::Open:
                palWritePad(GPIOD,  7, 1);
                palWritePad(GPIOG, 10, 0);
                chThdSleepMilliseconds(17000);
                break;
            case SwitchState::Close:
                palWritePad(GPIOD,  7, 0);
                palWritePad(GPIOG, 10, 1);
                chThdSleepMilliseconds(17000);
                break;
            default:
                palWritePad(GPIOD,  7, 0);
                palWritePad(GPIOG, 10, 0);
        }
    }

    return 0;
}
