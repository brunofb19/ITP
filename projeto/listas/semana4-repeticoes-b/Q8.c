/*
Voce esta trabalhando em uma empresa e esta responsavel pela compra de placas de
alumınio. Seu chefe pediu para que uma certa quantia de dinheiro fosse gasto em unidades
dessas placas de 2 fornecedores diferentes, mas ele quer que o dinheiro restante seja o menor
possıvel. Cada fornecedor pode vender no maximo 10 unidades. Como o prazo esta em
cima, voce pensou em testar no papel todas as possibilidades, mas logo viu que sao 121
combinacoes, e sera mais rapido escrever um programa com estruturas de repeticao em C
para resolver o seu problema. Escreva um programa que faca a leitura: do preco de cada
unidade do material do primeiro fornecedor, do preco do segundo fornecedor e da quantia
disponıvel para compra. Em seguida o programa deve escrever na tela quanto resta em
cada uma das possibilidades, desde que a compra seja possıvel. Por exemplo:
Digite o preco do primeiro fornecedor: 9
Digite o preco do segundo fornecedor: 11
Digite a quantia disponivel: 89
Comprando 0 do primeiro e 0 do segundo resta: 89
Comprando 0 do primeiro e 1 do segundo resta: 78
Comprando 0 do primeiro e 2 do segundo resta: 67
...
Comprando 1 do primeiro e 0 do segundo resta: 80
Comprando 1 do primeiro e 1 do segundo resta: 69
Comprando 1 do primeiro e 2 do segundo resta: 58
...
Comprando 9 do primeiro e 0 do segundo resta: 8
*/

#include <stdio.h>

int main() {
    int p1, p2, quant, i, j, resto;
    
    scanf("%d", &p1);
    scanf("%d", &p2);
    scanf("%d", &quant);
    
    for(i = 0; i <= 10; i++) {
        for(j = 0; j <= 10; j++) {
            int total = i * p1 + j * p2;
            if(total <= quant) {
                resto = quant - total;
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n", i, j, resto);
            }
        }
    }
    
    return 0;
}