#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/uart.h"
#include "driver/gpio.h"

#include "RS485.h"

#define UART2_TXD  (GPIO_NUM_17)
#define UART2_RXD  (GPIO_NUM_16)
#define UART2_RTS  (UART_PIN_NO_CHANGE)
#define UART2_CTS  (UART_PIN_NO_CHANGE)

#define RS485RD     21
#define BUF_SIZE    100

void RS485_echo(void)
{
    static char data_u2[BUF_SIZE];
    gpio_set_level(RS485RD, 0); //RS485输入模式
    int len2 = uart_read_bytes(UART_NUM_2, (uint8_t*)data_u2, BUF_SIZE, 20 / portTICK_RATE_MS);
    if(len2!=0)
    {
        printf("UART2 recv:");
        for(int i=0;i<len2;i++)
        {
            printf("%x ",data_u2[i]);
        }
        printf("\r\n");
        gpio_set_level(RS485RD, 1); //RS485输出模式
        uart_write_bytes(UART_NUM_2, "RS485_RECV:", 11);
        uart_write_bytes(UART_NUM_2, data_u2, len2);
        len2=0;
    }

}



void RS485_Init(void)
{
    
    /**********************uart init**********************************************/
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };


    uart_param_config(UART_NUM_2, &uart_config);
    uart_set_pin(UART_NUM_2, UART2_TXD, UART2_RXD, UART2_RTS, UART2_CTS);
    uart_driver_install(UART_NUM_2, BUF_SIZE * 2, 0, 0, NULL, 0);
    
    /******************************gpio init*******************************************/
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO16
    io_conf.pin_bit_mask = (1<<RS485RD);
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 1;
    //configure GPIO with the given settings
    gpio_config(&io_conf);


}