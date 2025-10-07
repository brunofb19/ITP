/*
Problema 8 - Validador de triângulos
Desenvolva um programa que leia três valores representando os lados de um triângulo e determine:
lista-s3.md 2025-08-27
3 / 3
Se os valores podem formar um triângulo (soma de dois lados sempre maior que o terceiro)
Se formar um triângulo, classificá-lo como:
Equilátero (todos os lados iguais)
Isósceles (dois lados iguais)
Escaleno (todos os lados diferentes)
Também classifique quanto aos ângulos:
Retângulo (a² = b² + c², onde a é o maior lado)
Acutângulo (a² < b² + c²)
Obtusângulo (a² > b² + c²)
*/

#include <stdio.h>

int main() {
    float l1, l2, l3, temp;
    scanf("%f", &l1);
    scanf("%f", &l2);
    scanf("%f", &l3);
    
    if (l1 < l2) { temp = l1; l1 = l2; l2 = temp; }
    if (l1 < l3) { temp = l1; l1 = l3; l3 = temp; }
    
    if (l1 >= l2 + l3) {
        printf("Nao forma triangulo\n");
        return 0;
    }
    
    if (l1 == l2 && l2 == l3) {
        printf("Equilatero\n");
    } else if (l1 == l2 || l1 == l3 || l2 == l3) {
        printf("Isosceles\n");
    } else {
        printf("Escaleno\n");
    }
    
    if (l1 * l1 == l2 * l2 + l3 * l3) {
        printf("Retangulo\n");
    } else if (l1 * l1 < l2 * l2 + l3 * l3) {
        printf("Acutangulo\n");
    } else {
        printf("Obtusangulo\n");
    }
    
    return 0;
}