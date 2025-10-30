#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_HIST 100
#define TAM_EXP 200


typedef struct {
    char exp[TAM_EXP];
    float res;
} CalcHist;

CalcHist hist[MAX_HIST];
int tot_calc = 0;
int idx_hist = 0;

float calcular(char si, float a, float b);
void calculadora_cientifica();

void conversor_de_unidades();
void conversor_moedas();
void conversor_comprimento();
void conversor_area();
void conversor_volume();
void conversor_massa();
void conversor_velocidade();
void mostrar_menu_calculadora();
void processar_numero_especial(char op, float *res, char *exp);
void processar_operacao_unaria(char op, float res, char *exp, char *temp);
void processar_operacao_binaria(char op, float res, float n2, char *exp, char *temp);

void add_hist(const char* exp, float res) {
    if (tot_calc < MAX_HIST) {
        strncpy(hist[tot_calc].exp, exp, TAM_EXP - 1);
        hist[tot_calc].exp[TAM_EXP - 1] = '\0';
        hist[tot_calc].res = res;
        tot_calc++;
    } else {
        strncpy(hist[idx_hist].exp, exp, TAM_EXP - 1);
        hist[idx_hist].exp[TAM_EXP - 1] = '\0';
        hist[idx_hist].res = res;
        idx_hist = (idx_hist + 1) % MAX_HIST;
    }
}

void mostrar_hist() {
    printf("\n=== HISTORICO DE CALCULOS ===\n");
    if (tot_calc == 0) {
        printf("Nenhum calculo no historico.\n");
        return;
    }
    
    int mostrar = (tot_calc < MAX_HIST) ? tot_calc : MAX_HIST;
    int start = (tot_calc < MAX_HIST) ? 0 : idx_hist;
    
    for (int i = 0; i < mostrar; i++) {
        int pos = (start + i) % MAX_HIST;
        printf("%d: %s = %.6f\n", i + 1, hist[pos].exp, hist[pos].res);
    }
    printf("Total de calculos: %d\n", tot_calc);
}

void limpar_hist() {
    tot_calc = 0;
    idx_hist = 0;
    printf("Historico limpo!\n");
}

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

void mostrar_menu_calculadora() {
    printf("\n=== CALCULADORA CIENTIFICA ===\n");
    printf("Operadores suportados:\n");
    printf("  + (soma)        - (subtracao)   / (divisao)\n");
    printf("  * (multiplicacao) ^ (exponencial) r (raiz quadrada)\n");
    printf("  | (modulo)      ! (fatorial)    l (logaritmo base 10)\n");
    printf("\nComandos especiais:\n");
    printf("  h - historico   c - limpar historico   = - calcular e sair\n");
    printf("  p - usar pi     e - usar numero de Euler\n");
    printf("\nComo usar:\n");
    printf("  Digite: numero operador numero\n");
    printf("  Exemplo: 5 + 3 * 2 =\n");
    printf("  Ou use: p * 2 (para calcular 2 * pi)\n\n");
}

void processar_numero_especial(char op, float *res, char *exp) {
    if(op == 'p') {
        *res = 3.141592;
        strcpy(exp, "π");
    } else if(op == 'e') {
        *res = 2.718281;
        strcpy(exp, "e");
    }
}

void processar_operacao_unaria(char op, float res, char *exp, char *temp) {
    if(op == 'r') {
        sprintf(temp, " sqrt(%.6f)", res);
    } else if(op == '|') {
        sprintf(temp, " |%.6f|", res);
    } else if(op == '!') {
        sprintf(temp, " %.6f!", res);
    } else if(op == 'l') {
        sprintf(temp, " log10(%.6f)", res);
    }
}

void processar_operacao_binaria(char op, float res, float n2, char *exp, char *temp) {
    sprintf(temp, " %c %.6f", op, n2);
}

void calculadora_cientifica() {
    float res, n1, n2=0;
    char op;
    char exp[TAM_EXP] = "";
    char temp[50];

    mostrar_menu_calculadora();

    scanf("%f", &n1);
    scanf(" %c", &op);
    res=n1;
    sprintf(exp, "%.6f", n1);

    while (op!='='){
        
        if(op == 'h' || op == 'H') {
            mostrar_hist();
            printf("\nDigite a proxima operacao (ou = para sair): ");
            scanf(" %c", &op);
            continue;
        } else if(op == 'c' || op == 'C') {
            limpar_hist();
            printf("\nDigite a proxima operacao (ou = para sair): ");
            scanf(" %c", &op);
            continue;
        } 

        if(op == 'p' || op == 'e') {
            processar_numero_especial(op, &res, exp);
            scanf(" %c", &op);
        }

        if((op!='r')&&(op!='|')&&(op!='!')&&(op!='l')&&(op!='=')){
            scanf("%f", &n2);            
        }
        
        if(op!='='){
            float temp_res = res;
            res=calcular(op, res, n2);

            if(op == 'r' || op == '|' || op == '!' || op == 'l') {
                processar_operacao_unaria(op, temp_res, exp, temp);
            } else {
                processar_operacao_binaria(op, temp_res, n2, exp, temp);
            }
            strcat(exp, temp);

            scanf(" %c", &op);
        }
    }
    printf("\nresultado da operacao: %f\n", res);
    add_hist(exp, res);

    printf("\nDeseja ver o historico? (s/n): ");
    char ver_hist;
    scanf(" %c", &ver_hist);
    if(ver_hist == 's' || ver_hist == 'S') {
        mostrar_hist();
    }
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