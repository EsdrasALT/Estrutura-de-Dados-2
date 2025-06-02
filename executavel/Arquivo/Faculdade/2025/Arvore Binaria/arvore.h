
#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <string.h>

#define TAM_CHAR 21

typedef char CHAVE [TAM_CHAR];
typedef struct {
   CHAVE chave;
   double preco;
} ITEM;

typedef struct NO_TAG *PONT;

typedef struct NO_TAG{
	ITEM item;
	PONT esq, dir;
} NO;

typedef PONT ARVORE;

void criaArvore (ARVORE*);

int insereArvore	(ITEM,PONT*);
int pesquisaArvore	(ITEM*,PONT*);
int retiraArvore	(ITEM,PONT*);
int alterarArvore	(ITEM,PONT*);
int alturaArvore	(PONT);

void percorreInArvore(PONT);


#endif /* ARVORE_H_ */
