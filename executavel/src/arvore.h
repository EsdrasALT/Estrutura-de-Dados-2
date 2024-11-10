#if !defined (ARVORE_H)
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RED 1
#define BLACK 0

typedef struct {
    int chave;
    int valor;
    bool cor;
}ITEM;

typedef struct NO_TAG *PONT;

typedef struct NO_TAG{
    ITEM item;
    PONT esq,dir;
}NO;

typedef PONT ARVORE;

void cria (ARVORE*);

bool isRed(PONT *p);
NO* newNode(int chave, int valor, bool cor);
int compareKeys(int key1, int key2);
NO* inserir(PONT* h, ITEM item);
NO* rodarAEsq(PONT* h);
NO* rodarADir(PONT* h);
NO* colorFlip(PONT* h);

#endif /* ARVORE_H */
