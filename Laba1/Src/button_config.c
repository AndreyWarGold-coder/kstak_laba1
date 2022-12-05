#include "button_config.h"
#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_exti.h>
#include <stdbool.h>

void GPIOA_Config(void) {
	GPIO_InitTypeDef gpioConf;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	gpioConf.GPIO_Pin  = GPIO_Pin_0;
	gpioConf.GPIO_Mode = GPIO_Mode_IN;

	GPIO_Init(GPIOA, &gpioConf);
}

void EXTI0_IRQHandler(void){
    if (EXTI_GetITStatus(EXTI_Line0)){
    	if(!is_pressed){
    		is_pressed = true;
    	} else {
    		is_pressed = false;
    	}
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

void EXTI_Config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line0;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
    NVIC_Init(&NVIC_InitStruct);
}
