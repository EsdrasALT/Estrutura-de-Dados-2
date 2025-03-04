#include <stdio.h>
#include "arvore_updated.h"

int main() {
    No* raiz = NULL;

    // Inserindo elementos na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 13);
    raiz = inserir(raiz, 17);

    printf("Árvore em ordem antes da remoção lógica:\n");
    imprimirArvore(raiz);
    printf("\n");

    // Removendo elementos logicamente
    removerLogico(raiz, 5);
    removerLogico(raiz, 15);

    printf("Árvore em ordem após a remoção lógica:\n");
    imprimirArvore(raiz);
    printf("\n");

    // Criando uma nova árvore sem os nós removidos logicamente
    No* novaRaiz = refreshTree(raiz);

    printf("Nova árvore após o refresh (excluindo nós removidos):\n");
    imprimirArvore(novaRaiz);
    printf("\n");

    // Liberando memória das árvores
    liberarArvore(raiz);
    liberarArvore(novaRaiz);

    return 0;
}
