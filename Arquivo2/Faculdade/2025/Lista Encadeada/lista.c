/*
 * lista.c
 *
 *  Created on: 22 de fev. de 2025
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void cria(LISTA *lista){
	//criando o cabeçalho
	lista->primeiro=(PONT)malloc(sizeof(CELULA));
	lista->ultimo=lista->primeiro;
	lista->primeiro->proximo=NULL;

	printf("Lista criada\n"); //debug
	printf("Lista: %p\n",lista); //debug
	printf("Cabeçalho: %p\n",lista->primeiro); //debug
	printf("Ultimo: %p\n",lista->ultimo); //debug
	printf("1° celula: %p\n",lista->primeiro->proximo); //debug
	printf("Ultimo: %p\n",lista->ultimo->proximo); //debug
	printf("\n\n");
}

int vazia (LISTA lista){
	return (lista.primeiro == lista.ultimo);
}

int insere(ITEM x,LISTA * lista){
	lista->ultimo->proximo=(PONT)malloc(sizeof(CELULA));
	lista->ultimo=lista->ultimo->proximo;
	lista->ultimo->item=x;
	lista->ultimo->proximo=NULL;

	printf("Celula criada\n"); //debug
	printf("Lista: %p\n",lista); //debug
	printf("Cabeçalho: %p\n",lista->primeiro); //debug
	printf("Ultimo: %p\n",lista->ultimo); //debug
	printf("Item: %d\n",lista->ultimo->item.chave); //debug
	printf("1° celula: %p\n",lista->primeiro->proximo); //debug
	printf("Ultimo: %p\n",lista->ultimo->proximo); //debug
	printf("\n\n");

	return 0;
}

void imprime(LISTA lista){
	PONT aux;

	aux = lista.primeiro->proximo;
	while (aux != NULL){
		printf("%d\n",aux->item.chave);
		aux = aux->proximo;
	}
}

int retira (int elemento,LISTA *lista,ITEM *item){
	PONT p,q;

	p=lista->primeiro;

	while(p->proximo !=NULL){
		if(p->proximo->item.chave == elemento){

			q = p->proximo;

			*item = q->item;


			p->proximo = q->proximo;
			if (p->proximo == NULL){
				lista->ultimo = p;
			}
			printf("variavel q: %p\n\n",q);
			free(q);
			return 0;
		}
		p=p->proximo;
	}
	return -1;
}
