/*
 * bebidasGaseificadas.c
 *
 *  Created on: 6 de dez de 2020
 *      Author: andre
 */
#include "bebidasGaseificadas.h"

void aguaComGas(void){
	pressostatoFiltro();
	pressostadoCO2();
	if(presF==0){
		filtroSaturado();
	}else if(presCO2 ==0){
		CO2Saturado();
	}else{
		resfriar(capsula[3].temperatura);
		HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_SET);
		bombaGas(3);
		HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_RESET);
	}
}

void refrigerante(void){
	pressostatoFiltro();
	pressostadoCO2();
	if(presF==0){
		filtroSaturado();
	}else if(presCO2 ==0){
		CO2Saturado();
	}else{
		resfriar(capsula[6].temperatura);
		HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_SET);
		bombaGas(6);
		HAL_GPIO_WritePin(GPIOA, Y2, GPIO_PIN_RESET);
	}
}
