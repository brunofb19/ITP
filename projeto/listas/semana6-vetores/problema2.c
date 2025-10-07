/*
Problema 2 - Álbum de figurinhas
Você está colecionando um álbum de figurinhas dos personagens de desenhos dos anos 2000. Você notou que
estão faltando as figurinhas de Bily e Mandy. Do Du, do Dudu e do Edu também. Você notou na verdade que
estão faltando quase todas! Para isso resolveu escrever um programa que informe facilmente quais figurinhas
estão faltando.
O programa deve ler a quantidade m (m ≤ 1000) de figurinhas da coleção completa (numeradas de 1 a
m) , a quantidade n (n ≤ m) de figurinhas que você possui e, em seguida, o número das n figurinhas (não
necessariamente em ordem crescente). O seu programa deve escrever na tela quais as figurinhas que estão
faltando, em ordem crescente.
Exemplos
Input                       Output
13 6                   1 3 4 6 9 10 12
2 5 13 8 11 7
*/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    
    int album[1001] = {0};
    int fig;
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &fig);
        album[fig] = 1;
    }
    
    int primeiro = 1;
    for(int i = 1; i <= m; i++) {
        if(album[i] == 0) {
            if(!primeiro) {
                printf(" ");
            }
            printf("%d", i);
            primeiro = 0;
        }
    }
    printf("\n");
    
    return 0;
}