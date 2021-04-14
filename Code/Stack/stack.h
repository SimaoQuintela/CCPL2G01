#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/**
* \brief Struct que enumera os tipos e que vai aplica-los na struct data
*/
typedef enum {
	LONG = 1,	/** Máscara com o valor 1 associado ao tipo long */
	DOUBLE = 2,	/** Máscara com o valor 2 associado ao tipo double */
	CHAR = 4,	/** Máscara com o valor 4 associado ao tipo char */
	STRING = 8	/** Máscara com o valor 8 associado ao tipo string */
} TYPE;


/**
* Uma struct que nos dá os tipos de dados que estamos a usar na stack
*/
typedef struct data {
	TYPE type;	/** Máscaras vindas do enum TYPE */

	long LONG;	/** Tipo long */
	double DOUBLE;	/** Tipo double */
	char CHAR;	/** Tipo char */
	char *STRING;	/** Tipo string */
} DATA;

/**
* \brief Struct que define a estrutura da stack, tendo ela uma inicialização com os tipos definidos em data, com uma variável que dá o tamanho e o número de elementos presentes na stack
*/
typedef struct stack{
	DATA *stack;	/** Tipo da stack */
	int size;		/** Tamanho da stack */
	int n_elems;	/** Número de elementos ao momento na stack */
} STACK;

int has_type(DATA elem, int mask);
STACK *new_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
DATA penultimo(STACK *s);
void print_stack(STACK *s);
DATA enesimo(STACK *s, int n);

#define STACK_OPERATION_PROTO(_type, _name)		\
	void push_##_name(STACK *s, _type val);		\
	_type pop_##_name(STACK *s);


STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)


#endif
