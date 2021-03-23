#ifndef ___STACK_H___
#define ___STACK_H___

#define LENGTH_STACK 5120

typedef struct {
	long array[LENGTH_STACK];
	int pos;
} STACK;


STACK NEW_STACK();
void PUSH(STACK *s, int valor);
long POP(STACK *s);
void PRINT_STACK(STACK s);

#endif