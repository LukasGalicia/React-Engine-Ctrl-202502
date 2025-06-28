/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */

/* OS INCLUDES */
#include "FreeRTOS.h"
#include "os_task.h"

/* HW INCLUDES */
#include "gio.h"
#include "het.h"

/* DRIVER INCLUDES */
#include "projlib/HX711_FREERTOS.h"

/* USER CODE END */

/* Include Files */

#include "sys_common.h"

/* USER CODE BEGIN (1) */

/* USER TASKS BEGIN */
void vTask_HX711_PollActs(void *pvParameters);
/* USER TASKS END */

/* USER DEFINES BEGIN */
/* USER DEFINES END */

/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
    /* HW Driver Init */
    gioInit();
    hetInit();

    /* IRQ Enable */
    _enable_IRQ();
    pwmEnableNotification(hetREG1, PWM_HX711_SCK, pwmEND_OF_DUTY);

    HX711_data_buff = 0x00000000U;

    /* User Tasks CREATE */
    /* HX711 Sensor Handler Task */
    MPU_xTaskCreate(vTask_HX711_PollActs,           // Task Code
                    "HX711 Handler Task",           // HL Task Name
                    2 * configMINIMAL_STACK_SIZE,   // Memory Stack Size
                    NULL,                           // Task Parameters
                    4,                              // Priority
                    NULL);                          // Task Handler (xTaskHandle)

    /* Scheduler START */
    vTaskStartScheduler();

    for(;;);
/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */

/* USER TASKS IMP, BEGIN */
void vTask_HX711_PollActs(void *pvParameters)
{
    /* HX711 POWER DOWN & INIT */
    MPU_vTaskDelay((TickType_t) 5);             // 500 us delay
    // HX711 OFF
    gioEnableNotification(PORT_HX711_DT, PIN_HX711_DT);     // Enable HX711 DT READY IRQ
    gioSetBit(PORT_HX711_SCK, PIN_HX711_SCK, 0U);   // Set SCK Low
    // HX711 ON

    for(;;);
}
/* USER TASKS END */

/* IRQ NOTIFICATIONS */
void gioNotification(gioPORT_t *port, uint32 bit)
{
    HX711_data_count = 0;
    gioDisableNotification(PORT_HX711_DT, PIN_HX711_DT);
    pwmStart(hetRAM1, PWM_HX711_SCK);
}

void pwmNotification(hetBASE_t * hetREG,uint32 pwm, uint32 notification)
{
    HX711_data_count++;
    if(HX711_data_count <= 24)
    {
        HX711_data_buff = (HX711_data_buff << 1) | gioGetBit(PORT_HX711_DT, PIN_HX711_DT);
    }
    else if(HX711_data_count >= 27)
    {
        pwmStop(hetRAM1, PWM_HX711_SCK);
    }
}

/* USER CODE END */
