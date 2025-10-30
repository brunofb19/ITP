/*
Alguns pilotos de Fórmula 1 vez ou outra conseguem algumas façanhas. Em 1983, no grande prêmio do
Oeste dos Estados Unidos, John Watson largou em 22º lugar e conseguiu terminar em primeiro! Você então
resolveu escrever um programa que facilite a identificação de pilotos que conseguem ganhar muitas posições.
Escreva um programa que leia um número inteiro n representando a quantidade de pilotos em uma corrida
de Fórmula 1 (1 ≤ n ≤ 20). Em seguida faça a leitura de n inteiros, representando a ordem de largada e,
depois, n inteiros, representando a ordem de chegada. Os pilotos são identificados pelos números de 1
a n. O programa deve em seguida escrever na tela o identificador do piloto que mais ganhou posições. Se
houver empate entre vários pilotos ou se ninguém ganhou posições, escreva empate.
A imagem a seguir ilustra a ordem de largada do Exemplo 1: largou em primeiro o piloto #2, em segundo
o piloto #5, em terceiro o piloto #3, em quarto o piloto #4 e, por fim, o piloto #1 largou em último.
Terminaram a corrida na seguinte ordem: piloto #1 em primeiro, seguido do piloto #5, piloto #2, piloto #3
e piloto #4. Nesse primeiro exemplo, o piloto #1 foi o que mais ganhou posições: 4.
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int largada[20];
    int chegada[20];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &largada[i]);
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &chegada[i]);
    }
    
    int melhor_piloto = 0;
    int melhor_ganho = -1;
    int empate = 0;
    
    for(int i = 0; i < n; i++) {
        int piloto = chegada[i];
        int pos_chegada = i + 1;
        
        int pos_largada = 0;
        for(int j = 0; j < n; j++) {
            if(largada[j] == piloto) {
                pos_largada = j + 1;
                break;
            }
        }
        
        int ganho = pos_largada - pos_chegada;
        
        if(ganho > melhor_ganho) {
            melhor_ganho = ganho;
            melhor_piloto = piloto;
            empate = 0;
        } else if(ganho == melhor_ganho && ganho > 0) {
            empate = 1;
        }
    }
    
    if(melhor_ganho <= 0 || empate) {
        printf("empate\n");
    } else {
        printf("%d\n", melhor_piloto);
    }
    
    return 0;
}