/*
 * fila.h
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#ifndef FILA_H_
#define FILA_H_

typedef struct CELULA_TAG *PONT;

typedef struct{
	int chave;
} ITEM;

typedef struct CELULA_TAG {
	ITEM item;
	PONT prox;
} CELULA;

typedef struct {
	PONT traseira,frente;
	int tamanho;
} FILA;

void cria(FILA*);
int vazia(FILA);
int enqueue(ITEM,FILA*); //Inserir (enqueue)
int dequeue(FILA*,ITEM*); //Remover(dequeue)
int look(FILA*,ITEM*);
int tamanho(FILA);


#endif /* FILA_H_ */
