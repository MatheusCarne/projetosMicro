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
#include "Utility.h"

#define k0!(GPIOE->IDR & (1<<4))  //verdadeiro quando estiver pressionado
#define k1!(GPIOE->IDR & (1<<3))
#define K_UP (GPIOA->IDR & (1<<0))
#define led_on1 GPIOA->ODR &= ~(1<<6)
#define led_off1 GPIOA->ODR |= (1<<6)
#define led_on2 GPIOA->ODR &= ~(1<<7)
#define led_off2 GPIOA->ODR |= (1<<7)
//#define desliga_led !

#define LED_0_ON GPIOA ->ODR |=(1<<0)
#define LED_0_OFF GPIOA ->ODR &=~(1<<0)
#define LED_1_ON GPIOA ->ODR |=(1<<1)
#define LED_1_OFF GPIOA ->ODR &=~(1<<1)
#define LED_2_ON GPIOA ->ODR |=(1<<2)
#define LED_2_OFF GPIOA ->ODR &=~(1<<2)
#define LED_3_ON GPIOA ->ODR |=(1<<3)
#define LED_3_OFF GPIOA ->ODR &=~(1<<3)
#define LED_4_ON GPIOA ->ODR |=(1<<4)
#define LED_4_OFF GPIOA ->ODR &=~(1<<4)
#define LED_5_ON GPIOA ->ODR |=(1<<5)
#define LED_5_OFF GPIOA ->ODR &=~(1<<5)
#define LED_6_ON GPIOA ->ODR |=(1<<6)
#define LED_6_OFF GPIOA ->ODR &=~(1<<6)
#define LED_7_ON GPIOA ->ODR |=(1<<7)
#define LED_7_OFF GPIOA ->ODR &=~(1<<7)


void atraso(int delay){
	while (delay>0) --delay;
}

int main(void)
{
	Configure_Clock();
	Delay_Start();
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;            //habilita o clock do GPIOE


   // GPIOA->MODER |= (0b01 << 0);    //configura o pino PA0 como saída
   // GPIOA->MODER |= (0b01 << 2);    //configura o pino PA1 como saída
   // GPIOA->MODER |= (0b01 << 4);    //configura o pino PA2 como saída
   // GPIOA->MODER |= (0b01 << 6);    //configura o pino PA3 como saída
   // GPIOA->MODER |= (0b01 << 8);    //configura o pino PA4 como saída
    //GPIOA->MODER |= (0b01 << 10);    //configura o pino PA5 como saída
    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída
    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída

    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada
    GPIOE->PUPDR |= (0b01 << 6);    //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)
    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada
    GPIOE->PUPDR |= (0b01 << 8);    //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)
    //GPIOA->MODER &= ~(0B00<<0);    //confg o pino PA0 como entrada
    //GPIOA->PUPDR |= (0B10<<0);    // liga resistor pull-down em PA0

    while(1){
    	led_off1;

    	//23
    	if (!k1){
    		led_off2;
    	}
    	if (k1){
    		led_on2;
    		while(!k1);
    		}



    	//22
    	/*if (k0 && !k1){
    	    led_off2;
    	    led_on1;
    	    	}
    	else if (!k0 && k1){
       		led_on2;
       		led_off1;
    	    	}*/



    	//25
    	/*if (k0 && !k1){ //testa se pressionou K0 antes de K1
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
    	}*/
    }
}
