#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

#include <stm32f4xx.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_tim.h>

static int MainMode = 0;

void TIM2_IRQHandler();

void INTTIM_Config();

#endif
