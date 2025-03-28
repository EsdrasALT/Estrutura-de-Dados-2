/*
 * hash.c
 *
 *  Created on: 27 de mar. de 2025
 *      Author: 2A226844158
 */

#include "hash.h"

int h(CHAVE chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return (soma % M);
}

void inicializa(DICIONARIO t) {
    for (int i = 0; i < M; i++) {
        strcpy(t[i].chave, VAZIO);
        t[i].quantidade = 0;
    }
}

int pesquisa(CHAVE ch, DICIONARIO t) {
    int inicial = h(ch);
    for (int i = 0; i < M; i++) {
        int indice = (inicial + i) % M;
        if (strcmp(t[indice].chave, ch) == 0) {
            return indice;
        }
        if (strcmp(t[indice].chave, VAZIO) == 0) {
            return -1; // Chave não encontrada
        }
    }
    return -1; // Chave não encontrada
}

int insere(ITEM x, DICIONARIO t) {
    int i, inicial;

    inicial = h(x.chave);
    i = 0;
    while ((strcmp(t[(inicial + i) % M].chave, VAZIO) != 0) &&
           (strcmp(t[(inicial + i) % M].chave, RETIRADO) != 0) &&
           (i < M))
        i++;
    if (i < M) {
        t[(inicial + i) % M] = x;
        return ((inicial + i) % M);
    } else {
        return -1;
    }
}

int retira(CHAVE ch, DICIONARIO t) {
    int i;
    i = pesquisa(ch, t);
    if (i != -1) {
        memcpy(t[i].chave, RETIRADO, sizeof(CHAVE));
        return 0;
    } else {
        return -1;
    }
}
