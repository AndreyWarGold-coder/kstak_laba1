#include "led_config.h"
#include <malloc.h>

void GPIOD_Config(void) {
	GPIO_InitTypeDef gpioConf;
	gpioConf.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	gpioConf.GPIO_Mode  = GPIO_Mode_OUT;
	gpioConf.GPIO_Speed = GPIO_Speed_2MHz;
	gpioConf.GPIO_OType = GPIO_OType_PP;
	gpioConf.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &gpioConf);
}

void on_led(uint32_t ledForOn) {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIOD->BSRRL ^= ledForOn;
}

void off_led(uint32_t ledForOn) {
	GPIOD->BSRRH ^= ledForOn;
}

void swap_led(uint32_t ledForOn) {
	GPIOD->ODR ^= ledForOn;
}
