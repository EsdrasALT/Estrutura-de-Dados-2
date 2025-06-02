
#include <stdio.h>
#include "arvore.h"

int main (void) {
	setbuf(stdout,NULL);
	ARVORE arvore;

	criaArvore(&arvore);

    FILE *arq = fopen("src/arq.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    ITEM item;
    while (fscanf(arq, "%s %lf", item.chave, &item.preco) != EOF) {
        if (insereArvore(item, &arvore) == -1) {
            printf("Erro na inserção de %s\n", item.chave);
        }
    }

    while (1) {
    	int opcao;
        printf("\n=== MENU ===\n");
        printf("1 - Inserir\n");
        printf("2 - Pesquisar\n");
        printf("3 - Remover\n");
        printf("4 - Alterar\n");
        printf("5 - Imprimir\n");
        printf("6 - Altura?\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n do buffer

        switch (opcao) {
            case 1:
                printf("Digite o nome do item: ");
                fgets(item.chave, TAM_CHAR, stdin);
                item.chave[strcspn(item.chave, "\n")] = '\0';

                printf("Digite o preco do item: ");
                scanf("%lf", &item.preco);
                getchar();

                if (insereArvore(item, &arvore) == -1)
                    printf("Item já existe.\n");
                else
                    printf("Item inserido com sucesso.\n");
                break;

            case 2:
                printf("Digite o nome do item a ser pesquisado: ");
                fgets(item.chave, TAM_CHAR, stdin);
                item.chave[strcspn(item.chave, "\n")] = '\0';

                if (pesquisaArvore(&item, &arvore) == -1)
                    printf("Item não encontrado.\n");
                else
                    printf("Item encontrado: %s %.2lf\n", item.chave, item.preco);
                break;

            case 3:
                printf("Digite o nome do item a ser removido: ");
                fgets(item.chave, TAM_CHAR, stdin);
                item.chave[strcspn(item.chave, "\n")] = '\0';

                if (retiraArvore(item, &arvore) == -1)
                    printf("Item não encontrado.\n");
                else
                    printf("Item removido com sucesso.\n");
                break;

            case 4:
                printf("Digite o nome do item a ser alterado: ");
                fgets(item.chave, TAM_CHAR, stdin);
                item.chave[strcspn(item.chave, "\n")] = '\0';

                printf("Digite o novo preco do item: ");
                scanf("%lf", &item.preco);
                getchar();

                if (alterarArvore(item, &arvore) == -1)
                    printf("Item não encontrado.\n");
                else
                    printf("Valor alterado: %s %.2lf\n", item.chave, item.preco);

                break;

            case 5:
                printf("In Ordem:\n");
                percorreInArvore(arvore);
                break;

            case 6:
            	printf("Altura da arvore: %d\n",alturaArvore(arvore));
                break;

            case 0:
                printf("Encerrando...\n");
                return 0;

            default:
                printf("Opcao invalida.\n");
        }
    }

	return 0;
}
