#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXTAM 10

typedef long CHAVE;
typedef struct ITEM_TAG {
	CHAVE chave;
} ITEM;
typedef int INDICE;
typedef ITEM VETOR[MAXTAM];


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
		printf("%ld ", vet[i].chave);
	}
	printf("\n");
}

void particao(ITEM *vet, INDICE esq, INDICE dir, INDICE *i, INDICE *j) {

	printf("========= INICIO particao()============\n\n");
	ITEM pivo,pivoInical,pivoCentral,pivoFinal,aux;
	INDICE mediaAritimetica;

	*i = esq;
	*j = dir;
	printf("Valor de *i: %d\n",*i);
	printf("Valor de *j: %d\n",*j);

	pivoInical = vet[esq];
	pivoCentral = vet[(esq+dir)/2];
	pivoFinal = vet[dir];
	mediaAritimetica = (pivoInical.chave + pivoCentral.chave + pivoFinal.chave)/3;
	printf("Media %d\n",mediaAritimetica);

	pivo = vet[(esq+dir)/2];
	printf("Pivo: %ld\n\n",pivo.chave);

	do {

		while(pivo.chave > vet[*i].chave){
			printf("1° while) %ld > %ld\n",pivo.chave,vet[*i].chave);
			(*i)++;
		}

		while(pivo.chave < vet[*j].chave){
			printf("2° while) %ld < %ld\n",pivo.chave,vet[*j].chave);
			(*j)--;
		}

		if(*i <= *j) {
			printf("if(*i <= *j)\n");
			printf("if(%d <= %d)\n\n",*i,*j);
			aux = vet[*i];
			vet[*i] = vet[*j];
			vet[*j] = aux;

			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);

	printf("========= FIM particao()============\n\n");
}

void ordena(ITEM *vet, INDICE esq, INDICE dir) { // 0, tam-1

	printf("========= INICIO ordena()============\n\n");

	INDICE i, j;

	particao(vet, esq, dir, &i, &j); // 0, tam-1

	if(esq < j){
		printf("1° if(esq < j)\n");
		printf("if(%d < %d)\n)",esq,j);
		printf("ordena(vet, esq, j)\n\n");
		ordena(vet, esq, j);
	}

	if(i < dir){
		printf("2° if(i < dir)\n");
		printf("if(%d < %d)\n)",i,dir);
		printf("ordena(vet, i, dir)\n\n");
		ordena(vet, i, dir);
	}

	printf("========= FIM ordena()============\n\n");


}

void quicksort(ITEM *vet, int tam) {
	ordena(vet, 0, tam-1);
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

	quicksort(vetor, tamanho);

	printf("Vetor original\n");
	imprime(vetor,tamanho);


	return 0;
}
