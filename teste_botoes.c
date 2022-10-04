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
#define k0!(GPIOE->IDR & (1<<4))  //verdadeiro quando estiver pressionado
#define k1!(GPIOE->IDR & (1<<3))
#define led_on1 GPIOA->ODR &= ~(1<<6)
#define led_off1 GPIOA->ODR |= (1<<6)
#define led_on2 GPIOA->ODR &= ~(1<<7)
#define led_off2 GPIOA->ODR |= (1<<7)
//#define desliga_led !

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;            //habilita o clock do GPIOE

    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída
    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada
    GPIOE->PUPDR |= (0b01 << 6);    //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)
    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada
    GPIOE->PUPDR |= (0b01 << 8);    //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)


    //o LED em PA6 só deve acender ao pressionar primeiro K0 e depois K1
    while(1)
    {
    	led_off1; //desliga os leds quando soltos
    	led_off2;
    	/*if (!k0 && !k1){
    		led_off;
    	}
    	else if (!k0 && k1){
    		led_off;
    		while(k1);
    	}*/
    	if (k0 && !k1){ //testa se pressionou K0 antes de K1
    		while(k0){ //enquanto K0 estiver pressionado
    			if(k1){ //teste se pressionou K1
    				led_on1; //acende o led se pressionou o K1
    				led_on2;
    			}
    			else{
    				led_off1; //apaga se não pressionou K1 ainda
    				led_off2;
    			}
    		}
    	}
    }
	for(;;);
}
