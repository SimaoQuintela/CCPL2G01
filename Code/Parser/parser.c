/**
* @file Ficheiro que contem a função relacionada ao parser.
*/
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "stack.h"
#include "maths.h"

/**
* \brief Função parse - Função responsável por fazer o parse de uma linha.
*
* @param strtok - O strtok vai percorrer a linha e separar em tokens sempre que encontra um delimitador.
* @param sobra - Se um token for um número inteiro a sobra é 0 logo, faz push desse valor, senão é um sinal e aplica a função correspondente.
* @param strtol - O strtol vai converter os tokens em inteiros. 
*/
void parse(char *line) {
    char *delims = " \t\n";

    STACK s = NEW_STACK();

    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);

        if (strlen(sobra) == 0){
            PUSH(&s, val_i); 
        }
        else if (strcmp(token, "+") == 0)  
            soma(&s);

        else if (strcmp(token, "-") == 0) 
            subtrai(&s);

        else if (strcmp(token, "*") == 0)  
            multiplica(&s);

        else if (strcmp(token, "/") == 0)   
            dividir(&s);

        else if (strcmp(token, "(") == 0)  
            decrementa(&s);

        else if (strcmp(token, ")") == 0)   
            incrementa(&s);

        else if (strcmp(token, "%") == 0)   
            modulo(&s);

        else if (strcmp(token, "#") == 0)   
            expoente(&s);

        else if (strcmp(token, "&") == 0)
            e(&s);                       

        else if (strcmp(token, "|") == 0)   
            ou(&s);                         

        else if (strcmp(token, "^") == 0)   
            xorr(&s);

        else if (strcmp(token, "~") == 0)
            nott(&s);
    }

    PRINT_STACK(s);
}
