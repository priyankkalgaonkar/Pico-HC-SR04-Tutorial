#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define TRIG_PIN 27
#define ECHO_PIN 28
#define SOUND_SPEED 0.034f // cm per microsecond
#define CM_TO_INCH 0.393701f

int main() {
    stdio_init_all(); // Initialize serial communication

    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_set_dir(ECHO_PIN, GPIO_IN);

    while (true) {
        // Send a 10us HIGH pulse to TRIG_PIN
        gpio_put(TRIG_PIN, 0);
        sleep_us(2);
        gpio_put(TRIG_PIN, 1);
        sleep_us(10);
        gpio_put(TRIG_PIN, 0);

        // Wait for the echo pin to go high (start of pulse)
        while (gpio_get(ECHO_PIN) == 0) {
            tight_loop_contents();
        }
        absolute_time_t start_time = get_absolute_time();

        // Wait for the echo pin to go low (end of pulse)
        while (gpio_get(ECHO_PIN) == 1) {
            tight_loop_contents();
        }
        absolute_time_t end_time = get_absolute_time();

        // Calculate pulse duration in microseconds
        int64_t duration_us = absolute_time_diff_us(start_time, end_time);

        // Calculate distance
        float distance_cm = duration_us * SOUND_SPEED / 2.0f;
        float distance_inch = distance_cm * CM_TO_INCH;

        // Print results
        printf("Distance (cm): %.2f\n", distance_cm);
        printf("Distance (inch): %.2f\n\n", distance_inch);

        sleep_ms(1000); // Wait for 1 second
    }
    return 0;
}