/*
Problema 7 - Sistema de equações do 2º grau
Crie um programa que resolva equações do segundo grau (ax² + bx + c = 0). O programa deve:
Ler os coeficientes a, b e c
Verificar se é uma equação do segundo grau (a ≠ 0)
Calcular o discriminante (Δ = b² - 4ac)
Determinar e exibir as raízes conforme o caso:
Se Δ > 0: duas raízes reais distintas
Se Δ = 0: uma raiz real
Se Δ < 0: não possui raízes reais
Fórmula das raízes: x = (-b ± √Δ) / (2a)
*/

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    
    if (a == 0) {
        printf("Nao e equacao do segundo grau\n");
        return 0;
    }
    
    delta = b * b - 4 * a * c;
    
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("%.2f %.2f\n", x1, x2);
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("%.2f\n", x1);
    } else {
        printf("Nao possui raizes reais\n");
    }
    
    return 0;
}