#include <string.h>
//#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "parser.h"
#include "maths.h"
#include "tokenizador.h"
#include "manipulacao_da_stack.h"

// função genérica
void parse(STACK *s, char *line) {
  char *delims = " \t\n";
  char *token;

  for(token = strtok_r(line, delims, &line); token != NULL; token = strtok_r(NULL, delims, &line)) {
      tokenizador(s, token);  
  }

  print_stack(s);
}

// função utilizada no comando l 
void parse2(STACK *s, char *line) {
  char *delims = " \t\n";
  char *token;

  for(token = strtok(line, delims, &line); token != NULL; token = strtok(NULL, delims, &line)) {
      tokenizador(s, token);  
  }
}
