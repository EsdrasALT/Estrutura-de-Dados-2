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

    ITEM pesquisa;
    strcpy(pesquisa.chave, "uva"); // Copia a string para o array
    pesquisa.quantidade=pesquisaHash(pesquisa,tabela);

    if(pesquisa.quantidade == -1){
    	printf("Item %s não existe no dicionario\n", pesquisa.chave);
    }else{
    	printf("Valor disponivel do item %s: %d",pesquisa.chave,pesquisa.quantidade);
    }

    fclose(arq);
    return 0;
}
