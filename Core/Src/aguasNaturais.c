/*
 * capsulas.h
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
//#include "funcoes.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "aguasNaturais.h"


void aguaNatural(void){
	int8_t pres = pressostato();
	if(pres == 0){

	}else{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
		bomba(1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	}
}
