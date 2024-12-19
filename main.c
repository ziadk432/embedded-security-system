// LED MAIN CODE

// #include <stdio.h>
// #include "pico/stdlib.h"

// int main()
// {

//     const uint led_pin = 8;

//     // Initialize LED pin
//     gpio_init(led_pin);
//     gpio_set_dir(led_pin, GPIO_OUT);

//     // Initialize chosen serial port
//     stdio_init_all();

//     // Loop forever
//     while (true)
//     {

//         // Blink LED
//         printf("Blinking!\r\n");
//         gpio_put(led_pin, true);
//         sleep_ms(1000);
//         gpio_put(led_pin, false);
//         sleep_ms(1000);
//     }
// }

// BUZZER MAIN CODE
// #include "pico/stdlib.h"
// #include "buzzer.h"

// #define BUZZER_PIN 8   // Change this to the GPIO pin you're using for the buzzer
// #define FREQUENCY 5000 // Frequency in Hz

// int main()
// {
//     stdio_init_all();
//     buzzer_init(BUZZER_PIN);

//     while (true)
//     {
//         buzzer_play_tone(BUZZER_PIN, FREQUENCY, 1000); // Play tone for 1 second
//         sleep_ms(1000);                                // Wait for 1 second
//     }

//     return 0;
// }

// SOUND SENSOR MAIN CODE
// #include "pico/stdlib.h"
// #include "sound_sensor.h"
// #include "led.h"

// #define SOUND_SENSOR_PIN 26 // GPIO pin where the sound sensor is connected (ADC pin)
// #define LED_PIN 8           // GPIO pin for the LED

// int main()
// {
//     // Initialize stdio for output via UART
//     stdio_init_all();

//     // Initialize the sound sensor
//     sound_sensor_init(SOUND_SENSOR_PIN);

//     // Initialize the LED
//     led_init(LED_PIN);

//     printf("Sound sensor and LED test initialized.\n");

//     while (true)
//     {
//         // Read the sound level from the sensor
//         uint16_t sound_level = sound_sensor_read_level(SOUND_SENSOR_PIN);

//         // Control the LED based on sound level threshold
//         if (sound_level > 124)
//         {                    // Example threshold
//             led_on(LED_PIN); // Turn ON the LED
//         }
//         else
//         {
//             led_off(LED_PIN); // Turn OFF the LED
//         }

//         // Delay for a short period
//         // sleep_ms(500);
//     }

//     return 0;
// }

// // PIR SENSOR MAIN CODE
// #include "pico/stdlib.h"
// #include "pir_sensor.h"
// #include "led.h"

// #define PIR_SENSOR_PIN 26 // GPIO pin where the PIR sensor is connected
// #define LED_PIN 8         // GPIO pin for the LED

// int main()
// {
//     // Initialize stdio for output via UART
//     stdio_init_all();

//     // Initialize the PIR motion sensor
//     ir_sensor_init(PIR_SENSOR_PIN);

//     // Initialize the LED
//     led_init(LED_PIN);

//     printf("PIR motion sensor and LED test initialized.\n");

//     while (true)
//     {
//         // Read the state of the PIR sensor
//         bool motion_detected = ir_sensor_detect(PIR_SENSOR_PIN);

//         // Control the LED based on motion detection
//         if (motion_detected)
//         {
//             printf("Motion detected! Turning ON LED.\n");
//             led_on(LED_PIN); // Turn ON the LED
//         }
//         else
//         {
//             printf("No motion detected. Turning OFF LED.\n");
//             led_off(LED_PIN); // Turn OFF the LED
//         }

//         // Delay for a short period to avoid rapid toggling
//         sleep_ms(1000);
//     }

//     return 0;
// }

// SERVO MOTOR MAIN CODE

// #include "pico/stdlib.h"
// #include "servo.h"

// // Define the GPIO pin for the servo (adjust to your setup)
// #define SERVO_PIN 15

