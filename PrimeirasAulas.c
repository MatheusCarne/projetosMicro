/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
			

void atraso(int delay){
	while (delay>0) --delay;
}

int main(void)
{
	RCC->AHB1ENR |=1; //liga o clock do gpioa
	GPIOA->MODER |=(0b01<<12); // conf o pino PA6 como saida

	while(1){
		GPIOA->ODR |=(1<<6);
		atraso(1000000);
		GPIOA->ODR &= ~(1<<6);
		atraso(1000000);
	}

	for(;;);
}
