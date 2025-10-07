/*
Problema 1 - Classificação de IMC
Modifique o programa do Problema 1 para que, além de calcular o IMC, também classifique o resultado de
acordo com a tabela:
Abaixo de 18.5: "Abaixo do peso"
Entre 18.5 e 24.9: "Peso normal"
Entre 25.0 e 29.9: "Sobrepeso"
30.0 ou mais: "Obesidade"
*/

#include <stdio.h>

int main() {
    float p, a, imc;
    scanf("%f", &p);
    scanf("%f", &a);
    imc = p / (a * a);
    printf("%.2f\n", imc);
    
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc <= 24.9) {
        printf("Peso normal\n");
    } else if (imc <= 29.9) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidade\n");
    }
    
    return 0;
}