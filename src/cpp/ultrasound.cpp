#include "ultrasound.hpp"

#pragma region Constructor

Ultrasound::Ultrasound() {
    // Constructor implementation
}

#pragma endregion



#pragma region GetDistance

float Ultrasound::GetDistance() {
    gpio_put(UltrasoundPins::TRIG, false);
    sleep_us(2);
    gpio_put(UltrasoundPins::TRIG, true);
    sleep_us(10);
    gpio_put(UltrasoundPins::TRIG, false);

    // Pulse duration measurement
    while (gpio_get(UltrasoundPins::ECHO) == 0);
    float startTime = to_us_since_boot(get_absolute_time());
    while (gpio_get(UltrasoundPins::ECHO) == 1);
    float endTime = to_us_since_boot(get_absolute_time());
    float pulseDuration = endTime - startTime;
    float distance = (pulseDuration * UltrasoundConstants::SOUND_SPEED) / 2;              // Speed of sound is 343 m/s or 0.0343 cm/us
    return distance;
}

#pragma endregion