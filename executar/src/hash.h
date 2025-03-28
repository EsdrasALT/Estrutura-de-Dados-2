/*
 * hash.h
 *
 *  Created on: 27 de mar. de 2025
 *      Author: 2A226844158
 */

#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <string.h>

#define M 113
#define N 20
#define VAZIO "                    \0"
#define RETIRADO "********************"

typedef char CHAVE[N + 1];

typedef struct {
    CHAVE chave;
    int quantidade;
} ITEM;

typedef ITEM DICIONARIO[M];

int h(CHAVE);

void inicializa(DICIONARIO t); // Declaração no header permanece a mesma

int pesquisa(CHAVE, DICIONARIO);

int insere(ITEM, DICIONARIO);

int retira(CHAVE, DICIONARIO);

#endif /* HASH_H_ */
