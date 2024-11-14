#include <stdio.h>
#include <stdlib.h>

// Função que vai ler e processar o arquivo
void lerArquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
        exit(1); // Sai do programa com código de erro
    }

    // Aqui, você pode adicionar o código para processar o arquivo
    printf("Arquivo '%s' aberto com sucesso.\n", nome_arquivo);

    fclose(arquivo);
}

int main(int argc, char *argv[]) {
    // Se o programa for executado sem o nome do arquivo, mostra a mensagem de ajuda
    if (argc != 2) {
        printf("Utilizacao: caminho <nome>\n\n");
        printf("<nome>: nome do arquivo contendo as informacoes do grafo\n");
        return 1; // Sai do programa com código de erro
    }

    // Nome do arquivo foi fornecido, chama a função para ler o arquivo
    lerArquivo(argv[1]);

    return 0;
}
