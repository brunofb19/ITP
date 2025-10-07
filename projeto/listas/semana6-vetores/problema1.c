/*
O MEC precisa de sua ajuda para automatizar a correção das provas objetivas do ENEM! Escreva um
programa que leia um número inteiro n representando o número de questões (1 ≤ n ≤ 20). Em seguida leia
as n respostas do gabarito e, em seguida, as n respostas do aluno. Assuma que as respostas estão sempre
entre 1 e 5. Depois o programa deve escrever na tela quantas questões o aluno acertou e a string “acertos” ou
“acerto” (para 1 acerto), conforme exemplo abaixo.
Exemplos
Input                  Output
4                   2 acertos
1 2 3 4
1 5 3 5

7                   1 acerto
1 2 3 2 1 5 4
3 3 3 3 3 3 3
*/

#include <stdio.h>

int main() {
    int n, acertos = 0;
    scanf("%d", &n);
    
    int gabarito[20], aluno[20];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &gabarito[i]);
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &aluno[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(gabarito[i] == aluno[i]) {
            acertos++;
        }
    }
    
    printf("%d %s\n", acertos, acertos == 1 ? "acerto" : "acertos");
    
    return 0;
}