// int main()
// {
//     // Initialize the chosen GPIO pin as PWM for the servo
//     servo_init(SERVO_PIN, 400); // Set initial position to 400ms (closed position)

//     while (true)
//     {
//         // Sweep the servo back and forth
//         sweep();
//         sleep_ms(20); // Pause for 20 milliseconds to create smooth movement

//         // Uncomment the following lines to test open/close functionality
//         // open();  // Set the servo to open position (2400ms)
//         // sleep_ms(1000);  // Wait for 1 second

//         // close();  // Set the servo to close position (400ms)
//         // sleep_ms(1000);  // Wait for 1 second
//     }
// }

// RFID SENSOR MAIN CODE
// #include "pico/stdlib.h"
// #include "rfid_rc522.h"
// #include "led.h"

// #define LED_PIN 8 // GPIO pin for the LED

// int main()
// {
//     // Initialize stdio for output via UART
//     stdio_init_all();

//     // Initialize the RC522 module
//     rfid_rc522_init();

//     // Initialize the LED pin
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);

//     while (1)
//     {
//         uint8_t uid[MAX_UID_LENGTH];
//         size_t uid_length;

//         // Check if an RFID tag is detected
//         if (rfid_rc522_read_card(uid, &uid_length))
//         {
//             // Turn on the LED
//             led_on(LED_PIN);
//         }
//         else
//         {
//             // Turn off the LED
//             led_off(LED_PIN);
//         }

//         // Small delay to avoid overwhelming the CPU
//         sleep_ms(100);
//     }

//     return 0;
// }

// #include "pico/stdlib.h"

// #define LED_PIN 8    // GPIO pin for the LED
// #define BUTTON_PIN 9 // GPIO pin for the button

// int main()
// {
//     // Initialize stdio for output via UART
//     stdio_init_all();

//     // Initialize the LED pin
//     gpio_init(LED_PIN);
//     gpio_set_dir(LED_PIN, GPIO_OUT);

//     // Initialize the button pin
//     gpio_init(BUTTON_PIN);
//     gpio_set_dir(BUTTON_PIN, GPIO_IN);
//     gpio_pull_up(BUTTON_PIN); // Enable internal pull-up resistor

//     bool led_state = false;      // Initial state of the LED
//     bool button_pressed = false; // Button pressed state

//     while (true)
//     {
//         // Read the state of the button
//         bool current_button_state = !gpio_get(BUTTON_PIN); // Button is active low

//         // Check if the button is pressed
//         if (current_button_state && !button_pressed)
//         {
//             // Toggle the LED state
//             led_state = !led_state;
//             gpio_put(LED_PIN, led_state); // Update the LED state

//             // Print the LED state to the console
//             if (led_state)
//             {
//                 printf("Button pressed! Turning ON LED.\n");
//             }
//             else
//             {
//                 printf("Button pressed! Turning OFF LED.\n");
//             }

//             // Update the button pressed state
//             button_pressed = true;
//         }
//         else if (!current_button_state)
//         {
//             // Reset the button pressed state when the button is released
//             button_pressed = false;
//         }

//         // Delay for a short period to debounce the button
//         sleep_ms(50);
//     }

//     return 0;
// }

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
bool led_state = false;

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

    // Initialize the button
    // button_init(BUTTON_PIN);

    // Initialize the buzzer
    buzzer_init(BUZZER_PIN);

    bool led_state = false;    // Initial state of the LED
    bool button_state = false; // Button state
    bool servo_open = false;   // Servo state
    bool last_button_state = BUTTON_RELEASED;

    while (true)
    {
        // Read the sound level from the sensor
        uint16_t sound_level = sound_sensor_read_level(SOUND_SENSOR_PIN);

        // Read the state of the PIR sensor
        bool motion_detected = ir_sensor_detect(PIR_SENSOR_PIN);

        Button_Init(); // Initialize the button
        // Check if the button is pressed and toggle servo state
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
