/**
* @file maths Módulo que contém as funções aritméticas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "maths.h"
#include "stack.h"

/**
* \author Nuno Costa
* \brief Função soma(+) para cada tipo, exceto strings.
* @param s Passagem da stack como parametro
*/ 
void soma(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, x+y);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, x+y);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), DOUBLE)){
        long x = pop_LONG(s);       // x long
        double y = pop_DOUBLE(s);   // y double

        double result = (double)x + y;  
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        double result = x + (double)y;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        long result = (long)x + (long)y;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        long result = (long)x + y;
        push_LONG(s, result);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        long result = x + (long)y;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        double result = (double)x + y;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        double result = x + (double)y;
        push_DOUBLE(s, result);
    }
}


/**
* \author Simão Quintela
* \brief Função subtração(-) para cada tipo, exceto strings.
* @param s Passagem da stack como parametro
*/ 
void subtrai(STACK *s){

if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, y-x);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, y-x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), DOUBLE)){
        long x = pop_LONG(s);       // x long
        double y = pop_DOUBLE(s);   // y double

        double result = y - (double)x ;  
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        double result = (double)y - x;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        long result = (long)y - (long)x;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        long result = y- (long)x;
        push_LONG(s, result);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        long result = (long)y - x;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        double result =  y - (double)x;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        double result = (double)y - x;
        push_DOUBLE(s, result);
    }
}


/**
* \author Simão Quintela
* \brief Função multiplicação(*) para cada tipo, exceto strings.
* @param s Passagem da stack como parametro
*/ 
void multiplica(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, x*y);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, x*y);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), DOUBLE)){
        long x = pop_LONG(s);       // x long
        double y = pop_DOUBLE(s);   // y double

        double result = (double)x * y;  
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        double result = x * (double)y;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        long result = (long)x * (long)y;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        long result = (long)x * y;
        push_LONG(s, result);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        long result = x * (long)y;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        double result = (double)x * y;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        double result = x * (double)y;
        push_DOUBLE(s, result);
    }
}

/**
* \author Hugo Rocha
* \brief Função divisão(/) para cada tipo, exceto strings.
* @param s Passagem da stack como parametro
*/ 
void dividir(STACK *s){
 if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long
        assert(x != 0);

        push_LONG(s, y / x);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        double y = pop_DOUBLE(s);   // y double
        assert(x != 0);             

        push_DOUBLE(s, y / x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), DOUBLE)){
        long x = pop_LONG(s);       // x long
        double y = pop_DOUBLE(s);   // y double
        assert(x != 0);  

        double result = (double)y / x;  
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long
        assert(x != 0);     

        double result = y / (double)x;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char
        assert(x != 0);       

        long result = (long)y / (long)x;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long
        assert(x != 0);       

        long result = (long)y / x;
        push_LONG(s, result);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char
        assert(x != 0);   

        long result = y / (long)x;
        push_LONG(s, result);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double
        assert(x != 0);   

        double result = (double)y / x;
        push_DOUBLE(s, result);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char   
        assert(x != 0);

        double result = y / (double)x;
        push_DOUBLE(s, result);
    }
}