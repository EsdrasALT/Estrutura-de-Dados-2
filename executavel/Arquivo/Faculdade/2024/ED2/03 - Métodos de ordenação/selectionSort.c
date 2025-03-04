#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXTAM 20

typedef long CHAVE;
typedef struct ITEM_TAG {
	CHAVE chave;
} ITEM;
typedef int INDICE;
typedef ITEM VETOR[MAXTAM];

void selecao (ITEM *vet, int tam){
	INDICE i,j,min;
	ITEM aux;

	for (i = 0; i < tam - 1; i++) {
	    min = i;
	    for (j = i; j < tam; j++) {
	        if (vet[j].chave < vet[min].chave) {
	            min = j;
	        }
	    }
	    aux = vet[min];
	    vet[min] = vet[i];
	    vet[i] = aux;
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

	for(i=tam-1; i>=0; i--){
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

	selecao(vetor,tamanho);

	printf("Vetor original\n");
	imprime(vetor,tamanho);


	return 0;
}
