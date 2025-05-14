/*
 * pilha.c
 *
 *  Created on: 18 de ago. de 2024
 *      Author: Bless
 */

//Chamada de pilha ou stack
//
//Conceito de primeiro a entrar é o ultimo a sair (ou vice-versa)
//
//Inserir um elemento é chamado de PUSH
//
//Remover um elemento é chamado de POP

//Link para visualização = https://www.cs.usfca.edu/~galles/visualization/StackArray.html

#include <stdio.h>

#define TAMPILHA 10

int pilha[TAMPILHA] = {0,0,0,0,0,0,0,0,0,0};
int topo=0;

void listarElementos(){
	printf("==========Fila Atual===========\n\n");
	for (int i=0;i<TAMPILHA;i++){
		printf("____");
		printf("\n|%d|\n",pilha[i]);
		printf("¨¨¨¨\n");
	}
	printf("\nHead: %d\n",topo);
	printf("\n\n");
}

void push(){
	int val;
	printf("Informe um valor: ");
	scanf("%d", &val);
	if (topo<TAMPILHA){
		pilha[topo]=val;
		topo++;
		listarElementos();
	}else{
		printf("Pilha cheia...\n");
	}
}

void pop(){
	if (topo >= 0){
		pilha[topo-1] = 0;
		topo--;
		listarElementos();
	}else{
		printf("Pilha vazia...\n");
	}
}

void clear(){
	for(int i=0;i<TAMPILHA;i++){
		pilha[i]=0;
	}
	topo = 0;
}
int main(void){
	setbuf(stdout,NULL);

	int op;

		do{
			printf("Digite uma das opções abaixo\n");
			printf("1 - Inserir (push)\n");
			printf("2 - Remover (pop)\n");
			printf("3 - Limpar (clear)\n");
			printf("4 - Sair\n");
			printf("Opção: ");
			scanf("%d", &op);

			switch(op){
				case 1:
					push();
					break;
				case 2:
					pop();
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

}
