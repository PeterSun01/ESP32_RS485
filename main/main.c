#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"


#include "RS485.h"


static void RS485_test_task(void* arg)
{
    while(1)
    {
      RS485_echo(); 
    }
}

void app_main()
{
    RS485_Init();   
    xTaskCreate(&RS485_test_task, "RS485_test_task", 2048, NULL, 10, NULL);
}


