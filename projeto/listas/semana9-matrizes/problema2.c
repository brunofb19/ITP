/*
Você foi contratado para ajudar na implementação de uma rede social que conta com M usuários cadastrados.
Um recurso que você quer implementar é a sugestão de amigos. Um usuário B deverá ser sugerido para A se
eles não forem amigos, mas ambos possuirem pelo menos um amigo em comum.
As amizades estão armazenadas em uma matriz M ◊ M de inteiros, onde o valor aij é igual a 1 se o usuário i
(0 Æ i<M) for amigo do usuário j (0 Æ j<M) e 0 caso contrário. Assuma que a matriz sempre é simétrica,
então aij = aji. Além disso não é possível ser amigo de si, então aii = 0.
Implemente um programa que leia um inteiro M (M Æ 100), seguidos de M ◊ M inteiros e um inteiro x. O
programa deve escrever todas as sugestões de amizades para o usuário x em ordem numérica crescente.
*/

#include <stdio.h>

int main() {
    int M, x;
    scanf("%d", &M);
    
    int amigos[100][100];
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &amigos[i][j]);
        }
    }
    
    scanf("%d", &x);
    
    for(int i = 0; i < M; i++) {
        if(i != x && amigos[x][i] == 0) {
            int amigo_comum = 0;
            
            for(int j = 0; j < M; j++) {
                if(amigos[x][j] == 1 && amigos[i][j] == 1) {
                    amigo_comum = 1;
                    break;
                }
            }
            
            if(amigo_comum) {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
    
    return 0;
}