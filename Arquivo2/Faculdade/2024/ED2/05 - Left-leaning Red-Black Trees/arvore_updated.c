#include <stdio.h>
#include <stdlib.h>
#include "arvore_updated.h"

// Função para criar um novo nó
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->removido = 0; // Inicialmente, o nó não está removido
    return novoNo;
}

// Função para inserir um nó na árvore
No* inserir(No* raiz, int chave) {
    if (raiz == NULL) return criarNo(chave);

    if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = inserir(raiz->dir, chave);

    return raiz;
}

// Função para buscar um nó na árvore (ignora nós removidos)
No* buscar(No* raiz, int chave) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == chave && raiz->removido == 0) return raiz;

    if (chave < raiz->chave)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

// Função para remover logicamente um nó (marcando como removido)
void removerLogico(No* raiz, int chave) {
    if (raiz == NULL) return;

    if (chave < raiz->chave) {
        removerLogico(raiz->esq, chave);
    } else if (chave > raiz->chave) {
        removerLogico(raiz->dir, chave);
    } else {
        raiz->removido = 1; // Marca o nó como removido
    }
}

// Função para imprimir a árvore em ordem (ignora nós removidos)
void imprimirArvore(No* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esq);
        if (raiz->removido == 0) // Imprime apenas nós não removidos
            printf("%d ", raiz->chave);
        imprimirArvore(raiz->dir);
    }
}

// Função para liberar memória da árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

// Função para copiar a árvore excluindo os nós removidos logicamente
No* refreshTree(No* raiz) {
    if (raiz == NULL) return NULL;

    if (raiz->removido == 1) {
        No* leftCopy = refreshTree(raiz->esq);
        No* rightCopy = refreshTree(raiz->dir);

        if (leftCopy == NULL) return rightCopy;
        if (rightCopy == NULL) return leftCopy;

        No* newRoot = criarNo(raiz->chave);
        newRoot->esq = leftCopy;
        newRoot->dir = rightCopy;
        return newRoot;
    }

    No* newRoot = criarNo(raiz->chave);
    newRoot->esq = refreshTree(raiz->esq);
    newRoot->dir = refreshTree(raiz->dir);
    return newRoot;
}
