/*
============================================================================
Name        : executar.c
Author      : 
Version     :
Copyright   : Your copyright notice
Description : Hello World in C, Ansi-style
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void) {

	FILA fila;
	ITEM item;

	cria(&fila);

	for (int i=0;i<50;i=i+10){
		item.chave = i;
		if(enqueue(item,&fila)){
			printf("Erro na inserção %d\n",i);
		}
		listarElementos(&fila);
	}
	
	while (!dequeue(&fila,&item)){
        printf("\nTamanho da fila: %d\n", tamanho(fila));   
        if(look(&fila,&item))   
            printf("Erro no exame do elemento da fila\n");
        printf("Elemento no inicio da fila: %d\n",item.chave);
	    listarElementos(&fila);
	}

	return 0;
}
