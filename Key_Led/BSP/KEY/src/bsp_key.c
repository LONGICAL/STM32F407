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
#include "bsp_key.h"
//******************************** Includes *********************************//

//******************************** Defines **********************************//
//********************* Thread_Func **********************//
osThreadId_t key_TaskHandle;
//********************* Thread_Func **********************//

//********************* Queue_Handler ********************//
QueueHandle_t key_queue;
//********************* Queue_Handler ********************//

const osThreadAttr_t key_Task_attributes = {
  .name = "key_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};

key_statues_t key_scan(key_press_statues_t *key_value)
{
    uint32_t counter = 0;
    key_press_statues_t key_statues_value = KEY_NOT_PRESSED;
    while (counter < 10000)
    {
        // 1.如果按键按下为高电平，则表示按键按下。
        // 2.如果按键按下，则发送对应消息到队列。
        if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_SET)
        {
            key_statues_value = KEY_PRESSED;
            *key_value = key_statues_value;
            return KEY_OK;
        }
        counter++;
    }
    *key_value = key_statues_value;
    // 按键未按下，则返回超时错误。
    return KEY_ERRORTIMEOUT;
}

void key_task_func(void *argument)
{
    key_statues_t key_ret          = KEY_OK;
    key_press_statues_t key_status = KEY_NOT_PRESSED;
    key_queue = xQueueCreate(10, sizeof( uint32_t ));
    uint32_t counter_tick = 0;
    if( NULL == key_queue )
    {
        printf("key_queue create failed!\r\n");
    }
    else
    {
        printf("key_queue create success!\r\n");
    }
    for (;;)
    {
        counter_tick++;
        key_ret = key_scan(&key_status);

        if( KEY_OK == key_ret )
        {
            if (KEY_PRESSED == key_status)
            {
                printf("key pressed!\r\n");
                if(pdTRUE == xQueueSendToFront(key_queue, &counter_tick, 0))
                {
                    printf("key_queue send success!\r\n");
                }
            }
        }
        if( KEY_ERRORTIMEOUT == key_ret )
        {
            printf("key not press\r\n");
        }
        osDelay(100);
    }    
    
}
//******************************** Defines **********************************//
