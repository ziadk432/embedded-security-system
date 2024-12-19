#include "button.h"
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Function to initialize the button (set the pin as input)
void Button_Init(void)
{
    // Initialize the GPIO pin as input
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN); // Set GPIO pin as input
    gpio_pull_up(BUTTON_PIN);          // Enable internal pull-up resistor (active low)
}

// Function to read the button state
uint8_t Button_Read(void)
{
    // Read the button state (0 = pressed, 1 = released)
    if (gpio_get(BUTTON_PIN) == 0)
    {
        return BUTTON_PRESSED;
    }
    else
    {
        return BUTTON_RELEASED;
    }
}

// Function to implement simple debouncing (delay method)
void Button_Debounce(void)
{
    // A simple delay to debounce the button
    sleep_ms(20);
}
