#pragma once

#pragma region Includes

#include <iostream>

#include "pico/stdlib.h"

#include "constants.hpp"

#pragma endregion

class Ultrasound 
{
    public:
        explicit Ultrasound();
        float GetDistance();
    private:
        // Private members
};
