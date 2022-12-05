#ifndef LED_CONFIG_H
#define LED_CONFIG_H

#include <stm32f4xx.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>

#define LED1   	GPIO_Pin_12
#define LED2   	GPIO_Pin_13
#define LED3   	GPIO_Pin_14
#define LED4   	GPIO_Pin_15

void GPIOD_Config(void);

void on_led(uint32_t);

void off_led(uint32_t);

void swap_led(uint32_t);

#endif
