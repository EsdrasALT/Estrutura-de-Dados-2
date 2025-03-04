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
	setbuf(stdout,NULL);
	FILA fila;
	ITEM item;
	int i, y, opcao = 0;

	cria (&fila);

		do{
			printf("\nSelecione a opção:\n");
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
				enqueue(item,&fila);
				break;
			case 2:
				dequeue(&fila,&item);
				break;
			case 3:
				if(look(&fila,&item)){
					printf("Erro no examinar da fila\n");
				} else {
				printf("Elemento na frente da fila: %d\n",item.chave);
				}
				break;
			case 4:
				printf("Tamanho da fila: %d\n",tamanho(fila));
				break;
			case -1:
				break;
			default:
				printf("Opcao invalida.");
			}

		}while(opcao != -1);

	return 0;


}


