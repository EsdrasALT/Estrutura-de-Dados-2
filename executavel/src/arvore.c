#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arvore.h"

void cria (ARVORE *arvore){
	*arvore = NULL;
    printf("Árvore inicializada.\n");
}

bool isRed(PONT *p){
	if (*p == NULL) return 0;
	return ((*p)->item.cor == RED);
}

NO* newNode(int chave, int valor, bool cor){

	NO *novoNo = (PONT) malloc (sizeof (NO));

    if (novoNo == NULL) {
        perror("Falta de memoria");
        exit(1);
    }

    printf("Digite a chave: ");
    scanf("%d", &chave);
    printf("Digite o valor: ");
    scanf("%d", &valor);

	(*novoNo).item.chave = chave;
	(*novoNo).item.valor = valor;
	(*novoNo).item.cor = cor;
	(*novoNo).esq = NULL;
	(*novoNo).dir = NULL;

	return novoNo;
}

int compareKeys(int key1, int key2) {
    if (key1 < key2) return -1;
    if (key1 > key2) return 1;
    return 0;
}

NO* inserir(PONT* h, ITEM item){
    if (h == NULL)
        return newNode(item.chave, item.valor,RED); //TODO ajuste na inserção - valor deve vir na chamada da função na main?

    if (isRed((*h)->esq) && isRed((*h)->dir))
    	colorFlip(h);

    int cmp = compareKeys(item.chave, (*h)->item.chave);

    if (cmp == 0) {
    	(*h)->item.valor = item.valor;
    } else if (cmp < 0) {
    	(*h)->esq = inserir((*h)->esq, item);
    } else {
    	(*h)->dir = inserir((*h)->dir, item);
    }

    if (isRed((*h)->dir))
    h = rodarAEsq(h);

    if (isRed((*h)->esq) && isRed((*h)->esq->esq))
    h = rodarADir(h);

    return -1;
}

NO* rodarAEsq(PONT* h){

	NO*x=(*h)->esq;
	(*h)->dir=x->esq;
	x->esq=(*h);
	x->item.cor=x->esq->item.cor;
	x->esq->item.cor=RED;
	return x;
}

NO* rodarADir(PONT* h){

	NO*x=(*h)->dir;
	(*h)->esq=x->dir;
	x->dir=(*h);
	x->item.cor=x->dir->item.cor;
	x->dir->item.cor=RED;
	return x;
}

NO* colorFlip(PONT* h){
	(*h)->item.cor = !(*h)->item.cor;
	(*h)->esq->item.cor = !(*h)->esq->item.cor;
	(*h)->dir->item.cor = !(*h)->dir->item.cor;
	return (*h);
}


