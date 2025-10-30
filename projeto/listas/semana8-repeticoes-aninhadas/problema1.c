/*
A megasena é um jogo de aposta em que são sorteadas 6 dezenas e em cada cartela o jogador anota 6 dezenas
(aposta mínima). Na lotomania, o jogador marca 50 dezenas e são sorteadas 20. Escreva um programa
que leia um inteiro m (1 ≤ m ≤ 30), um inteiro n (m ≤ n ≤ 50), representando a quantidade de números
sorteados e a quantidade de números de uma aposta, respectivamente. Em seguida deve ler os m números
sorteados, os n números da aposta e escrever na tela quantos números o jogador acertou. Note que o intervalo
dos números sorteados/apostados é desconhecido (vide exemplo 3). Assuma que um número não aparece
mais de uma vez no mesmo sorteio nem na mesma aposta.
*/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    
    int sorteados[30];
    int aposta[50];
    
    for(int i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &aposta[i]);
    }
    
    int acertos = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(aposta[i] == sorteados[j]) {
                acertos++;
                break;
            }
        }
    }
    
    printf("%d\n", acertos);
    return 0;
}