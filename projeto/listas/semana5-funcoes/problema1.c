/*
Problema 1 - Horários das rondas
Um grupo de policiais precisa realizar periodicamente algumas rondas para minimizar os impactos da
criminalidade no bairro. Horários periódicos como a cada 30 minutos são fáceis de calcular, mas muito
previsíveis. Os policiais pediram sua ajuda para listar os horários das rondas em dois formatos possíveis:
1. No formato 24h: hh:mm, com as horas entre 0 e 23 e os minutos entre 0 e 59. Por exemplo:
a. 00:15
b. 09:07
c. 12:53
d. 22:44
2. Ou no formato 12h: hh:mm AA, com as horas entre 1 e 12 e os minutos entre 0 e 59, onde AA
pode ser AM para horários antes do meio-dia e PM para horários depois do meia-dia (consulte
https://pt.wikipedia.org/wiki/Sistema_hor%C3%A1rio_de_12_horas). Por exemplo (os mesmos
horários do exemplo acima):
a. 12:15 AM
b. 09:07 AM
c. 12:53 PM
d. 10:44 PM
A entrada do programa consiste em 2 inteiros contendo horas e minutos da primeira ronda (sempre no formato
24h), seguidos de um inteiro, tal que 0 significa escrever os horários das rondas no formato 24h e 1 no formato
12h. O programa deve escrever na saída os horários de todas as rondas obedecendo os seguintes acréscimos
em relação ao horário da primeira ronda: 1h, 2h10m, 4h40m e 12h5m.
Para resolver essa questão, seu programa deve implementar uma função que escreve um horário na tela,
tratando os casos em que as horas e/ou os minutos estão fora do intervalo. Por exemplo, se o horário passado
for 25 horas e 10 minutos, a função deve escrever 1 hora e 10 minutos (passou de um dia para o outro) – isso
deve facilitar bastante a programação do resto.
*/

#include <stdio.h>

void escreve_horario(int h, int m, int formato) {
    if (formato == 0) {
        printf("%02d:%02d\n", h % 24, m % 60);
    } else {
        int hora_12 = h % 12;
        if (hora_12 == 0) hora_12 = 12;
        
        if (h % 24 < 12) {
            printf("%02d:%02d AM\n", hora_12, m % 60);
        } else {
            printf("%02d:%02d PM\n", hora_12, m % 60);
        }
    }
}

int main() {
    int h, m, formato;
    scanf("%d", &h);
    scanf("%d", &m);
    scanf("%d", &formato);
    
    escreve_horario(h, m, formato);
    escreve_horario(h + 1, m, formato);
    escreve_horario(h + 2, m + 10, formato);
    escreve_horario(h + 4, m + 40, formato);
    escreve_horario(h + 12, m + 5, formato);
    
    return 0;
}