// Exemplo de implementação de espalhamento com endereçamento aberto:

#include <stdio.h>
#include <string.h>
#define M 113
#define N 20
#define VAZIO "____________________"
#define RETIRADO "********************"

typedef char CHAVE [N+1];
typedef struct {
	CHAVE chave;
	int quantidade;
} ITEM;

typedef ITEM DICIONARIO [M];

int h (CHAVE chave){
	int i, soma;

	soma =0;
	for(i=0;i<N;i++){
		soma+=chave[i];
	}
	return (soma % M);
}

void inicializa (DICIONARIO t ){
	int i;
	for(i=0;i<M;i++){
		strcpy(t[i].chave, VAZIO);
	}
}

int pesquisa (CHAVE ch, DICIONARIO t){
	int i, inicial;

	inicial = h(ch);
	i=0;

	while (
	    (strncmp(t[(inicial + i) % M].chave, VAZIO, N)) &&  // Verifica se a chave no índice é "VAZIO"
	    (strncmp(t[(inicial + i) % M].chave, ch, N)) &&      // Verifica se a chave no índice é igual à chave que estamos buscando
	    (i < M)                                              // Garante que não ultrapassamos o limite de tentativas (M)
	) {
	    i++;  // Incrementa o valor de 'i' para tentar no próximo índice
	}

	if (!strncmp(t[(inicial + i) % M].chave, ch, N)) {
	    return ((inicial + i) % M);  // Retorna o índice correspondente se a chave foi encontrada
	} else {
	    return -1;  // Retorna -1 se a chave não foi encontrada após todas as tentativas
	}
}

int insere (ITEM x, DICIONARIO t){
	int i, inicial;

	inicial = h(x.chave);
	i=0;

	while (
	    (strncmp(t[(inicial + i) % M].chave, VAZIO, N)) &&  // Verifica se a chave no índice é "VAZIO"
	    (strncmp(t[(inicial + i) % M].chave, RETIRADO, N)) &&      // Verifica se a chave no índice é igual à chave que estamos buscando
	    (i < M)                                              // Garante que não ultrapassamos o limite de tentativas (M)
	) {
	    i++;  // Incrementa o valor de 'i' para tentar no próximo índice
	}

	if (i<M) {
		t[(inicial+i) % M] = x;
	    return ((inicial + i) % M);  // Retorna o índice correspondente se a chave foi encontrada
	} else {
	    return -1;  // Retorna -1 se a chave não foi encontrada após todas as tentativas
	}
}

int retira (CHAVE ch, DICIONARIO t){
	int i;

	i = pesquisa (ch,t);
	if(i != -1){
		memcpy (t[i].chave, RETIRADO, sizeof(CHAVE));
		return 0;
	} else {
		return -1;
	}
}

int main(void){
	DICIONARIO dic;
	CHAVE palavra;
	ITEM item;
	int rslt;

	inicializa(dic);
	for(;;){

		scanf("%s", palavra);

		if(!strcmp(palavra, "fim")){
			break;
		}

		rslt = pesquisa (palavra,dic);

		if(rslt == -1){
			memset(item.chave, '_', N);
			strncpy (item.chave, palavra, N);
			item.quantidade =0;
			rslt = insere (item, dic);
		}

		if (rslt == -1){
			printf("Dicionario cheio \n");
		} else {
			dic[rslt].quantidade++;
			printf("%s: %d\n", dic[rslt].chave,dic[rslt].quantidade);
		}
	}
	return 0;
}



















