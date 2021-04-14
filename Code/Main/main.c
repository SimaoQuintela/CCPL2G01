/** 
* @file main ficheiro que contém a função main.
* \author Simão Quintela
*/
#include <stdio.h>
#include "parser.h"
#include "stack.h"

/**
*	\brief Função principal do programa responsável por inicializar a stack e passar a stack e uma linha para a função parse.
*/
int main() {
  char buf[BUFSIZ];       // linha que vai ser lida, com o tamanho BUFSIZ(macro pré-definida)
  STACK *s = new_stack();
  
  parse(s, fgets(buf, BUFSIZ, stdin));
  return 0;
}
