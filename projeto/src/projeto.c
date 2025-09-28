#include <stdio.h>
#include <math.h>

float calcular(char si, float a, float b);
void calculadora_cientifica();

void conversor_de_unidades();
void conversor_moedas();
void conversor_comprimento();
void conversor_area();
void conversor_volume();
void conversor_massa();
void conversor_velocidade();


float calcular(char si, float a, float b){
    float res_aux = 1;
    
    if(si == '+') {
        res_aux = a + b;
    } else if (si == '-') {
        res_aux = a - b;
    } else if (si == '/') {
        if(b == 0) {
            printf("Erro: Divisao por zero!\n");
            return 0;
        }
        res_aux = a / b;
    } else if (si == '*') {
        res_aux = a * b;
    } else if (si == '^') {
        res_aux = powf(a, b);
    } else if (si == 'r') {
        if(a < 0) {
            printf("Erro: Raiz quadrada de numero negativo!\n");
            return 0;
        }
        res_aux = sqrtf(a);
    } else if (si == '|') {
        res_aux = fabsf(a);
    } else if (si == '!') {
        if(a < 0 || a != (int)a) {
            printf("Erro: Fatorial de numero negativo ou nao inteiro!\n");
            return 0;
        }
        res_aux = 1;
        for(int i = (int)a; i > 1; i--) {
            res_aux *= i;
        }
    } else if (si == 'l') {
        if(a <= 0) {
            printf("Erro: Logaritmo de numero nao positivo!\n");
            return 0;
        }
        res_aux = log10f(a);
    } else {
        printf("Operador invalido: %c\n", si);
        return a;
    }
    
    return res_aux;
}

void calculadora_cientifica() {
    float res, n1, n2=0;
    char op;

    printf("\n=== CALCULADORA CIENTIFICA ===\n");
    printf("operadores suportados: +(soma), -(subtração), /(divisão), *(multplicação), ^(exponencial), r(raiz quadrada), |(modulo), !(fatorial), l(logaritmo)\n");
    printf("como usar: digite o primeiro numero, a operacao e o segundo numero, apos isso, caso queira o resultado, digite o simbolo de '=', caso queira calcular em cima do resultado da operacao realizada, digite novamente mais um operador seguido de mais um numero\n");
    printf("caso queira utilizar um numero irracional (pi ou euler), ao inves de digitar um operador, digite 'p' para pi ou 'e' para euler, e depois digite a operação juntamente com o segundo numero (caso seja uma operação que necessite) novamente \n\n");

    scanf("%f", &n1);
    scanf(" %c", &op);
    res=n1;

    while (op!='='){
        if(op=='p'){
            res=3.141592;
            scanf(" %c", &op);
        } else if(op=='e'){
            res=2.718281;
            scanf(" %c", &op);
        }
        if((op!='r')&&(op!='|')&&(op!='!')&&(op!='l')){
            scanf("%f", &n2);            
        }
        if(op!='='){
            res=calcular(op, res, n2);
            scanf(" %c", &op);
        }
    }
    printf("\nresultado da operacao: %f\n", res);
}

void conversor_de_unidades(){
    int gp;
    
    printf("\n=== CONVERSOR DE UNIDADES ===\n");
    printf("Selecione o grupo de unidades:\n");
    printf("1 - Moedas\n");
    printf("2 - Comprimento\n");
    printf("3 - Area\n");
    printf("4 - Volume\n");
    printf("5 - Massa\n");
    printf("6 - Velocidade\n");
    printf("Opcao: ");
    scanf("%d", &gp);
    
    if(gp == 1) {
        conversor_moedas();
    } else if(gp == 2) {
        conversor_comprimento();
    } else if(gp == 3) {
        conversor_area();
    } else if(gp == 4) {
        conversor_volume();
    } else if(gp == 5) {
        conversor_massa();
    } else if(gp == 6) {
        conversor_velocidade();
    } else {
        printf("Grupo invalido!\n");
    }
}

