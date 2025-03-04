#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main(int argc, char *argv[])
{
    FILE *arquivo = fopen("src/entrada.txt", "r");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir arquivo\n");
        return 1;
    }

    MATRIZ a, b, c;

    printf("Primeiro grupo de matrizes\n");
    criaMatriz(&a); leMatriz(&a, arquivo); imprimeMatriz(&a);
    criaMatriz(&b); leMatriz(&b, arquivo); imprimeMatriz(&b);

	printf("Soma\n");
	criaMatriz(&c); somaMatriz(&a, &b, &c); imprimeMatriz(&c);

	printf("Produto\n");
	apagaMatriz(&c); multiplicaMatriz(&a, &b, &c); imprimeMatriz(&c);

	printf("Segundo grupo de matrizes\n");
	apagaMatriz(&a); apagaMatriz(&b); apagaMatriz(&c);
	leMatriz(&a, arquivo); imprimeMatriz(&a);
	leMatriz(&b, arquivo); imprimeMatriz(&b);

	printf("Soma\n");
	criaMatriz(&c); somaMatriz(&a, &b, &c); imprimeMatriz(&c);

	printf("Produto\n");
	apagaMatriz(&c); multiplicaMatriz(&a, &b, &c); imprimeMatriz(&c);

	apagaMatriz(&a); apagaMatriz(&b); apagaMatriz(&c);

    fclose(arquivo);
	return 0;
}
