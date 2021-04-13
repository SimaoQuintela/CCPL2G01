/**	@file stack Módulo que contém a stack e todas as operações adjacentes
* \author Simão Quintela
* \author Hugo Rocha
* \author Tiago Guedes
* \author Paulo Vasconcelos
* \author Nuno Costa
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
* \brief Função que verifica o tipo de um token.
* @returns Retorna verdadeiro se o elemento e a máscara tiverem o mesmo tipo, senão retorna falso
* @param elem Número passado como parâmetro.
* @param mask Uma máscara, ou seja um dos quatro tipos LONG, DOUBLE, CHAR, STRING
*/
int has_type(DATA elem, int mask){
	return (elem.type & mask) != 0;
}

/**
* \brief Função responsável pela criação da stack
* @returns Retorna uma stack.
*/
STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->size = 100;
	s->stack = (DATA *) calloc(s->size, sizeof(DATA));
	return s;
}

/**
* \brief Função responsável por guardar o elemento no topo da stack e incrementar o stack pointer.
* @param s Passagem da stack como parâmetro
* @param elem Número passado como parâmetro
*/
void push(STACK *s, DATA elem){
	if(s->size == s->n_elems){
		s->size += 100;
		s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
	}
	s->stack[s->n_elems] = elem;
	s->n_elems++;
}

/**
* \brief Função responsável por decrementar o stack pointer.
* @param s Passagem da stack como parâmetro
* @returns Retorna o valor para o qual aponta o stack pointer depois de ser decrementado.
*/
DATA pop(STACK *s){
	s->n_elems--;
	return s->stack[s->n_elems];
}

/**
* \brief Função responsável por retornar o que está no topo da stack.
* @param s Passagem da stack como parâmetro
* @returns Retorna o que está no topo da stack.
*/
DATA top(STACK *s){
	return s->stack[s->n_elems -1];
}

/**
* \brief Função responsável por retornar o que está na posição anterior ao topo da stack.
* @param s Passagem da stack como parâmetro
* @returns Retorna o que está na posição anterior ao topo da stack.
*/
DATA penultimo(STACK *s){
	return s->stack[s->n_elems -2];
}


/**
* \brief Função responsável por retornar o N-ésimo elemento a partir do topo da stack.
* @param s Passagem da stack como parâmetro
* @param n N-ésimo elemento a remover contando a partir do topo da stack.
* @returns Retorna o N-ésimo elemento a partir do topo da stack.
*/
DATA enesimo(STACK *s, int n){
    return s->stack[s->n_elems - n - 1];
}

/**
* \brief Imprime a stack.
*/
void print_stack(STACK *s){
	for(int i = 0; i <s->n_elems; i++){
		DATA elem = s->stack[i];
		TYPE type = elem.type;
		switch(type){
			case LONG: printf("%ld", elem.LONG);
				break;
			case DOUBLE: printf("%g", elem.DOUBLE);
				break;
			case CHAR: printf("%c", elem.CHAR);
				break;
			case STRING: printf("%s", elem.STRING);
				break;
		}
	}
	printf("\n");
}

/*
* \brief Macro que faz a substituição de texto de acordo com o stack_operation correspondente para podermos ter de uma forma rápida e eficiente um push e um pop para cada tipo.
*/
#define STACK_OPERATION(_type, _name)			\
	void push_##_name(STACK *s, _type val){ 	\
		DATA elem;								\
		elem.type = _name;						\
		elem._name = val;						\
		push(s, elem);							\
	}											\
	_type pop_##_name(STACK *s){				\
		DATA elem = pop(s); 					\
		assert(elem.type == _name);				\
		return elem._name;						\
	}

/**
* \brief Protótipos para a macro.
*/

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
