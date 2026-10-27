#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// Most ESP32 dev boards use GPIO 2 for the built-in blue LED
#define BLINK_GPIO 2

static const char *TAG = "blink_example";

void app_main(void)
{
    ESP_LOGI(TAG, "Initializing GPIO %d for blinking...", BLINK_GPIO);

    // Configure the GPIO pin as an output
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        // Turn LED on
        ESP_LOGI(TAG, "Turning the LED ON");
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second

        // Turn LED off
        ESP_LOGI(TAG, "Turning the LED OFF");
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}