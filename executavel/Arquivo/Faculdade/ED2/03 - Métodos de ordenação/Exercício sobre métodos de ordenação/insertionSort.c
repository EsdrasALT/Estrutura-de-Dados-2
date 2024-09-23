#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXTAM 20

typedef long CHAVE;
typedef struct ITEM_TAG {
	CHAVE chave;
} ITEM;
typedef int INDICE;
typedef ITEM VETOR[MAXTAM+1];

void insercao(ITEM *vet, int tam){
	INDICE i,j;
	ITEM aux;

	for(i=1; i<tam; i++){
		aux = vet[i]; // variavel temporario p/ armazenar o elemento que sera
					  //comparado e inserido na posicao correta
		j = i-1; //ira servir para pegar o elemento a esquerda
		vet[0] = aux;
		while(aux.chave < vet[j].chave){ //
			vet[j+1] = vet[j]; //ele "copia" os elementos da esquerda p/
							   //direita ate que a condição seja while pare
			j--;
		}
		vet[j+1] = aux; //e na posição correta ele coloca o valor ordenado
	}
}

double randNumber (){
	double res = (double) rand() / INT_MAX;
	if (res > 1.0) res = 1.0;
	return res;
}

void permuta(VETOR vet, int tam){
	ITEM b;
	int i,j;

	for(i=tam-1; i>=1; i--){
		j = (i * randNumber()) + 1;
		b = vet[i];
		vet[i] = vet[j];
		vet[j] = b;
	}
}

void imprime(VETOR vet, int tam){
	int i;

	for(i=0;i<tam;i++){
		printf("%d ", vet[i].chave);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	setbuf(stdout,NULL);

	VETOR vetor;
	int tamanho = sizeof(vetor)/sizeof(ITEM);
	int i;

	for(i=0;i<tamanho;i++){
		vetor[i].chave = i; //preenchendo o vetor
	}

	permuta(vetor,tamanho);

	printf("Vetor original\n");
	imprime(vetor,tamanho);

	insercao(vetor,tamanho);

	printf("Vetor Ordendao\n");
	imprime(vetor,tamanho);


	return 0;
}
