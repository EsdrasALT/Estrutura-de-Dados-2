/*
 * LLRB.h
 *
 *  Created on: 8 de mai. de 2025
 *      Author: 2A226844158
 */

#ifndef LLRB_H_
#define LLRB_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAM_CHAR 21
#define VERMELHO true
#define PRETO false

typedef char CHAVE [TAM_CHAR];
typedef struct {
   CHAVE chave;
   double valor;
} ITEM;

typedef struct NO_TAG *PONT;

typedef struct NO_TAG{
	ITEM item;
	PONT esq, dir;
//	bool corEh;
	int corEh;
} NO;

typedef PONT ARVORE;

bool ehVermelho(ARVORE*);

void criaArvore (ARVORE*);

int insereArvore	(PONT*, ITEM*);
int pesquisaArvore	(ITEM*,PONT*);
int retiraArvore	(ITEM,PONT*);
int alterarArvore	(ITEM,PONT*);
int alturaArvore	(PONT);

void percorreInArvore(PONT);

#endif /* LLRB_H_ */
