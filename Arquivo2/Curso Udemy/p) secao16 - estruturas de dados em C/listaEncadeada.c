#include <stdio.h>
#include <stdlib.h>

struct st_no{
	int val;
	struct st_no *proximo;
};

typedef struct st_no no;

int vazia(no *lista){
	if (lista->proximo == NULL){
		return 1;
	}else{
		return 0;
	}
}

void iniciarLista(no *lista){
	lista->proximo = NULL;

}

void liberarLista(no* lista){
	if(!vazia(lista)){
		no *proximoNo, noAtual;
		noAtual = lista->proximo;
		while(noAtual != NULL){
			proximoNo = noAtual.proximo;
			free(noAtual);
			noAtual = proximoNo;
		}
	}
}
