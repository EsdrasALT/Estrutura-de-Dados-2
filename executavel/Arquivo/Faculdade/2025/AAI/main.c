// Aluno: [Esdras Altivo Batista Corrêa]
// Turma: 4NA
// Professor: FlÃ¡vio Velloso Laper
// Atividade Auto-instrucional - Estruturas de Dados II - Maio de 2025

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITO INT_MAX

// Estrutura para armazenar informaÃ§Ãµes de um nÃ³ no algoritmo de Dijkstra
typedef struct {
    int distancia;
    int predecessor;
    int permanente; // 0 para temporÃ¡rio, 1 para permanente
} NoInfo;

// FunÃ§Ã£o para imprimir a mensagem de utilizaÃ§Ã£o
void imprimir_uso() {
    printf("Utilizacao: caminho <nome>\n");
    printf("<nome>: nome do arquivo contendo as informacoes do grafo\n");
}

// FunÃ§Ã£o para liberar a memÃ³ria alocada
void liberar_memoria(int num_cidades, int **matriz_dist, NoInfo *info_nos, int *caminho) {
    if (matriz_dist) {
        for (int i = 0; i < num_cidades; i++) {
            if (matriz_dist[i]) {
                free(matriz_dist[i]);
            }
        }
        free(matriz_dist);
    }
    if (info_nos) {
        free(info_nos);
    }
    if (caminho) {
        free(caminho);
    }
}

