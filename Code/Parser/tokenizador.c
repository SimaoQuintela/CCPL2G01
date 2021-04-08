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

    else if (strcmp(token, "+") == 0)	// função soma
        soma(s);

    else if (strcmp(token, "-") == 0)   // função subtração
        subtrai(s);

    else if (strcmp(token, "*") == 0)	// função multiplicação
        multiplica(s);

    else if (strcmp(token, "/") == 0)	// função divisão
   		dividir(s);

   	else if (strcmp(token, "(") == 0)	// decremento
   		decrementa(s);

   	else if (strcmp(token, ")") == 0)	// incremento
   		incrementa(s);

   	else if (strcmp(token, "%") == 0)	// função módulo
   		modulo(s);

   	else if (strcmp(token, "#") == 0)	// função expoente
   		expoente(s);

   	else if (strcmp(token, "&") == 0)
   		e(s);							// função que conta quantos bits 2 numeros têm em comum

   	else if (strcmp(token, "|") == 0)	// função que dados dois numeros faz a reuniao da quantidade de bits a 1 
   		ou(s);							

   	else if (strcmp(token, "^") == 0)	
   		xorr(s);

   	else if (strcmp(token, "~") == 0)
   		nott(s);
      
    else if(strcmp(token, "@") == 0)
      rodatres(s);

    else if(strcmp(token, "\\") == 0)
      trocadois(s);

    else if (strcmp(token, "_") == 0)
      duplica(s);

    else if (strcmp(token, ";") == 0)
      popp(s);

    else if(strcmp(token, "$") == 0)
      copian(s);

    else if(strcmp(token, "i") == 0)
      converte_para_long(s);

	  else if(strcmp(token, "f") == 0)
      converte_para_double(s);
      
    else if(strcmp(token, "c") == 0)
      converte_para_char(s);
        
    else if(strcmp(token, "l") == 0)
      ler_linha(s);
}

int verifica_carater(char carater){
  char string_de_carateres [23] = "+-*/()%#&|^~@_;$\\lfic";
  int resultado = 1;

  for(int i = 0; string_de_carateres[i]; i++){
    if(string_de_carateres[i] == carater)
      resultado = 0;
  }

  return resultado;
}