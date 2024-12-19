#include "pico/stdlib.h"
#include "pir_sensor.h"
#include "sound_sensor.h"
#include "servo.h"
#include "led.h"
#include "button.h"
#include "buzzer.h"

#define SOUND_SENSOR_PIN 26 // GPIO pin where the sound sensor is connected (ADC pin)
#define PIR_SENSOR_PIN 14   // GPIO pin where the PIR sensor is connected
#define LED_PIN 8           // GPIO pin for the LED
#define SERVO_PIN 15        // GPIO pin for the servo
#define BUTTON_PIN 13       // GPIO pin for the button
#define BUZZER_PIN 9        // GPIO pin for the buzzer

int main()
{
    // Initialize stdio for output via UART
    stdio_init_all();

    // Initialize the PIR motion sensor
    ir_sensor_init(PIR_SENSOR_PIN);

    // Initialize the sound sensor
    sound_sensor_init(SOUND_SENSOR_PIN);

    // Initialize the LED
    led_init(LED_PIN);

    // Initialize the chosen GPIO pin as PWM for the servo
    servo_init(SERVO_PIN, 400);

    // Initialize the buzzer
    buzzer_init(BUZZER_PIN);

    bool button_state = false; // Button state
    bool last_button_state = BUTTON_RELEASED;

    while (true)
    {
        // Read the sound level from the sensor
        uint16_t sound_level = sound_sensor_read_level(SOUND_SENSOR_PIN);

        // Read the state of the PIR sensor
        bool motion_detected = ir_sensor_detect(PIR_SENSOR_PIN);

        Button_Init(); // Initialize the button

        Button_Debounce(); // Debounce the button

        uint8_t current_button_state = Button_Read(); // Read the current button state

        // Check if the button was just pressed (transitional state)
        if (current_button_state == BUTTON_PRESSED && last_button_state == BUTTON_RELEASED)
        {
            // Toggle the LED state
            button_state = !button_state;
        }

        if (button_state == true)
        {
            close();
            if (motion_detected || sound_level > 124)
            {
                led_on(LED_PIN);                         // Turn ON the LED
                buzzer_play_tone(BUZZER_PIN, 5000, 100); // Play tone for 1 second
            }
            else
            {
                led_off(LED_PIN);        // Turn OFF the LED
                buzzer_stop(BUZZER_PIN); // Stop the buzzer
            }
        }
        else
        {
            open();
            led_off(LED_PIN);
            buzzer_stop(BUZZER_PIN); // Stop the buzzer
        }

        // Update the last button state for next loop iteration
        last_button_state = current_button_state;
    }

    return 0;
}
