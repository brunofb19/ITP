#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_HIST 100
#define TAM_EXP 200


typedef struct {
    char exp[TAM_EXP];
    float res;
} CalcHist;

CalcHist *hist = NULL;
int tot_calc = 0;
int capacidade_hist = 0;

float calcular(char si, float a, float b);
void calculadora_cientifica();
void mostrar_menu_calculadora();
void processar_numero_especial(char op, float *res, char *exp);
void processar_operacao_unaria(char op, float res, char *exp, char *temp);
void processar_operacao_binaria(char op, float res, float n2, char *exp, char *temp);

void conversor_de_unidades();
void conversor_moedas();
void conversor_comprimento();
void conversor_area();
void conversor_volume();
void conversor_massa();
void conversor_velocidade();
void mostrar_menu_unidades(const char* titulo, const char* unidades[], int num_unidades);
int opcao_valida(int op, int max_op);
int criar_conversor (const char** nomes_unidades, float* fatores, int num_unidades, const char* titulo, float *resultado);

int expandir_historico() {
    int nova_capacidade = (capacidade_hist == 0) ? 10 : capacidade_hist * 2;

    CalcHist *novo_hist = (CalcHist*)realloc(hist, nova_capacidade * sizeof(CalcHist));
    
    if (novo_hist == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para o historico!\n");
        return 0;
    }
    
    hist = novo_hist;
    capacidade_hist = nova_capacidade;
    return 1;
}

void add_hist(const char* exp, float res) {

    if(exp == NULL) return;


    if (tot_calc >= capacidade_hist) {
        if (!expandir_historico()) {
            return; 
        }
    }
    
    CalcHist *elemento = &hist[tot_calc];
    strncpy(elemento->exp, exp, TAM_EXP - 1);
    elemento->exp[TAM_EXP - 1] = '\0';
    elemento->res = res;
    tot_calc++;
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
    if (hist != NULL) {
        free(hist);
        hist = NULL;
        tot_calc = 0;
        capacidade_hist = 0;
        printf("Memoria do historico liberada!\n");
    }
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
    
    const char* grupos[] = {
        "Moedas",
        "Comprimento",
        "Area", 
        "Volume",
        "Massa",
        "Velocidade"
    };
    
    for(int i = 0; i < 6; i++) {
        printf("%d - %s\n", i + 1, grupos[i]);
    }
    printf("Opcao: ");
    scanf("%d", &gp);
    
    void (*funcoes_conversor[])() = {
        conversor_moedas,
        conversor_comprimento,
        conversor_area,
        conversor_volume, 
        conversor_massa,
        conversor_velocidade
    };
    
    if(opcao_valida(gp, 6)) {
        funcoes_conversor[gp - 1]();
    } else {
        printf("Grupo invalido!\n");
    }
}

void mostrar_menu_unidades(const char* titulo, const char* unidades[], int num_unidades) {
    printf("\n=== %s ===\n", titulo);
    printf("Unidades disponiveis:\n");
    for(int i = 0; i < num_unidades; i++) {
        printf("%d - %s\n", i + 1, unidades[i]);
    }
}

int opcao_valida(int op, int max_op) {
    return (op >= 1 && op <= max_op);
}

int criar_conversor(const char** nomes_unidades, float* fatores, int num_unidades, const char* titulo, float *resultado) {

    if(nomes_unidades == NULL || fatores == NULL || resultado == NULL) {
        printf("Erro: Ponteiros invalidos!\n");
        return 0;
    }
    
    mostrar_menu_unidades(titulo, nomes_unidades, num_unidades);
    
    int op1, op2;
    float val;
    
    printf("Selecione a unidade de origem: ");
    scanf("%d", &op1);
    printf("Selecione a unidade de destino: ");
    scanf("%d", &op2);
    printf("Digite o valor: ");
    scanf("%f", &val);
    
    if(!opcao_valida(op1, num_unidades) || !opcao_valida(op2, num_unidades)) {
        printf("Opcao invalida!\n");
        return 0;
    }
    
    *resultado = val * fatores[op1 - 1] / fatores[op2 - 1];
    return 1;
}

