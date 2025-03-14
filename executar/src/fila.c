#include "fila.h"

void cria (FILA *fila){
	fila->fim=(PONT)malloc(sizeof(CELULA));
	fila->inicio=fila->fim;
	fila->inicio->prox=NULL;
	fila->tamanho=0;
}

int vazia (FILA fila){
	return (fila.inicio==fila.fim);
}

int enqueue(ITEM item,FILA *fila){
	PONT auxiliar;

	auxiliar=(PONT)malloc(sizeof(CELULA));

	auxiliar->item=item;
	auxiliar->prox=NULL;

	fila->fim->prox = auxiliar;
	fila->fim = auxiliar;

	fila->tamanho++;

	printf("Item inserido na fila %d\n",item.chave);
	return 0;
}

int dequeue(FILA *fila,ITEM *item){
    PONT remover;
    
    if(vazia(*fila))
        return -1;
        
    remover = fila->inicio;
    fila->inicio = remover->prox;
    free(remover);
    fila->tamanho--;
    
    return 0;   
}

int look(FILA *fila,ITEM *item){
	if (vazia(*fila))
		return -1;

	*item=fila->inicio->prox->item;

	return 0;
}

void listarElementos(FILA *fila){
	PONT aux = fila->inicio->prox;
	printf("\n========FILA ATUAL===========\n");

	while(aux !=NULL){
        printf("|%d| <- ", aux->item.chave);
        aux = aux->prox;
    }
    printf("NULL\n");

}

int tamanho(FILA fila){
    return fila.tamanho;
}

