/*
No código exemplo12.c (parte 4) vimos como criar uma função que retorna indiretamente o maior número de
um vetor de inteiros e o respectivo índice. Agora você deverá fazer algo parecido. A função deve retornar o
endereço base de um vetor contendo todos os índices de um determinado número buscado no vetor. Você
também deve acrescentar um retorno indireto através de ponteiro para armazenar a quantidade de ocorrências.
A função deve seguir a seguinte assinatura:
int * buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd)
onde v é o endereço base do vetor de inteiros a ser analisado, n a quantidade de inteiros nesse vetores,
valor representa o valor buscado no vetor e qtd um ponteiro para inteiro que contém o endereço onde será
armazenado a quantidade de ocorrências desse inteiro buscado. A função deve retornar NULL caso não
encontre ocorrências.
A função main deve ler um inteiro n que representa a quantidade de elementos do vetor de inteiros. O vetor
deve ser alocado dinamicamente. Em seguida, o programa deve ler do usuário os n inteirose um valor inteiro
a ser buscado. Depois o programa deve obter os índices de todas as ocorrências desse valor informado. O
programa deve escrever na saída a quantidade de ocorrências e os índices. Lembre-se de liberar todos os
vetores alocados dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int n) {
    return (int*)malloc(n * sizeof(int));
}

int *somaVetores(int *u, int n1, int *v, int n2, int *n3) {
    if(n1 != n2) {
        return NULL;
    }
    
    int *resultado = alocarVetor(n1);
    *n3 = n1;
    
    for(int i = 0; i < n1; i++) {
        resultado[i] = u[i] + v[i];
    }
    
    return resultado;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    
    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);
    
    for(int i = 0; i < n1; i++) {
        scanf("%d", &u[i]);
    }
    
    for(int i = 0; i < n2; i++) {
        scanf("%d", &v[i]);
    }
    
    int n3;
    int *soma = somaVetores(u, n1, v, n2, &n3);
    
    if(soma == NULL) {
        printf("dimensoes incompatíveis\n");
    } else {
        for(int i = 0; i < n3; i++) {
            printf("%d ", soma[i]);
        }
        printf("\n");
        free(soma);
    }
    
    free(u);
    free(v);
    
    return 0;
}