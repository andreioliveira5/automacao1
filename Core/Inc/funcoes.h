/*
 * funcoes.h
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "main.h"

#ifndef INC_FUNCOES_H_
#define INC_FUNCOES_H_
#include "telas.h"
typedef struct capsulas{

	char nome[15]; //Nome para exibir no display
	int32_t temperatura; //temperatura para o controlador
	float tempo; //tempo em ms subtraido do tempo da bomba e do gas em bebidas gaseificadas
	uint8_t gas; //0 sem gas 1 com gas;
	int16_t tipo; //temperatura 0 natural 1 quente 2 fria
	float gast; // tempo do gas

}capsulas;


#endif /* INC_FUNCOES_H_ */

/*-----Defines utilizados----*/

#define NUMBER_OF_CONVERSION 16
#define graus ((3.3/4095)/0.005)

#define P1  GPIO_PIN_11 // PRESSOSTATO DA SAIDA DE AGUA - PORTA B11
#define Y3  GPIO_PIN_5 //VALVULA DE AGUA NATURAL SEM AQUECIMENTO OU RESFRIAMENTO - PORTA A5
#define SAIDA  GPIO_PIN_10 //SAIDA DO SISTEMA - PORTA B10
#define Y1  GPIO_PIN_3 //valvula y1 - porta A3
#define Y2 GPIO_PIN_4 // VALVULA Y2 - PORTA A4
#define P2 GPIO_PIN_6 //PRESSOSTADO DO CO2
#define Y4 GPIO_PIN_7 //VALVULA Y4 CO2
//variaveis do DMA
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;;

//variaveis globais de definição;


int32_t Vsense;
float temperatura;
uint8_t flag;
uint32_t adcData[NUMBER_OF_CONVERSION];
int8_t aquecido;
int8_t presF, presCO2;


capsulas capsula[8];

//variais para usar nas funções de entrada e saida


/*
 * Descição das funções
 */
void pressostatoFiltro(void);

void bomba(int8_t tipo);

void aquecer(int32_t temperatura);

void resfriar(int32_t temperatura);

void calibrar(void);

void iniciar(void);

void pressostadoCO2(void);

void bombaGas(int8_t tipo);
