/*
 * funcoes.c
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
#include "funcoes.h"

/**
 * @brief Leitura do pressostado do filtro
 *
 * Essa função lê o pino P1 onde esta ligado o pressostato do filtro de agua
 */
void pressostatoFiltro(void){
	presF= HAL_GPIO_ReadPin(GPIOB, P1);
}

/**
 * @brief Bomba de bebidas sem gás
 *
 * Essa função é responsavel por gerenciar a bomba das bebidas sem gás.
 * @param[in] tipo :Valor corespondente ao tipo de bebida que será produzida.
 */
void bomba(int8_t tipo){
	int16_t i;
	int16_t contador = 0;

		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_SET);
		for(i=0; i < 200; i++){// aceleração
			TIM2->CCR1 = contador;
			contador +=10;
			HAL_Delay(1);
		}
		HAL_Delay(capsula[tipo].tempo);
		for(i=0; i<250;i++){
			TIM2->CCR1 = contador;
			contador -=8;
			HAL_Delay(1);
		}
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_RESET);
}

/**
 * @brief Aquecimento
 *
 * Essa função é responsavel por aquecer a água para produção de bebidas quentes
 * @param[in] temperatura :Temperatura final que a bebida deve atingir.
 */
void aquecer(int32_t temperatura){
	int8_t i, j;
	int32_t adc1, t1=0, t1f=0, erro;
	int32_t pwm = 500, kp =27;
	aquecendo();
	do{
		for(i=0; i<4; i++){
			HAL_ADC_Start_DMA(&hadc1, adcData, NUMBER_OF_CONVERSION);
			while(!flag);
			flag = 1;
			adc1=0;
			for(j=0; j <NUMBER_OF_CONVERSION/2; j++){
				adc1+= adcData[i];
			}
			adc1/= (NUMBER_OF_CONVERSION/2);
			t1+=adc1;
		}
		t1 /= 4;
		t1f = t1*graus+5;
		if(t1f>100)t1f = 100;
		variaveis(0xCD, t1f);
		erro = temperatura - t1f;
		if(erro > 0){
			TIM2->CCR2 = pwm+(erro*kp);
		}
		HAL_Delay(50);
	}while(t1f < temperatura);
	TIM2->CCR2 =0; //???
}

/**
 * @brief Resfriamento
 *
 * Essa função é responsavel por resfriar a água para produção de bebidas geladas
 * @param[in] temperatura :Temperatura final que a bebida deve atingir.
 */
void resfriar(int32_t temperatura){
	int8_t i, j;
	int32_t adc2, t2, t2f, erro;
	int32_t pwm = 50, kp =4;
	resfriando();
	do{
		for(i=0; i<4; i++){
			HAL_ADC_Start_DMA(&hadc1, adcData, NUMBER_OF_CONVERSION);
			while(!flag);
			flag = 1;
			adc2=0;
			for(j=0; j <NUMBER_OF_CONVERSION/2; j++){
				adc2+= adcData[i+8];
			}
			adc2/= (NUMBER_OF_CONVERSION/2);
			t2+=adc2;
		}
		t2 /= 4;
		t2f = t2*graus+5; //testar o maximo
		if(t2f>50)t2f = 50;
		variaveis(0xCD, t2f);
		erro = t2f - temperatura;
		if(erro > 0){
			TIM2->CCR3 = pwm+(erro*kp);
		}
		HAL_Delay(50);
	}while(t2f > temperatura);
	TIM2->CCR3 =0; //
}

/**
 * @brief Calibragem do ADC
 *
 * Essa função é responsavel pela calibrassão do ADC do controlador
 */
void calibrar (void){
	  HAL_ADCEx_Calibration_Start(&hadc1);
}

/**
 * @brief Inicialização das capsulas
 *
 * Essa função é responsavel por iniciar os valores das capsulas e o timer do relogio
 */
