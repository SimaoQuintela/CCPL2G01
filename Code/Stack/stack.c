#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int has_type(DATA elem, int mask){
	return (elem.type & mask) != 0;
}

STACK *new_stack(){
	STACK *s = (STACK *) calloc(1, sizeof(STACK));
	s->size = 100;
	s->stack = (DATA *) calloc(s->size, sizeof(DATA));
	return s;
}

void push(STACK *s, DATA elem){
	if(s->size == s->n_elems){
		s->size += 100;
		s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
	}
	s->stack[s->n_elems] = elem;
	s->n_elems++;
}

DATA pop(STACK *s){
	s->n_elems--;
	return s->stack[s->n_elems];
}

DATA top(STACK *s){
	return s->stack[s->n_elems -1];
}
DATA penultimo(STACK *s){
	return s->stack[s->n_elems -2];
}

int is_empty(STACK *s){
	return s->n_elems = 0;
}

DATA enesimo(STACK *s, int n){
    return s->stack[s->n_elems - n - 1];
}

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


STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
