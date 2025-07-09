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
#include "os_queue.h"

/* HW INCLUDES */
#include "gio.h"
#include "het.h"
#include "adc.h"

/* DRIVER INCLUDES */
#include "projlib/HX711_FREERTOS.h"

/* USER CODE END */

/* Include Files */

#include "sys_common.h"

/* USER CODE BEGIN (1) */

/* USER TASKS BEGIN */
/* HX711 Polling */
void vTask_HX711_Poll(void *pvParameters);
TaskHandle_t xTask_HX711_Poll_Handle;

/* BLDC Control */
void vTask_MotorCtrl(void *pvParameters);
TaskHandle_t xTask_MotorCtrl_Handle;
/* USER TASKS END */

/* USER QUEUES BEGIN */
QueueHandle_t xQueue_HX711_DataQueue;
/* USER QUEUES END */

/* USER DEFINES BEGIN */
#define BLDC_PWM    2U
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
    /*
     *  Working on branch main
     */

    /* HW Driver Init */
    gioInit();
    hetInit();
    adcInit();

    /* IRQ Enable */
    _enable_IRQ();

    /* User Queues CREATE */
    while((xQueue_HX711_DataQueue = xQueueCreate(1, sizeof(HX711Data_t))) == NULL);

    /* User Tasks CREATE */
    /* BLDC Controller Task */
    MPU_xTaskCreate(vTask_MotorCtrl,                // Task Code
                    "BLDC Control Task",            // HL Task Name
                    3 * configMINIMAL_STACK_SIZE,   // Memory Stack Size
                    NULL,                           // Task Parameters
                    3,                              // Priority
                    &xTask_MotorCtrl_Handle);       // Task Handler (xTaskHandle)

    /* Scheduler START */
    vTaskStartScheduler();

    for(;;);
/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */

/* USER TASKS IMP, BEGIN */
void vTask_HX711_Poll(void *pvParameters)
{
    HX711Data_t HX711_dataRead;

    /* HX711 POWER DOWN & INIT */
    HX711_data_buff = 0x00000000U;                  // Initialize buffer
    gioSetBit(PORT_HX711_SCK, PIN_HX711_SCK, 1U);   // Set SCK High
    MPU_vTaskDelay((TickType_t) 1);                 // HX711 Power-off Delay
    // HX711 OFF

    xQueueReset(xQueue_HX711_DataQueue);
    gioEnableNotification(PORT_HX711_DT, PIN_HX711_DT);     // Enable HX711 DT READY IRQ
    gioSetBit(PORT_HX711_SCK, PIN_HX711_SCK, 0U);           // Set SCK Low
    // HX711 ON
    // This line marks the start of normal AS operation

    for(;;)
    {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);                // Wait for DT IRQ
        /* DT IRQ HAS ARRIVED */

        HX711_dataRead = DECODE_TWOS_COMPLEMENT(HX711_data_buff);                       // Decode Sensor data to signed int
        if(xQueueSend(xQueue_HX711_DataQueue, &HX711_dataRead, 0) == errQUEUE_FULL)     // Send final sensor data reading
        {
            asm(" nop");
        }
        HX711_data_count = 0U;              // Reset data bit counter
        HX711_data_buff = 0x00000000U;      // Reset data buffer

        gioEnableNotification(PORT_HX711_DT, PIN_HX711_DT);         // Reset DT pin interrupt
    }
}

void vTask_MotorCtrl(void *pvParameters)
{
    adcData_t ADC_CtrlData;
    HX711Data_t HX711_CtrlData;
    float ADCMotorThrtt;            // Floating value for Pot-Set Throttle

    pwmStart(hetRAM1, BLDC_PWM);    // Start Motor Signal

    /* HX711 Sensor Handler Task CREATE */
    MPU_xTaskCreate(vTask_HX711_Poll,               // Task Code
                    "HX711 Handler Task",           // HL Task Name
                    3 * configMINIMAL_STACK_SIZE,   // Memory Stack Size
                    NULL,                           // Task Parameters
                    4,                              // Priority
                    &xTask_HX711_Poll_Handle);      // Task Handler (xTaskHandle)

    for(;;)
    {
        xQueueReceive(xQueue_HX711_DataQueue, &HX711_CtrlData, portMAX_DELAY);
        adcStartConversion(adcREG1, adcGROUP1);
        while(adcIsConversionComplete(adcREG1, adcGROUP1) == 0);
        adcGetData(adcREG1, adcGROUP1, &ADC_CtrlData);
        ADCMotorThrtt = ((((float) ADC_CtrlData.value) / 4095.0) * 5.0) + 5.0;

        // Set Motor Throttle
        pwmSetDuty(hetRAM1, BLDC_PWM, (uint32_t) ADCMotorThrtt);
    }
}
/* USER TASKS END */

/* IRQ NOTIFICATIONS */
/*
 *  HX711 acquisition happens in Gio IRQ
 */
void gioNotification(gioPORT_t *port, uint32 bit)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    gioDisableNotification(PORT_HX711_DT, PIN_HX711_DT);    // Disable DT pin IRQ

    /* HX711 DATA ACQ BEGIN */
    while(++HX711_data_count <= HX711_RES_128R_A)           // Generate HX711 pulse train
    {
        gioToggleBit(PORT_HX711_SCK, PIN_HX711_SCK);
        gioToggleBit(PORT_HX711_SCK, PIN_HX711_SCK);
        if(HX711_data_count <= 24)
            HX711_data_buff = (HX711_data_buff << 1) | gioGetBit(PORT_HX711_DT, PIN_HX711_DT);
    }
    /* HX711 DATA ACQ END*/

    vTaskNotifyGiveFromISR(xTask_HX711_Poll_Handle, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/* USER CODE END */
