/*
 ============================================================================
 Name        : arvoreBinaria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "arvore.h"

int main(void) {
	setbuf(stdout,NULL);
	FILE *arq;
	ARVORE arv;
	ITEM item;
	int i;

	cria(&arv);
	arq = fopen ("arq.txt", "r");
	while (fscanf(arq,"%d",&i) != EOF){
		item.preco = i;
		if (insere (item, &arv) == -1)
			printf("Erro na insercao de %d\n",i);
	}

	printf("Pre ordem:\n");
	percorrePre(arv);

	printf("Pos ordem:\n");
	percorrePos(arv);

	printf("In ordem:\n");
	percorreIn(arv);

	while(1){
		printf("Favor informar o item a retirar: ");
		scanf("%c",&item.nome);

		if (item.nome == -1)
			break;

		if (retira (item,&arv) == -1){
			printf("Elemento não existe na arvore\n");
		} else {
			printf("Elemento retirado da arvore\n");
			percorreIn(arv);
		}
	}

	return 0;
}
