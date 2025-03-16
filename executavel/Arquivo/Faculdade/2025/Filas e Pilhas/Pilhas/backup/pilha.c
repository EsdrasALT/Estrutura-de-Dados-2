#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


void cria(PILHA *pilha){
	pilha->topo = (PONT) malloc (sizeof(CELULA));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;
}

int vazia(PILHA pilha){
	return(pilha.topo == pilha.fundo);
}

int push (ITEM x, PILHA *pilha){
	PONT aux;

	aux = (PONT) malloc (sizeof(CELULA));
	pilha->topo->item = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
	return 0;
}

int pop(PILHA *pilha, ITEM *item){
	PONT q;

	if (vazia (*pilha))
		return -1;

	q = pilha->topo;
	pilha->topo = q->prox;
	*item = q->prox->item;
	free(q);
	pilha->tamanho--;
	return 0;
}

int look (PILHA *pilha, ITEM *item){
	if(vazia(*pilha))
		return -1;

	*item = pilha->topo->prox->item;
	return 0;
}

int tamanho (PILHA pilha){
	return pilha.tamanho;
}
