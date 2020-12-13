/*
 * telas.c
 *
 *  Created on: 7 de dez de 2020
 *      Author: andre
 */
#include "telas.h"

/**
 * @brief Display: Aquecendo
 *
 * Essa função é responsavel por mostrar no display quando o controlador está aquecendo e inicia a temperatura
 */
void aquecendo(void){
	limpar();
	escreve_string(0x80, "Aquecendo...");
	escreve_string(0xC0, "Temp. atual: 0");
}
/**
 * @brief Display: Resfriando
 *
 * Essa função é responsavel por mostrar no display quando o controlador está resfriando e inicia a temperatura
 */
void resfriando(void){
	limpar();
	escreve_string(0x80, "Resfriando...");
	escreve_string(0xC0, "Temp. atual:0");

}


/**
 * @brief Display: Temperatura da agua
 *
 * Essa função é responsavel pelo menu de escolha da temperatura da água sem gás.
 */
void menuAgua(void){
	int8_t valor, aux2;
	limpar();
	escreve_string(0x80, "Natural");
	escreve_string(0xc0, "Conf.| + - |Sair");
	aux2=0;
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

/**
 * @brief Display: Misturando CO2
 *
 * Essa função  mostra no display quando uma bebida de co2 está sendo produzida
 *
 * @param[in] num :Recebe o tipo da bomba para printar o nome da bebida no display
 */
void misturando(uint8_t num){
	limpar();
	escreve_string(0x80, "Misturando gás");
	escreve_string(0xc0, capsula[num].nome);
}

/**
 * @brief Display: Confirmação
 *
 * Essa função printa no display a fungiruação de confirmação dos botões.
 */
void confirmacao(void){
	escreve_string(0xc0, " Conf=C | Sair=S");
}

/**
 * @ brief Dsiplay: Capsula detectada
 *
 * Essa função é reponsavel por mostrar no display a bebida que foi selecionado por meio da leitura das capsulas
 * Alem de chamas as funções de menu para escolha da agua e conformação por meio do teclado
 * Também chama as funções de cada bebida se for o caso.
 *
 * @param[in] tipo :O numero correspondente do tipo da bebida, 1 agua, 2 agua com gas, 3 chá gelado, 4 cha quente, 5 refrigerante
 */
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
			sairEscrever();
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

		valor=botoes();

		if(valor == 1){
			aguaComGas();
		}else if(valor==4){
			sairEscrever();
		}else{
			valor = botoes();
		}
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

		valor = botoes();

		if(valor == 1){
			chaGelado();
		}else if(valor==4){
			sairEscrever();
		}else{
			valor = botoes();
		}
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


		valor = botoes();

		if(valor == 1){
			chaQuente();
		}else if(valor==4){
			sairEscrever();
		}else{
			valor = botoes();
		}
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


		valor = botoes();

		if(valor == 1){
			refrigerante();
		}else if(valor==4){
			sairEscrever();
		}else{
			valor = botoes();
		}
		break;
	default:
		limpar();
		escreve_string(0x80, "Capsula vazia");
		HAL_Delay(5000);
		limpar();
		relogio();
		break;
	}
}

/**
 * @brief Display: Filtro Saturado
 *
 * Essa função mostra quando o filtro de agua está saturado
 */
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

/**
 * @brief Display: CO2 Vazio
 *
 * Essa função mostra quando o o cilindro de CO2 está vazio
 */
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

/**
 * @brief Display: Bebida pronta/
 *
 * Essa função mostra quando a bebida está pronta.
 */
void final(void){
	limpar();
	escreve_string(0x80, "Sua bebida esta");
	escreve_string(0xc5, "pronta!");
	HAL_Delay(5000);
	limpar();
	relogio();
}

/**
 * @brief Display: Relogio
 * Esssa função é responsavel por mostrar o relogio no display alem de testar os valor do Bn1 para saber quando uma capsula foi inserida.
 *
 */
void relogio(void){
	while (1){
		lerBits();
		if(bn1 >= 1){
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
			escreve_string(0x8C, "    ");
		}
	}
}

/**
 * @brief Display: Agua gelada
 *
 * Essa função é chamada pelo menu de agua para escrever agua gelada no display
 */
void aguagEscrita(void){
	limpar();
	escreve_string(0x80, "agua gelada  ");
	escreve_string(0xc0, "Conf.| + - |Sair");
}
/**
 * @brief Display: Agua quente
 *
 * Essa função é chamada pelo menu de agua para escrever agua quente no display
 */
void aguaqEscrita(void){
	limpar();
	escreve_string(0x80, "agua quente   ");
	escreve_string(0xc0, "Conf.| + - |Sair");
	}

/**
 * @brief Cancelar
 *
 * Essa função avisa o usuario para tirar a capsula quando cancelar a produção do liquido.
 */
void sairEscrever(void){
	limpar();
	escreve_string(0x80, "Retire a capsula");
	HAL_Delay(5000);
	limpar();
}
/**
 * @brief Display: Agua natural
 *
 * Essa função é chamada pelo menu de agua para escrever agua natural(em temperatura ambiente) no display
 */
void aguanEscrita(void){
	limpar();
	escreve_string(0x80, "agua natural    ");
	escreve_string(0xc0, "Conf.| + - |Sair");
}

