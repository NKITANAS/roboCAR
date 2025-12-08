#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#pragma region MotorPins
namespace Motors
{
    // Motor Control pins
    constexpr int MOTOR1PIN1      = 1;
    constexpr int MOTOR1PIN2      = 2;
    constexpr int MOTOR2PIN1      = 3;
    constexpr int MOTOR2PIN2      = 4;
}
#pragma endregion

#pragma region SensorPins
namespace Sensors
{
    // Ultrasound Sensor Pins
    constexpr int ULTRASOUND_TRIG = 5;
    constexpr int ULTRASOUND_ECHO = 6;
}
#pragma endregion


#endif