#include "sound_sensor.h"
#include "hardware/adc.h"

// Initialize the sound sensor
void sound_sensor_init(uint sensor_pin)
{
    adc_init();                // Initialize the ADC module
    adc_gpio_init(sensor_pin); // Initialize the GPIO pin for ADC
}

// Read the sound level from the sensor
uint16_t sound_sensor_read_level(uint sensor_pin)
{
    adc_select_input(sensor_pin - 26); // Map GPIO pin to ADC input (GPIO 26 = ADC0, 27 = ADC1, etc.)
    return adc_read();                 // Return the 12-bit ADC value (0-4095)
}
