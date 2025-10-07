/*
Problema 3 - Sistema de notas
Desenvolva um programa que leia três notas de um aluno e calcule sua média. O programa deve:
Calcular a média aritmética
Determinar se o aluno foi aprovado (média ≥ 7.0), reprovado (média < 4.0) ou está em recuperação
(4.0 ≤ média < 7.0)
Se estiver em recuperação, calcular qual nota precisa tirar na prova final para ser aprovado (média
final ≥ 5.0, onde média final = (média + nota final)/2)
*/

#include <stdio.h>

int main() {
    float n1, n2, n3, med, nec;
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);
    
    med = (n1 + n2 + n3) / 3;
    printf("%.2f\n", med);
    
    if (med >= 7.0) {
        printf("Aprovado\n");
    } else if (med < 4.0) {
        printf("Reprovado\n");
    } else {
        printf("Recuperacao\n");
        nec = 10 - med;
        printf("%.2f\n", nec);
    }
    
    return 0;
}