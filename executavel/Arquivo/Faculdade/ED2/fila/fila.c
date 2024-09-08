#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void cria(FILA *fila){
	fila->traseira = (PONT) malloc (sizeof(CELULA));
	fila->frente = fila->traseira;
	fila->traseira->prox = fila->traseira;
	fila->traseira->prox=NULL;
	fila->tamanho = 0;
}

int vazia(FILA fila){
	return(fila.traseira == fila.frente);
}

int enqueue(ITEM y,FILA *fila){
	PONT aux;

	aux = (PONT) malloc (sizeof(CELULA));
	fila->traseira->item = y;
	aux->prox = fila->traseira;
	fila->traseira = aux;
	fila->tamanho++;
	return 0;
}

int dequeue(FILA *fila,ITEM *item){
	PONT p;

	if (vazia(*fila))
		return -1;

	p = fila->traseira;
	fila->traseira = p->prox;
	*item = p->prox->item;
	free(p);
	fila->tamanho--;
	return 0;
}

int look (FILA *fila, ITEM *item){
	if(vazia(*fila))
		return -1;

	*item = fila->traseira->prox->item;
	return 0;
}

int tamanho (FILA fila){
	return fila.tamanho;
}

