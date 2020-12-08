/*
 * telas.c
 *
 *  Created on: 7 de dez de 2020
 *      Author: andre
 */
#include "telas.h"

void aquecendo(int32_t tempDesejada){
	limpar();
	escreve_string(0x80, "Aquecendo...");
	escreve_string(0xC0, "Temp. Final:");
	variaveis(0xCC, tempDesejada);
}

void resfriando(int32_t tempDesejada){
	limpar();
	escreve_string(0x80, "Resfriando...");
	escreve_string(0xC0, "Temp. Final:");
	variaveis(0xCC, tempDesejada);
}

void menuAgua(void);

void misturando(void);

void confirmacao(void);

void capsulaEscolhida(void);

void final(void);

void filtroSaturado(void);

void CO2Saturado(void);
