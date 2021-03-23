/**
* @file Ficheiro que contem as funções relacionadas com a Stack.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"


/**
* \author Simão Quintela 
* \brlef NEW_STACK - Função responsável por criar e inicializar a stack.
*
* @returns Retorna a Stack.
*/
STACK NEW_STACK(){
	STACK s;

	s.pos = 0;

	return s;
}


/** 
* \author Simão Quintela 
* \brlef Função PUSH - Função responsável por acrescentar elementos à stack e incrementar o stack pointer.
* @param valor - valor a colocar no local para onde o apontador está a apontar antes do incremento.
*/
void PUSH(STACK *s, int valor){

	s->array[s->pos] = valor;
    s->pos++; 
}
