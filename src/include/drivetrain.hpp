#pragma once

#pragma region Includes

#include "constants.hpp"
#include "pico.h"

#pragma endregion

namespace DrivetrainConstants
{
    //
    enum StateEnum
    {
        STOP,
        FORWARD,
        BACKWARD,
        LEFTFORWARD,
        LEFTBACKWARD,
        RIGHTFORWARD,
        RIGHTBACKWARD,
        DEFAULT
    };
}

class Drivetrain 
{
    public:
        explicit Drivetrain();
        void Drive(DrivetrainConstants::StateEnum State);
    private:
        // Private members
};