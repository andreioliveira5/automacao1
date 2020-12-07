/*
 * funcoes.c
 *
 *  Created on: 30 de nov de 2020
 *      Author: andre
 */
#include "funcoes.h"


void pressostatoFiltro(void){
	presF= HAL_GPIO_ReadPin(GPIOB, P1);
}

//bebidas sem gas
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

void aquecer(int32_t temperatura){
	int8_t i, j;
	int32_t adc1, t1=0, t1f=0, erro;
	int32_t pwm = 1000, kp =18;
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
			t1=adc1;
		}
		t1 /= 4;
		t1f = t1*graus+5; //testar o maximo
		if(t1f>100)t1f = 100;
		erro = temperatura - t1f;
		if(erro > 0){
			TIM2->CCR2 = pwm+(erro*kp);
		}
		HAL_Delay(50);
	}while(t1f < temperatura);
	TIM2->CCR2 =0; //???
	aquecido = 1;
}

void resfriar(int32_t temperatura){
	int8_t i, j;
	int32_t adc2, t2, t2f, erro;
	int32_t pwm = 100, kp =2;
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
			t2=adc2;
		}
		t2 /= 4;
		t2f = t2*graus+5; //testar o maximo
		if(t2f>50)t2f = 50;
		erro = t2f - temperatura;
		if(erro > 0){
			TIM2->CCR3 = pwm+(erro*kp);
		}
		HAL_Delay(50);
	}while(t2f > temperatura);
	TIM2->CCR3 =0; //???
	aquecido = 1;
}

void calibrar (void){
	  HAL_ADCEx_Calibration_Start(&hadc1);
}

void iniciar(void){


	//Água natural em temperatura ambiente
	strcpy(capsula[0].nome, "ÁGUA");
	capsula[0].temperatura = 0;
	capsula[0].tempo = 2550; //tempo em ms com o tempo da bomba diminuido
	capsula[0].gas = 0;
	capsula[0].tipo = 0;
	capsula[0].gast =0;

	//Água natural aquecida
	strcpy(capsula[1].nome, "ÁGUA QUENTE"); // nome da bebida
	capsula[1].temperatura = 60; //temperatura desejada
	capsula[1].tempo = 2550; //tempo em ms com o tempo da bomba diminuido
	capsula[1].gas = 0; // sem gas
	capsula[1].tipo = 1; //aquecida
	capsula[1].gast =0; // sem gas

	//Água natural resfriada
	strcpy(capsula[2].nome, "ÁGUA GELADA");
	capsula[2].temperatura = 15;
	capsula[2].tempo = 2550; //tempo em ms com o tempo da bomba diminuido
	capsula[2].gas = 0; //sem gas
	capsula[2].tipo = 2; //Gelada
	capsula[2].gast =0; // sem gas

	//Água com gás
	strcpy(capsula[3].nome, "ÁGUA COM GÁS");
	capsula[3].temperatura = 15;
	capsula[3].tempo = 1050; //tempo em ms com o tempo da bomba diminuido
	capsula[3].gas = 1; //COM GAS
	capsula[3].tipo = 2; // GELADA
	capsula[3].gast =1300; //1,5 SEGUNDOS - 200 MS DA BOMBA

	//Chá gelado
	strcpy(capsula[4].nome, "CHÁ GELADO");
	capsula[4].temperatura = 20;
	capsula[4].tempo = 2250; //2,7 segundos - 450 ms da bomba
	capsula[4].gas = 0; //SEM GAS
	capsula[4].tipo = 2; // GELADA
	capsula[4].gast =0; // SEM GAS

	//Chá quente
	strcpy(capsula[5].nome, "CHÁ QUENTE");
	capsula[5].temperatura = 60;
	capsula[5].tempo = 2250; //2,7S -450 MS DA BOMBA
	capsula[5].gas = 0;
	capsula[5].tipo = 1;// QUENTE
	capsula[5].gast =0;

	//Refrigerante
	strcpy(capsula[6].nome, "REFRIGERANTE");
	capsula[6].temperatura = 17;
	capsula[6].tempo = (3550-2360); //4S - 450 MS DA BOMBA - TEMPO DO GAS
	capsula[6].gas = 0;
	capsula[6].tipo = 0;
	capsula[6].gast =2360;
}




