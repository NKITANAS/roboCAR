#pragma once


#pragma region Includes

#include <iostream>

#include "pico/stdlib.h"

#include "constants.hpp"

#pragma endregion


#pragma region Ultrasound Constants

namespace UltrasoundConstants
{
    constexpr float SOUND_SPEED = 0.0343; // cm/us
}

#pragma endregion


class Ultrasound 
{
    public:
        explicit Ultrasound();
        float GetDistance();
    private:
        // Private members
        
};
