/*
 * matriz.h
 *
 *  Created on: 22 de fev. de 2025
 *      Author: Bless
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#define TAM_BUFFER 255
#define NULO 0

#include "lista.h"

typedef struct {
	int nLinhas, nColunas;
	LISTA *linhas;
	LISTA *coluna;
} MATRIZ;

void criaMatriz(MATRIZ*);
void leMatriz(MATRIZ*,FILE*);
	void inicializaMatriz(MATRIZ*,int,int);
	void insereMatriz(MATRIZ*,int,int,double);
void imprimeMatriz(MATRIZ*);

void somaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
void multiplicaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
	double obterElementoPeloIndice(MATRIZ*,int,int);

void apagaMatriz(MATRIZ*);
int  vaziaMatriz(MATRIZ*);


#endif /* MATRIZ_H_ */
