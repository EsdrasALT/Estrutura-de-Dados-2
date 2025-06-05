#include <stdlib.h>
#include <stdio.h>
#include "LLRB.h"

bool ehVermelho(ARVORE *arvore){
	if (arvore == NULL) return 0;
	return (arvore->corEh != NULL);
}

//public Value get(Key key)
//{
// Node x = root;
// while (x != null)
// {
// int cmp = key.compareTo(x.key);
// if (cmp == 0) return x.val;
// else if (cmp < 0) x = x.left;
// else if (cmp > 0) x = x.right;
// }
// return null;
//}
//
//public Key min()
//{
// Node x = root;
// while (x != null) x = x.left;
// if (x == null) return null;
// else return x.key;
//}


int insereArvore (PONT *arvore,ITEM *item){

    if (*arvore == NULL) {
        *arvore = (PONT) malloc(sizeof(NO));
        (*arvore)->item = item;
        (*arvore)->esq = NULL;
        (*arvore)->dir = NULL;
        return 0;
    }

    int cmp = strcmp(item->chave, (*arvore)->item.chave);
    if (cmp < 0)
        return insereArvore(item, &(*arvore)->esq);
    if (cmp > 0)
        return insereArvore(item, &(*arvore)->dir);

    return -1;
}

int rodarHorario (PONT* arvore){

	PONT aux;

	return 0;
}
