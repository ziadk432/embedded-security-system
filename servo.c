// Control a servo by degrees or millis

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "servo.h"

float clockDiv = 64;
float wrap = 39062;
int currentMillis = 400;
bool direction = true;

void setMillis(int servoPin, float millis)
{
    pwm_set_gpio_level(servoPin, (millis / 20000.f) * wrap);
}

void servo_init(int servoPin, float startMillis)
{
    gpio_set_function(servoPin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(servoPin);

    pwm_config config = pwm_get_default_config();

    uint64_t clockspeed = clock_get_hz(5);
    clockDiv = 64;
    wrap = 39062;

    while (clockspeed / clockDiv / 50 > 65535 && clockDiv < 256)
        clockDiv += 64;
    wrap = clockspeed / clockDiv / 50;

    pwm_config_set_clkdiv(&config, clockDiv);
    pwm_config_set_wrap(&config, wrap);

    pwm_init(slice_num, &config, true);

    setMillis(servoPin, startMillis);
}

void sweep()
{
    currentMillis += (direction) ? 300 : -300;
    if (currentMillis >= 2400)
        direction = false;
    if (currentMillis <= 400)
        direction = true;
    setMillis(SERVO_PIN, currentMillis);
}

void open()
{
    setMillis(SERVO_PIN, 2400);
}

void close()
{
    setMillis(SERVO_PIN, 1000);
}