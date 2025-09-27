#include <stdio.h>
#include <math.h>

float calcular(float a, float b, char si){
    float res_aux = 1;
    
    if(si == '+') {
        res_aux = a + b;
    } else if (si == '-') {
        res_aux = a - b;
    } else if (si == '/') {
        if(b == 0) {
            printf("Erro: Divisao por zero!\n");
            return 0;
        }
        res_aux = a / b;
    } else if (si == '*') {
        res_aux = a * b;
    } else if (si == '^') {
        res_aux = powf(a, b);
    } else if (si == 'r') {
        if(a < 0) {
            printf("Erro: Raiz quadrada de numero negativo!\n");
            return 0;
        }
        res_aux = sqrtf(a);
    } else if (si == '|') {
        res_aux = fabsf(a);
    } else if (si == '!') {
        if(a < 0 || a != (int)a) {
            printf("Erro: Fatorial de numero negativo ou nao inteiro!\n");
            return 0;
        }
        res_aux = 1;
        for(int i = (int)a; i > 1; i--) {
            res_aux *= i;
        }
    } else if (si == 'l') {
        if(a <= 0) {
            printf("Erro: Logaritmo de numero nao positivo!\n");
            return 0;
        }
        res_aux = log10f(a);
    } else {
        printf("Operador invalido: %c\n", si);
        return a;
    }
    
    return res_aux;
}

void calculadora_cientifica() {
    float res, n1, n2=0;
    char op;

    printf("operadores suportados: +(soma), -(subtração), /(divisão), *(multplicação), ^(exponencial), r(raiz quadrada), |(modulo), !(fatorial), l(logaritmo)\n");
    printf("como usar: digite o primeiro numero, a operacao e o segundo numero, apos isso, caso queira o resultado, digite o simbolo de '=', caso queira calcular em cima do resultado da operacao realizada, digite novamente mais um operador seguido de mais um numero\n");
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
}

void conversor_de_unidades(){

}


int main() {
    char sel;

    printf("ola, esta eh a sua calculadora multi funcao\n");
    printf("selecione a opcao de calculadora que voce deseja:\n C - (calculadora cientifica)\n U - (conversor de unidades)\n M - (calculadora de matrizes)\n");
    scanf(" %c", &sel);
    if(sel=='C' || sel=='c'){
        calculadora_cientifica();
    } else if(sel=='U' || sel=='u'){
        conversor_de_unidades();
    }


    return 0;
}