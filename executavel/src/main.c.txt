/*
 * main.c
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
	FILE *arq;
	FILA fila;
	ITEM item;
	int i, y, opcao = 0;

	cria (&fila);

//	arq = fopen ("src/arq.txt","r");
//	while (fscanf (arq,"%d",&i) != EOF){
//		item.chave = i;
//		if (enqueue (item, &fila) == -1)
//			printf("Erro no compilamento de %d\n", i);
//	}
//
//	printf("Tamano da fila %d\n", tamanho(fila));
//	if(look(&fila, &item))
//		printf("Erro no exame do topo da fila \n");
//	printf("Elemento no topo %d\n", item.chave);
//
//	printf("Fila: ");
//	while (!dequeue (&fila, &item))
//		printf("%d ", item.chave);
//	printf("\n");

		do{
			printf("Selecione a opção: \n\n");
			printf("[1] - Inserir (enqueue): \n");
			printf("[2] - Remover (dequeue): \n");
			printf("[3] - Olhar o primeiro elemento: \n");
			printf("[4] - Tamanho da Fila: \n");
			printf("[-1] - Sair. \n");
			printf("OpÃ§Ã£o: ");
			scanf("%d", &opcao);

			switch(opcao){
			case 1:
				printf("Informe o elemento para adicionar na fila: ");
				scanf("%d", &item.chave);
				enqueue(item,fila);
				break;
			case 2:
				int dequeue(FILA*,ITEM*); //Remover(dequeue)

				dequeue(fila,item);
				break;
			case 3:
				look();
				break;
			case 4:
				tamanho();
				break;
			case -1:
				break;
			default:
				printf("Opcao invalida.");
			}

		}while(opcao != -1);

	return 0;


}


