#ifndef RFID_RC522_H
#define RFID_RC522_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Define I2C pins and configuration for RC522
#ifndef RFID_I2C_PORT
#define RFID_I2C_PORT i2c0 // Default I2C port
#endif

#ifndef RFID_SDA_PIN
#define RFID_SDA_PIN 0 // I2C SDA pin
#endif

#ifndef RFID_SCK_PIN
#define RFID_SCK_PIN 2 // I2C SCK pin.
#endif

#ifndef RFID_RST_PIN
#define RFID_RST_PIN 21 // Reset pin for RC522 module
#endif

#define MAX_UID_LENGTH 10 // Maximum UID size for RC522

// Function to initialize the RC522 module
void rfid_rc522_init(void);

// Function to check for a card and retrieve its UID
bool rfid_rc522_read_card(uint8_t *uid, size_t *uid_length);

#endif // RFID_RC522_H