/*
 * main.c
 *
 *  Created on: 27 de mar. de 2025
 *      Author: 2A226844158
 */

#include <stdio.h>
#include "hash.h"

int main(void) {
	setbuf(stdout,NULL);
    DICIONARIO dic;
    CHAVE palavra;
    ITEM item;
    int rslt;

    inicializa(dic);

    for (;;) {
    	printf("Digite sua palavra: ");
    	scanf("%20s", palavra);
        if (strcmp(palavra, "fim") == 0)
            break;
        rslt = pesquisa(palavra, dic);
        if (rslt == -1) {
        	memset(item.chave, 0, sizeof(CHAVE));
        	strncpy(item.chave, palavra, N);
            item.quantidade = 0;
            rslt = insere(item, dic); // Insere o novo item
            if(rslt==-1)
            	printf("Dicionario cheio\n");
            else {
            	dic[rslt].quantidade++;
            	printf("%s: %d\n", dic[rslt].chave,
            					   dic[rslt].quantidade);
            }
        }
    }
    return 0;
}
