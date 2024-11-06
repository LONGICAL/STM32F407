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
led_status_t led_on_off(led_operation_t led_operation)
{
    led_status_t ret = LED_OK;
    if(LED_ON==led_operation)
    {
        // turn on led
        HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
    }
    else if(LED_OFF==led_operation)
    {
        // turn off led
        HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
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
//******************************** Defines **********************************//

