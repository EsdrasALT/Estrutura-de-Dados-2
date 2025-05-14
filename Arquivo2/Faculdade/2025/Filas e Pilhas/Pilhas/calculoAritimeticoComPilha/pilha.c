#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void cria(PILHA *pilha){
	pilha->topo = (PONT) malloc (sizeof(CELULA));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;
}

int push (ITEM x, PILHA *pilha){
	PONT aux;

	aux = (PONT) malloc (sizeof(CELULA));
	pilha->topo->item = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
	return 0;
}

void examinarExpressao(){

	char exp[QTDE];
	printf("Digite a sua expressão: \n");
	fgets(exp, sizeof(exp), stdin);
	printf("Expressao digitada %s", exp);

    printf("\nExpressao: %s\nRetorno: %d\n", exp, identificaFormacao(exp));

}

int identificaFormacao(char x[]){
    int i = 0;
    PILHA remover,pilha;
    ITEM item;

    cria(&pilha);

    while(x[i] != '\0'){
        if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
        	strcpy(item.caracteres, x[i]);
        	push(pilha, item);
            imprimir(pilha);
        }
        else if(x[i] == ']' || x[i] == ')' || x[i] == '}'){
//            remover = desempilhar(&pilha);
            if(forma_par(x[i], pilha.topo->item.caracteres) == 0){
                printf("\tEXPRESSAO MAL FORMADA!\n");
                return 1; // expressao está mal formada
            }
            free(remover);
        }
        i++;
    }
    imprimir(pilha);
    if(pilha){
        printf("\tExpressao mal formada!\n");
        return 1;
    }
    else{
        printf("\tEXPRESSAO BEM FORMADA!\n");
        return 0;
    }
}

void imprimir(PILHA *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%c\n", pilha->topo->item.caracteres);
        pilha = pilha->topo->prox;
    }
    printf("\tFIM PILHA\n\n");
}

int formarPar(char f, char d){
    switch(f){
    case ')':
        if(d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if(d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if(d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    }
}















int vazia(PILHA pilha){
	return(pilha.topo == pilha.fundo);
}



int pop(PILHA *pilha, ITEM *item){
	PONT q;

	if (vazia (*pilha))
		return -1;

	q = pilha->topo;
	pilha->topo = q->prox;
	*item = q->prox->item;
	free(q);
	pilha->tamanho--;
	return 0;
}

int look (PILHA *pilha, ITEM *item){
	if(vazia(*pilha))
		return -1;

	*item = pilha->topo->prox->item;
	return 0;
}

int tamanho (PILHA pilha){
	return pilha.tamanho;
}


