/*
Um campeonato de futebol conta com M times, numerados de 0 a M ≠ 1. Cada time enfrenta cada um
dos outros times uma única vez. Os resultados são armazenados em uma matriz, onde o elemento aij
(0 Æ i, j Æ M ≠ 1) representa quantos gols o time i fez contra o time j. Portanto, o resultado da partida
i ◊ j (ou j ◊ i, tanto faz pois é uma única partida) é aij gols para i e aji gols para j. No exemplo abaixo, o
resultado do time 3 contra o time 0 foi a30 para o time 3 e a03 para o time 0, ou seja, 3 ◊ 1.
Implemente um programa que leia um inteiro M (M Æ 20), seguidos de M ◊ M inteiros. Como um time não
enfrenta ele próprio, assuma que os elementos da diagonal são sempre 0. O programa deve escrever quantas
partidas terminaram empatadas.
*/

#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);
    
    int resultados[20][20];
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &resultados[i][j]);
        }
    }
    
    int empates = 0;
    
    for(int i = 0; i < M; i++) {
        for(int j = i + 1; j < M; j++) {
            if(resultados[i][j] == resultados[j][i]) {
                empates++;
            }
        }
    }
    
    printf("%d\n", empates);
    return 0;
}