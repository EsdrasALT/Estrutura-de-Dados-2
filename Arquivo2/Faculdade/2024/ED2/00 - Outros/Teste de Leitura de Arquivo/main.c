#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo = fopen("src/Arquivo.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // 2. Ler caractere por caractere
    printf("Ler caractere por caractere\n\n");
    int ch;
    while ((ch = fgetc(arquivo)) != EOF) {
        putchar(ch);
    }

    // 3. Verificar fim do arquivo
    if (feof(arquivo)) {
        printf("\nFim do arquivo alcançado.\n\n");
    }

    // 4. Ler linha por linha
    printf("Ler linha por linha\n\n");
    char linha[100];
    rewind(arquivo); // Voltar ao início do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // 5. Ler dados formatados
    printf("Ler dados formatados\n\n");
    rewind(arquivo);  // Voltar ao início do arquivo
    char nome[50];
    int idade;
    char profissao[50];
    while (fscanf(arquivo, "Nome: %[^\n]\nIdade: %d\nProfissão: %[^\n]\n", nome, &idade, profissao) != EOF) {
        printf("Nome: %s, Idade: %d, Profissão: %s\n", nome, idade, profissao);
    }

    // 6. Gravar um caractere
    fputc('\n', arquivo);

    // 7. Gravar uma string
    printf("Gravar uma string\n\n");
    rewind(arquivo);
    fseek(arquivo, 0, SEEK_END);  // Mover para o final do arquivo
    fputs("Nome: Ana Costa\nIdade: 32\nProfissão: Analista de Sistemas\n", arquivo);

    // 8. Gravar dados formatados
    printf("Gravar dados formatados\n\n");
    fprintf(arquivo, "Nome: Lucas Pereira\nIdade: 27\nProfissão: Arquiteto de Soluções\n");

    // 9. Fechar o arquivo
    fclose(arquivo);

    return 0;
}
