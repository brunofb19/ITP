#include <stdio.h>
#include <math.h>

float calcular(char si, float a, float b){
    float res_aux;
    if(si=='+'){
        res_aux=a+b;
    }   else if (si=='-'){
        res_aux=a-b;
    }   else if (si=='/'){
        res_aux=a/b;
    }   else if (si=='*'){
        res_aux=a*b;
    }
    return res_aux;
}


int main() {
    float n1, n2, res;
    char op;

    printf("ola, esta eh sua calculadora multi funcao\n");
    printf("operadores suportados: +, -, /, *\n");

    scanf("%f", &n1);
    scanf(" %c", &op);
    res=n1;

    while (op!='.'){
        scanf("%f", &n2);
        res=calcular(op, res, n2);
        scanf(" %c", &op);
    }
    printf("resultado da operacao: %f", res);


    return 0;
}