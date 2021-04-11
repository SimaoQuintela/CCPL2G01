/** 
* @file main ficheiro que contém a função main.
* \author Simão Quintela
*/
#include <stdio.h>
#include "parser.h"
#include "stack.h"

/**
* \brief A função main inicializa a stack e passa-a como parametro ao fgets que é passado como parametro juntamente com a stack para o parse.
* @param BUFSIZ Macro pré-definida(stdio.h) que é responsável por dar o tamanho à linha que vamos ler.
* @param stdin Macro pré-definida(stdio.h) que é responsável pelo input.
* \brief O parse está a receber a stack e a função fgets como parâmetros.
*/
int main() {
  char buf[BUFSIZ];
  STACK *s = new_stack();
  
  parse(s, fgets(buf, BUFSIZ, stdin));
  return 0;
}
