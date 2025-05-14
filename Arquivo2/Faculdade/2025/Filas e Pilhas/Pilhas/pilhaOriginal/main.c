/*
 * main.c
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
	FILE *arq;
	PILHA pilha;
	ITEM item;
	int i;

	cria (&pilha);

	arq = fopen ("src/arq.txt","r");
	while (fscanf (arq,"%d",&i) != EOF){
		item.chave = i;
		if (push (item, &pilha) == -1)
			printf("Erro no compilamento de %d\n", i);
	}

	printf("Tamano da pilha %d\n", tamanho(pilha));
	if(look(&pilha, &item))
		printf("Erro no exame do topo da pilha \n");
	printf("Elemento no topo %d\n", item.chave);

	printf("Pilha: ");
	while (!pop (&pilha, &item))
		printf("%d ", item.chave);
	printf("\n");

//	Atividade 2 - analise de expressão aritimetica por pilhas
//#include <stdio.h>
//#include <stdlib.h>
//#include "biblioteca.h"
//
//int main(int argc, char *argv[]) {
//    if (argc != 2) {
//        printf("Uso: %s 'expressao_aritmetica'\n", argv[0]);
//        return 1;
//    }
//
//    const char *expressao = argv[1];
//
//    int resultado = avaliar(expressao);
//    printf("Resultado: %d\n", resultado);
//
//    return 0;
//}


	return 0;


}


