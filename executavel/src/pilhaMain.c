#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s 'expressao_aritmetica'\n", argv[0]);
        return 1;
    }

    const char *expressao = argv[1];

    int resultado = avaliar(expressao);
    printf("Resultado: %d\n", resultado);

    return 0;
}
