/*
 * lista.h
 *
 *  Created on: 22 de fev. de 2025
 *      Author: Bless
 */

#ifndef LISTA_H_
#define LISTA_H_

typedef struct CELULA_TAG *PONT;

typedef struct {
	int linha, coluna;
	double valor;
} ITEM;

typedef struct CELULA_TAG {
	ITEM item;
	PONT direita, abaixo;
} CELULA;

typedef struct {
	PONT primeiro, ultimo;
} LISTA;

void criaLista(LISTA*);

int  insereLinhaLista(LISTA*,PONT);
int  insereColunaLista(LISTA*,PONT);

void imprimeLinhaLista(LISTA*,int);

#endif /* LISTA_H_ */
