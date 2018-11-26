#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

#include "Led.h"

#define GPIO_LED    22

void Led_Init(void)
{
    gpio_config_t io_conf;

    //disable interrupt
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO16
    io_conf.pin_bit_mask = (1<<GPIO_LED);
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 1;
    //configure GPIO with the given settings
    gpio_config(&io_conf);    
}


void Led_On(void)
{
    gpio_set_level(GPIO_LED, 1);
}
void Led_Off(void)
{
    gpio_set_level(GPIO_LED, 0);
}