/*
 * quicksort.c
 *
 *  Created on: 10 de set. de 2024
 *      Author: 1P918
 */

#include <stdio.h>

void imprime(int *v, int tam) {
	for(int i = 0; i < tam; i++)
		printf("%02d ", v[i]);
	printf("\n");
}

void particao(int *v, int esq, int dir, int *i, int *j) {

	*i = esq;
	*j = dir;
	int pivo = v[(*i+*j)/2];
	int aux;

	do {
		while(pivo > v[*i]) (*i)++;
		while(pivo < v[*j]) (*j)--;

		if(*i <= *j) {
			aux = v[*i]; v[*i] = v[*j]; v[*j] = aux;
			(*i)++; (*j)--;
		}
	} while (*i <= *j);
}

void ordena(int *v, int esq, int dir) {

	int i, j;

	particao(v, esq, dir, &i, &j);

	if(esq < j)
		ordena(v, esq, j);

	if(i < dir)
		ordena(v, i, dir);

}

void quicksort(int *v, int tam) {
	ordena(v, 0, tam-1);
}

int main(void) {

	int vet[] = {27,13,42,7,33,89,2,4,18,77,95,1,5,38,78,45,0,93};
	int tamanho = sizeof(vet) / sizeof(int);

	imprime(vet, tamanho);

	quicksort(vet, tamanho);

	imprime(vet, tamanho);

	return 0;
}
