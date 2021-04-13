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
* \author Nuno Costa
* @param s Passagem da stack como parâmetro
* \brief Função soma(+) para cada tipo, exceto strings.
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

        push_DOUBLE(s, (double)x + y);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        push_DOUBLE(s, x + (double)y);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)x +(long)y);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        push_LONG(s, (long)x + y);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, x +(long)y);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, (double)x +y);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        push_DOUBLE(s, x+(double)y);
    }
}


/**
* \author Simão Quintela
* @param s Passagem da stack como parâmetro
* \brief Função subtração(-) para cada tipo, exceto strings.
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

        push_DOUBLE(s, y-(double)x);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        push_DOUBLE(s, (double)y -x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)y -(long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        push_LONG(s, y - (long)x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)y - x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, y-(double)x);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        push_DOUBLE(s, (double)y - x);
    }
}


/**
* \author Simão Quintela
* \brief Função multiplicação(*) para cada tipo, exceto strings.
* @param s Passagem da stack como parâmetro
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

        push_DOUBLE(s, (double)x * y);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        push_DOUBLE(s, x * (double)y);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)x * (long)y);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        push_LONG(s, (long)x * y);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, x*(long)y);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, (double)x * y);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        push_DOUBLE(s, x * (double)y);
    }
}

/**
* \author Hugo Rocha
* \brief Função divisão(/) para cada tipo, exceto strings.
* @param s Passagem da stack como parâmetro
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

        push_DOUBLE(s, (double)y / x);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long
        assert(x != 0);     

        push_DOUBLE(s, y / (double)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char
        assert(x != 0);       

        push_LONG(s, (long)y / (long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long
        assert(x != 0);       

        push_LONG(s, (long)y / x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char
        assert(x != 0);   

        push_LONG(s, y / (long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double
        assert(x != 0);   

        push_DOUBLE(s, (double)y /x);

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char   
        assert(x != 0);

        push_DOUBLE(s, y/(double) x);
    }
}


/**
* \author Hugo Rocha
* \brief Função responsável por decrementar(() 1 unidade para cada tipo, exceto strings.
* @param s Passagem da stack como parâmetro
*/ 
void decrementa(STACK *s){
 if(has_type(top(s), LONG)){
        long x = pop_LONG(s);       // x long
        push_LONG(s, x - 1);

    } else if(has_type(top(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        push_DOUBLE(s, x - 1);

    } else if(has_type(top(s), CHAR)){
        char x = pop_CHAR(s);       // x char

        push_CHAR(s, x-1);
    }
  
}

/**
* \author Hugo Rocha
* \brief Função responsável por incrementar()) 1 unidade para cada tipo, exceto strings.
* @param s Passagem da stack como parâmetro
*/ 
void incrementa(STACK *s){
  if(has_type(top(s), LONG)){
        long x = pop_LONG(s);       // x long
        push_LONG(s, x + 1);

    } else if(has_type(top(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        push_DOUBLE(s, x + 1);

    } else if(has_type(top(s), CHAR)){
        char x = pop_CHAR(s);       // x char

        push_CHAR(s, x + 1);
    }
  
}



/**
* \author Nuno Costa
* \brief Função módulo(%) para cada tipo, exceto strings e doubles.
* @param s Passagem da stack como parâmetro
*/ 
void modulo(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long
        assert(x != 0);

        push_LONG(s, y%x);
    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char
        assert(x != 0);

        push_LONG(s, (long)y % (long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 
        assert(x != 0);

        push_LONG(s, y % (long)x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char
        assert(x != 0);

        push_LONG(s, (long)y % x);
    }
}


/**
* \author Tiago Guedes
* \brief Função expoente(#) para cada tipo, exceto strings.
* @param s Passagem da stack como parâmetro
*/ 
void expoente(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, pow(y,x));

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), DOUBLE)){
        double x = pop_DOUBLE(s);   // x double
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, pow(y,x));

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), DOUBLE)){
        long x = pop_LONG(s);       // x long
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, pow(y,(double)x));

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), LONG)){
        double x = pop_DOUBLE(s);   // x double
        long y =  pop_LONG(s);      // y long

        push_DOUBLE(s, pow((double)y, x));

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, pow((long)y,(long)x));

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long 

        push_LONG(s, pow(y,(long)x));

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, pow((long)y,x));

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), DOUBLE)){
        char x = pop_CHAR(s);       // x char 
        double y = pop_DOUBLE(s);   // y double

        push_DOUBLE(s, pow(y,(double)x));

    } else if(has_type(top(s), DOUBLE) && has_type(penultimo(s), CHAR)){
        double x = pop_DOUBLE(s);   // x double 
        char y = pop_CHAR(s);       // y char

        push_DOUBLE(s, pow((double)y,x));
    }
}


/**
* \author Tiago Guedes
* \brief Função "e"(&) responsável por determinar a interseção de bits entre dois números inteiros.
* @param s Passagem da stack como parâmetro
*/ 
void e(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, y & x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)y & (long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long

        push_LONG(s, (long)y & x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, y & (long)x);
    }
}

/**
* \author Tiago Guedes
* \brief Função "ou"(|) responsável por determinar a reunião de bits entre dois números inteiros.
* @param s Passagem da stack como parâmetro
*/ 
void ou(STACK *s){
    if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, y | x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)y | (long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long

        push_LONG(s, (long)y | x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, y | (long)x);
    }
}

/**
* \author Paulo Vasconcelos
* \brief Função xor(^) responsável por colocar a 0 todos os bits em comum e a 1 todos os bits diferentes entre si, de dois números e calcular o seu resultado.
* @param s Passagem da stack como parâmetro
*/ 
void xorr(STACK *s){
 if(has_type(top(s), LONG) && has_type(penultimo(s), LONG)){
        long x = pop_LONG(s);       // x long
        long y = pop_LONG(s);       // y long

        push_LONG(s, y ^ x);
    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        char y = pop_CHAR(s);       // y char

        push_LONG(s, (long)y ^ (long)x);

    } else if(has_type(top(s), CHAR) && has_type(penultimo(s), LONG)){
        char x = pop_CHAR(s);       // x char
        long y = pop_LONG(s);       // y long

        push_LONG(s, (long)y ^ x);

    } else if(has_type(top(s), LONG) && has_type(penultimo(s), CHAR)){
        long x = pop_LONG(s);       // x long
        char y = pop_CHAR(s);       // y char

        push_LONG(s, y ^ (long)x);
    }
}
/**
* \author Paulo Vasconcelos
* \brief Função nott responsável por inverter todos os bits de um número inteiro
* @param s Passagem da stack como parâmetro
*/ 
void nott(STACK *s){
  if(has_type(top(s), LONG)){
        long x = pop_LONG(s);       // x long
        push_LONG(s, ~x);

    } else if(has_type(top(s), CHAR)){
        char x = pop_CHAR(s);       // x char
        long y = (long)x;

        push_LONG(s, ~y);
    }

}
