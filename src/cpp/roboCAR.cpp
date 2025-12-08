#pragma region Includes

#include "roboCAR.hpp"

#pragma endregion

#pragma region GPIOPins

// Motor Control pins
constexpr int MOTOR1PIN1 = 1;
constexpr int MOTOR1PIN2 = 2;
constexpr int MOTOR2PIN1 = 3;
constexpr int MOTOR2PIN2 = 4;

// Ultrasound sensor pins
constexpr int TRIG      =  5;
constexpr int ECHO      =  6;

#pragma endregion

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
    gpio_init(MOTOR1PIN1); gpio_set_dir(MOTOR1PIN1, true);
    gpio_init(MOTOR1PIN2); gpio_set_dir(MOTOR1PIN2, true);
    gpio_init(MOTOR2PIN1); gpio_set_dir(MOTOR2PIN1, true);
    gpio_init(MOTOR2PIN2); gpio_set_dir(MOTOR2PIN2, true);

    // Ultrasound Sensor Pins
    gpio_init(TRIG);       gpio_set_dir(TRIG, true);
    gpio_init(ECHO);       gpio_set_dir(ECHO, false);

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
            gpio_put(MOTOR1PIN1, 1);
            gpio_put(MOTOR1PIN2, 0);
            gpio_put(MOTOR2PIN1, 1);
            gpio_put(MOTOR2PIN2, 0);
            break;
        case BACKWARD:
            gpio_put(MOTOR1PIN1, 0);
            gpio_put(MOTOR1PIN2, 1);
            gpio_put(MOTOR2PIN1, 0);
            gpio_put(MOTOR2PIN2, 1);
            break;
        case LEFTFORWARD:
            gpio_put(MOTOR1PIN1, 1);
            gpio_put(MOTOR1PIN2, 0);
            gpio_put(MOTOR2PIN1, 0);
            gpio_put(MOTOR2PIN2, 0);
            break;
        case RIGHTFORWARD:
            gpio_put(MOTOR1PIN1, 0);
            gpio_put(MOTOR1PIN2, 0);
            gpio_put(MOTOR2PIN1, 1);
            gpio_put(MOTOR2PIN2, 0);
            break;
        case RIGHTBACKWARD:
            gpio_put(MOTOR1PIN1, 0);
            gpio_put(MOTOR1PIN2, 0);
            gpio_put(MOTOR2PIN1, 0);
            gpio_put(MOTOR2PIN2, 1);
            break;
        case LEFTBACKWARD:
            gpio_put(MOTOR1PIN1, 0);
            gpio_put(MOTOR1PIN2, 1);
            gpio_put(MOTOR2PIN1, 0);
            gpio_put(MOTOR2PIN2, 1);
            break;
        case STOP:
            gpio_put(MOTOR1PIN1, 0);
            gpio_put(MOTOR1PIN2, 0);
            gpio_put(MOTOR2PIN1, 0);
            gpio_put(MOTOR2PIN2, 0);
            break;
    }
}
#pragma endregion