/*
Problema 2 - Calculadora de energia elétrica
Uma companhia de energia cobra da seguinte forma:
Residencial: R$ 0,60 por kWh
Comercial: R$ 0,48 por kWh
Industrial: R$ 1,29 por kWh
Além disso, há uma taxa fixa de R$ 15,00 para todos os tipos. Crie um programa que leia o consumo em
kWh e o tipo de consumidor (R para residencial, C para comercial, I para industrial) e calcule o valor total da
conta.
*/

#include <stdio.h>

int main() {
    float kwh, total;
    char tipo;
    scanf("%f", &kwh);
    scanf(" %c", &tipo);
    
    if (tipo == 'R') {
        total = kwh * 0.60 + 15.00;
    } else if (tipo == 'C') {
        total = kwh * 0.48 + 15.00;
    } else if (tipo == 'I') {
        total = kwh * 1.29 + 15.00;
    }
    
    printf("%.2f\n", total);
    return 0;
}