/*
Problema 3 - A construção da ponte
A prefeitura está pedindo sua ajuda para determinar o comprimento de uma ponte que será construída. A
ponte será construída nos dois pontos mais altos da região. Os dois pontos mais altos são sempre iguais,
então não deve haver uma ponte inclinada. Escreva um programa que leia um número n (assuma n ≤ 30), em
seguida n números inteiros (todos maiores que 0) representando a altura do terreno (vide Figuras a seguir).
O programa deve escrever na tela o comprimento da ponte que une os dois pontos mais altos. Assuma que há
sempre duas, e somente duas, ocorrências do ponto mais alto e que o comprimento da ponte é no mínimo 1.
Exemplos
Input                           Output
10                                4
2 5 3 2 2 3 5 3 2 1

10                                2
4 5 3 5 5 6 5 3 6 4

20                                13
1 2 4 6 1 2 3 3 3 3
4 4 5 4 3 2 3 6 4 2
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int terreno[30];
    int max = 0;
    int pos1 = -1, pos2 = -1;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &terreno[i]);
        if(terreno[i] > max) {
            max = terreno[i];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(terreno[i] == max) {
            if(pos1 == -1) {
                pos1 = i;
            } else {
                pos2 = i;
            }
        }
    }
    
    printf("%d\n", pos2 - pos1);
    
    return 0;
}