void iniciar(void){


	//Água natural em temperatura ambiente
	strcpy(capsula[0].nome, "água");
	capsula[0].temperatura = 0;
	capsula[0].tempo = 2550; //tempo em ms com o tempo da bomba diminuido
	capsula[0].gas = 0;
	capsula[0].tipo = 0;
	capsula[0].gast =0;

	//Água natural aquecida
	strcpy(capsula[1].nome, "agua quente"); // nome da bebida
	capsula[1].temperatura = 60; //temperatura desejada
	capsula[1].tempo = 2550; //tempo em ms com o tempo da bomba diminuido
	capsula[1].gas = 0; // sem gas
	capsula[1].tipo = 1; //aquecida
	capsula[1].gast =0; // sem gas

	//Água natural resfriada
	strcpy(capsula[2].nome, "água gelada");
	capsula[2].temperatura = 15;
	capsula[2].tempo = 2550; //tempo em ms com o tempo da bomba diminuido
	capsula[2].gas = 0; //sem gas
	capsula[2].tipo = 2; //Gelada
	capsula[2].gast =0; // sem gas

	//Água com gás
	strcpy(capsula[3].nome, "água com gás");
	capsula[3].temperatura = 15;
	capsula[3].tempo = 1050; //tempo em ms com o tempo da bomba diminuido
	capsula[3].gas = 1; //COM GAS
	capsula[3].tipo = 2; // GELADA
	capsula[3].gast =1300; //1,5 SEGUNDOS - 200 MS DA BOMBA

	//Chá gelado
	strcpy(capsula[4].nome, "chá gelado");
	capsula[4].temperatura = 20;
	capsula[4].tempo = 2250; //2,7 segundos - 450 ms da bomba
	capsula[4].gas = 0; //SEM GAS
	capsula[4].tipo = 2; // GELADA
	capsula[4].gast =0; // SEM GAS

	//Chá quente
	strcpy(capsula[5].nome, "chá quente");
	capsula[5].temperatura = 60;
	capsula[5].tempo = 2250; //2,7S -450 MS DA BOMBA
	capsula[5].gas = 0;
	capsula[5].tipo = 1;// QUENTE
	capsula[5].gast =0;

	//Refrigerante
	strcpy(capsula[6].nome, "refrigerante");
	capsula[6].temperatura = 17;
	capsula[6].tempo = (3550-2360); //4S - 450 MS DA BOMBA - TEMPO DO GAS
	capsula[6].gas = 0;
	capsula[6].tipo = 2;
	capsula[6].gast =2360;
}

void pressostadoCO2(void){
	presCO2= HAL_GPIO_ReadPin(GPIOA, P2);
}

/**
 * @brief Bomba de bebidas com gás
 *
 * Essa função é responsavel por gerenciar a bomba das bebidas com gás.
 * @param[in] tipo :Valor corespondente ao tipo de bebida que será produzida.
 */
void bombaGas(int8_t tipo){
	int16_t i;
		int16_t contador = 0;
		limpar();
		misturando(tipo);
		HAL_GPIO_WritePin(GPIOA, Y4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_SET);
		for(i=0; i < 200; i++){// aceleração
			TIM2->CCR1 = contador;
			contador +=10;
			HAL_Delay(1);
		}
		HAL_Delay(capsula[tipo].gast);
		HAL_GPIO_WritePin(GPIOA, Y4, GPIO_PIN_RESET);
		HAL_Delay(capsula[tipo].tempo);

		for(i=0; i<250;i++){
			TIM2->CCR1 = contador;
			contador -=8;
			HAL_Delay(1);
		}
		HAL_GPIO_WritePin(GPIOB, SAIDA, GPIO_PIN_RESET);
	}


/**
 * @brief Botões
 *
 *
 * Essa função é responsavel pela leitura do teclado
 *
 * @retval Valores de 1 a 4 para o controle das entradas
 *
 */
uint8_t botoes(void){
	while(1){
		if(HAL_GPIO_ReadPin(GPIOA, canc)==0){
			return 1;
		}
		if(HAL_GPIO_ReadPin(GPIOA, mais)==0){
			return 2;
		}
		if(HAL_GPIO_ReadPin(GPIOA, menos)==0){
			return 3;
		}
		if(HAL_GPIO_ReadPin(GPIOA, sair)==0){
			return 4;
		}
	}
}


/**
 * @brief Leitura da capsula
 *
 * Essa função le os 3 bits para a seleção das capsulas
 */
void lerBits(void){
	int bit1Temporario, bit2Temporario, bit3Temporario;
	bit1Temporario= HAL_GPIO_ReadPin(GPIOB, Bit1);
	bit2Temporario= HAL_GPIO_ReadPin(GPIOB, Bit2);
	bit3Temporario= HAL_GPIO_ReadPin(GPIOB, Bit3);
	bn1 = bit1Temporario*4+ bit2Temporario*2+ bit3Temporario;
}


