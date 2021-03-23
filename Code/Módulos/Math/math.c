/**
* \author Tiago Guedes
* \brlef Função modulo - Função responsável por devolver o resto da divisão inteira entre dois números.
*/
void modulo(STACK *s){
   long X = POP(s);
   long Y = POP(s);
   PUSH(s, Y % X);
}


/**
* \author Tiago Guedes
* \brlef Função expoente - Função responsável por fazer a exponencialização entre dois números sendo o primeiro a base e o segundo o expoente.
*/
void expoente(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, pow(Y, X));
}


/**
* \author Tiago Guedes
* \brlef Função e - Função responsável por determinar a interseção de bits entre dois números.
*/
void e(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y & X);
}


/**
* \author Tiago Guedes
* \brlef Função ou - Função responsável por determinar a reunião de bits entre dois números.
*/
void ou(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y | X);
}



/**
* \author Tiago Guedes
* \brlef Função xorr - Função responsável por colocar a 0 todos os bits em comum e a 1 todos os bits diferentes entre si, de dois números.
*/
void xorr(STACK *s){
    long X = POP(s);
    long Y = POP(s);
    PUSH(s, Y ^ X);
}


/**
* \author Tiago Guedes
* \brlef Função nott - Função responsável por inverter todos os bits de um número.
*/
void nott(STACK *s){
    long X = POP(s);
    PUSH(s, (~X));
}