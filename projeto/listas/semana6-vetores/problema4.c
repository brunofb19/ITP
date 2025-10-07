/*
Problema 4 - Em busca do tesouro perdido
Cheque esperto é um famoso pirata que sempre pede ajuda aos alunos de ITP para encontrar tesouros. Em
seu mapa há 10 ilhas numeradas de 0 a 9. Ele não sabe em qual dessas ilha está o tesouro. Quando ele visita
a ilha i, os nativos afirmam que o tesouro está supostamente na ilha v[i]. Ele pediu sua ajuda para determinar
a primeira ilha que, partindo da ilha 0, será visitada uma segunda vez se for seguindo a sugestão dos
nativos. Ele acredita que lá deva estar o tesouro.
A imagem a seguir ilustra o exemplo para o vetor: {8, 4, 3, 0, 7, 4, 2, 1, 5, 2}. Por exemplo, os nativos da ilha 0
afirmam que o tesouro está na ilha 8 (valor que está em v[0]) e os nativos da ilha 8 afirmam que o tesouro está
na ilha 5 (valor que está em v[8]). Cheque esperto visita as ilhas na sequência: 0 → 8 → 5 → 4 → 7 → 1 → 4
A entrada do programa consiste na sugestão dos nativos em cada uma das 10 ilhas, desde a ilha 0 até a ilha
9. A saída do seu programa deve ser a primeira ilha que será visitada uma segunda vez.
Exemplos
Input                       Output
1 2 3 4 5 6 7 8 9 0           0
8 4 3 0 7 4 2 1 5 2           4
*/

#include <stdio.h>

int main() {
    int v[10];
    int visitado[10] = {0};
    
    for(int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }
    
    int atual = 0;
    
    while(1) {
        if(visitado[atual]) {
            printf("%d\n", atual);
            break;
        }
        visitado[atual] = 1;
        atual = v[atual];
    }
    
    return 0;
}