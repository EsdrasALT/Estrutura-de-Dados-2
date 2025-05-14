/*
 * quicksort.c
 *
 *  Created on: 10 de set. de 2024
 *      Author: 1P918
 */

#include <stdio.h>

void imprime(int *vet, int tam) {
	for(int i = 0; i < tam; i++)
		printf("%02d ", vet[i]);
	printf("\n");
}

void particao(int *vet, int esq, int dir, int *i, int *j) {

	*i = esq;
	*j = dir;
	int pivo = vet[(*i+*j)/2];
	int aux;

	do {
		while(pivo > vet[*i]) (*i)++;
		while(pivo < vet[*j]) (*j)--;

		if(*i <= *j) {
			aux = vet[*i];
			vet[*i] = vet[*j];
			vet[*j] = aux;
			(*i)++; (*j)--;
		}
	} while (*i <= *j);
}

void ordena(int *vet, int esq, int dir) { // 0, tam-1

	int i, j;

	particao(vet, esq, dir, &i, &j); // 0, tam-1

	if(esq < j)
		ordena(vet, esq, j);

	if(i < dir)
		ordena(vet, i, dir);

}

void quicksort(int *vet, int tam) {
	ordena(vet, 0, tam-1);
}

int main(void) {

	int vetor[] = {27,13,42,7,33,89,2,4,18,77,95,1,5,38,78,45,0,93};
	int tamanho = sizeof(vetor) / sizeof(int);

	imprime(vetor, tamanho);

	quicksort(vetor, tamanho);

	imprime(vetor, tamanho);

	return 0;
}
