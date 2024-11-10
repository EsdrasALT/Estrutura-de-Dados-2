#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvore.h"

int main(void){
	setbuf(stdout, NULL);

    ARVORE arvore;
    cria(&arvore);

    int opcao;
    ITEM item;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1 - Inserir um valor\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (inserir(&arvore, item) == -1)
                    printf("Erro na inserção do nó com chave %d\n", item.chave);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
    return 0;
}
