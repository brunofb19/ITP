/*
Você está implementando um detector de placas de carro. Uma das coisas que facilitará a busca na base
de dados é saber se a placa está no padrão brasileiro ou no padrão mercosul. A tabela a seguir especifica o
formato relativo aos dois padrões (L indica uma letra maiúscula e A um algarismo).

Padrão              Formato             Exemplo
Brasileiro          LLL-AAAA            ATX-1010
Mercosul            LLLALAA             ATX1M010

Crie um programa que leia uma palavra (sem espaços) de até 10 caracteres e escreva “brasileiro” ou “mercosul”
se estiver de acordo com um padrão ou outro, ou ainda “inválido” caso não se enquadre em nenhum dos dois.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[11];
    scanf("%s", placa);
    int len = strlen(placa);
    
    if(len == 8 && placa[3] == '-') {
        int valida = 1;
        for(int i = 0; i < 3; i++) {
            if(!isupper(placa[i])) valida = 0;
        }
        for(int i = 4; i < 8; i++) {
            if(!isdigit(placa[i])) valida = 0;
        }
        if(valida) {
            printf("brasileiro\n");
            return 0;
        }
    }
    
    if(len == 7) {
        int valida = 1;
        for(int i = 0; i < 3; i++) {
            if(!isupper(placa[i])) valida = 0;
        }
        if(!isupper(placa[4])) valida = 0;
        if(!isdigit(placa[3])) valida = 0;
        if(!isdigit(placa[5])) valida = 0;
        if(!isdigit(placa[6])) valida = 0;
        if(valida) {
            printf("mercosul\n");
            return 0;
        }
    }
    
    printf("invalido\n");
    return 0;
}