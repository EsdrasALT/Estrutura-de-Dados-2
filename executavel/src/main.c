#include "hash.h"

int main() {
    DICIONARIO tabela;
    inicializa(tabela);

    FILE *arq = fopen("src/arq.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    ITEM item;
    while (fscanf(arq, "%s %d", item.chave, &item.quantidade) != EOF) {
        if (inserirHash(item, tabela) == -1) {
            printf("Erro na inserção de %s\n", item.chave);
        }
    }

    imprimeHash(tabela);

    fclose(arq);
    return 0;
}
