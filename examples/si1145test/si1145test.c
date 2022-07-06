#include "driver/gpio.h"
#include "si1145.h"
#include <esp_err.h>
#include <stdio.h>>

#define GPIO_SDA GPIO_NUM_21
#define GPIO_SCL GPIO_NUM_22

void get_uv_values(void)
{
  si1145_t sensor;
  memset(&sensor, 0, sizeof(bme680_t));
  ESP_ERROR_CHECK(si1145_init_desc(&sensor,0, GPIO_SDA, GPIO_SCL));
  si1145_init_sensor(&sensor);
  int uv;
  if (si1145_read_uv(&sensor, &uv) == ESP_OK)
  {
    float uv = float(uv) / 100;
    printf("UV Value: %f \n", uv);
    return;
  }
  printf("Failed to read value\n");

}
