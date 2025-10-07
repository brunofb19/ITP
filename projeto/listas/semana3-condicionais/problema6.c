/*
Problema 6 - Diagnóstico médico simples
Desenvolva um programa que ajude em um diagnóstico médico básico baseado em sintomas. O programa
deve perguntar:
Tem febre? (S/N)
Tem dor de cabeça? (S/N)
Tem dor no corpo? (S/N)
Tem tosse? (S/N)
Com base nas respostas, o programa deve sugerir:
Febre + Dor de cabeça + Dor no corpo: "Possível gripe"
Tosse + Febre: "Possível resfriado"
Apenas dor de cabeça: "Possível enxaqueca"
Apenas febre: "Consulte um médico"
Nenhum sintoma: "Você parece estar bem"
Qualquer outra combinação: "Consulte um médico para avaliação"
*/

#include <stdio.h>

int main() {
    char f, dc, db, t;
    scanf(" %c", &f);
    scanf(" %c", &dc);
    scanf(" %c", &db);
    scanf(" %c", &t);
    
    if (f == 'S' && dc == 'S' && db == 'S') {
        printf("Possivel gripe\n");
    } else if (t == 'S' && f == 'S') {
        printf("Possivel resfriado\n");
    } else if (dc == 'S' && f == 'N' && db == 'N' && t == 'N') {
        printf("Possivel enxaqueca\n");
    } else if (f == 'S' && dc == 'N' && db == 'N' && t == 'N') {
        printf("Consulte um medico\n");
    } else if (f == 'N' && dc == 'N' && db == 'N' && t == 'N') {
        printf("Voce parece estar bem\n");
    } else {
        printf("Consulte um medico para avaliacao\n");
    }
    
    return 0;
}