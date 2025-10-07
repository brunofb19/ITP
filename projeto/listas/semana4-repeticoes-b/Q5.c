/*
5. Escreva um programa que leia um n´umero n (que representa o n´umero de linhas) e escreva
na tela o seguinte padr˜ao, nesse exemplo com 5 linhas:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

#include <stdio.h>

int main() {
    int n, i, j, num = 1;
    scanf("%d", &n);
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
    
    return 0;
}