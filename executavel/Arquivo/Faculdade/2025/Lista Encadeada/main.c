/*
 * main.c
 *
 *  Created on: 22 de fev. de 2025
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (void){
	setbuf(stdout,NULL);
	FILE *arq;
	LISTA lista;
	ITEM item;
	int i;

	cria(&lista);

	vazia(lista); //Apos criar a lista, com certeza sera 1

	arq=fopen("src/arq.txt","r");
	while(fscanf(arq,"%d",&i)!=EOF){
		item.chave=i;
		if (insere(item, &lista) == -1) //Se retornar -1, então identificamos o "erro" ou uma ação esperada
			printf("Erro na insercao de %d\n",i);
	}

	imprime(lista);

	while(!vazia(lista)){ //quando for 0 acabou os itens
		printf("Digite um valor a retirar (-1 para encerrar): ");
		scanf("%d",&i);

		if(i == -1)
			break;

		if(retira(i,&lista,&item) == -1){
			printf("Elemento não existe na lista \n");
			imprime(lista);
		} else {
			printf("Elemento %d retirado da lista\n",item.chave);
			imprime(lista);
		}
	}

	return 0;
}


