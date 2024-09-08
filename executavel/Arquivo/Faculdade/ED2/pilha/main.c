/*
 * main.c
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
	FILE *arq;
	PILHA pilha;
	ITEM item;
	int i;

	cria (&pilha);

	arq = fopen ("src/arq.txt","r");
	while (fscanf (arq,"%d",&i) != EOF){
		item.chave = i;
		if (push (item, &pilha) == -1)
			printf("Erro no compilamento de %d\n", i);
	}

	printf("Tamano da pilha %d\n", tamanho(pilha));
	if(look(&pilha, &item))
		printf("Erro no exame do topo da pilha \n");
	printf("Elemento no topo %d\n", item.chave);

	printf("Pilha: ");
	while (!pop (&pilha, &item))
		printf("%d ", item.chave);
	printf("\n");

	return 0;


}


