#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

#pragma region Includes

#include "roboCAR.hpp"
#include "constants.hpp"
#include "drivetrain.hpp"

#pragma endregion

#pragma region DrivetrainConstants



class Drivetrain
{
    public:
        enum DriveDir {
            FORWARD,
            BACKWARD,
            LEFTFORWARD,
            LEFTBACKWARD,
            RIGHTFORWARD,
            RIGHTBACKWARD,
            STOP
        };
       
        explicit Drivetrain();
        void     Drive(DriveDir State);

};

#endif