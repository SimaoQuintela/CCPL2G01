#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#include <math.h>
#include "stack.h"  
#include "maths.h"
#include "parser.h"

void rodatres(STACK *s){    // carater @
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);
    push(s, y);
    push(s, x);
    push(s, z);
}

void trocadois(STACK *s){    // carater '\'
    DATA x = pop(s);
    DATA y = pop(s);
    push(s, x);
    push(s, y);
}

void duplica(STACK *s){   // carater _
    DATA x = pop(s);
    //pop(s);
    push(s, x);
    push(s, x);
}

void popp(STACK *s){    // carater ;
    pop(s);
}

void copian(STACK *s){        // carater $
    int x = pop_LONG(s);
    push(s, enesimo(s, x));   // enesimo definida na stack
}

void converte_para_long(STACK *s){
    if(has_type(top(s), DOUBLE)){
        double x = pop_DOUBLE(s);

        push_LONG(s, (long)x);
    } else if (has_type(top(s), CHAR)){
        char x = pop_CHAR(s);
        
        push_LONG(s, (long)x);
    }
}

void converte_para_double(STACK *s){
    if(has_type(top(s), LONG)){
        long x = pop_LONG(s);

        push_DOUBLE(s, (double)x); 
    } else if (has_type(top(s), CHAR)){
        char x = pop_CHAR(s);
        
        push_DOUBLE(s, (double)x);
    }
}

void converte_para_char(STACK *s){
    if(has_type(top(s), LONG)){
        long x = pop_LONG(s);

        push_CHAR(s, (char)x); 
    } else if (has_type(top(s), DOUBLE)){
        double x = pop_DOUBLE(s);
        
        push_CHAR(s, (char)x);
    }
}

void ler_linha(STACK *s){
    char linha[BUFSIZ];
    char *new_line = fgets(linha, BUFSIZ, stdin);

    parse2(s, new_line);
}


