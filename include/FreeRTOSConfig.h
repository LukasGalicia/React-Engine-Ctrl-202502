/*
    FreeRTOS V7.4.0 - Copyright (C) 2013 Real Time Engineers Ltd.

    FEATURES AND PORTS ARE ADDED TO FREERTOS ALL THE TIME.  PLEASE VISIT
    http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.

    >>>>>>NOTE<<<<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
    details. You should have received a copy of the GNU General Public License
    and the FreeRTOS license exception along with FreeRTOS; if not itcan be
    viewed here: http://www.freertos.org/a00114.html and also obtained by
    writing to Real Time Engineers Ltd., contact details for whom are available
    on the FreeRTOS WEB site.

    1 tab == 4 spaces!

    ***************************************************************************
     *                                                                       *
     *    Having a problem?  Start by reading the FAQ "My application does   *
     *    not run, what could be wrong?"                                     *
     *                                                                       *
     *    http://www.FreeRTOS.org/FAQHelp.html                               *
     *                                                                       *
    ***************************************************************************


    http://www.FreeRTOS.org - Documentation, books, training, latest versions, 
    license and Real Time Engineers Ltd. contact details.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, and our new
    fully thread aware and reentrant UDP/IP stack.

    http://www.OpenRTOS.com - Real Time Engineers ltd license FreeRTOS to High 
    Integrity Systems, who sell the code with commercial support, 
    indemnification and middleware, under the OpenRTOS brand.
    
    http://www.SafeRTOS.com - High Integrity Systems also provide a safety 
    engineered and independently SIL3 certified version for use in safety and 
    mission critical applications that require provable dependability.
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

/* USER CODE BEGIN (0) */
/* USER CODE END */
#define configUSE_PREEMPTION		  1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	1
#define configUSE_FPU							1
#define configUSE_IDLE_HOOK			  0
#define configUSE_TICK_HOOK			  0
#define configUSE_TRACE_FACILITY	  0
#define configUSE_16_BIT_TICKS		  0
#define configCPU_CLOCK_HZ			  ( ( unsigned portLONG ) 80000000 ) /* Timer clock. */
#define configTICK_RATE_HZ			  ( ( TickType_t ) 10000 )
#define configMAX_PRIORITIES		  ( 5 )
#define configMINIMAL_STACK_SIZE	  ( ( unsigned portSHORT ) 128 )
#define configTOTAL_HEAP_SIZE		  ( ( size_t ) 8192 )
#define configMAX_TASK_NAME_LEN		  ( 16 )
#define configIDLE_SHOULD_YIELD		  1
#define configGENERATE_RUN_TIME_STATS 0
#define configUSE_MALLOC_FAILED_HOOK  0

/* USER CODE BEGIN (1) */
/* USER CODE END */

#define configSUPPORT_STATIC_ALLOCATION			0
#define configSUPPORT_DYNAMIC_ALLOCATION		1

#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 1
#define configUSE_TICKLESS_IDLE					1

/* USER CODE BEGIN (2) */
/* USER CODE END */

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		    0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Mutexes */
#define configUSE_MUTEXES               0
#define configUSE_RECURSIVE_MUTEXES     0

/* Semaphores */
#define configUSE_COUNTING_SEMAPHORES   0

/* Timers */
#define configUSE_TIMERS                0
#define configTIMER_TASK_PRIORITY		( 0 )
#define configTIMER_QUEUE_LENGTH		0
#define configTIMER_TASK_STACK_DEPTH	( 0 )

/* USER CODE BEGIN (3) */
/* USER CODE END */

/* Set the following definitions to 1 to include the API function, or zero to exclude the API function. */
#define INCLUDE_vTaskPrioritySet		    1
#define INCLUDE_uxTaskPriorityGet		    1
#define INCLUDE_vTaskDelete					1
#define INCLUDE_vTaskCleanUpResources	    0
#define INCLUDE_vTaskSuspend		     	1
#define INCLUDE_xTaskResumeFromISR			1
#define INCLUDE_vTaskDelayUntil			    1
#define INCLUDE_vTaskDelay				    1
#define INCLUDE_xTaskGetSchedulerState      1
#define INCLUDE_uxTaskGetStackHighWaterMark 1
#define INCLUDE_xTaskAbortDelay             1
#define INCLUDE_eTaskGetState               1
#define INCLUDE_xTaskGetHandle              1
#define INCLUDE_xTaskGetIdleTaskHandle      1

/* USER CODE BEGIN (4) */
/* USER CODE END */


/* debug ASSERT */
#define configASSERT( x ) if( ( x ) == pdFALSE ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* USER CODE BEGIN (5) */
/* USER CODE END */

#endif /* FREERTOS_CONFIG_H */
