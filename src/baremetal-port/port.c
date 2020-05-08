/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-04-20     chenyaxing   first version
 */

#include <stm32f4xx.h>

extern int rt_hw_usart_init();
extern void system_clock_config(int);
extern int clock_information(void);

void clk_init(char *clk_source, int source_freq, int target_freq)
{

    HAL_Init();
    __set_PRIMASK(0);
    system_clock_config(target_freq);
    __set_PRIMASK(1);

}

int uart_init()
{
    rt_hw_usart_init();
    clock_information();
    return 0;
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void _error_handler(char *s, int num)
{
    /* USER CODE BEGIN Error_Handler */
    /* User can add his own implementation to report the HAL error return state */
    while (1)
    {
    }
    /* USER CODE END Error_Handler */
}
