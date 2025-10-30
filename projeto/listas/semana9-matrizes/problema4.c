/*
Você está planejando uma viagem (somente ida) de uma cidade X para uma cidade Z. Para isso você está
pesquisando passagens de avião que sejam as mais baratas possível, nem que para isso seja necessário passar
por uma cidade Y. Foi possível coletar preços de passagens com diversas origens e destinos que foram
armazenados em uma matriz M ◊ M de inteiros, onde o valor aij representa o preço em reais para ir da
cidade i para a cidade j. Implemente um programa que leia um inteiro M (M Æ 10), seguidos de M ◊ M
inteiros, um inteiro X e um inteiro Z. O programa deve escrever o custo da viagem de X para Z, passando
por no máximo 1 cidade intermediária, com menor custo total. Esse custo deve ser precedido pelas cidades
separadas por traço (vide exemplo abaixo).
*/

#include <stdio.h>

int main() {
    int M, X, Z;
    scanf("%d", &M);
    
    int precos[10][10];
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &precos[i][j]);
        }
    }
    
    scanf("%d", &X);
    scanf("%d", &Z);
    
    int melhor_custo = precos[X][Z];
    int melhor_inter = -1;
    
    for(int i = 0; i < M; i++) {
        if(i != X && i != Z) {
            if(precos[X][i] > 0 && precos[i][Z] > 0) {
                int custo = precos[X][i] + precos[i][Z];
                if(custo < melhor_custo || melhor_custo == 0) {
                    melhor_custo = custo;
                    melhor_inter = i;
                }
            }
        }
    }
    
    if(melhor_inter == -1) {
        printf("%d-%d R$%d\n", X, Z, melhor_custo);
    } else {
        printf("%d-%d-%d R$%d\n", X, melhor_inter, Z, melhor_custo);
    }
    
    return 0;
}