/**
* @file Ficheiro que contem as funções das operações matemáticas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "maths.h"
#include "stack.h"

/**
* \author Hugo Rocha
* \brlef Função soma - Função responsável por fazer a soma.
*/
void soma(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, X + Y);
}


/**
* \author Hugo Rocha
* \brlef Função subtrai - Função responsável por fazer a subtração entre dois números.
*/
void subtrai(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y - X);
}


/**
* \author Hugo Rocha
* \brlef Função multiplica - Função responsável por fazer a multiplicação entre dois números.
*/
void multiplica(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, X * Y);
}


/**
* \author Hugo Rocha
* \brlef Função dividir - Função responsável por fazer a divisão inteira entre dois números, garantindo que X é diferente de zero.
*/
void dividir(STACK *s){
    long X = POP(s);
    assert(X != 0);
    long Y = POP(s);
    PUSH(s, Y / X);
}


/**
* \author Hugo Rocha
* \brlef Função decrementa - Função responsável por fazer a decrementação.
*/
void decrementa(STACK *s){
    long X = POP(s);
    PUSH(s, X - 1);
}


/**
* \author Hugo Rocha
* \brlef Função incrementa - Função responsável por fazer a incrementação.
*/
void incrementa(STACK *s){
    long X = POP(s);
    PUSH(s, X + 1);
}


