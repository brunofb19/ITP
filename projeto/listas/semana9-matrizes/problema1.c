/*
Um campo agrícola possui setores organizados de forma matricial, onde alguns são de terras férteis e outros
inférteis. Irrigadores ocupam um setor por completo, nunca estão localizados na borda da matriz e irrigam
cada um dos 4 setores vizinhos (norte, sul, leste, oeste).
Implemente um programa que leia um inteiro M, um inteiro N (M Æ 10, N Æ 10), seguidos de M ◊N inteiros.
Depois o programa deve escrever quantos setores férteis estão cobertos por pelo menos um irrigador e
quantos não estão. Um 0 representa um setor infértil, 1 um setor fértil e 2 um setor ocupado por um irrigador.
O setor onde está localizado o próprio irrigador não deve ser contabilizado.
*/

#include <stdio.h>

int main() {
    int M, N;
    scanf("%d", &M);
    scanf("%d", &N);
    
    int campo[10][10];
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }
    
    int cobertos = 0, nao_cobertos = 0;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(campo[i][j] == 1) {
                int irrigado = 0;
                
                if(i > 0 && campo[i-1][j] == 2) irrigado = 1;
                if(i < M-1 && campo[i+1][j] == 2) irrigado = 1;
                if(j > 0 && campo[i][j-1] == 2) irrigado = 1;
                if(j < N-1 && campo[i][j+1] == 2) irrigado = 1;
                
                if(irrigado) {
                    cobertos++;
                } else {
                    nao_cobertos++;
                }
            }
        }
    }
    
    printf("%d %d\n", cobertos, nao_cobertos);
    return 0;
}