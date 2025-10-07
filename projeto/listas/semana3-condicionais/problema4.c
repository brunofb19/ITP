/*
Problema 4 - Jogo: pedra, papel, tesoura
Crie um programa que simule uma partida de "pedra, papel, tesoura". O programa deve:
Ler a jogada do jogador 1 (P para pedra, A para papel, T para tesoura)
Ler a jogada do jogador 2 (P para pedra, A para papel, T para tesoura)
Determinar e exibir o vencedor seguindo as regras:
Pedra vence Tesoura
Tesoura vence Papel
Papel vence Pedra
Jogadas iguais resultam em empate
*/

#include <stdio.h>

int main() {
    char j1, j2;
    scanf(" %c", &j1);
    scanf(" %c", &j2);
    
    if (j1 == j2) {
        printf("Empate\n");
    } else if ((j1 == 'P' && j2 == 'T') || 
               (j1 == 'T' && j2 == 'A') || 
               (j1 == 'A' && j2 == 'P')) {
        printf("Jogador 1 venceu\n");
    } else {
        printf("Jogador 2 venceu\n");
    }
    
    return 0;
}