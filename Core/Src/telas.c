/*
 * telas.c
 *
 *  Created on: 7 de dez de 2020
 *      Author: andre
 */
#include "telas.h"

void aquecendo(void){
	limpar();
	escreve_string(0x80, "Aquecendo...");
	escreve_string(0xC0, "Temp. atual: 0");
}

void resfriando(void){
	limpar();
	escreve_string(0x80, "Resfriando...");
	escreve_string(0xC0, "Temp. atual:0");

}

void menuAgua(void){
	int8_t valor, aux, aux2;
	limpar();
	escreve_string(0x80, "Natural");
	escreve_string(0xc0, "Conf.| + - |Sair");
	aux=aux2=0;
	while(1){
		valor = botoes();
		switch(valor){
		case 1:
			aguaNatural();
			break;
		case 2:
			if(aux==0){
				aguaqEscrita();
				aux=1;
				aux2=0
			}else{
				aguagEescrita();
				aux2=1;
				aux=0;
			}
			break;
		case 3:
			if(aux2==0){
				aguagEscrita();
				aux2=1;
				aux=0;
			}else{
				agua1Eescrita();
				aux2=0;
				aux=1;
			}
			break;
		case 4:
			relogio();
			break;
		}
	}
}

void misturando(uint8_t num){
	limpar();
	escreve_string(0x80, "Misturando gás");
	escreve_string(0xc0, capsula[num].nome);
}

void confirmacao(void){
	escreve_string(0xc0, " Conf=C | Sair=S");
}

void capsulaEscolhida(int8_t tipo){
	int8_t valor;
	switch (tipo){
	case 1:
		limpar();
		escreve_string(0x86, capsula[0].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x86, capsula[0].nome);
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x86, capsula[0].nome);
		confirmacao();
		HAL_Delay(4000);
		valor = botoes();
		if(valor == 1){
			menuAgua();
		}else if(valor==4){
			relogio();
		}else{
			valor = botoes();
		}

		break;
	case 2:
		limpar();
		HAL_Delay(300);
		escreve_string(0x82, capsula[3].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x82, capsula[3].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x82, capsula[3].nome);
		confirmacao();
		HAL_Delay(4000);

		//confirmacao();
		break;
	case 3:
		limpar();
		escreve_string(0x83, capsula[4].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x83, capsula[4].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x83, capsula[4].nome);
		confirmacao();
		HAL_Delay(4000);

		valor = botoes();
		break;
	case 4:
		limpar();
		escreve_string(0x83, capsula[5].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x83, capsula[5].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x83, capsula[5].nome);
		confirmacao();
		HAL_Delay(4000);

		break;
	case 5:
		limpar();
		escreve_string(0x82, capsula[6].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x82, capsula[6].nome);
		confirmacao();
		HAL_Delay(1000);

		limpar();
		HAL_Delay(300);
		escreve_string(0x82, capsula[6].nome);
		confirmacao();
		HAL_Delay(4000);

		break;
	case 6:
		limpar();
		escreve_string(0x80, "Capsula vazia");
		break;
	}
}

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
	lerBits();
	if(bn1 !=0){

	}else{
		//relogio
	}
}

void aguagEescrita(void){
	escreve_string(0xC0, "água gelada");
}

void aguaqEscrita(void){
	escreve_string(0xC0, "água quente");
}
