
#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>

NoAdjacencia* criar_no_adjacencia(int v) {
    NoAdjacencia* novo_no = (NoAdjacencia*) malloc(sizeof(NoAdjacencia));
    if (!novo_no) {
        perror("Erro ao alocar memória para nó de adjacência");
        return NULL;
    }
    novo_no->vertice = v;
    novo_no->proximo = NULL;
    return novo_no;
}

Grafo* criar_grafo(int V) {
    if (V <= 0) {
        fprintf(stderr, "Erro: Número de vértices deve ser positivo.\n");
        return NULL;
    }

    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    if (!grafo) {
        perror("Erro ao alocar memória para o grafo");
        return NULL;
    }

    grafo->num_vertices = V;

    // Aloca o array de ponteiros para as listas de adjacências
    grafo->lista_adj = (NoAdjacencia**) malloc(V * sizeof(NoAdjacencia*));
    if (!grafo->lista_adj) {
        perror("Erro ao alocar memória para a lista de adjacências");
        free(grafo);
        return NULL;
    }

    // Inicializa todas as listas de adjacências como vazias (NULL)
    for (int i = 0; i < V; i++) {
        grafo->lista_adj[i] = NULL;
    }

    // Inicializa campos auxiliares (serão alocados sob demanda pelos algoritmos)
    grafo->visitado = NULL;
    grafo->pilha_recursao = NULL;
    grafo->resultado_topologico = NULL;
    grafo->indice_topologico = 0;

    return grafo;
}

