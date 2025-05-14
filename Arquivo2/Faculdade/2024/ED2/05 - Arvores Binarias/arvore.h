/*
 * biblioteca.h
 *
 *  Created on: 28 de out. de 2024
 *      Author: 2A226844158
 */

#ifndef ARVORE_H_
#define ARVORE_H_

typedef char CHAVE [21];
typedef struct {
	CHAVE nome;
	double preco;
} ITEM;

typedef struct NO_TAG *PONT;

typedef struct NO_TAG{
	ITEM item;
	PONT esq,dir;
}NO;

typedef PONT ARVORE;

void cria (ARVORE*);
int pesquisa (ITEM*,PONT*);
int insere (ITEM,PONT*);
int retira (ITEM,PONT*);
void percorreIn (PONT p);
void percorrePre (PONT p);
void percorrePos (PONT p);

#endif /* ARVORE_H_ */
