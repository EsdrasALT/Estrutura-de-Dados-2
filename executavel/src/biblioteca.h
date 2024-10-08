#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef char CHAVE [21];
typedef struct {
   CHAVE nome;
   double preço;
} ITEM;

typedef ITEM DICIONARIO [100];

// Protótipos das funções
void inicializaz(DICIONARIO dicio);
int inserir(ITEM item, DICIONARIO dicio);
int pesquisar(CHAVE chave, DICIONARIO dicio);
int alterar(CHAVE chave, DICIONARIO dicio);
int remover(CHAVE chave, DICIONARIO dicio);

#endif
