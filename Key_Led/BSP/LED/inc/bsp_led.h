/******************************************************************************
 * Copyright (C) 2024 EternalChip, Inc.(Gmbh) or its affiliates.
 *
 * All Rights Reserved.
 *
 * @file bsp_led.h
 *
 * @par dependencies
 * - stdio.h
 * - stdint.h
 *
 * @author LONG | R&D Dept. | EternalChip 
 *
 * @brief Provide the HAL APIs of Key and corresponding opetions.
 *
 * Processing flow:
 *
 * call directly.
 *
 * @version V1.0 2023-12-03
 *
 * @note 1 tab == 4 spaces!
 *
 *****************************************************************************/

#ifndef __BSP_LED_H__
#define __BSP_LED_H__

//******************************** Includes *********************************//
#include <stdint.h> //  the compiling lib.
#include <stdio.h>

#include "main.h" //  Core / OS layer
#include "cmsis_os.h"

#include "queue.h" //  specific file for operations
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
//******************************** Includes *********************************//

//******************************** Defines **********************************//

//********************* Thread_Func **********************//

//********************* Thread_Func **********************//

//********************* Queue_Handler ********************//

//********************* Queue_Handler ********************//
//****************** function resturn status  ************//
typedef enum
{
    LED_OK = 0,               /* Operation completed successfully.  */
    LED_ERROR = 1,            /* Run-time error without case matched*/
    LED_ERRORTIMEOUT = 2,     /* Operation failed with timeout      */
    LED_ERRORRESOURCE = 3,    /* Resource not available.            */
    LED_ERRORPARAMETER = 4,   /* Parameter error.                   */
    LED_ERRORNOMEMORY = 5,    /* Out of memory.                     */
    LED_ERRORISR = 6,         /* Not allowed in ISR context         */
    LED_RESERVED = 0x7FFFFFFF /* Reserved                           */
} led_status_t;

typedef enum
{
    LED_ON = 0,     /* Operation completed successfully.  */
    LED_OFF = 1,    /* Operation completed successfully.  */
    LED_TOGGLE = 2, /* Operation completed successfully.  */
} led_operation_t;

//******************************** Defines **********************************//
#endif // BSP_LED_H