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
#define botao_k0!(GPIOE->IDR & (1<<4))
#define desliga_led !

int main(void)
{
	RCC->AHB1ENR |=0b10001; //liga o clock do gpioa e gpioe
	GPIOA->MODER |=(0b01<<12); // confg pino PA6 cm saida
	GPIOA->MODER |= (0b01 << 14); //configura o pino PA7 como saída

	//confg PE4 e PE3 cm entradas

	GPIOE->MODER &=~(0B11<<8); // confg pino PE4 como entrada - nivel logico baixo
	GPIOE->MODER &= ~(0b11 << 6);  //configura pino PE3 como entrada
	GPIOE-> PUPDR |=(0B01<<8); // habilitou resistor de pull up no pino PE4
	GPIOE-> PUPDR |=(0B01<<3); // PE3

	while (1){
		// lendo o botao
		int a = (GPIOE->IDR & (1<<4));
		int b = (GPIOE->IDR & (1<<3));
		//testa a logica
		if(a){
			GPIOA->ODR |=(1<<6); // desliga o led
		} else {
			GPIOA->ODR &= ~(1<<6); // liga o led
		}
		if(b){
			GPIOA->ODR |=(1<<7); // desliga o led
		} else {
			GPIOA->ODR &= ~(1<<7); // liga o led
		}
	}

	for(;;);
}
