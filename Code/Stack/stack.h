#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/**
*  Struct que enumera os tipos e que vai aplica-los na struct data
*
*/
typedef enum {
	LONG = 1,	/**< Tipo LOng com o valor 1 (2⁰) associado */
	DOUBLE = 2,	/**< Tipo Double com o valor 2 (2¹) associado */
	CHAR = 4,	/**< Tipo Char com o valor 4 (2²) associado */
	STRING = 8	/**< Tipo String com o valor 8 (2³) */
} TYPE;


/**
* Uma struct que nos dá os tipos de dados que estamos a usar na stack
*/
typedef struct data {
	TYPE type;	/**< tipos de dados vindos do enum TYPE */
	long LONG;	/**< Tipo long */
	double DOUBLE;	/**< Tipo double */
	char CHAR;	/**< Tipo char */
	char *STRING;	/**< Tipo string */
} DATA;

/**
* Struct que define a estrutura da stack, tendo ela uma inicialização com os tipos definidos em data, com uma variável que dá o tamanho e o número de elementos presentes na stack
*/
typedef struct stack{
	DATA *stack;	/**< Tipo da stack */
	int size;	/**< Tamanho da stack */
	int n_elems;	/**< Número de elementos ao momento na stack */
} STACK;

int has_type(DATA elem, int mask);
STACK *new_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
DATA penultimo(STACK *s);
void print_stack(STACK *s);
DATA enesimo(STACK *s, int n);

/**
* Macro que faz a substituição de texto de acordo com o stack_operation correspondente para podermos ter de uma forma rápida e eficiente um push e um pop para cada tipo.
*/
#define STACK_OPERATION_PROTO(_type, _name)		\
	void push_##_name(STACK *s, _type val);		\
	_type pop_##_name(STACK *s);


STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)


#endif
