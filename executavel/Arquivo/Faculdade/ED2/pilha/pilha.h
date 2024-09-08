/*
 * pilha.h
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#ifndef PILHA_H_
#define PILHA_H_

typedef struct CELULA_TAG *PONT;

typedef struct{
	int chave;
} ITEM;

typedef struct CELULA_TAG {
	ITEM item;
	PONT prox;
} CELULA;

typedef struct {
	PONT fundo,topo;
	int tamanho;
} PILHA;

void cria(PILHA*);
int vazia(PILHA);
int push(ITEM,PILHA*); //Inserir (push)
int pop(PILHA*,ITEM*); //remover (pop)
int look(PILHA*,ITEM*);
int tamanho(PILHA);

#endif /* PILHA_H_ */
