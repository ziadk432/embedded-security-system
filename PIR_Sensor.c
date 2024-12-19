#include "PIR_Sensor.h"
#include <stdio.h>

void ir_sensor_init(uint IR_SENSOR_PIN) {
    gpio_init(IR_SENSOR_PIN);
    gpio_set_dir(IR_SENSOR_PIN, GPIO_IN);
}


bool ir_sensor_detect(uint IR_SENSOR_PIN) {
    return gpio_get(IR_SENSOR_PIN) ; 
}