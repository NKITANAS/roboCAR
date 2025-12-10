#include "drivetrain.hpp"

#pragma region Constructor

Drivetrain::Drivetrain() 
{
    // Constructor implementation
}

#pragma endregion



#pragma region Drive

/*
M# - Motor #
W  - Wheel

     FRONT
W - M1 _________ M2 - W
    |           |
    |           |
    W___________W
        BACK
*/

void Drivetrain::Drive(DrivetrainConstants::StateEnum State) 
{
    switch (State) 
    {
        case DrivetrainConstants::STOP:             // Stop all motors
            gpio_put(MotorPins::m_1A, 0);
            gpio_put(MotorPins::m_1B, 0);
            gpio_put(MotorPins::m_2A, 0);
            gpio_put(MotorPins::m_2B, 0);
            break;
        case DrivetrainConstants::FORWARD:         // Both motors forward
            gpio_put(MotorPins::m_1A, 1);
            gpio_put(MotorPins::m_1B, 0);
            gpio_put(MotorPins::m_2A, 1);
            gpio_put(MotorPins::m_2B, 0);            
            break;
        case DrivetrainConstants::BACKWARD:        // Both motors backward
            gpio_put(MotorPins::m_1A, 0);
            gpio_put(MotorPins::m_1B, 1);
            gpio_put(MotorPins::m_2A, 0);
            gpio_put(MotorPins::m_2B, 1);
            break;
        case DrivetrainConstants::LEFTFORWARD:     // Use the left motor only to go turn forward
            gpio_put(MotorPins::m_1A, 1);
            gpio_put(MotorPins::m_1B, 0);
            gpio_put(MotorPins::m_2A, 0);
            gpio_put(MotorPins::m_2B, 0);
            break;
        case DrivetrainConstants::LEFTBACKWARD:    // Use the left motor only to go backward
            gpio_put(MotorPins::m_1A, 0);
            gpio_put(MotorPins::m_1B, 1);
            gpio_put(MotorPins::m_2A, 0);
            gpio_put(MotorPins::m_2B, 0);
            break;
        case DrivetrainConstants::RIGHTFORWARD:    // Use the right motor only to go turn forward
            gpio_put(MotorPins::m_1A, 0);
            gpio_put(MotorPins::m_1B, 0);
            gpio_put(MotorPins::m_2A, 1);
            gpio_put(MotorPins::m_2B, 0);            
            break;
        case DrivetrainConstants::RIGHTBACKWARD:   // Use the right motor only to go turn backward
            gpio_put(MotorPins::m_1A, 0);
            gpio_put(MotorPins::m_1B, 0);
            gpio_put(MotorPins::m_2A, 0);
            gpio_put(MotorPins::m_2B, 1);           
            break;
        case DrivetrainConstants::DEFAULT:         // Do nothing; Continue whatever was happening
            break;
        default:
            gpio_put(MotorPins::m_1A, 0);
            gpio_put(MotorPins::m_1B, 0);
            gpio_put(MotorPins::m_2A, 0);
            gpio_put(MotorPins::m_2B, 0);            
            break;
    }
}

#pragma endregion

