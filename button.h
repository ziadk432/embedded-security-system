#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h"

// Define the GPIO pin for the button
#define BUTTON_PIN 13

#define BUTTON_PRESSED 0  // Logic level for pressed state (active low)
#define BUTTON_RELEASED 1 // Logic level for released state

// Function prototypes
void Button_Init(void);
uint8_t Button_Read(void);
void Button_Debounce(void);

#endif // BUTTON_H
