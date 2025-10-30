/*
Crie uma função misturar que recebe 2 strings como parâmetros e retorna uma nova string (alocada
dinamicamente) alternando as letras de ambas as strings. Caso não possuam o mesmo tamanho, as letras
restantes da string maior devem ser colocadas ao final da nova string. Por exemplo, ao misturar “teste” e “algo”,
obtém-se “taelsgtoe”. Já ao misturar “asa” e “inconstitucionalidade” obtém-se “aisnaconstitucionalidade”.
char * misturar(char *str1, char *str2)
A função main deve ler duas strings (uma por linha, com ou sem espaços) de até 100 caracteres, chamar
a função misturar e escrever na tela o resultado. Não se esqueça de liberar a memória do que foi alocado
dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturar(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_len = len1 > len2 ? len1 : len2;
    
    char *resultado = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int pos = 0;
    
    for(int i = 0; i < max_len; i++) {
        if(i < len1) {
            resultado[pos] = str1[i];
            pos++;
        }
        if(i < len2) {
            resultado[pos] = str2[i];
            pos++;
        }
    }
    
    resultado[pos] = '\0';
    return resultado;
}

int main() {
    char str1[101], str2[101];
    
    fgets(str1, 101, stdin);
    fgets(str2, 101, stdin);
    
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
    char *misturada = misturar(str1, str2);
    printf("%s\n", misturada);
    
    free(misturada);
    return 0;
}

