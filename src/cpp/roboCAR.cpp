#include "roboCAR.hpp"
// Ideally main and Robot are in different files, but for the sake of my sanity and god forbid having to modify a cmake.txt, 
// they're here)))) Enjoy the spaghetti future me!


#pragma region Class Declarations

Drivetrain RobotDrive;
Ultrasound RobotUltrasound;

#pragma endregion


#pragma region Constructor
roboCAR::roboCAR() {
    // Constructor implementation
}
#pragma endregion


#pragma region Periodic

void roboCAR::Periodic(roboCAR &roboCAR) 
{
    float UltrasoundDistance = RobotUltrasound.GetDistance();
    // Assume the Ultrasound distance is in centimeters
    if (UltrasoundTurnActive) 
    {
        RobotDrive.Drive(DrivetrainConstants::BACKWARD);                // Turn left while obstacle is detected
        if (UltrasoundDistance > 40.0) {                               // If obstacle is cleared
            RobotDrive.Drive(DrivetrainConstants::LEFTBACKWARD);
            if (UltrasoundDistance > 100.0) {
                roboCAR.UltrasoundTurnActive = false;                   // Resume normal operation
            }
        }
    } 
    else if (UltrasoundDistance < 20.0) {     
        roboCAR.UltrasoundTurnActive = true;                            // If an obstacle is closer than 20 cm
        RobotDrive.Drive(DrivetrainConstants::STOP);
    } else {
        RobotDrive.Drive(DrivetrainConstants::FORWARD);
    }

}

#pragma endregion


#pragma region Initialize

void roboCAR::Initialize() 
{
    stdio_init_all();
    
    // Motor pins - init pin and set to output
    gpio_init(MotorPins::m_1A);      gpio_set_dir(MotorPins::m_1A, true);
    gpio_init(MotorPins::m_1B);      gpio_set_dir(MotorPins::m_1B, true);
    gpio_init(MotorPins::m_2A);      gpio_set_dir(MotorPins::m_2A, true);
    gpio_init(MotorPins::m_2B);      gpio_set_dir(MotorPins::m_2B, true);

    // Ultrasound sensor pins - set trig to out and echo to in
    gpio_init(UltrasoundPins::TRIG); gpio_set_dir(UltrasoundPins::TRIG, true);
    gpio_init(UltrasoundPins::ECHO); gpio_set_dir(UltrasoundPins::ECHO, false);
}

#pragma endregion


#pragma region MainLoop
int main() {
    roboCAR Robot;
    Robot.Initialize();
    while (true) {
        Robot.Periodic(Robot);
    }
    return 0;
}
#pragma endregion