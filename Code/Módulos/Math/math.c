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
* \brief Função soma - Função responsável por fazer a soma.
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


/**
* \author Tiago Guedes
* \brlef Função modulo - Função responsável por devolver o resto da divisão inteira entre dois números.
*/
void modulo(STACK *s){
   long X = POP(s);
   long Y = POP(s);
   PUSH(s, Y % X);
}


/**
* \author Tiago Guedes
* \brlef Função expoente - Função responsável por fazer a exponencialização entre dois números sendo o primeiro a base e o segundo o expoente.
*/
void expoente(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, pow(Y, X));
}


/**
* \author Tiago Guedes
* \brlef Função e - Função responsável por determinar a interseção de bits entre dois números.
*/
void e(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y & X);
}


/**
* \author Tiago Guedes
* \brlef Função ou - Função responsável por determinar a reunião de bits entre dois números.
*/
void ou(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y | X);
}



/**
* \author Tiago Guedes
* \brlef Função xorr - Função responsável por colocar a 0 todos os bits em comum e a 1 todos os bits diferentes entre si, de dois números.
*/
void xorr(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y ^ X);
}


/**
* \author Tiago Guedes
* \brlef Função nott - Função responsável por inverter todos os bits de um número.
*/
void nott(STACK *s){
    long X = POP(s);
    PUSH(s, (~X));
}
