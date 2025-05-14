
#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "lista.h"

void criaMatriz(MATRIZ *matriz) {
	matriz->nColunas=0;
	matriz->nLinhas=0;
	matriz->linhas=NULL;
	matriz->coluna=NULL;
}

void leMatriz(MATRIZ* matriz, FILE* arquivo) {
  char myString[TAM_BUFFER];
  int linha = 0, coluna = 0;
  int linhaCelula = 0, colunaCelula = 0;
  double valor = 0;

  if (feof(arquivo)) {
      printf("Fim do arquivo atingido.\n");
      return;
  }

  if (!fgets(myString, TAM_BUFFER, arquivo)) {
      return; // Retorna se não há mais conteúdo
  }
  sscanf(myString, "%d %d", &linha, &coluna);

  if (linha <= 0 || coluna <= 0) {
      printf("Erro: tentando inserir uma matriz inválida.\n");
      return;
  }

  inicializaMatriz(matriz, linha, coluna);

  while (fgets(myString, TAM_BUFFER, arquivo)) {
      sscanf(myString, "%d %d %lf", &linhaCelula, &colunaCelula, &valor);

      if (linhaCelula < 0 || colunaCelula < 0) {
          break;
      }

      if (valor != 0) {
          insereMatriz(matriz, linhaCelula, colunaCelula, valor);
      }
  }
}


void inicializaMatriz(MATRIZ* matriz, int linhas, int colunas){
	int i;

	matriz->nLinhas=linhas;
	matriz->nColunas=colunas;
	matriz->linhas = (LISTA*)malloc(matriz->nLinhas * sizeof(LISTA));
	matriz->coluna = (LISTA*)malloc(matriz->nColunas * sizeof(LISTA));
	for(i=0;i<matriz->nLinhas;i++) criaLista(&matriz->linhas[i]);
	for(i=0;i<matriz->nColunas;i++) criaLista(&matriz->coluna[i]);
}

void criaLista(LISTA *lista){
	lista->primeiro=(PONT)malloc(sizeof(CELULA));
	lista->ultimo=lista->primeiro;
	lista->primeiro->abaixo=NULL;
	lista->primeiro->direita=NULL;
}

void insereMatriz(MATRIZ* matriz, int linha, int coluna, double valor) {
    if (valor == 0) return;

    PONT novaCelula = (PONT)malloc(sizeof(CELULA));
    if (!novaCelula) {
        printf("Erro ao alocar memória para nova célula\n");
        return;
    }

    novaCelula->item.linha = linha;
    novaCelula->item.coluna = coluna;
    novaCelula->item.valor = valor;
    novaCelula->direita = NULL;
    novaCelula->abaixo = NULL;

	if (insereLinhaLista(&matriz->linhas[linha - 1], novaCelula) == -1) //Se retornar -1, então identificamos o "erro" ou uma ação esperada
		printf("Erro na insercao de da celula em linha\n");

	if (insereColunaLista(&matriz->coluna[coluna - 1], novaCelula) == -1) //Se retornar -1, então identificamos o "erro" ou uma ação esperada
		printf("Erro na insercao de da celula em coluna\n");
}

int insereLinhas_fim (LISTA *lista, PONT celula){
    lista->ultimo->direita = celula;
    lista->ultimo = lista->ultimo->direita;
    lista->ultimo->direita=NULL;
    return 0;
}

int insereLinhaLista(LISTA *lista, PONT celula){

	PONT p;
	p=lista->primeiro;
	while(p->direita != NULL){ //Percorre a lista até encontrar a posição correta
		if(celula->item.coluna < p->direita->item.coluna){ //Verifica se o novo elemento deve ser inserido antes de p->direita
			celula->direita = p->direita;
			p->direita = celula;
//			Insere o novo elemento no meio da lista
//			celula->direita = p->direita;
//			p->direita = celula;
//
//			O novo nó herda a ligação do nó atual (p->direita).
//			Depois, o nó atual (p) passa a apontar para o novo nó.
//
//			Exemplo antes da inserção (15 deve entrar entre 10 e 20):
//			[10] → [20] → [30] → NULL
//
//			Após a inserção:
//			[10] → [15] → [20] → [30] → NULL
			return 0;
		}
		p = p->direita;
	}
	return insereLinhas_fim(lista,celula);
}

int insereColunas_fim(LISTA *lista, PONT celula){
    lista->ultimo->abaixo = celula;
	lista->ultimo = lista->ultimo->abaixo;
	lista->ultimo->abaixo=NULL;
    return 0;
}

int insereColunaLista(LISTA *lista, PONT celula){

	PONT p;
	p=lista->primeiro;
	while(p->abaixo != NULL){
		if(celula->item.linha < p->abaixo->item.linha){
			celula->abaixo = p->abaixo;
			p->abaixo = celula;
			return 0;
		}
		p = p->abaixo;
	}
	return insereColunas_fim(lista,celula);
}

