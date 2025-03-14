#include <stdio.h>
#include <ctype.h>
#include "biblioteca.h"

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

int esta_vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha *pilha, int valor) {
    pilha->itens[++pilha->topo] = valor;
}

int desempilhar(Pilha *pilha) {
    if (!esta_vazia(pilha)) {
        return pilha->itens[pilha->topo--];
    }
    return -1;
}

int topo(Pilha *pilha) {
    if (!esta_vazia(pilha)) {
        return pilha->itens[pilha->topo];
    }
    return -1;
}

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int aplicar_operacao(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int avaliar(const char *expressao) {
    Pilha pilha_operandos, pilha_operadores;
    inicializar_pilha(&pilha_operandos);
    inicializar_pilha(&pilha_operadores);
    empilhar(&pilha_operadores, 'F');

    int i = 0;
    while (expressao[i] != '\0') {
        if (isspace(expressao[i])) {
            i++;
            continue;
        }

        if (isdigit(expressao[i])) {
            empilhar(&pilha_operandos, expressao[i] - '0');
        } else if (expressao[i] == '(') {
            empilhar(&pilha_operadores, expressao[i]);
        } else if (expressao[i] == ')') {
            while (topo(&pilha_operadores) != '(') {
                char op = desempilhar(&pilha_operadores);
                int val2 = desempilhar(&pilha_operandos);
                int val1 = desempilhar(&pilha_operandos);
                empilhar(&pilha_operandos, aplicar_operacao(val1, val2, op));
            }
            desempilhar(&pilha_operadores);
        } else {
            while (!esta_vazia(&pilha_operadores) && precedencia(topo(&pilha_operadores)) >= precedencia(expressao[i])) {
                char op = desempilhar(&pilha_operadores);
                int val2 = desempilhar(&pilha_operandos);
                int val1 = desempilhar(&pilha_operandos);
                empilhar(&pilha_operandos, aplicar_operacao(val1, val2, op));
            }
            empilhar(&pilha_operadores, expressao[i]);
        }
        i++;
    }

    while (topo(&pilha_operadores) != 'F') {
        char op = desempilhar(&pilha_operadores);
        int val2 = desempilhar(&pilha_operandos);
        int val1 = desempilhar(&pilha_operandos);
        empilhar(&pilha_operandos, aplicar_operacao(val1, val2, op));
    }

    return desempilhar(&pilha_operandos);
}
