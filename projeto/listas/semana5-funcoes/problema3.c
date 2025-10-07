/*
Problema 3 - Pousando a sonda espacial
Você faz parte de uma equipe do INPE que precisa encontrar um local seguro para pousar uma sonda
no terreno de uma lua de Saturno. Após algumas análises, seus colegas conseguiram modelar a altura da
superfície como uma função bidimensional
f(x, y) = sin(cos(y) + x) + cos(y + sin(x))
Todas as alturas abaixo de zero e acima de 2 provocam danos para a sonda e devem ser evitadas. Um trecho
dessa superfície está na imagem abaixo. A sonda (cujo centro é o ponto branco na figura) possui um certo
tamanho e, portanto, todos os 4 pontos (em verde) também devem estar em uma altura permitida. Se a
sonda estiver em p = (x, y), esses pontos estarão em (x + 0.2, y + 0.2), (x − 0.2, y − 0.2), (x + 0.2, y − 0.2) e
(x − 0.2, y + 0.2). Se todos os 5 pontos estiverem na altura segura, o ponto de pouso é dito seguro.
Como a lua de Saturno possui fortes rajadas de vento, pode ser que a sonda não pouse exatamente no local
p = (x, y). Para ter uma maior segurança, você deve verificar também as condições de pouso em (x + 2, y),
(x − 2, y), (x, y − 2) e (x, y + 2) (vide os pontos em azul a, b, c e d na figura).
Escreva um programa que leia a coordenada de pouso da sonda (x, y) e escreva a classificação do local, de
acordo com as seguintes regras:
1. Se esse ponto não for seguro, a classificação é “troque de coordenada”
2. Se esse ponto for seguro, conte quantos dos 4 locais vizinhos são seguros:
b. 0 ou 1 ponto seguro: “inseguro”
c. 2 ou 3 pontos seguros: “relativamente seguro”
d. 4 pontos seguros: “seguro”
Todas as coordenadas devem ser declaradas como float e seu programa deve implementar pelo menos duas
funções: uma para calcular a altura do terreno em função da coordenada (x, y) e outra função para verificar
se a coordenada (x, y) é um ponto de pouso seguro.
*/

#include <stdio.h>
#include <math.h>

float altura(float x, float y) {
    return sin(cos(y) + x) + cos(y + sin(x));
}

int ponto_seguro(float x, float y) {
    float pontos[5][2] = {
        {x, y},
        {x + 0.2, y + 0.2},
        {x - 0.2, y - 0.2},
        {x + 0.2, y - 0.2},
        {x - 0.2, y + 0.2}
    };
    
    for (int i = 0; i < 5; i++) {
        float h = altura(pontos[i][0], pontos[i][1]);
        if (h < 0 || h > 2) {
            return 0;
        }
    }
    return 1;
}

int main() {
    float x, y;
    scanf("%f", &x);
    scanf("%f", &y);
    
    if (!ponto_seguro(x, y)) {
        printf("troque de coordenada\n");
        return 0;
    }
    
    float vizinhos[4][2] = {
        {x + 2, y},
        {x - 2, y},
        {x, y + 2},
        {x, y - 2}
    };
    
    int seguros = 0;
    for (int i = 0; i < 4; i++) {
        if (ponto_seguro(vizinhos[i][0], vizinhos[i][1])) {
            seguros++;
        }
    }
    
    if (seguros <= 1) {
        printf("inseguro\n");
    } else if (seguros <= 3) {
        printf("relativamente seguro\n");
    } else {
        printf("seguro\n");
    }
    
    return 0;
}

