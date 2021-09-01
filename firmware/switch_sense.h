#include "ch.hpp"

void InitSwitchSense();

enum class SwitchState
{
    Open,
    Close,
    None,
    Indeterminite,
};

SwitchState SenseSwitch();
