#include <stdio.h>
#include "calc_cie.h"
#include "con_uni.h"

int main() {
    char sel;
    int aux = 1;
    
    do {
        printf("ola, esta eh a sua calculadora multi funcao\n");
        printf("selecione a opcao de calculadora que voce deseja:\n C - (calculadora cientifica)\n U - (conversor de unidades)\n");
        scanf(" %c", &sel);
        
        if(sel == 'C' || sel == 'c') {
            calculadora_cientifica();
            aux = 0;
        } else if(sel == 'U' || sel == 'u') {
            conversor_de_unidades();
            aux = 0;
        } else {
            printf("digite a opcao certa\n");
        }
    } while(aux == 1);

    return 0;
}