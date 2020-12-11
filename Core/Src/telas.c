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
 void menuAgua(void){
	limpar();
	escreve_string(0x80, "temperatura");
	escreve_string(0xc0, "Conf.| + - |Sair");
}

void misturando(uint8_t num){
	limpar();
	escreve_string(0x80, "Misturando gás");
	escreve_string(0xc0, capsula[num].nome);
}

void confirmacao(void){
	limpar();
	escreve_string(0x80, "confirmar = C");
	escreve_string(0xc0, "Sair = S");
}

void capsulaEscolhida(int8_t tipo){
	switch (tipo){
	case 1:
		limpar();
		escreve_string(0x84, "Capsula");
		escreve_string(0xC6, capsula[0].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC6, capsula[0].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC6, capsula[0].nome);
		HAL_Delay(4000);

		menuAgua();
		break;
	case 2:
		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula");
		escreve_string(0xC2, capsula[3].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC2, capsula[3].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC2, capsula[3].nome);
		HAL_Delay(4000);

		//confirmacao();
		break;
	case 3:
		limpar();
		escreve_string(0x84, "Capsula");
		escreve_string(0xC3, capsula[4].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC3, capsula[4].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC3, capsula[4].nome);
		HAL_Delay(4000);

		break;
	case 4:
		limpar();
		escreve_string(0x84, "Capsula");
		escreve_string(0xC3, capsula[5].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC3, capsula[5].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC3, capsula[5].nome);
		HAL_Delay(4000);

		break;
	case 5:
		limpar();
		escreve_string(0x84, "Capsula");
		escreve_string(0xC2, capsula[6].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC2, capsula[6].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x84, "Capsula   ");
		escreve_string(0xC2, capsula[6].nome);
		HAL_Delay(4000);

		break;
	case 6:
		limpar();
		escreve_string(0x80, "Capsula vazia");
		break;
	}
}

void final(void);

void filtroSaturado(void){
	limpar();
	escreve_string(0x80, "Filtro saturado");
	HAL_Delay(1000);

	limpar();
	HAL_Delay(300);
	escreve_string(0x80, "Filtro saturado");
	HAL_Delay(1000);

	limpar();
	HAL_Delay(300);
	escreve_string(0x80, "Filtro saturado");
	HAL_Delay(1000);

	limpar();
	HAL_Delay(300);
	escreve_string(0x80, "Filtro saturado");
	HAL_Delay(1000);
}

void CO2Saturado(void){
	limpar();
	escreve_string(0x80, "CO2 vazio");
	HAL_Delay(1000);

	limpar();
	HAL_Delay(300);
	escreve_string(0x80, "CO2 vazio");
	HAL_Delay(1000);

	limpar();
	HAL_Delay(300);
	escreve_string(0x80, "CO2 vazio");
	HAL_Delay(1000);

	limpar();
	HAL_Delay(300);
	escreve_string(0x80, "CO2 vazio");
	HAL_Delay(1000);
}

void final(void){
	escreve_string(0x80, "Sua bebida esta");
	escreve_string(0xc5, "pronta!");
}

void relogio(void){

}
