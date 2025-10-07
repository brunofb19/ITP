/*
Problema 4 - jogo de dardos
Cansados das mesmas regras do jogo de dardos, um grupo de amigos resolveu inovar: ganha pontos não
só quem acerta mais perto do alvo, mas ganha também uma pontuação bônus (metade da principal) quem
acerta próximo do último lançamento. Afinal, quem lança errado sempre no mesmo lugar também tem boa
pontaria, ela só não está calibrada.
O seu programa deve ler as coordenadas (x, y), dois números reais, de 10 lançamentos e escrever na tela a
pontuação total.

Distância Pontuação principal Pontuação bônus
[0, 1]         +10 pts             +5 pts
]1, 2]          +6 pts              +3 pts
]2, 3]          +4 pts              +2 pts
Acima de 3       0 pts               0 pts

O centro do alvo sempre está em (0, 0), a distância é dada pela distância euclidiana e, claro, não há pontuação bônus para o
primeiro lançamento, pois não há lançamento anterior.
*/

#include <stdio.h>
#include <math.h>

int main() {
    float x, y, px, py;
    int i, pontos = 0;
    
    for (i = 0; i < 10; i++) {
        scanf("%f", &x);
        scanf("%f", &y);
        
        float dist_alvo = sqrt(x * x + y * y);
        
        if (dist_alvo <= 1) {
            pontos += 10;
        } else if (dist_alvo <= 2) {
            pontos += 6;
        } else if (dist_alvo <= 3) {
            pontos += 4;
        }
        
        if (i > 0) {
            float dist_anterior = sqrt((x - px) * (x - px) + (y - py) * (y - py));
            
            if (dist_anterior <= 1) {
                pontos += 5;
            } else if (dist_anterior <= 2) {
                pontos += 3;
            } else if (dist_anterior <= 3) {
                pontos += 2;
            }
        }
        
        px = x;
        py = y;
    }
    
    printf("%d\n", pontos);
    return 0;
}