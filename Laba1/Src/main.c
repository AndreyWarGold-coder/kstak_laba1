#include "button_config.h"
#include "led_config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "misc.h"
#include "timer_config.h"

void swap_mode () {
	int mode = MainMode;
	if(is_pressed) {
		mode = 3 - MainMode;
	}
	switch(mode) {
		case 0: {
			off_led(LED2 | LED3 | LED4);
			on_led(LED1);
			break;
		}
		case 1: {
			off_led(LED1 | LED3 | LED4);
			on_led(LED2);
			break;
		}
		case 2: {
			off_led(LED1 | LED2 | LED4);
			on_led(LED3);
			break;
		}
		case 3: {
			off_led(LED1 | LED2 | LED3);
			on_led(LED4);
			break;
		}
	}
}

int main(void)
{
	GPIOD_Config();
	GPIOA_Config();
	EXTI_Config();
	INTTIM_Config();
	while (1) {
		swap_mode();
    }
}
