/*
Problema 2 - salve o homem aranha
O homem aranha tem levado algumas quedas enquanto perambula pela cidade, pois às vezes a teia não é
longa o suficiente para alcançar o prédio. Então ele resolveu pedir a sua ajuda. Seu programa deve ler como
entrada:
1. A coordenada inicial do homem aranha (x, y)
2. O comprimento máximo da teia (float)
3. Um inteiro n representando a quantidade de alvos onde ele vai lançar a teia
4. n coordenadas dos alvos (x, y)
Todos os componentes das coordenadas devem ser declarados como float.
Estando o alvo em (ax, ay) e o homem aranha em (x, y), se ele conseguir fixar a teia no alvo, sua nova
coordenada (x', y') será:
(x', y') = (2ax- x, y) 
A teia não alcança o alvo se a distância euclidiana for menor que o comprimento máximo da teia.
Seu programa deve escrever na tela S se ele consegue usar todos os alvos e N caso contrário
*/ 

#include <stdio.h>
#include <math.h>

int main() {
    float x, y, teia, ax, ay;
    int n, i;
    int consegue = 1;
    
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &teia);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%f", &ax);
        scanf("%f", &ay);
        
        float dist = sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y));
        
        if (dist > teia) {
            consegue = 0;
        }
        
        if (consegue) {
            float nx = 2 * ax - x;
            float ny = y;
            x = nx;
            y = ny;
        }
    }
    
    if (consegue) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}