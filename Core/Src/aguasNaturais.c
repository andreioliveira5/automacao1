/*
 * capsulas.h
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
//#include "funcoes.h"

#include "aguasNaturais.h"


void aguaNatural(void){
	pressostatoFiltro();
	if(presF == 0){

	}else{
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_SET);
		bomba(1);
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_RESET);
	}
}

void aguaQuente(void){
	pressostatoFiltro();
	if(presF == 0){

	}else{
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_SET);
		bomba(1);
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_RESET);
	}
}


void aguaGelada(void){

}
