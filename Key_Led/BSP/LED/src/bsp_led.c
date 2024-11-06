/******************************************************************************
 * Copyright (C) 2024 EternalChip, Inc.(Gmbh) or its affiliates.
 *
 * All Rights Reserved.
 *
 * @file key.c
 *
 * @par dependencies
 * - bsp_key.h
 * - stdint.h
 * -
 *
 * @author LONG | R&D Dept. | EternalChip
 *
 * @brief Provide the HAL APIs of Key and corresponding opetions.
 *
 * Processing flow:
 *
 * call directly.
 *
 * @version V1.0 2024-11-03
 *
 * @note 1 tab == 4 spaces!
 *
 *****************************************************************************/
//******************************** Includes *********************************//
#include "bsp_led.h"

//******************************** Includes *********************************//

//******************************** Defines **********************************//

//********************* Thread_Func **********************//
const osThreadAttr_t led_Task_attributes = {
    .name = "led_Task",
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityNormal,
};
osThreadId_t led_TaskHandle;
//********************* Thread_Func **********************//

//********************* Queue_Handler ********************//
QueueHandle_t led_queue;
//********************* Queue_Handler ********************//

led_status_t led_on_off(led_operation_t led_operation)
{
    led_status_t ret = LED_OK;
    if(LED_ON==led_operation)
    {
        // turn on led
        HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
    }
    else if(LED_OFF==led_operation)
    {
        // turn off led
        HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
    }
    else if (LED_TOGGLE == led_operation)
    {
        // LED_TOGGLE led
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    }
    else
    {
        ret = LED_ERROR;
    }
}

void led_task_func(void *argument)
{
    led_status_t        led_ret = LED_OK;
    led_operation_t   led_value = LED_ON;
    led_queue = xQueueCreate(10, sizeof(led_operation_t));
    if(NULL == led_queue)
    {
        printf("led_queue create failed!\r\n");
    }
    else
    {
        printf("led_queue create success!\r\n");
    }
    for (;;)
    {
        printf("led_task_func\r\n");

        if(led_queue != 0)
        {
            if ( xQueueReceive( led_queue, &( led_value ), (TickType_t) 100 ) )
            {
                printf("receive led_value: [%d] \r\n", led_value);
                led_on_off(led_value);
            }

        }
        osDelay(100);
    }
}

//******************************** Defines **********************************//

