#ifndef ARVORE_UPDATED_H
#define ARVORE_UPDATED_H

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
    int removido; // 0 = ativo, 1 = removido logicamente
} No;

// Funções da árvore binária
No* inserir(No* raiz, int chave);
No* buscar(No* raiz, int chave);
void removerLogico(No* raiz, int chave);
void imprimirArvore(No* raiz);
void liberarArvore(No* raiz);
No* refreshTree(No* raiz); // Novo protótipo para a função refresh

#endif // ARVORE_UPDATED_H
