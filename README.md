# Projeto AV01 - Complexidade e Computabilidade de Algoritmos

**Equipe:**
1. Matheus Ferreira Amaral
2. Guilherme Parnaiba Nunes
3. Caique Brito
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

* **Responsável:** Guilherme Parnaíba Nunes
* **Pseudocódigo:**
```text
INICIO
-  FUNCAO2_PARES_MATRIZ(n, matriz[n][n])
1    maiores_que_5 = i = j = 0
-
2    ENQUANTO i < n FAÇA
3      j = i
4      ENQUANTO j < n FAÇA
5       SE matriz[j][i] + matriz[i][j] FOR MÚTIPLO DE 5 FAÇA
6         INCREMENTA maiores_que_5
-       FIM_SE
7      INCREMENTA j
-      FIM_ENQUANTO
8    INCREMENTA i
-    FIM_ENQUANTO
-
9    RETORNE maiores_que_5
-  FIM_FUNCAO2_PARES_MATRIZ
FIM
```

* **Análise de Complexidade (Linha a linha):**
>- Linha 1: 1 <br>
>- Linha 2: n+1 <br>
>- Linha 3: n <br>
>- Linha 4: (n²+3n)/2 <br>
>- Linha 5: (n²+n)/2 <br>
>- Linha 6: (n²+n)/2 <br>
>- Linha 7: (n²+n)/2 <br>
>- Linha 8: n <br>
>- Linha 9: 1 <br>

* **Expressão de Complexidade e Big O:**
* *Expressão: 2n²+6n+3* 
```
    = 1+n+1+n+(n²+3n)/2+(n²+n)/2+(n²+n)/2+(n²+n)/2+n+1
    = 3((n²+n)/2)+((n²+3n)/2)+3n+3
    = 2n²+3n+3n+3
    = 2n²+6n+3
```
* *Big O: O(n²)*

* **Cálculo de Tempo (Entrada n=500):**
* *Pela expressão: 5,03003*10^-3*
```
    = 2(500)²+6(500)+3
    = 2(250.000)+3.000+3
    = 500.000+3.000+3
    = 503.003
    = 5,03003*10^5 (Instruções)
    Tempo = intruções/vel. de processamento (10^8 inst./s)
    Tempo = 5,03003*10^5/10^8
    Tempo = 5,03003*10^-3 segundo ou 0,00503003 segundo
```
* *Pelo Big O: 2.5*10^-3 s*
```
    = (500)²
    = 250.000
    = 2.5*10^5 (Instruções)
    Tempo = intruções/vel. de processamento (10^8 inst./s)
    Tempo = 2.5*10^5/10^8
    Tempo = 2.5*10^-3 segundo
```

---

### Função 3: Comparação de Matrizes Tridimensionais

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


* **Cálculo de Tempo (Entrada n=300):**
* ...



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
