/*
 * capsulas.h
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */

#include <aguaSemGas.h>


/**
 * @brief Água temperatura ambiente
 *
 *
 * Essa função é reponsavel por gerenciar as funções necessarias para a produção de agua sem gás em temperatura ambiente.
 */
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

/**
 * @brief Água quente
 *
 * Essa função é responsavel por gerenciar as funções para a produção de agua quente.
 */
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

/**
 * @brief Água gelada
 *
 * Essa função é responsavel por gerenciar as funções para a produção de agua gelada
 */
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

/**
 * @brief Chá Gelado
 *
 *Essa função é responsavel por gerenciar as funções para a produção de chá gelado
 */
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

/**
 * @brief Chá Quente
 *
 *Essa função é responsavel por gerenciar as funções para a produção de chá quente
 */
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
