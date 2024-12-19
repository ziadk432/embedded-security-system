#ifndef SOUND_SENSOR_H
#define SOUND_SENSOR_H

#include "pico/stdlib.h"

// Define the default pin for the sound sensor
#ifndef SOUND_SENSOR_PIN
#define SOUND_SENSOR_PIN 26 // Default GPIO pin for the sound sensor (ADC pin)
#endif

// Function to initialize the sound sensor
void sound_sensor_init(uint sensor_pin);

// Function to read the sound level (ADC value)
uint16_t sound_sensor_read_level(uint sensor_pin);

#endif
