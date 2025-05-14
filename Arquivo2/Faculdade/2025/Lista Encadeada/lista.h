/*
 * listaa.h
 *
 *  Created on: 22 de fev. de 2025
 *      Author: Bless
 */

#ifndef LISTA_H_
#define LISTA_H_

typedef struct CELULA_TAG *PONT;

typedef struct {
	int chave;
} ITEM;

typedef struct CELULA_TAG{
	ITEM item;
	PONT proximo;
} CELULA;

typedef struct {
	PONT primeiro,ultimo;
} LISTA;

void cria (LISTA*);
int vazia (LISTA);
int insere (ITEM,LISTA*);
int retira (int,LISTA*,ITEM*);
void imprime (LISTA);

#endif /* LISTA_H_ */
