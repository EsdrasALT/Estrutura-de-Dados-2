#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Função para ler o arquivo e montar a matriz
int **lerArquivo(const char *nomeArquivo, int *numCidades, int *origem, int *destino) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    fscanf(arquivo, "%d %d %d", numCidades, origem, destino);

    int **matriz = (int **)malloc((*numCidades) * sizeof(int *));
    for (int i = 0; i < *numCidades; i++) {
        matriz[i] = (int *)malloc((*numCidades) * sizeof(int));
        for (int j = 0; j < *numCidades; j++) {
            matriz[i][j] = (i == j) ? 0 : INT_MAX; // Distância 0 para si mesmo, infinito para outros
        }
    }

    int cidade1, cidade2, distancia;
    while (fscanf(arquivo, "%d %d %d", &cidade1, &cidade2, &distancia) != EOF && cidade1 != -1) {
        matriz[cidade1 - 1][cidade2 - 1] = distancia;
        matriz[cidade2 - 1][cidade1 - 1] = distancia; // Grafo não direcionado
    }

    fclose(arquivo);
    return matriz;
}

// Função para liberar memória
void liberarMatriz(int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilizacao: caminho <nome>\n");
        return 1;
    }

    int numCidades, origem, destino;
    int **matriz = lerArquivo(argv[1], &numCidades, &origem, &destino);
    if (!matriz) {
        return 1;
    }

    // Exemplo: imprimir a matriz
    for (int i = 0; i < numCidades; i++) {
        for (int j = 0; j < numCidades; j++) {
            if (matriz[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    liberarMatriz(matriz, numCidades);
    return 0;
}
