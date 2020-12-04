/*
 * funcoes.c
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
#include "funcoes.h"


int8_t pressostato(void){
	int8_t pressostato = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);
	return pressostato;
}

void bomba(int8_t tipo){
	int16_t i;
	int16_t contador = 0;
	switch(tipo){
	case(1): // água natural

		for(i=0; i < 200; i++){// aceleração
			TIM2->CCR1 = contador;
			contador +=10;
			HAL_Delay(1);
		}
		HAL_Delay(2549);
		for(i=0; i<250;i++){
			TIM2->CCR1 = contador;
			contador -=8;
			HAL_Delay(1);
		}
		break;
	case(2): //Água gelada
		break;
	case(3): //Água quente
		break;
	case(4): //Água com gás
		break;
	case(5): //Chá gelado
		break;
	case(6)://Chá Quente
		break;

	}
}
