
#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

void criaArvore (ARVORE *arv){
    *arv = NULL;
}

int pesquisaArvore(ITEM *item, PONT *no){
    if (*no == NULL)
        return -1;

    int cmp = strcmp(item->chave, (*no)->item.chave);

    if (cmp < 0)
        return pesquisaArvore(item, &(*no)->esq);
    if (cmp > 0)
        return pesquisaArvore(item, &(*no)->dir);

    *item = (*no)->item;
    return 0;
}

int insereArvore(ITEM item, PONT *no){
    if (*no == NULL) {
        *no = (PONT) malloc(sizeof(NO));
        (*no)->item = item;
        (*no)->esq = NULL;
        (*no)->dir = NULL;
        return 0;
    }

    int cmp = strcmp(item.chave, (*no)->item.chave);
    if (cmp < 0)
        return insereArvore(item, &(*no)->esq);
    if (cmp > 0)
        return insereArvore(item, &(*no)->dir);

    return -1;
}

void antecessorArvore(PONT no, PONT *arvore){
    if ((*arvore)->dir != NULL) {
    	antecessorArvore(no, &(*arvore)->dir);
        return;
    }

    no->item = (*arvore)->item;
    no = *arvore;
    *arvore = (*arvore)->esq;
    free(no);
}

int retiraArvore(ITEM item, PONT *no){
    PONT aux;

    if (*no == NULL)
        return -1;

    int cmp = strcmp(item.chave, (*no)->item.chave);
    if (cmp < 0)
        return retiraArvore(item, &(*no)->esq);
    if (cmp > 0)
        return retiraArvore(item, &(*no)->dir);


    if ((*no)->dir == NULL) {
        aux = *no;
        *no = (*no)->esq;
        free(aux);
        return 0;
    }

    if ((*no)->esq == NULL) {
        aux = *no;
        *no = (*no)->dir;
        free(aux);
        return 0;
    }

    antecessorArvore(*no, &(*no)->esq);
    return 0;
}

int alterarArvore (ITEM item,PONT *no){
    if (*no == NULL)
        return -1;

    int cmp = strcmp(item.chave, (*no)->item.chave);

    if (cmp < 0)
        return alterarArvore(item, &(*no)->esq);
    if (cmp > 0)
        return alterarArvore(item, &(*no)->dir);

    (*no)->item = item;
    return 0;
}

int alturaArvore (PONT no){
	if(no == NULL){
		return -1;
	}
	else{
		int esq = alturaArvore(no->esq);
		int dir = alturaArvore(no->dir);
		if (esq > dir)
			return esq + 1;
		else
			return dir + 1;
	}
}

void percorreInArvore(PONT no){
    if (no != NULL) {
    	percorreInArvore(no->esq);
        printf("%s %lf\n",no->item.chave, no->item.preco);
        percorreInArvore(no->dir);
    }
}
