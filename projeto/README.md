# Introdução a Técnicas de Programação - Unidade 1
**Aluno**: Bruno Ferreira da Silva
**Matrícula**: 20250041199
**Período**: 2025.2
## 📁 Estrutura do Projeto
- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo
## 🚀 Projeto: Calculadora Multifuncional
**Descrição**: O código implementa uma calculadora multifuncional, que reúne uma calculadora científica e um conversor de unidades em um único programa.
A parte científica realiza operações como soma, subtração, multiplicação, divisão, potência, raiz quadrada, logaritmo, módulo e fatorial, enquanto o conversor trabalha com moedas, comprimento, área, volume, massa e velocidade. Além disso, inclui um sistema de histórico, implementado por meio de um vetor de estruturas, que armazena as expressões e resultados calculados durante a execução.
**Repositório**: https://github.com/brunofb19/bruno_ferreira-itp-2025-2.git
**Vídeo de Demonstração**: https://youtu.be/a8BIftcM2No
### Funcionalidades Implementadas:
- Calculadora científica com operações de soma, subtração, multiplicação, divisão, potência, raiz quadrada, logaritmo, módulo e fatorial;
- Conversor de unidades com suporte a moedas, comprimento, área, volume, massa e velocidade;
- Histórico de cálculos, armazenando expressões e resultados.
- Tratamento de entrada e exibição de resultados formatados.

### Conceitos da U1 Aplicados:
- Estruturas condicionais:
Utilizadas amplamente através de comandos if e else if para identificar a operação matemática escolhida pelo usuário, bem como as opções dentro dos conversores (por exemplo, escolher o tipo de unidade ou moeda).
- Estruturas de repetição:
Aplicadas com laços for no cálculo de fatoriais e do-while no controle do menu principal, permitindo que o programa repita as opções até que o usuário decida encerrar.
- Vetores:
Empregados na implementação do histórico de cálculos, onde cada elemento do vetor armazena uma estrutura (struct) contendo a expressão e o resultado.
- Funções:
O código foi dividido em múltiplas funções para organizar as funcionalidades:
calcular() → executa as operações matemáticas principais;
calculadora_cientifica() → gerencia a interface da calculadora e as chamadas de função;
conversor_moedas(), conversor_comprimento(), conversor_area(), conversor_volume(), conversor_massa() e conversor_velocidade() → realizam as conversões específicas;
add_hist(), mostrar_hist() e limpar_hist() → controlam o histórico de cálculos.

## 📚 Listas de Exercícios
### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas
### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos
### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos
### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-11: Implementações
### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial
### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido
## 🎯 Principais Aprendizados
Com este projeto, compreendi melhor o uso de estruturas condicionais, laços de repetição, funções e vetores na prática.
Aprendi também a organizar o código de forma modular, facilitando sua leitura e manutenção, além de perceber a importância da clareza e estruturação no desenvolvimento em C.
## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão 13.2.0
- **Editor**: Visual Studio Code