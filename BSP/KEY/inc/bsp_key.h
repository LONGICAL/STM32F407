/******************************************************************************
 * Copyright (C) 2024 EternalChip, Inc.(Gmbh) or its affiliates.
 *
 * All Rights Reserved.
 *
 * @file bsp_key.h
 *
 * @par dependencies
 * - bsp_key.h
 * - stdio.h
 * - stdint.h
 *
 * @author Jack | R&D Dept. | EternalChip 立芯嵌入式
 *
 * @brief Provide the HAL APIs of Key and corresponding opetions.
 *
 * Processing flow:
 *
 * call directly.
 *
 * @version V1.0 2024-10-30
 *
 * @note 1 tab == 4 spaces!
 *
 *****************************************************************************/
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

//******************************** Includes *********************************//
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdio.h>
#include <stdint.h>
//******************************** Includes *********************************//

//******************************** Defines **********************************//

//*********************Queue_Handler ********************//

typedef enum
{
    KEY_OK = 0,               /* Operation completed successfully.  */
    KEY_ERROR = 1,            /* Run-time error without case matched*/
    KEY_ERRORTIMEOUT = 2,     /* Operation failed with timeout      */
    KEY_ERRORRESOURCE = 3,    /* Resource not available.            */
    KEY_ERRORPARAMETER = 4,   /* Parameter error.                   */
    KEY_ERRORNOMEMORY = 5,    /* Out of memory.                     */
    KEY_ERRORISR = 6,         /* Not allowed in ISR context         */
    KEY_RESERVED = 0x7FFFFFFF /* Reserved                           */
} key_statues_t;

typedef enum
{
    KEY_PRESSED = 0,     /* Operation completed successfully.  */
    KEY_NOT_PRESSED = 1, /* Run-time error without case matched*/
} key_press_statues_t;

//******************************** Defines **********************************//
key_statues_t key_scan(key_press_statues_t *key_value);
#endif // BSP_KEY_H