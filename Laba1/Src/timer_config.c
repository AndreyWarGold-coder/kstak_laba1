#include "timer_config.h"
#include "button_config.h"

void TIM2_IRQHandler(void) {
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
		if(MainMode == 3){
			MainMode = 0;
		}else{
			MainMode ++;
		}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

void INTTIM_Config(void) {
	NVIC_InitTypeDef nvic_struct;
	nvic_struct.NVIC_IRQChannel = TIM2_IRQn;
	nvic_struct.NVIC_IRQChannelCmd = ENABLE;
	nvic_struct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_struct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&nvic_struct);
	TIM_TimeBaseInitTypeDef tim_struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	tim_struct.TIM_Prescaler = 42000 - 1;
	if (is_pressed) {
		tim_struct.TIM_Period = 800 - 1;
	} else {
		tim_struct.TIM_Period = 1500 - 1;
	}
	tim_struct.TIM_ClockDivision = 0;
	tim_struct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &tim_struct);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
}
