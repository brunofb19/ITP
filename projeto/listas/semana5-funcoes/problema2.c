/*
Problema 2 - Primos triplos
O filho de um amigo seu tem só 12 anos e está encantado com os números primos. Ele gosta tanto que está
montando uma lista com todos os trios de primos na forma (x, x+ 2, x+ 6). Ele conseguiu encontrar o trio 641,
643, 647, mas levou quase uma tarde toda para encontrá-lo. Ele soube que você está aprendendo programação
e é capaz de escrever um programa que escreva todos os trios de primos até 50000 quase instaneamente! É
sua hora então de automatizar essa árdua tarefa usando a linguagem C.
A saída do programa deve ser todos os trios de primos na forma (x, x + 2, x + 6) até 50000, um por linha, no
formato (x, x+2, x+6). Ou seja, as 4 primeiras linhas da saída devem ser:
(5, 7, 11)
(11, 13, 17)
(17, 19, 23)
(41, 43, 47)
Para facilitar a programação, você deve necessariamente escrever uma função que retorna se um determinado
número passado como parâmetro é primo ou não!
*/

#include <stdio.h>

int eh_primo(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    for (int x = 2; x <= 50000; x++) {
        if (eh_primo(x) && eh_primo(x + 2) && eh_primo(x + 6)) {
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }
    return 0;
}