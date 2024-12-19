#include "rfid_rc522.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

// READ THIS!!! RFID got burnt and we couldn't buy one in time, so we resorted to using a button
// to simulate a security system from the inside where the button opens the gate and disables the alarm

// Function to initialize the RC522 module
void rfid_rc522_init(void)
{
    // Initialize I2C
    i2c_init(RFID_I2C_PORT, 100 * 1000); // 100 kHz I2C frequency
    gpio_set_function(RFID_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(RFID_SCK_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(RFID_SDA_PIN);
    gpio_pull_up(RFID_SCK_PIN);

    // Initialize the reset pin
    gpio_init(RFID_RST_PIN);
    gpio_set_dir(RFID_RST_PIN, GPIO_OUT);
    gpio_put(RFID_RST_PIN, 1); // Set reset pin high
}

// Function to check for a card and retrieve its UID
bool rfid_rc522_read_card(uint8_t *uid, size_t *uid_length)
{
    // Dummy implementation for reading card UID
    uint8_t dummy_uid[] = {0xDE, 0xAD, 0xBE, 0xEA, 0xEF};
    *uid_length = sizeof(dummy_uid);
    memcpy(uid, dummy_uid, *uid_length);
    return true;
}