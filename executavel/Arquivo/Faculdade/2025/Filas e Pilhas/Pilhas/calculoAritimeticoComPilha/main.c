/*
 * main.c
 *
 *  Created on: 8 de set. de 2024
 *      Author: Bless
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
	setbuf(stdout,NULL);

	PILHA operador,operando;
	ITEM item;
	cria(&operador); cria(&operando);
	item.FDE = '#';
	if (push(item,&operador) == -1)
		printf("Erro no empilhanento do FDE: %c\n", item.FDE);

	examinasExpressao();

	return 0;

}


