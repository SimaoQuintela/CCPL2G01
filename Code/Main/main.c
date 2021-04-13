/** 
* @file main ficheiro que contém a função main.
* \author Simão Quintela
*/
#include <stdio.h>
#include "parser.h"
#include "stack.h"

int main() {
  char buf[BUFSIZ];
  STACK *s = new_stack();
  
  parse(s, fgets(buf, BUFSIZ, stdin));
  return 0;
}
