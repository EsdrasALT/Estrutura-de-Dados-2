/*
 ============================================================================
 Name        : executavel.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Fila ou Queue
//
//enqueue() = adiciona um elemento na fila
//dequeue() = remove o elemento da fila
//clear() = limpa a fila
//
//head = o primeiro da fila
//tail = quantos tem na fila

//Link para visualização = https://www.cs.usfca.edu/~galles/visualization/QueueArray.html

#include <stdio.h>

#define TAMFILA 10

int fila[TAMFILA] = {0,0,0,0,0,0,0,0,0,0};
int head = 0; // proximo a ser atendido
int tail = 0; // ultimo da fila

void listarElementos(){
	printf("==========Fila Atual===========\n\n");
	for (int i=0;i<TAMFILA;i++){
		printf("-");
		printf("|%d|",fila[i]);
		printf("-");
	}
	printf("\nHead: %d\n",head);
	printf("Tail: %d\n", tail);
	printf("\n\n");
}

void enqueue(){
	int val;
	if (tail < TAMFILA){
		printf("Informe o elemento que sera adicionado na cauda: ");
		scanf("%d", &val);
		fila[tail] = val;
		tail++;
		listarElementos();
	}else{
		printf("A fila esta cheia..\n");
	}
}

void dequeue(){
	if (head < tail){
		fila[head] = 0;
		head++;
		listarElementos();
	}else{
		printf("A fila esta vazia...\n");
	}
}

void clear(){
	for (int i=0;i<TAMFILA;i++){
		fila[i] = 0;
	}
	head = 0;
	tail = 0;
	listarElementos();
	printf("Lista limpa\n");
}

int main(void) {
	setbuf(stdout,NULL);

	int op;

	do{
		printf("Digite uma das opções abaixo\n");
		printf("1 - Inserir (enqueue)\n");
		printf("2 - Remover (dequeue)\n");
		printf("3 - Limpar (clear)\n");
		printf("4 - Sair\n");
		printf("Opção: ");
		scanf("%d", &op);

		switch(op){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				clear();
				break;
			case 4:
				printf("Saindo...");
				op = 0;
				break;
			default:
				printf("Opcao invalida");
				break;
		}
	}while(op);

	return 0;
}
