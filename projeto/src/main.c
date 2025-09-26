#include <stdio.h>
#include <math.h>

float calcular(char si, float a, float b) {
    float res_aux = 1;
    
    if(si == '+') {
        res_aux = a + b;
    } else if (si == '-') {
        res_aux = a - b;
    } else if (si == '/') {
        if(b == 0) {
            printf("Erro: Divisão por zero!\n");
            return 0;
        }
        res_aux = a / b;
    } else if (si == '*') {
        res_aux = a * b;
    } else if (si == '^') {
        res_aux = powf(a, b);
    } else if (si == 'r') {
        if(a < 0) {
            printf("Erro: Raiz quadrada de número negativo!\n");
            return 0;
        }
        res_aux = sqrtf(a);
    } else if (si == '|') {
        res_aux = fabsf(a);
    } else if (si == '!') {
        if(a < 0 || a != (int)a) {
            printf("Erro: Fatorial de número negativo ou não inteiro!\n");
            return 0;
        }
        res_aux = 1;
        for(int i = (int)a; i > 1; i--) {
            res_aux *= i;
        }
    } else if (si == 'l') {
        if(a <= 0) {
            printf("Erro: Logaritmo de número não positivo!\n");
            return 0;
        }
        res_aux = log10f(a);
    } else {
        printf("Operador inválido: %c\n", si);
        return a;
    }
    
    return res_aux;
}



int main() {
    float res, n1, n2=0;
    char op;

    printf("ola, esta eh sua calculadora multi funcao\n");
    printf("operadores suportados: +(soma), -(subtração), /(divisão), *(multplicação), ^(exponencial), r(raiz quadrada), |(modulo), !(fatorial), l(logaritmo)\n");
    printf("como usar: digite o primeiro numero, a operacao e o segundo numero, apos isso, caso queira o resultado, digite o simbolo de '=', caso queira calcular em cima do resultado da operacao realizada, digite novamente mais um operador, e mais um numero\n");
    printf("caso queira utilizar um numero irracional (pi ou euler), ao inves de digitar um operador, digite 'p' para pi ou 'e' para euler, e depois digite a operação juntamente com o segundo numero (caso seja uma operação que necessite) novamente \n\n");

    scanf("%f", &n1);
    scanf(" %c", &op);
    res=n1;

    while (op!='='){
        if(op=='p'){
            res=3.141592;
            scanf(" %c", &op);
        } else if(op=='e'){
            res=2.718281;
            scanf(" %c", &op);
        }
        if((op!='r')&&(op!='|')&&(op!='!')&&(op!='l')){
            scanf("%f", &n2);            
        }
        res=calcular(op, res, n2);
        scanf(" %c", &op);
    }
    printf("\nresultado da operacao: %f\n", res);


    return 0;
}