#include "roboCAR.hpp"

#pragma region Variables
// DriveState enum
enum DriveState 
{
    FORWARD,
    BACKWARD,
    LEFTFORWARD,
    RIGHTFORWARD,
    LEFTBACKWARD,
    RIGHTBACKWARD,
    STOP
};


// Function defs
void setMotor(DriveState);

#pragma endregion



int main()
{
    #pragma region Init

    // Init and set motor pins to output
    gpio_init(Motors::MOTOR1PIN1); gpio_set_dir(Motors::MOTOR1PIN1, true);
    gpio_init(Motors::MOTOR1PIN2); gpio_set_dir(Motors::MOTOR1PIN2, true);
    gpio_init(Motors::MOTOR2PIN1); gpio_set_dir(Motors::MOTOR2PIN1, true);
    gpio_init(Motors::MOTOR2PIN2); gpio_set_dir(Motors::MOTOR2PIN2, true);

    // Ultrasound Sensor Pins
    gpio_init(Sensors::ULTRASOUND_TRIG);       gpio_set_dir(Sensors::ULTRASOUND_TRIG, true);
    gpio_init(Sensors::ULTRASOUND_ECHO);       gpio_set_dir(Sensors::ULTRASOUND_ECHO, false);

    // init stdio
    stdio_init_all();

    #pragma endregion

    while (true) 
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}


#pragma region DriveTrain
void setMotor(DriveState state) 
{
    switch (state) 
    {
        case FORWARD:
            gpio_put(Motors::MOTOR1PIN1, 1);
            gpio_put(Motors::MOTOR1PIN2, 0);
            gpio_put(Motors::MOTOR2PIN1, 1);
            gpio_put(Motors::MOTOR2PIN2, 0);
            break;
        case BACKWARD:
            gpio_put(Motors::MOTOR1PIN1, 0);
            gpio_put(Motors::MOTOR1PIN2, 1);
            gpio_put(Motors::MOTOR2PIN1, 0);
            gpio_put(Motors::MOTOR2PIN2, 1);
            break;
        case LEFTFORWARD:
            gpio_put(Motors::MOTOR1PIN1, 1);
            gpio_put(Motors::MOTOR1PIN2, 0);
            gpio_put(Motors::MOTOR2PIN1, 0);
            gpio_put(Motors::MOTOR2PIN2, 0);
            break;
        case RIGHTFORWARD:
            gpio_put(Motors::MOTOR1PIN1, 0);
            gpio_put(Motors::MOTOR1PIN2, 0);
            gpio_put(Motors::MOTOR2PIN1, 1);
            gpio_put(Motors::MOTOR2PIN2, 0);
            break;
        case RIGHTBACKWARD:
            gpio_put(Motors::MOTOR1PIN1, 0);
            gpio_put(Motors::MOTOR1PIN2, 0);
            gpio_put(Motors::MOTOR2PIN1, 0);
            gpio_put(Motors::MOTOR2PIN2, 1);
            break;
        case LEFTBACKWARD:
            gpio_put(Motors::MOTOR1PIN1, 0);
            gpio_put(Motors::MOTOR1PIN2, 1);
            gpio_put(Motors::MOTOR2PIN1, 0);
            gpio_put(Motors::MOTOR2PIN2, 1);
            break;
        case STOP:
            gpio_put(Motors::MOTOR1PIN1, 0);
            gpio_put(Motors::MOTOR1PIN2, 0);
            gpio_put(Motors::MOTOR2PIN1, 0);
            gpio_put(Motors::MOTOR2PIN2, 0);
            break;
    }
}
#pragma endregion