/*
O OpenMeet é um software que tem servido para os professores lecionarem suas aulas no formato remoto.
Infelizmente o SIGAA não é integrado a esse software, dificultando avaliar quem não está com as frequências
em dia. Porém, o OpenMeet é capaz de produzir um relatório de presença no seguinte formato:
data1 aluno1 aluno2 aluno3 . . . data2 aluno1 aluno2 . . .
Sua missão agora é ajudar o professor. Ele quer um programa que leia o nome de um aluno e a string das
frequências (conforme formato acima, no máximo 1000 caracteres) para então, em seguida, escrever o número
de aulas em que o aluno esteve ausente. Todas as datas seguem exatamente o formato DD/MM. Cada aluno
é identificado apenas pelo seu primeiro nome, contém no máximo 10 caracteres e não há dois nomes iguais.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char aluno[11];
    char frequencia[1001];
    
    scanf("%s", aluno);
    getchar();
    fgets(frequencia, 1001, stdin);
    
    int total_aulas = 0;
    int ausencias = 0;
    char *token = strtok(frequencia, " \n");
    
    while(token != NULL) {
        if(strchr(token, '/') != NULL) {
            total_aulas++;
            int presente = 0;
            char *next = strtok(NULL, " \n");
            while(next != NULL && strchr(next, '/') == NULL) {
                if(strcmp(next, aluno) == 0) {
                    presente = 1;
                }
                next = strtok(NULL, " \n");
            }
            if(!presente) {
                ausencias++;
            }
            token = next;
        } else {
            token = strtok(NULL, " \n");
        }
    }
    
    printf("%d\n", ausencias);
    return 0;
}