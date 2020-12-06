/*
 * funcoes.h
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#ifndef INC_FUNCOES_H_
#define INC_FUNCOES_H_
#endif /* INC_FUNCOES_H_ */

/*-----Defines utilizados----*/
#define NUMBER_OF_CONVERSION 16
#define graus ((3.3/4095)*0.005)

//variaveis do DMA
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;;

//variaveis globais de definição;
typedef struct {
	char nome[15];
	int32_t temperatura;
	float tempo;
	uint8_t gas;
	int16_t tipo;
	float gast;
}tipo_capsula;

int32_t Vsense;
float temperatura;
uint8_t flag;
uint32_t adcData[NUMBER_OF_CONVERSION];
int8_t aquecido;

tipo_capsula capsula[8];

//variais para usar nas funções de entrada e saida
int16_t P1 = GPIO_PIN_11; // PRESSOSTATO DA SAIDA DE AGUA - PORTA B11
int16_t Y3 = GPIO_PIN_5; //VALVULA DE AGUA NATURAL SEM AQUECIMENTO OU RESFRIAMENTO - PORTA A5
int16_t SAIDA = GIOP_PIN_10 //SAIDA DO SISTEMA - PORTA B10


int8_t pressostato(void);

void bomba(int8_t tipo);

void aquecer(void);

void resfriar(void);

void calibrar(void);

void iniciar(void);

