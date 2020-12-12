/*
 * capsulas.h
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */

#include "aguasNaturais.h"


void aguaNatural(void){
	pressostatoFiltro();
	if(presF == 0){
		filtroSaturado();
	}else{
		limpar();
		escreve_string(0x80, "Preparando...");
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_SET);
		bomba(0);
		HAL_GPIO_WritePin(GPIOA, Y3, GPIO_PIN_RESET);
		final();
	}
}

void aguaQuente(void){
	pressostatoFiltro();
	if(presF == 0){
		filtroSaturado();
	}else{
		aquecer(capsula[1].temperatura);
		limpar();
		escreve_string(0x80, "Preparando...");
		HAL_GPIO_WritePin(GPIOA, Y1, GPIO_PIN_SET);
		bomba(1);
		HAL_GPIO_WritePin(GPIOA, Y1, GPIO_PIN_RESET);
		final();
	}
}

void aguaGelada(void){
	pressostatoFiltro();
		if(presF == 0){
			filtroSaturado();
		}else{
			resfriar(capsula[2].temperatura);
			limpar();
			escreve_string(0x80, "Preparando...");
			HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_SET);
			bomba(2);
			HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_RESET);
			final();
		}
}

void chaGelado(void){
	pressostatoFiltro();
	if(presF ==0){
		filtroSaturado();
	}else{
		resfriar(capsula[4].temperatura);
		limpar();
		escreve_string(0x80, "Preparando...");
		HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_SET);
		bomba(4);
		HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_RESET);
		final();
	}
}

void chaQuente(void){
	pressostatoFiltro();
	if(presF ==0){
		filtroSaturado();
	}else{
		aquecer(capsula[5].temperatura);
		limpar();
		escreve_string(0x80, "Preparando...");
		HAL_GPIO_WritePin(GPIOA, Y1, GPIO_PIN_SET);
		bomba(5);
		HAL_GPIO_WritePin(GPIOA, Y1, GPIO_PIN_RESET);
		final();
	}
}