void imprimeMatriz(MATRIZ *matriz) {
    printf("(\n");

    for (int i = 0; i < matriz->nLinhas; i++) {
        printf("  ");
        imprimeLinhaLista(&matriz->linhas[i], matriz->nColunas);
        printf("\n");
    }
    printf(")\n\n");
}

void imprimeLinhaLista(LISTA *lista, int numColunas) {
    PONT atual = lista->primeiro->direita;
    double valoresLinha[numColunas];

    for (int j = 0; j < numColunas; j++) {
        valoresLinha[j] = 0;
    }

    while (atual) {
        valoresLinha[atual->item.coluna - 1] = atual->item.valor;
        atual = atual->direita;
    }

    for (int j = 0; j < numColunas; j++) {
        printf("%.0f", valoresLinha[j]);
        if (j < numColunas - 1) {
            printf(" ");
        }
    }
}

void apagaMatriz(MATRIZ *matriz) {
    if (!matriz->linhas) return;

    for (int i = 0; i < matriz->nLinhas; i++) {
        PONT atualLinha = matriz->linhas[i].primeiro;
        PONT tempLinha;

        while (atualLinha) {
            PONT atualColuna = atualLinha->direita;

            while (atualColuna) {
                PONT tempColuna = atualColuna;
                atualColuna = atualColuna->direita;
                free(tempColuna);
            }
            tempLinha = atualLinha;
            atualLinha = atualLinha->abaixo;
            free(tempLinha);
        }
    }

    free(matriz->linhas);
    free(matriz->coluna);

    matriz->linhas = NULL;
    matriz->coluna = NULL;
    matriz->nLinhas = 0;
    matriz->nColunas = 0;

    if (vaziaMatriz(matriz) == 0) {
        printf("Erro: a matriz não foi apagada corretamente!\n");
    }
}

int vaziaMatriz(MATRIZ *matriz) {
    if (!matriz || !matriz->linhas) return 1;

    for (int i = 0; i < matriz->nLinhas; i++) {
        if (matriz->linhas[i].primeiro && matriz->linhas[i].primeiro->direita != NULL) {
            return 0;
        }
    }
    return 1;
}

void somaMatriz(MATRIZ *a, MATRIZ *b, MATRIZ *c) {
    if (a->nLinhas != b->nLinhas || a->nColunas != b->nColunas) {
        printf("\nMatrizes de Ordem diferente.\nSó é possível somar matrizes de mesma ordem\n");
        return;
    }
    criaMatriz(c); inicializaMatriz(c, a->nLinhas, a->nColunas);

//Vamos percorrer cada linha da matriz para somar os elementos correspondentes.
    for (int i = 0; i < a->nLinhas; i++) {
        PONT matA = a->linhas[i].primeiro->direita;
        PONT matB = b->linhas[i].primeiro->direita;

//O loop continua até percorrer todos os elementos não nulos de A e B na linha atual.
        while (matA != NULL || matB != NULL) {

//Se matA ainda tem elementos, colunaA recebe o índice da coluna do próximo elemento.
//Se matA acabou, recebe um valor maior (nColunas + 1) para indicar que já percorremos tudo.
//O mesmo vale para matB.
            int colunaA = matA ? matA->item.coluna : a->nColunas + 1;
            int colunaB = matB ? matB->item.coluna : b->nColunas + 1;

            if (colunaA == colunaB) {
                double soma = matA->item.valor + matB->item.valor;
                if (soma != 0) {
                    insereMatriz(c, i + 1, colunaA, soma);
                }
                matA = matA->direita;
                matB = matB->direita;
            } else if (colunaA < colunaB) {
                insereMatriz(c, i + 1, colunaA, matA->item.valor);
                matA = matA->direita;
            } else {
                insereMatriz(c, i + 1, colunaB, matB->item.valor);
                matB = matB->direita;
            }
        }
    }
}

void multiplicaMatriz(MATRIZ *a, MATRIZ *b ,MATRIZ *c){
    if (a->nColunas != b->nLinhas) {
        printf("\nNao foi possivel multiplicar as matrizes\nNúmero de colunas de A é diferente do número de linhas de B\n");
        return;
    }

    if (vaziaMatriz(a) || vaziaMatriz(b))
        return;

    criaMatriz(c); inicializaMatriz(c, a->nLinhas, b->nColunas);

    for (int i = 1; i <= a->nLinhas; i++) {
        for (int j = 1; j <= b->nColunas; j++) {
            double total = 0;

            for (int k = 1; k <= a->nColunas; k++) {
                total += obterElementoPeloIndice(a, i, k) * obterElementoPeloIndice(b, k, j);
            }

            if (total != 0) {
                insereMatriz(c, i, j, total);
            }
        }
    }
}

double obterElementoPeloIndice(MATRIZ *matriz, int linha, int coluna) {
    PONT celula = matriz->linhas[linha - 1].primeiro->direita;

    while (celula != NULL) {
        if (celula->item.coluna == coluna) {
            return celula->item.valor;
        }
        celula = celula->direita;
    }
    return 0;
}


