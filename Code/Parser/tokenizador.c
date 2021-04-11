#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "tokenizador.h"
#include "maths.h"
#include "manipulacao_da_stack.h"

void tokenizador(STACK *s, char* token){
    char *sobra1;
    char *sobra2;
    char carater = token[0];

    long val_l = strtol(token, &sobra1, 10);
    double val_d = strtod(token, &sobra2);    
	
    if(strlen(sobra1) == 0)
        push_LONG(s, val_l);
       
    else if(strlen(sobra2) == 0)
        push_DOUBLE(s, val_d);
        
    else if(strlen(token) != 1)
        push_STRING(s, token);

    else if(verifica_carater(carater) == 1)
        push_CHAR(s, carater); 


    if(strcmp(token, "-") == 0)   // sinal -
    	subtrai(s);
    else{
      switch(token[0]){
        case 43: soma(s);         // sinal + em notação ASCII
          break;
        case 42: multiplica(s);   // sinal * em notação ASCII
          break;
        case 47: dividir(s);      // sinal / em notação ASCII
          break;
        case 40: decrementa(s);   // sinal ( em notação ASCII
          break;
        case 41: incrementa(s);   // sinal ) em notação ASCII
          break;
        case 37: modulo(s);       // sinal % em notação ASCII
          break;
        case 35: expoente(s);     // sinal # em notação ASCII
          break;
        case 38: e(s);            // sinal & em notação ASCII
          break;
        case 124: ou(s);          // sinal | em notação ASCII
          break;
        case 94: xorr(s);         // sinal ^ em notação ASCII
          break;
        case 126: nott(s);        // sinal ~ em notação ASCII
          break;
        case 64: rodatres(s);     // sinal @ em notação ASCII
          break; 
        case 92: trocadois(s);    /* sinal \ em notação ASCII */
          break;
        case 95: duplica(s);      // sinal _ em notação ASCII
          break;
        case 59: popp(s);         // sinal ; em notação ASCII
          break;
        case 36: copian(s);       // sinal $ em notação ASCII
          break;
        case 105: converte_para_long(s);    // sinal i em notação ASCII
          break;
        case 102: converte_para_double(s);  // sinal f em notação ASCII
          break;
        case 99: converte_para_char(s);     // sinal c em notação ASCII
          break;  
        case 108: ler_linha(s);             // sinal l em notação ASCII
          break;
    }
  }
}
	

/**
* \author Simão Quintela
* \brief A função verifica_carater recebe como parametro um token(carater) e precorre uma string que contém todos os carateres associados às operações aritméticas e de conversão
* @returns Caso o carater seja igual a qualquer um dos tokens contidos na string, a função retorna 0(falso), senão retorna 1(verdadeiro);
*/
int verifica_carater(char carater){
  char string_de_carateres [23] = "+-*/()%#&|^~@_;$\\lfic";
  int resultado = 1;

  for(int i = 0; string_de_carateres[i]; i++){
    if(string_de_carateres[i] == carater)
      resultado = 0;
  }

  return resultado;
}
