#include "ch.hpp"

void InitSwitchSense();

enum class SwitchState
{
    Up,
    Down,
    None,
    Indeterminite,
};

SwitchState SenseSwitch();
