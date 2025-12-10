#pragma once

#pragma region Includes

#include <iostream>

#include "pico/stdlib.h"

#include "constants.hpp"
#include "drivetrain.hpp"
#include "ultrasound.hpp"

#pragma endregion

class roboCAR 
{
    public:
        explicit roboCAR();
        void Periodic(roboCAR &roboCAR);
        void Initialize();
        // more stuff
    private:
        // Private members
        bool UltrasoundTurnActive = false;
};