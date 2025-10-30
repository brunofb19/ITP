/*
Quando temos dois vetores de mesma dimensão ˛u = (u0, u1, u2, ..., un) e ˛v = (v0, v1, v2, ..., vn), a soma ˛u + ˛v
é dada por:
˛u + ˛v = (u0 + v0, u1 + v1, u2 + v2, ..., un + vn)
Partindo do código q2inicial.c, preencha as funções não implementadas e na função main:
• ler do usuário um inteiro n1, um inteiro n2
• alocar dinamicamente um vetor u de n1 números inteiros e outro v de n2 números inteiros usando a
função alocarVetor
• ler n1 inteiros para u e n2 inteiros para v
• chamar a função somaVetores
• escrever na tela o vetor resultante da soma dos dois vetores ou ‘dimensoes incompativeis’ caso n1 ”= n2
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