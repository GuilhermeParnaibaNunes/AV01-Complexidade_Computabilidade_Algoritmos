# Projeto AV01 - Complexidade e Computabilidade de Algoritmos

**Equipe:**
1. Matheus Ferreira Amaral
2. Guilherme Parnaiba Nunes
3. Caique Brito - 46972960 RGM
4. Tasso Tanouss
5. Daniel Costa Carvalho Martins - 37196201 RGM

## Como executar
Para baixar e testar o projeto localmente:

**1. Clone o repositório**
Para baixar e testar o projeto localmente, abra o terminal e execute:

```bash
git clone https://github.com/GuilhermeParnaibaNunes/AV01-Complexidade_Computabilidade_Algoritmos

```

**2. Acesse a pasta do projeto**

```bash
cd AV01-Complexidade_Computabilidade_Algoritmos

```

**3. Compile o código**
Como o projeto é modularizado, é necessário compilar o arquivo principal junto com todas as implementações das funções. Se estiver utilizando o **GCC** no terminal, execute:

```bash
gcc main.c funcao1.c funcao2.c funcao3.c funcao4.c funcao5.c -o projeto_av01

```

*(Nota: O projeto utiliza VLA - Variable Length Arrays. O GCC suporta isso nativamente a partir do padrão C99. Caso sua IDE ou compilador exija, você pode precisar adicionar a flag `-std=c99`)*.

**4. Execute o programa**
Após a compilação bem-sucedida, inicie o menu principal com o comando correspondente ao seu sistema operacional:

* **No Windows:**

```cmd
projeto_av01.exe

```

* **No Linux / macOS:**

```bash
./projeto_av01

```
---

## Documentação das Funções

### Função 1: Contagem de Ocorrências Distintas
* **Responsável:** [Nome]
* **Pseudocódigo:**
```text
  INICIO
    // Escreva o pseudocódigo aqui
  FIM
```

* **Análise de Complexidade (Linha a linha):**
* Linha 1: O(1)
* Linha 2: ...


* **Expressão de Complexidade e Big O:**
* Expressão: ...
* Big O: O(...)


* **Cálculo de Tempo (Entrada n=50.000, k=4.000):**
* ...



---

### Função 2: Análise de Pares em Matriz Triangular

* **Responsável:** [Nome]
* **Pseudocódigo:**
```text
INICIO
  // Escreva o pseudocódigo aqui
FIM
```

* **Análise de Complexidade (Linha a linha):**
* Linha 1: O(1)
* Linha 2: ...


* **Expressão de Complexidade e Big O:**
* Expressão: ...
* Big O: O(...)


* **Cálculo de Tempo (Entrada n=500):**
* ...



---

### Função 3: Comparação de Matrizes Tridimensionais

* **Responsável:** [Nome]
* **Pseudocódigo:**
```text
FUNÇÃO FUNCAO3_COMPARA_MATRIZES(n, A, B)
  total_iguais <- 0

  PARA i <- 0 ATÉ n - 1 FAÇA
    PARA j <- 0 ATÉ n - 1 FAÇA
      PARA k <- 0 ATÉ n - 1 FAÇA
        SE A[i][j][k] = B[i][j][k] ENTÃO
          total_iguais <- total_iguais + 1
        FIM_SE
      FIM_PARA
    FIM_PARA
  FIM_PARA

  RETORNE total_iguais
FIM_FUNÇÃO
```


* **Análise de Complexidade (Linha a linha):**
* Linha 1 (`total_iguais <- 0`): executada 1 vez -> O(1)
* Linha 2 (`PARA i`): controla o laço externo, executa n+1 vezes (n iterações + 1 teste de saída) -> O(n)
* Linha 3 (`PARA j`): aninhado em i, executa n vezes para cada i -> O(n²)
* Linha 4 (`PARA k`): aninhado em i e j, executa n vezes para cada par (i, j) -> O(n³)
* Linha 5 (`SE A[i][j][k] = B[i][j][k]`): comparação de custo constante, executada uma vez por combinação (i, j, k) -> O(n³)
* Linha 6 (`total_iguais <- total_iguais + 1`): custo constante, executada no máximo n³ vezes (pior caso: todas as posições iguais) -> O(n³)
* Linha 7 (`RETORNE total_iguais`): executada 1 vez -> O(1)


* **Expressão de Complexidade e Big O:**
* Expressão: T(n) = c1 + c2·n + c3·n² + c4·n³ + c5·n³ + c6
* O termo dominante é c4·n³ + c5·n³, pois cresce muito mais rápido que os demais quando n aumenta.
* Big O: O(n³)


* **Cálculo de Tempo (Entrada n=300):**
* Número de operações: n³ = 300³ = 27.000.000
* Considerando uma máquina de referência capaz de executar ~10⁸ (100 milhões) operações elementares por segundo:
* Tempo estimado = 27.000.000 / 100.000.000 = 0,27 segundos



---

### Função 4: Análise de Casos Assimétricos no Condicional

* **Responsável:** [Nome]
* **Pseudocódigo:**
```text
INICIO
  // Escreva o pseudocódigo aqui
FIM
```


* **Análise de Complexidade (Linha a linha):**
* Linha 1: O(1)
* Linha 2: ...


* **Expressão de Complexidade e Big O:**
* Expressão: ...
* Big O: O(...)


* **Cálculo de Tempo (Entrada n=50.000 no pior caso):**
* ...



---

### Função 5: Contagem de Elementos Presentes em Vetor Ordenado

* **Responsável:** [Nome]
* **Pseudocódigo:**
```text
FUNÇÃO BUSCA_BINARIA(A, n, valor)
  inicio <- 0
  fim <- n - 1

  ENQUANTO inicio <= fim FAÇA
    meio <- inicio + (fim - inicio) / 2

    SE A[meio] = valor ENTÃO
      RETORNE verdadeiro
    FIM_SE

    SE A[meio] < valor ENTÃO
      inicio <- meio + 1
    SENÃO
      fim <- meio - 1
    FIM_SE
  FIM_ENQUANTO

  RETORNE falso
FIM_FUNÇÃO

FUNÇÃO FUNCAO5_BUSCA_BINARIA(n, A, B)
  total_encontrados <- 0

  PARA i <- 0 ATÉ n - 1 FAÇA
    SE BUSCA_BINARIA(A, n, B[i]) ENTÃO
      total_encontrados <- total_encontrados + 1
    FIM_SE
  FIM_PARA

  RETORNE total_encontrados
FIM_FUNÇÃO
```


* **Análise de Complexidade (Linha a linha):**
* Linha 1: O(1)
* Linha 2: ...


* **Expressão de Complexidade e Big O:**
* Expressão: ...
* Big O: O(...)


* **Cálculo de Tempo (Entrada n=10.000.000):**
* ...
