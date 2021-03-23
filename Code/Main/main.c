/**
* @file Ficheiro que contém a função main do programa.
*/
#include <stdio.h>
#include "parser.h"

/**
* \brlef Função principal do programa.
* 
* @param BUFSIZ Macro pré-definida que dá o tamanho da linha lida.
*
* @returns Retorna 0 se tudo correr bem.
*/
int main() {
  char buf[BUFSIZ];
  parse(fgets(buf, BUFSIZ, stdin));
  return 0;
}
