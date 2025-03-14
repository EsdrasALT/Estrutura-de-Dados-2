#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct {
    int topo;
    int itens[100];
} Pilha;

void inicializar_pilha(Pilha *pilha);
int esta_vazia(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
int desempilhar(Pilha *pilha);
int topo(Pilha *pilha);

int precedencia(char op);
int aplicar_operacao(int a, int b, char op);
int avaliar(const char *expressao);

#endif
