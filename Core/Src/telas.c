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
			if(aux2 == 0 ) aguaNatural();
			if(aux2 == 1 ) aguaQuente();
			if(aux2 == 2 ) aguaGelada();
			break;
		case 4:
			sairEscrever();
			relogio();
			break;
		default:
			if(valor == 2)aux2++;
			if(valor == 3)aux2--;
			if(aux2== 3)aux2=0;
			if(aux2== -1)aux2=2;
			if(aux2==0)aguanEscrita();
			if(aux2==2)aguagEscrita();
			if(aux2==1)aguaqEscrita();
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
	limpar();
	escreve_string(0x80, "Sua bebida esta");
	escreve_string(0xc5, "pronta!");
	HAL_Delay(5000);
	relogio();
}

void relogio(void){
	while (1){
		lerBits();
		if(bn1 !=0){
			capsulaEscolhida(bn1);
		}else{
			if(horas < 10){
				escreve_string(0x84, "0");
				variaveis(0x85, horas);

			}else{
				variaveis(0x84, horas);
			}
			escreve_string(0x86, ":");
			if(minutos < 10){
				escreve_string(0x87, "0");
				variaveis(0x88, minutos);
			}else{
				variaveis(0x87, minutos);
			}
			escreve_string(0x89, ":");
			if(segundos < 10){
				escreve_string(0x8A, "0");
				variaveis(0x8B, segundos);
			}else{
				variaveis(0x8A, segundos);
			}
		}
	}
}
void aguagEscrita(void){
	limpar();
	escreve_string(0x80, "agua gelada  ");
	escreve_string(0xc0, "Conf.| + - |Sair");
}

void aguaqEscrita(void){
	limpar();
	escreve_string(0x80, "agua quente   ");
	escreve_string(0xc0, "Conf.| + - |Sair");
	}

void sairEscrever(void){
	limpar();
	escreve_string(0x80, "Retire a capsula");
	HAL_Delay(5000);
}

void aguanEscrita(void){
	limpar();
	escreve_string(0x80, "agua natural    ");
	escreve_string(0xc0, "Conf.| + - |Sair");
}

