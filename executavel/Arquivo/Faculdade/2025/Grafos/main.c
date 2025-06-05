
#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main() {
    int V, E; // Número de vértices e arestas
    int u, v; // Vértices para ler as arestas

    // Lê o número de vértices e arestas da entrada padrão
    if (scanf("%d %d", &V, &E) != 2) {
        fprintf(stderr, "Erro ao ler número de vértices e arestas.\n");
        return 1;
    }

    if (V <= 0) {
        fprintf(stderr, "Erro: Número de vértices deve ser positivo.\n");
        return 1;
    }

    // Cria o grafo
    Grafo* grafo = criar_grafo(V);
    if (!grafo) {
        fprintf(stderr, "Erro ao criar o grafo.\n");
        return 1;
    }

    // Lê as arestas e adiciona ao grafo
    printf("Lendo %d arestas...\n", E);
    for (int i = 0; i < E; ++i) {
        if (scanf("%d %d", &u, &v) != 2) {
            fprintf(stderr, "Erro ao ler a aresta %d.\n", i + 1);
            destruir_grafo(grafo);
            return 1;
        }
        // Validação básica dos índices dos vértices
        if (u < 0 || u >= V || v < 0 || v >= V) {
             fprintf(stderr, "Erro: Vértice inválido na aresta %d (%d -> %d). Vértices devem estar entre 0 e %d.\n", i + 1, u, v, V - 1);
             destruir_grafo(grafo);
             return 1;
        }
        adicionar_aresta(grafo, u, v);
    }

    printf("\nGrafo criado com sucesso.\n");

    // 1. Detectar Ciclo
    printf("\nVerificando a existência de ciclos...\n");
    if (detectar_ciclo(grafo)) {
        printf("Resultado: O grafo contém um ciclo. Ordenação topológica não é possível.\n");
    } else {
        printf("Resultado: O grafo não contém ciclos (é um DAG).\n");

        // 2. Realizar Ordenação Topológica (somente se for DAG)
        printf("\nRealizando a ordenação topológica...\n");
        int* ordem_topologica = ordenacao_topologica(grafo);

        if (ordem_topologica) {
            printf("Ordenação Topológica: ");
            for (int i = 0; i < grafo->num_vertices; ++i) {
                printf("%d ", ordem_topologica[i]);
            }
            printf("\n");
            // Libera a memória alocada para o resultado da ordenação
            free(ordem_topologica);
        } else {
            fprintf(stderr, "Erro ao calcular a ordenação topológica (possível problema de alocação).\n");
        }
    }



    // Libera a memória do grafo
    destruir_grafo(grafo);
    printf("\nMemória do grafo liberada.\n");

    return 0;
}

