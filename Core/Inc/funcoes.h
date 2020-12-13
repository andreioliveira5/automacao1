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
#include <string.h>
#include "main.h"
#include "telas.h"

#ifndef INC_FUNCOES_H_
#define INC_FUNCOES_H_

/**
 * Estrutura para as capsulas
 */
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

#define NUMBER_OF_CONVERSION 16 // NUMERO DE CONVERSÕES DO ADC
#define graus ((3.3/4095)/0.005) // CALCULO DE CONVERSÃO DO VALOR DE LEITURA DO DMA PARA USO NOS PWM

#define P1  GPIO_PIN_11 // PRESSOSTATO DA SAIDA DE AGUA - PORTA B11
#define Y3  GPIO_PIN_5 //VALVULA DE AGUA NATURAL SEM AQUECIMENTO OU RESFRIAMENTO - PORTA A5
#define SAIDA  GPIO_PIN_10 //SAIDA DO SISTEMA - PORTA B10
#define Y1  GPIO_PIN_3 //valvula y1 - porta A3
#define Y2 GPIO_PIN_4 // VALVULA Y2 - PORTA A4
#define P2 GPIO_PIN_6 //PRESSOSTADO DO CO2
#define Y4 GPIO_PIN_7 //VALVULA Y4 CO2
#define canc GPIO_PIN_9 // PINO DO BOTÃO DE CONFIRMAR  = port A9
#define mais GPIO_PIN_10 // PINO DO BOTÃO DE MAIS = PORTA A10
#define menos GPIO_PIN_11 //PINO DE BOTÃO DE MENOS = PORTA A11
#define sair GPIO_PIN_12 // PINO DE BOTÃSO DE SAIR - PORTA A12
#define Bit1 GPIO_PIN_12 //BIT MAIS SIGNIFICATIVO
#define Bit2 GPIO_PIN_13 //BIT DO MEIO
#define Bit3 GPIO_PIN_14//BIT MENOS SIGNIFICATIVO
//variaveis do DMA
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

//variaveis globais de definição;


//int32_t Vsense;
//float temperatura;
uint8_t flag; // flag do dma
uint32_t adcData[NUMBER_OF_CONVERSION]; // vetor para armazenamento da leitura do dma
//int8_t aquecido;
int8_t presF, presCO2; // variaveis dos pressostatos do filtro é co2
int8_t horas, minutos, segundos; // variaveis do relogio
int8_t bn1; //variaveis de leitura da bomba

capsulas capsula[8]; //variavel do tipo capsulas para armazenar as capsulas

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

uint8_t botoes(void);
