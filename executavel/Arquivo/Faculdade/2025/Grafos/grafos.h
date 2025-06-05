
#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar bool nos algoritmos

// --- Estruturas ---

typedef struct NoAdjacencia {
    int vertice;                ///< Vértice de destino da aresta.
    struct NoAdjacencia* proximo; ///< Ponteiro para o próximo nó na lista de adjacências.
} NoAdjacencia;

typedef struct Grafo {
    int num_vertices;       ///< Número total de vértices no grafo.
    NoAdjacencia** lista_adj; ///< Array de ponteiros para as listas de adjacências (um ponteiro por vértice).
    // Campos auxiliares para algoritmos (alocados dinamicamente quando necessário)
    int* visitado;          ///< Array para marcar vértices visitados (DFS, BFS, Topológico, Ciclo).
    int* pilha_recursao;    ///< Array para marcar vértices na pilha de recursão atual (Detecção de Ciclo).
    int* resultado_topologico; ///< Array para armazenar o resultado da ordenação topológica.
    int indice_topologico;  ///< Índice atual para preencher o resultado_topologico.
} Grafo;

// --- Protótipos das Funções ---

// --- Funções Básicas ---
Grafo* criar_grafo(int V);
void destruir_grafo(Grafo* grafo);
void adicionar_aresta(Grafo* grafo, int origem, int destino);

// --- Algoritmos de Percurso ---
void DFS_util(Grafo* grafo, int v, int visitado[]);
void busca_profundidade(Grafo* grafo);
void busca_largura(Grafo* grafo, int v_inicial);

// --- Ordenação Topológica ---
void ordenacao_topologica_util(Grafo* grafo, int v);
int* ordenacao_topologica(Grafo* grafo);

// --- Detecção de Ciclo ---
bool detectar_ciclo_util(Grafo* grafo, int v);
bool detectar_ciclo(Grafo* grafo);

// --- Funções Auxiliares ---
void imprimir_grafo(Grafo* grafo);

#endif // GRAFO_H

