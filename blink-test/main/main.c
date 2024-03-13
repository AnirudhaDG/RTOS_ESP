#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
 
TaskHandle_t Task1Handle = NULL;
 
#define BLINK_GPIO1 GPIO_NUM_2
 
void task1(void *arg)
{
  esp_rom_gpio_pad_select_gpio(BLINK_GPIO1);
  gpio_set_direction(BLINK_GPIO1, GPIO_MODE_OUTPUT);
  while(1) {
  printf("Turning off the LED\n");
      gpio_set_level(BLINK_GPIO1, 0);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
  printf("Turning on the LED\n");
      gpio_set_level(BLINK_GPIO1, 1);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
 
void app_main(void)
{
  xTaskCreate(task1, "task1", 4096, NULL,10, &Task1Handle); 
  // 4096 is the size of task stack number of variables 
  // 10 is priority
}