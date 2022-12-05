#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H

#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_exti.h>
#include <stm32f4xx_rcc.h>
#include <stdbool.h>

static bool is_pressed = false;

void GPIOA_Config(void);

void EXTI0_IRQHandler(void);

void EXTI_Config(void);

#endif