void destruir_grafo(Grafo* grafo) {
    if (!grafo) {
        return;
    }

    for (int i = 0; i < grafo->num_vertices; i++) {
        NoAdjacencia* atual = grafo->lista_adj[i];
        while (atual != NULL) {
            NoAdjacencia* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(grafo->lista_adj);

    // Libera memória dos arrays auxiliares se foram alocados
    if (grafo->visitado) free(grafo->visitado);
    if (grafo->pilha_recursao) free(grafo->pilha_recursao);
    if (grafo->resultado_topologico) free(grafo->resultado_topologico);

    free(grafo);
}

void adicionar_aresta(Grafo* grafo, int origem, int destino) {
    if (!grafo) {
        fprintf(stderr, "Erro: Grafo não inicializado.\n");
        return;
    }
    if (origem < 0 || origem >= grafo->num_vertices || destino < 0 || destino >= grafo->num_vertices) {
        fprintf(stderr, "Erro: Vértice de origem (%d) ou destino (%d) inválido.\n", origem, destino);
        return;
    }

    // Cria o novo nó para representar a aresta (origem -> destino)
    NoAdjacencia* novo_no = criar_no_adjacencia(destino);
    if (!novo_no) {
        // Erro já foi impresso por criar_no_adjacencia
        return; // Não adiciona a aresta se a alocação falhar
    }

    // Insere o novo nó no início da lista de adjacências do vértice de origem
    novo_no->proximo = grafo->lista_adj[origem];
    grafo->lista_adj[origem] = novo_no;
}

void imprimir_grafo(Grafo* grafo) {
    if (!grafo) {
        printf("Grafo é NULL.\n");
        return;
    }
    printf("--- Representação do Grafo (Lista de Adjacências) ---\n");
    for (int v = 0; v < grafo->num_vertices; ++v) {
        NoAdjacencia* temp = grafo->lista_adj[v];
        printf("Vértice %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertice);
            temp = temp->proximo;
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");
}


// --- Implementação da Busca em Profundidade (DFS) ---
void DFS_util(Grafo* grafo, int v, int visitado[]) {
    // Marca o vértice atual como visitado
    visitado[v] = 1;
    printf("Visitando vértice %d (DFS)\n", v);

    // Percorre todos os vértices adjacentes a este vértice
    NoAdjacencia* adj = grafo->lista_adj[v];
    while (adj != NULL) {
        int vizinho = adj->vertice;
        // Se o vizinho não foi visitado, chama DFS recursivamente para ele
        if (!visitado[vizinho]) {
            DFS_util(grafo, vizinho, visitado);
        }
        adj = adj->proximo;
    }
}

void busca_profundidade(Grafo* grafo) {
    if (!grafo) {
        fprintf(stderr, "Erro: Grafo é NULL em busca_profundidade.\n");
        return;
    }

    // Aloca memória para o array de visitados
    int* visitado = (int*) calloc(grafo->num_vertices, sizeof(int)); // Inicializa com 0
    if (!visitado) {
        perror("Erro ao alocar memória para array visitado na DFS");
        return;
    }

    printf("--- Iniciando Busca em Profundidade (DFS) ---\n");
    // Chama a função utilitária DFS para todos os vértices não visitados
    // Isso garante que todos os componentes conectados sejam visitados
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (!visitado[i]) {
            DFS_util(grafo, i, visitado);
        }
    }
    printf("--- Fim da Busca em Profundidade (DFS) ---\n");

    // Libera a memória alocada para o array de visitados
    free(visitado);
}




// --- Implementação da Busca em Largura (BFS) ---
void busca_largura(Grafo* grafo, int v_inicial) {
    if (!grafo) {
        fprintf(stderr, "Erro: Grafo é NULL em busca_largura.\n");
        return;
    }
    if (v_inicial < 0 || v_inicial >= grafo->num_vertices) {
        fprintf(stderr, "Erro: Vértice inicial (%d) inválido para BFS.\n", v_inicial);
        return;
    }

    // Aloca memória para o array de visitados (inicializa com 0)
    int* visitado = (int*) calloc(grafo->num_vertices, sizeof(int));
    if (!visitado) {
        perror("Erro ao alocar memória para array visitado na BFS");
        return;
    }

    // Cria uma fila para a BFS (implementação simples com array)
    int* fila = (int*) malloc(grafo->num_vertices * sizeof(int));
    if (!fila) {
        perror("Erro ao alocar memória para a fila na BFS");
        free(visitado);
        return;
    }
    int frente = 0, tras = 0;

    printf("--- Iniciando Busca em Largura (BFS) a partir do vértice %d ---\n", v_inicial);

    // Marca o vértice inicial como visitado e o enfileira
    visitado[v_inicial] = 1;
    fila[tras++] = v_inicial;

    // Loop principal da BFS: continua enquanto a fila não estiver vazia
    while (frente != tras) {
        // Desenfileira um vértice
        int v_atual = fila[frente++];
        printf("Visitando vértice %d (BFS)\n", v_atual);

        // Obtém todos os vizinhos do vértice desenfileirado
        NoAdjacencia* adj = grafo->lista_adj[v_atual];
        while (adj != NULL) {
            int vizinho = adj->vertice;
            // Se o vizinho não foi visitado, marca como visitado e enfileira
            if (!visitado[vizinho]) {
                visitado[vizinho] = 1;
                fila[tras++] = vizinho;
            }
            adj = adj->proximo;
        }
    }
    printf("--- Fim da Busca em Largura (BFS) ---\n");

    // Libera a memória alocada
    free(visitado);
    free(fila);
}


// --- Implementação da Ordenação Topológica (Baseada em DFS) ---
void ordenacao_topologica_util(Grafo* grafo, int v) {
    // Marca o vértice atual como visitado (estado 1: visitando/visitado)
    grafo->visitado[v] = 1;

    // Percorre todos os vizinhos do vértice atual
    NoAdjacencia* adj = grafo->lista_adj[v];
    while (adj != NULL) {
        int vizinho = adj->vertice;
        // Se o vizinho não foi visitado, chama recursivamente para ele
        if (grafo->visitado[vizinho] == 0) { // 0: não visitado
            ordenacao_topologica_util(grafo, vizinho);
        }
        // Nota: A detecção de ciclo (verificação de aresta de retorno)
        // é feita separadamente pela função detectar_ciclo.
        adj = adj->proximo;
    }

    // Após visitar todos os descendentes, insere o vértice atual
    // no início da lista de ordenação topológica (fim do array)
    grafo->resultado_topologico[grafo->indice_topologico--] = v;
}

int* ordenacao_topologica(Grafo* grafo) {
    if (!grafo) {
        fprintf(stderr, "Erro: Grafo é NULL em ordenacao_topologica.\n");
        return NULL;
    }

    // Aloca memória para o array de visitados (estado 0: não visitado)
    grafo->visitado = (int*) calloc(grafo->num_vertices, sizeof(int));
    if (!grafo->visitado) {
        perror("Erro ao alocar memória para visitado em ordenacao_topologica");
        return NULL;
    }

    // Aloca memória para o array que armazenará o resultado
    grafo->resultado_topologico = (int*) malloc(grafo->num_vertices * sizeof(int));
    if (!grafo->resultado_topologico) {
        perror("Erro ao alocar memória para resultado_topologico");
        free(grafo->visitado);
        grafo->visitado = NULL; // Garante que não será liberado de novo em destruir_grafo
        return NULL;
    }
    grafo->indice_topologico = grafo->num_vertices - 1; // Começa do fim do array

    // Chama a função utilitária recursiva para todos os vértices não visitados
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->visitado[i] == 0) {
            ordenacao_topologica_util(grafo, i);
        }
    }

    // Limpa o array visitado do grafo após o uso (boa prática)
    free(grafo->visitado);
    grafo->visitado = NULL;

    // Retorna o ponteiro para o resultado. O ponteiro no grafo é zerado
    // para que a memória não seja liberada por destruir_grafo.
    int* resultado_final = grafo->resultado_topologico;
    grafo->resultado_topologico = NULL;

    return resultado_final;
}


// --- Implementação da Detecção de Ciclo (Baseada em DFS) ---

bool detectar_ciclo_util(Grafo* grafo, int v) {
    // Marca o vértice atual como 'visitando'
    grafo->visitado[v] = 1;

    // Percorre todos os vizinhos
    NoAdjacencia* adj = grafo->lista_adj[v];
    while (adj != NULL) {
        int vizinho = adj->vertice;

        // Se o vizinho não foi visitado, chama recursivamente
        if (grafo->visitado[vizinho] == 0) {
            if (detectar_ciclo_util(grafo, vizinho)) {
                return true; // Ciclo encontrado na chamada recursiva
            }
        }
        // Se o vizinho já está na pilha de recursão ('visitando'), encontramos uma aresta de retorno
        else if (grafo->visitado[vizinho] == 1) {
            return true; // Ciclo detectado!
        }
        // Se visitado[vizinho] == 2, o vizinho já foi completamente explorado, não faz nada.

        adj = adj->proximo;
    }

    // Remove o vértice da pilha de recursão, marcando-o como 'totalmente visitado'
    grafo->visitado[v] = 2;
    return false; // Nenhum ciclo encontrado a partir deste vértice nesta DFS path
}

bool detectar_ciclo(Grafo* grafo) {
    if (!grafo) {
        fprintf(stderr, "Erro: Grafo é NULL em detectar_ciclo.\n");
        return false; // Ou algum indicativo de erro
    }

    // Aloca e inicializa o array de visitados (0: não visitado, 1: visitando, 2: visitado)
    grafo->visitado = (int*) calloc(grafo->num_vertices, sizeof(int));
    if (!grafo->visitado) {
        perror("Erro ao alocar memória para visitado em detectar_ciclo");
        return false; // Indica falha, embora um ciclo possa existir
    }

    // Chama a função utilitária recursiva para todos os vértices não visitados (estado 0)
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->visitado[i] == 0) {
            if (detectar_ciclo_util(grafo, i)) {
                // Ciclo encontrado, libera memória e retorna true
                free(grafo->visitado);
                grafo->visitado = NULL;
                return true;
            }
        }
    }

    // Nenhum ciclo encontrado após verificar todos os componentes
    free(grafo->visitado);
    grafo->visitado = NULL;
    return false;
}



