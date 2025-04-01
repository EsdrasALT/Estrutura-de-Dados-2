#include "hash.h"

void cria(LISTA *lista){
	//criando o cabeçalho
	lista->primeiro=(PONT)malloc(sizeof(CELULA));
	lista->ultimo=lista->primeiro;
	lista->primeiro->proximo=NULL;

    strncpy(lista->ultimo->item.chave, VAZIO, TAM_CHAVE + 1);
    lista->ultimo->item.chave[TAM_CHAVE + 1] = '\0';
}

void inicializa(DICIONARIO dicionario) {
    for (int i = 0; i < TAM_VETOR; i++) {
    	cria(&dicionario[i]);
    }
}

int calcularChaveHash(CHAVE chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return (soma % TAM_VETOR);
}

int inserirHash(ITEM item, DICIONARIO dicionario) {
    int i, inicial;

    inicial = calcularChaveHash(item.chave);
    i = 0;
    while ((strncmp(dicionario[(inicial + i) % TAM_VETOR].ultimo->item.chave, VAZIO, TAM_CHAVE) != 0) &&
    	  (strncmp(dicionario[(inicial + i) % TAM_VETOR].ultimo->item.chave, RETIRADO, TAM_CHAVE) != 0) &&
          (i < TAM_VETOR))
        i++;
    if (i < TAM_VETOR) {
    	inserirLista(item,&dicionario[(inicial+i) % TAM_VETOR]);
    	return 0;
    } else {
        return -1;
    }
}

int inserirLista(ITEM item,LISTA *lista){
	lista->ultimo->proximo=(PONT)malloc(sizeof(CELULA));

	lista->ultimo=lista->ultimo->proximo;
	lista->ultimo->item=item;
	lista->ultimo->proximo=NULL;

	return 0;
}

int pesquisaHash(ITEM item, DICIONARIO dicionario){
    int i, inicial;

    inicial = calcularChaveHash(item.chave);
    i = 0;
    while (dicionario[(inicial + i) % TAM_VETOR].ultimo != NULL &&
    	  strncmp(dicionario[(inicial + i) % TAM_VETOR].ultimo->item.chave, VAZIO, TAM_CHAVE) != 0 &&
    	  strncmp(dicionario[(inicial + i) % TAM_VETOR].ultimo->item.chave, item.chave, TAM_CHAVE) != 0 &&
          (i < TAM_VETOR))
        i++;

    if (dicionario[(inicial + i) % TAM_VETOR].ultimo != NULL &&
        strncmp(dicionario[(inicial + i) % TAM_VETOR].ultimo->item.chave, item.chave, TAM_CHAVE) == 0) {
    	return pesquisaLista(item,&dicionario[(inicial+i) % TAM_VETOR]);
    } else {
        return -1;
    }
}

int pesquisaLista(ITEM item, LISTA *lista){
	PONT aux = lista->primeiro->proximo;
	while (aux != NULL){
		if(strncmp(aux->item.chave, item.chave, TAM_CHAVE) == 0){
			return aux->item.quantidade;
		}
		aux = aux->proximo;
	}
	return -1;
}


void imprimeHash(DICIONARIO dicionario) {
    for (int i = 0; i < TAM_VETOR; i++) {
        imprimeLista(dicionario[i]);
        if (dicionario[i].primeiro->proximo == NULL) {
            printf("Lista na posição %d está vazia.\n", i);
        }
    }
}

void imprimeLista(LISTA lista){
	PONT aux;

	aux = lista.primeiro->proximo;
	while (aux != NULL){
		printf("%s\n",aux->item.chave);
		aux = aux->proximo;
	}
}

