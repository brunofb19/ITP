/*
Problema 5 - Calculadora de desconto progressivo
Uma loja oferece descontos progressivos baseados no valor da compra:
Até R$ 100,00: sem desconto
De R$ 100,01 a R$ 500,00: 10% de desconto
De R$ 500,01 a R$ 1000,00: 15% de desconto
Acima de R$ 1000,00: 20% de desconto
Crie um programa que leia o valor da compra e calcule:
O valor do desconto
O valor final a ser pago
A porcentagem de desconto aplicada
*/

#include <stdio.h>

int main() {
    float val, desc, final;
    int porc;
    scanf("%f", &val);
    
    if (val <= 100.00) {
        porc = 0;
    } else if (val <= 500.00) {
        porc = 10;
    } else if (val <= 1000.00) {
        porc = 15;
    } else {
        porc = 20;
    }
    
    desc = val * porc / 100;
    final = val - desc;
    
    printf("%.2f\n", desc);
    printf("%.2f\n", final);
    printf("%d%%\n", porc);
    
    return 0;
}