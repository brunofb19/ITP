/*
Escreva um programa que leia 12 inteiros, representando a quantidade de chuva em cada um desses meses
(de Janeiro até Dezembro). O programa deve em seguida escrever na tela um ranking ordenado do mês com
mais chuva para o mês com menos chuva. Em cada linha da saída deve constar o mês e a quantidade de
chuva. Você pode utilizar o arquivo q2inicial.c disponível no github como código inicial. Para simplificar a
questão, você pode assumir que não há dois meses com a mesma quantidade de chuva.
Para ordenar, utilize um desses três algoritmos: bubble sort, selection sort ou insertion sort.
*/

#include <stdio.h>

int main() {
    int chuva[12];
    char *meses[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
                    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    for(int i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }
    
    for(int i = 0; i < 11; i++) {
        for(int j = i + 1; j < 12; j++) {
            if(chuva[i] < chuva[j]) {
                int temp = chuva[i];
                chuva[i] = chuva[j];
                chuva[j] = temp;
                
                char *temp_mes = meses[i];
                meses[i] = meses[j];
                meses[j] = temp_mes;
            }
        }
    }
    
    for(int i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i], chuva[i]);
    }
    
    return 0;
}