/*
 * fila.h
 *
 *  Created on: 11 de mar. de 2025
 *      Author: 2A226844158
 */

#ifndef FILA_H_
#define FILA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct CELULA_TAG *PONT;

typedef struct{
	int chave;
} ITEM;

typedef struct CELULA_TAG {
	ITEM item;
	PONT prox;
} CELULA;

typedef struct {
	PONT inicio; // equivale ao topo
	PONT fim; // equivale ao fundo
	int tamanho;
} FILA;

void cria(FILA*);
int vazia(FILA);
int enqueue(ITEM,FILA*); //Inserir (enqueue)
int dequeue(FILA*,ITEM*); //Remover(dequeue)
int look(FILA*,ITEM*);
int tamanho(FILA);

void listarElementos(FILA*);


#endif /* FILA_H_ */
