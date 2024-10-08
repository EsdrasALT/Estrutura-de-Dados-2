#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"  // Importa o arquivo de cabeçalho personalizado

int main() {
	setbuf(stdout,NULL);

    FILE *arquivo = fopen("src/arquivo.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    return 0;
}
