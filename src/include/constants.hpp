#pragma once

#pragma region Includes

#include <cstdint>

#include "pico/stdlib.h"

#pragma endregion


// Constants for roboCAR project
#pragma region Motor Pins

namespace MotorPins
{
    //
    constexpr auto m_1A = 2;
    constexpr auto m_1B = 3;
    constexpr auto m_2A = 4;
    constexpr auto m_2B = 5;
}
namespace UntrasoundPins
{
    //
    constexpr auto TRIG = 6;
    constexpr auto ECHO = 7;
}