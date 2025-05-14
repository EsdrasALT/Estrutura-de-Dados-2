#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void cria (ARVORE *arv){
	*arv = NULL;
}

int pesquisa (ITEM *x, PONT *p) {
    if (*p == NULL)
        return -1;

    if (x->nome < (*p)->item.nome)
        return pesquisa(x, &(*p)->esq);
    if (x->nome > (*p)->item.nome)
        return pesquisa(x, &(*p)->dir);

    *x = (*p)->item;
    return 0;
}

int insere (ITEM x, PONT *p) {
    if (*p == NULL) {
        *p = (PONT) malloc(sizeof(NO));
        (*p)->item = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return 0;
    }

    if (x.nome < (*p)->item.nome)
        return insere(x, &(*p)->esq);
    if (x.nome > (*p)->item.nome)
        return insere(x, &(*p)->dir);

    return -1;
}

void antecessor (PONT q, PONT *r){
	if ((*r)->dir != NULL){
		antecessor (q,&(*r)->dir);
		return;
	}
	q->item = (*r)->item;
	q = *r;
	*r = (*r)->esq;
	free(q);
}

int retira (ITEM x, PONT *p){
	PONT aux;

	if (*p == NULL)
		return -1;

	if(x.nome < (*p)->item.nome)
		return retira (x,&(*p)->esq);
	if(x.nome > (*p)->item.nome)
		return retira (x,&(*p)->dir);

	if((*p)->dir == NULL){
		aux = *p;
		*p = (*p)->esq;
		free(aux);
		return 0;
	}

	if((*p)->esq == NULL){
		aux = *p;
		*p = (*p)->dir;
		free(aux);
		return 0;
	}

	antecessor(*p,&(*p)->esq);
	return 0;
}

void percorreIn(PONT p){
	if (p!=NULL){
		percorrePre(p->esq);
		printf("%s\n", p->item.nome);
		percorrePre(p->dir);
	}
}

void percorrePre(PONT p){
	if (p!=NULL){
		printf("%s\n", p->item.nome);
		percorrePre(p->esq);
		percorrePre(p->dir);
	}
}

void percorrePos(PONT p){
	if (p!=NULL){
		percorrePos(p->esq);
		percorrePos(p->dir);
		printf("%s\n", p->item.nome);
	}
}