void conversor_moedas() {
    int op1, op2;
    float val, res;
    
    printf("\n=== CONVERSOR DE MOEDAS ===\n");
    printf("Unidades disponiveis:\n");
    printf("1 - Dolar Americano (USD)\n");
    printf("2 - Euro (EUR)\n");
    printf("3 - Real Brasileiro (BRL)\n");
    printf("4 - Libra Esterlina (GBP)\n");
    printf("5 - Iene Japones (JPY)\n");
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    
    float usd_eur = 0.85;
    float usd_brl = 5.20;
    float usd_gbp = 0.73;
    float usd_jpy = 110.50;
    
    float val_usd;
    if(op1 == 1) {
        val_usd = val;
    } else if(op1 == 2) {
        val_usd = val / usd_eur;
    } else if(op1 == 3) {
        val_usd = val / usd_brl;
    } else if(op1 == 4) {
        val_usd = val / usd_gbp;
    } else if(op1 == 5) {
        val_usd = val / usd_jpy;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    if(op2 == 1) {
        res = val_usd;
    } else if(op2 == 2) {
        res = val_usd * usd_eur;
    } else if(op2 == 3) {
        res = val_usd * usd_brl;
    } else if(op2 == 4) {
        res = val_usd * usd_gbp;
    } else if(op2 == 5) {
        res = val_usd * usd_jpy;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    printf("\nResultado: %.2f\n", res);
}

void conversor_comprimento() {
    int op1, op2;
    float val, res;
    
    printf("\n=== CONVERSOR DE COMPRIMENTO ===\n");
    printf("Unidades disponiveis:\n");
    printf("1 - Metro (m)\n");
    printf("2 - Centimetro (cm)\n");
    printf("3 - Quilometro (km)\n");
    printf("4 - Milimetro (mm)\n");
    printf("5 - Pe (ft)\n");
    printf("6 - Jarda (yd)\n");
    printf("7 - Polegada (in)\n");
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    
    float val_m;
    if(op1 == 1) {
        val_m = val;
    } else if(op1 == 2) {
        val_m = val / 100;
    } else if(op1 == 3) {
        val_m = val * 1000;
    } else if(op1 == 4) {
        val_m = val / 1000;
    } else if(op1 == 5) {
        val_m = val * 0.3048;
    } else if(op1 == 6) {
        val_m = val * 0.9144;
    } else if(op1 == 7) {
        val_m = val * 0.0254;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    if(op2 == 1) {
        res = val_m;
    } else if(op2 == 2) {
        res = val_m * 100;
    } else if(op2 == 3) {
        res = val_m / 1000;
    } else if(op2 == 4) {
        res = val_m * 1000;
    } else if(op2 == 5) {
        res = val_m / 0.3048;
    } else if(op2 == 6) {
        res = val_m / 0.9144;
    } else if(op2 == 7) {
        res = val_m / 0.0254;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    printf("\nResultado: %.6f\n", res);
}

void conversor_area() {
    int op1, op2;
    float val, res;
    
    printf("\n=== CONVERSOR DE AREA ===\n");
    printf("Unidades disponiveis:\n");
    printf("1 - Metro quadrado (m²)\n");
    printf("2 - Quilometro quadrado (km²)\n");
    printf("3 - Centimetro quadrado (cm²)\n");
    printf("4 - Hectare (ha)\n");
    printf("5 - Pe quadrado (ft²)\n");
    printf("6 - Acre (ac)\n");
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    
    float val_m2;
    if(op1 == 1) {
        val_m2 = val;
    } else if(op1 == 2) {
        val_m2 = val * 1000000;
    } else if(op1 == 3) {
        val_m2 = val / 10000;
    } else if(op1 == 4) {
        val_m2 = val * 10000;
    } else if(op1 == 5) {
        val_m2 = val * 0.092903;
    } else if(op1 == 6) {
        val_m2 = val * 4046.86;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    if(op2 == 1) {
        res = val_m2;
    } else if(op2 == 2) {
        res = val_m2 / 1000000;
    } else if(op2 == 3) {
        res = val_m2 * 10000;
    } else if(op2 == 4) {
        res = val_m2 / 10000;
    } else if(op2 == 5) {
        res = val_m2 / 0.092903;
    } else if(op2 == 6) {
        res = val_m2 / 4046.86;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    printf("\nResultado: %.6f\n", res);
}

void conversor_volume() {
    int op1, op2;
    float val, res;
    
    printf("\n=== CONVERSOR DE VOLUME ===\n");
    printf("Unidades disponiveis:\n");
    printf("1 - Metro cubico (m³)\n");
    printf("2 - Litro (L)\n");
    printf("3 - Centimetro cubico (cm³)\n");
    printf("4 - Mililitro (mL)\n");
    printf("5 - Galao americano (gal)\n");
    printf("6 - Onca fluida (fl oz)\n");
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    
    float val_l;
    if(op1 == 1) {
        val_l = val * 1000;
    } else if(op1 == 2) {
        val_l = val;
    } else if(op1 == 3) {
        val_l = val / 1000;
    } else if(op1 == 4) {
        val_l = val / 1000;
    } else if(op1 == 5) {
        val_l = val * 3.78541;
    } else if(op1 == 6) {
        val_l = val * 0.0295735;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    

    if(op2 == 1) {
        res = val_l / 1000;
    } else if(op2 == 2) {
        res = val_l;
    } else if(op2 == 3) {
        res = val_l * 1000;
    } else if(op2 == 4) {
        res = val_l * 1000;
    } else if(op2 == 5) {
        res = val_l / 3.78541;
    } else if(op2 == 6) {
        res = val_l / 0.0295735;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    printf("\nResultado: %.6f\n", res);
}

void conversor_massa() {
    int op1, op2;
    float val, res;
    
    printf("\n=== CONVERSOR DE MASSA ===\n");
    printf("Unidades disponiveis:\n");
    printf("1 - Quilograma (kg)\n");
    printf("2 - Grama (g)\n");
    printf("3 - Miligrama (mg)\n");
    printf("4 - Tonelada (t)\n");
    printf("5 - Libra (lb)\n");
    printf("6 - Onca (oz)\n");
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    

    float val_kg;
    if(op1 == 1) {
        val_kg = val;
    } else if(op1 == 2) {
        val_kg = val / 1000;
    } else if(op1 == 3) {
        val_kg = val / 1000000;
    } else if(op1 == 4) {
        val_kg = val * 1000;
    } else if(op1 == 5) {
        val_kg = val * 0.453592;
    } else if(op1 == 6) {
        val_kg = val * 0.0283495;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    if(op2 == 1) {
        res = val_kg;
    } else if(op2 == 2) {
        res = val_kg * 1000;
    } else if(op2 == 3) {
        res = val_kg * 1000000;
    } else if(op2 == 4) {
        res = val_kg / 1000;
    } else if(op2 == 5) {
        res = val_kg / 0.453592;
    } else if(op2 == 6) {
        res = val_kg / 0.0283495;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    printf("\nResultado: %.6f\n", res);
}

void conversor_velocidade() {
    int op1, op2;
    float val, res;
    
    printf("\n=== CONVERSOR DE VELOCIDADE ===\n");
    printf("Unidades disponiveis:\n");
    printf("1 - Metro por segundo (m/s)\n");
    printf("2 - Quilometro por hora (km/h)\n");
    printf("3 - Milha por hora (mph)\n");
    printf("4 - Pe por segundo (ft/s)\n");
    printf("5 - No (kn)\n");
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    
    float val_ms;
    if(op1 == 1) {
        val_ms = val;
    } else if(op1 == 2) {
        val_ms = val / 3.6;
    } else if(op1 == 3) {
        val_ms = val * 0.44704;
    } else if(op1 == 4) {
        val_ms = val * 0.3048;
    } else if(op1 == 5) {
        val_ms = val * 0.514444;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    if(op2 == 1) {
        res = val_ms;
    } else if(op2 == 2) {
        res = val_ms * 3.6;
    } else if(op2 == 3) {
        res = val_ms / 0.44704;
    } else if(op2 == 4) {
        res = val_ms / 0.3048;
    } else if(op2 == 5) {
        res = val_ms / 0.514444;
    } else {
        printf("Opcao invalida!\n");
        return;
    }
    
    printf("\nResultado: %.6f\n", res);
}


int main() {
    char sel;
    int aux=1;
    do{
        printf("ola, esta eh a sua calculadora multi funcao\n");
        printf("selecione a opcao de calculadora que voce deseja:\n C - (calculadora cientifica)\n U - (conversor de unidades)\n");
        scanf(" %c", &sel);
        if(sel=='C' || sel=='c'){
            calculadora_cientifica();
            aux = 0;
        } else if(sel=='U' || sel=='u'){
            conversor_de_unidades();
            aux = 0;
        } else{
            printf("digite a opcao certa\n");
        }
    }while(aux==1);

    return 0;
}