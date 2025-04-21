#ifndef HASH_H_
#define HASH_H_

//declarações de inclusão
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declarações de definiçoes
#define TAM_CHAVE 20
#define TAM_VETOR 113
#define VAZIO "____________________"
#define RETIRADO "********************"

//declarações estruturas
typedef struct CELULA_TAG *PONT;
typedef char CHAVE[TAM_CHAVE + 1];

typedef struct {
    CHAVE chave;
    int quantidade;
} ITEM;

typedef struct CELULA_TAG {
    ITEM item;
    PONT proximo;
} CELULA;

typedef struct {
    PONT primeiro, ultimo;
} LISTA;

typedef LISTA DICIONARIO[TAM_VETOR];

//declarações prototipos
void inicializa(DICIONARIO);
void cria(LISTA*);

//int vazia(LISTA);

int calcularChaveHash(CHAVE);

int inserirHash(ITEM, DICIONARIO);
int inserirLista(ITEM, LISTA*);

int pesquisaHash(ITEM, DICIONARIO);
int pesquisaLista(ITEM, LISTA*);

void imprimeHash(DICIONARIO);
void imprimeLista(LISTA);

int retira(int, LISTA*, ITEM*);




int retira_hash(int, DICIONARIO);

#endif /* HASH_H_ */
