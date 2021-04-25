/**
* @file parser Módulo que contém o parser, que tem como objetivo separar uma string token a token e envia-la para o tokenizador para interpretar os vários tokens.
* \author Simao Quintela
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "parser.h"
#include "maths.h"
#include "tokenizador.h"
#include "manipulacao_da_stack.h"

/**
* \brief A função parse recebe uma stack e uma linha (vindas da main), percorre essa linha separa em token e envia-os um a um para o tokenizador que os vai interpretar.
* \brief Saindo do ciclo for, a função print_stack imprime a stack.
* @param s Passagem da stack como parametro
* @param letras Passagem das letras como parametro
* @param line Linha a ser lida.
*/
void parse(STACK *s, STACK *letras, char *line) {
  char *delims = " \t\n";
  char *token;
  
  for(token = strtok_r(line, delims, &line); token != NULL; token = strtok_r(NULL, delims, &line)) {
      tokenizador(s, letras, token);  
  }

  print_stack(s);
}


/**
* \brief A função parse2 está responsável por ler linhas subsequentes à primeira 
* @param s Passagem da stack como parametro
* @param letras Passagem das letras como parametro
* @param line Linha a ser lida.
*/
void parse2(STACK *s, STACK *letras, char *line) {
  char *delims = " \t\n";
  char *token;

  for(token = strtok_r(line, delims, &line); token != NULL; token = strtok_r(NULL, delims,&line)) {
      tokenizador(s, letras, token);  
  }
}
