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
		bomba(0);
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_RESET);
	}
}

void aguaQuente(void){
	pressostatoFiltro();
	if(presF == 0){

	}else{
		aquecer(capsula[1].temperatura);
		HAL_GPIO_WritePin(GPIOA, Y1, GPIO_PIN_SET);
		bomba(1);
		HAL_GPIO_WritePin(GPIOA, Y1, GPIO_PIN_RESET);
	}
}

void aguaGelada(void){
	pressostatoFiltro();
		if(presF == 0){

		}else{
			resfriar(capsula[2].temperatura);
			HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_SET);
			bomba(1);
			HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_RESET);
		}
}
