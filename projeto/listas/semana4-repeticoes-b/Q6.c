/*
(usando 3 fors ou usando 2 fors) Escreva um programa que escreva na tela todos os
trios pitagoricos onde o maior numero e menor que 1000. Tres numeros naturais a, b e c
formam um trio pitagorico caso: a²+b²=c²
*/

#include <stdio.h>

int main() {
    int a, b, c;
    
    for(a = 1; a < 1000; a++) {
        for(b = a; b < 1000; b++) {
            for(c = b; c < 1000; c++) {
                if(a*a + b*b == c*c) {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    
    return 0;
}