int main(int argc, char *argv[]) {
    // 1. Verificar argumentos de linha de comando
    if (argc != 2) {
        imprimir_uso();
        return 1;
    }

    char *nome_arquivo = argv[1];
    FILE *arquivo;
    int num_cidades, origem, destino;
    int **matriz_dist = NULL; // Matriz de adjacÃªncias (distÃ¢ncias)
    NoInfo *info_nos = NULL;  // InformaÃ§Ãµes para Dijkstra (distÃ¢ncia, predecessor, estado)
    int *caminho = NULL;      // Para armazenar o caminho encontrado

    // 2. Abrir e ler o arquivo do grafo
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo '%s'\n", nome_arquivo);
        imprimir_uso();
        return 1;
    }

    // Ler a primeira linha: nÃºmero de cidades, origem, destino
    if (fscanf(arquivo, "%d %d %d", &num_cidades, &origem, &destino) != 3) {
        fprintf(stderr, "Erro: Formato invalido na primeira linha do arquivo '%s'\n", nome_arquivo);
        fclose(arquivo);
        imprimir_uso();
        return 1;
    }

    // Validar origem e destino (considerando cidades numeradas de 1 a num_cidades)
    if (num_cidades <= 0 || origem < 1 || origem > num_cidades || destino < 1 || destino > num_cidades) {
        fprintf(stderr, "Erro: Numero de cidades, origem ou destino invalidos no arquivo '%s'\n", nome_arquivo);
        fclose(arquivo);
        return 1;
    }

    // Ajustar origem e destino para Ã­ndice 0
    origem--;
    destino--;

    // 3. Alocar memÃ³ria dinamicamente
    // Alocar matriz de distÃ¢ncias
    matriz_dist = (int **)malloc(num_cidades * sizeof(int *));
    if (matriz_dist == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria para matriz de distancias (linhas)\n");
        fclose(arquivo);
        return 1;
    }
    for (int i = 0; i < num_cidades; i++) {
        matriz_dist[i] = (int *)malloc(num_cidades * sizeof(int));
        if (matriz_dist[i] == NULL) {
            fprintf(stderr, "Erro: Falha na alocacao de memoria para matriz de distancias (colunas)\n");
            liberar_memoria(i, matriz_dist, NULL, NULL); // Libera o que foi alocado atÃ© agora
            fclose(arquivo);
            return 1;
        }
        // Inicializar matriz com INFINITO e 0 na diagonal principal
        for (int j = 0; j < num_cidades; j++) {
            matriz_dist[i][j] = (i == j) ? 0 : INFINITO;
        }
    }

    // Alocar vetor de informaÃ§Ãµes dos nÃ³s para Dijkstra
    info_nos = (NoInfo *)malloc(num_cidades * sizeof(NoInfo));
    if (info_nos == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria para informacoes dos nos\n");
        liberar_memoria(num_cidades, matriz_dist, NULL, NULL);
        fclose(arquivo);
        return 1;
    }

    // Alocar vetor para armazenar o caminho
    caminho = (int *)malloc(num_cidades * sizeof(int));
    if (caminho == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria para o caminho\n");
        liberar_memoria(num_cidades, matriz_dist, info_nos, NULL);
        fclose(arquivo);
        return 1;
    }

    // Ler as arestas do arquivo e preencher a matriz de distÃ¢ncias
    int cidade1, cidade2, dist;
    while (fscanf(arquivo, "%d %d %d", &cidade1, &cidade2, &dist) == 3) {
        if (cidade1 == -1 && cidade2 == -1 && dist == -1) {
            break; // Fim do arquivo
        }
        // Validar cidades e distÃ¢ncia
        if (cidade1 < 1 || cidade1 > num_cidades || cidade2 < 1 || cidade2 > num_cidades || dist < 0) {
            fprintf(stderr, "Erro: Informacao de aresta invalida no arquivo '%s' (%d %d %d)\n", nome_arquivo, cidade1, cidade2, dist);
            liberar_memoria(num_cidades, matriz_dist, info_nos, caminho);
            fclose(arquivo);
            return 1;
        }
        // Ajustar para Ã­ndice 0 e preencher matriz (grafo nÃ£o direcionado)
        matriz_dist[cidade1 - 1][cidade2 - 1] = dist;
        matriz_dist[cidade2 - 1][cidade1 - 1] = dist;
    }
    fclose(arquivo);

    // 4. Implementar o Algoritmo de Dijkstra
    // InicializaÃ§Ã£o
    for (int i = 0; i < num_cidades; i++) {
        info_nos[i].distancia = INFINITO;
        info_nos[i].predecessor = -1;
        info_nos[i].permanente = 0;
    }
    info_nos[origem].distancia = 0;

    int no_atual = origem;
    while (no_atual != -1) {
        info_nos[no_atual].permanente = 1; // Tornar o nÃ³ atual permanente

        // Se o nÃ³ atual for o destino, podemos parar (otimizaÃ§Ã£o)
        if (no_atual == destino) {
            break;
        }

        // Atualizar distÃ¢ncias dos vizinhos nÃ£o permanentes
        for (int vizinho = 0; vizinho < num_cidades; vizinho++) {
            if (!info_nos[vizinho].permanente && matriz_dist[no_atual][vizinho] != INFINITO) {
                int nova_dist = info_nos[no_atual].distancia + matriz_dist[no_atual][vizinho];
                if (nova_dist < info_nos[vizinho].distancia) {
                    info_nos[vizinho].distancia = nova_dist;
                    info_nos[vizinho].predecessor = no_atual;
                }
            }
        }

        // Encontrar o prÃ³ximo nÃ³ com a menor distÃ¢ncia temporÃ¡ria
        int menor_dist = INFINITO;
        no_atual = -1;
        for (int i = 0; i < num_cidades; i++) {
            if (!info_nos[i].permanente && info_nos[i].distancia < menor_dist) {
                menor_dist = info_nos[i].distancia;
                no_atual = i;
            }
        }
    }

    // 5. Verificar se existe caminho e construir a saÃ­da
    printf("Caminho de %d para %d: ", origem + 1, destino + 1);

    if (info_nos[destino].distancia == INFINITO) {
        // Liberar memÃ³ria antes de imprimir a mensagem de erro especÃ­fica
        // para evitar vazamentos caso a impressÃ£o falhe ou o programa termine aqui.
        // No entanto, a especificaÃ§Ã£o pede para imprimir a mensagem e encerrar,
        // entÃ£o vamos seguir a especificaÃ§Ã£o, mas idealmente a liberaÃ§Ã£o seria feita.
        // liberar_memoria(num_cidades, matriz_dist, info_nos, caminho);
        printf("\nNao existe caminho de %d para %d\n", origem + 1, destino + 1);
    } else {
        // Reconstruir o caminho do destino para a origem
        int count = 0;
        int temp = destino;
        while (temp != -1) {
            if (count >= num_cidades) { // SeguranÃ§a contra loops inesperados
                 fprintf(stderr, "\nErro: Loop detectado ao reconstruir caminho.\n");
                 liberar_memoria(num_cidades, matriz_dist, info_nos, caminho);
                 return 1; // Indica um erro interno
            }
            caminho[count++] = temp;
            temp = info_nos[temp].predecessor;
        }

        // Imprimir o caminho na ordem correta (origem para destino)
        for (int i = count - 1; i >= 0; i--) {
            int cidade_atual = caminho[i];
            printf("%d(%d) ", cidade_atual + 1, info_nos[cidade_atual].distancia);
        }
        printf("\n");
    }

    // 6. Liberar memÃ³ria alocada
    liberar_memoria(num_cidades, matriz_dist, info_nos, caminho);

    return 0; // Sucesso
}