void conversor_moedas() {
    float res;
    
    const char* unidades[] = {
        "Dolar Americano (USD)",
        "Euro (EUR)", 
        "Real Brasileiro (BRL)",
        "Libra Esterlina (GBP)",
        "Iene Japones (JPY)"
    };

    float fatores[] = {1.0, 0.85, 5.20, 0.73, 110.50};
    int num_unidades = 5;
    
    if(criar_conversor(unidades, fatores, num_unidades, "CONVERSOR DE MOEDAS", &res)) {
        printf("\nResultado: %.2f\n", res);
    }
}

void conversor_comprimento() {
    float res;
    
    const char* unidades[] = {
        "Metro (m)",
        "Centimetro (cm)", 
        "Quilometro (km)",
        "Milimetro (mm)",
        "Pe (ft)",
        "Jarda (yd)", 
        "Polegada (in)"
    };
    int num_unidades = 7;
    float fatores[] = {1.0, 0.01, 1000.0, 0.001, 0.3048, 0.9144, 0.0254};
    
    if(criar_conversor(unidades, fatores, num_unidades, "CONVERSOR DE COMPRIMENTO", &res)) {
        printf("\nResultado: %.6f\n", res);
    }

}

void conversor_area() {
    float res;
    
    const char* unidades[] = {
        "Metro quadrado (m²)",
        "Quilometro quadrado (km²)", 
        "Centimetro quadrado (cm²)",
        "Hectare (ha)",
        "Pe quadrado (ft²)",
        "Acre (ac)"
    };
    
    float fatores[] = {1.0, 1000000.0, 0.0001, 10000.0, 0.092903, 4046.86};
    int num_unidades = 6;

    if(criar_conversor(unidades, fatores, num_unidades, "CONVERSOR DE AREA", &res)) {
        printf("\nResultado: %.6f\n", res);
    }

}

void conversor_volume() {
    float res;

    const char* unidades[] = {
        "Metro cubico (m³)",
        "Litro (L)",
        "Centimetro cubico (cm³)",
        "Mililitro (mL)",
        "Galao americano (gal)",
        "Onca fluida (fl oz)"
    };
    
    float fatores[] = {1000.0, 1.0, 0.001, 0.001, 3.78541, 0.0295735};
    int num_unidades = 6;
    
    if(criar_conversor(unidades, fatores, num_unidades, "CONVERSOR DE VOLUME", &res)) {
        printf("\nResultado: %.6f\n", res);
    }
}

void conversor_massa() {
    float res;
    
    const char* unidades[] = {
        "Quilograma (kg)",
        "Grama (g)",
        "Miligrama (mg)",
        "Tonelada (t)",
        "Libra (lb)",
        "Onca (oz)"
    };
    
    float fatores[] = {1.0, 0.001, 0.000001, 1000.0, 0.453592, 0.0283495};
    int num_unidades = 6;
    
    if(criar_conversor(unidades, fatores, num_unidades, "CONVERSOR DE MASSA", &res)) {
        printf("\nResultado: %.6f\n", res);
    }
}

void conversor_velocidade() {
    float res;
    
    const char* unidades[] = {
        "Metro por segundo (m/s)",
        "Quilometro por hora (km/h)",
        "Milha por hora (mph)",
        "Pe por segundo (ft/s)",
        "No (kn)"
    };
    
    float fatores[] = {1.0, 1.0/3.6, 0.44704, 0.3048, 0.514444};
    int num_unidades = 5;
    
    if(criar_conversor(unidades, fatores, num_unidades, "CONVERSOR DE VELOCIDADE", &res)) {
        printf("\nResultado: %.6f\n", res);
    }
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