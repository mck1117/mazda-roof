#include "ch.hpp"
#include "hal.h"

#include "switch_sense.h"
enum class RoofState
{
    Unknown,
    Open,
    Closed,
    Opening,
    Closing,
};

void InitCan();

int main()
{
    halInit();
    chibios_rt::System::init();

    InitCan();
    InitSwitchSense();

    palSetPadMode(GPIOD, 7, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOG, 10, PAL_MODE_OUTPUT_PUSHPULL);

    RoofState roofState = RoofState::Closed;

    while (1)
    {
        auto switchState = GetSwitch();

        // Determine current state

        // TODO: determine state by reading CAN messages instead
        switch (switchState) {
            case SwitchState::Open:
                roofState = RoofState::Opening;
                break;
            case SwitchState::Close:
                roofState = RoofState::Closing;
                break;
            default:
                // TODO: hack
                roofState = RoofState::Open;
                break;
        }

        // Set the output as a function of the current state
        switch (roofState) {
        case RoofState::Opening:
            SetSwitch(SwitchState::Open);
            break;
        case RoofState::Closing:
            SetSwitch(SwitchState::Close);
            break;
        default:
            SetSwitch(SwitchState::None);
            break;
        }
    }

    return 0;
}
