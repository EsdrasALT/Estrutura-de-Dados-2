/*
 * main.c
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
	FILE *arq;
	FILA fila;
	ITEM item;
	int i;

	cria (&fila);

	arq = fopen ("src/arq.txt","r");
	while (fscanf (arq,"%d",&i) != EOF){
		item.chave = i;
		if (enqueue (item, &fila) == -1)
			printf("Erro no compilamento de %d\n", i);
	}

	printf("Tamano da fila %d\n", tamanho(fila));
	if(look(&fila, &item))
		printf("Erro no exame do topo da fila \n");
	printf("Elemento no topo %d\n", item.chave);

	printf("Fila: ");
	while (!dequeue (&fila, &item))
		printf("%d ", item.chave);
	printf("\n");

	return 0;


}


