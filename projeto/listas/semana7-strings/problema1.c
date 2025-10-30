/*
A entrada do programa consiste em uma palavra com até 20 caracteres composta somente por . e x, onde o
primeiro representa um espaço vazio e o segundo representa uma bomba. Depois o programa deve ler um
inteiro representando um índice na palavra (começando de 0) e escrever na tela bum! caso nesse índice haja
uma bomba ou escrever na tela um inteiro representando quantas bombas há na adjacência do índice em
questão.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char campo[21];
    int pos;
    
    scanf("%s", campo);
    scanf("%d", &pos);
    
    int len = strlen(campo);
    
    if(campo[pos] == 'x') {
        printf("bum!\n");
    } else {
        int bombas = 0;
        if(pos > 0 && campo[pos-1] == 'x') bombas++;
        if(pos < len-1 && campo[pos+1] == 'x') bombas++;
        printf("%d\n", bombas);
    }
    
    return 0;
}