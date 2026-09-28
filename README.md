# Projeto AV01 - Complexidade e Computabilidade de Algoritmos

**Equipe:**
1. Matheus Ferreira Amaral
2. Guilherme Parnaíba Nunes
3. Caique Brito
4. Tasso Tanouss
5. Daniel Costa Carvalho Martins

---

## Como executar

Para baixar e testar o projeto localmente:

**1. Clone o repositório**

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

* **Responsável:** Matheus Ferreira Amaral

* **Pseudocódigo:**
```text
INICIO
-  FUNCAO1_OCORRENCIAS(n, vetor[n], k, buscados[k])
1    total = 0
-
2    PARA i VARIANDO DE 1 ATÉ k FAÇA
3      PARA j VARIANDO DE 1 ATÉ n FAÇA
4        SE buscados[i] = vetor[j] ENTÃO
5          total = total + 1
-        FIM_SE
-      FIM_PARA
-    FIM_PARA
-
6    RETORNE total
-  FIM_FUNCAO1_OCORRENCIAS
FIM
```

* **Análise de Complexidade (Linha a linha):**

| Linha | Comando | Execuções | Complexidade |
|:---:|---|---|:---:|
| 1 | `total = 0` | 1 | O(1) |
| 2 | `para i variando de 1 até k` | k + 1 | O(k) |
| 3 | `para j variando de 1 até n` | k(n + 1) | O(kn) |
| 4 | `se buscados[i] = vetor[j]` | kn | O(kn) |
| 5 | `total = total + 1` | kn (pior caso) | O(kn) |
| 6 | `retorne total` | 1 | O(1) |

* **Expressão de Complexidade e Big O:**
```
T(n,k) = 1 + (k + 1) + k(n + 1) + kn + kn + 1
       = 3kn + 2k + 3
```
* **Big O:** `O(nk)`

* **Cálculo de Tempo (Entrada n = 50.000, k = 4.000):**
```
T(n,k) = 3kn + 2k + 3
T(50.000, 4.000) = 3 × 50.000 × 4.000 + 2 × 4.000 + 3
T(50.000, 4.000) = 600.008.003 instruções

Tempo = instruções / vel. de processamento (10^8 inst./s)
Tempo = 600.008.003 / 100.000.000
Tempo ≈ 6,00008 segundos
```
Portanto, o tempo estimado de execução é de aproximadamente **6 segundos**.

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

| Linha | Comando | Execuções | Complexidade |
|:---:|---|---|:---:|
| 1 | `maiores_que_5 = i = j = 0` | 1 | O(1) |
| 2 | `ENQUANTO i < n` | n + 1 | O(n) |
| 3 | `j = i` | n | O(n) |
| 4 | `ENQUANTO j < n` | (n²+3n)/2 | O(n²) |
| 5 | `SE matriz[j][i]+matriz[i][j] FOR MÚLTIPLO DE 5` | (n²+n)/2 | O(n²) |
| 6 | `INCREMENTA maiores_que_5` | (n²+n)/2 (pior caso) | O(n²) |
| 7 | `INCREMENTA j` | (n²+n)/2 | O(n²) |
| 8 | `INCREMENTA i` | n | O(n) |
| 9 | `RETORNE maiores_que_5` | 1 | O(1) |

* **Expressão de Complexidade e Big O:**
```
= 1+n+1+n+(n²+3n)/2+(n²+n)/2+(n²+n)/2+(n²+n)/2+n+1
= 3((n²+n)/2)+((n²+3n)/2)+3n+3
= 2n²+3n+3n+3
= 2n²+6n+3
```
* **Big O:** `O(n²)`

* **Cálculo de Tempo (Entrada n = 500):**

*Pela expressão:*
```
= 2(500)²+6(500)+3
= 2(250.000)+3.000+3
= 500.000+3.000+3
= 503.003
= 5,03003×10^5 (instruções)

Tempo = instruções / vel. de processamento (10^8 inst./s)
Tempo = 5,03003×10^5 / 10^8
Tempo = 5,03003×10^-3 segundo ou 0,00503003 segundo
```

*Pelo Big O:*
```
= (500)²
= 250.000
= 2,5×10^5 (instruções)

Tempo = instruções / vel. de processamento (10^8 inst./s)
Tempo = 2,5×10^5 / 10^8
Tempo = 2,5×10^-3 segundo
```

---

### Função 3: Comparação de Matrizes Tridimensionais

* **Responsável:** Caique Brito

* **Pseudocódigo:**
```text
INICIO
-  FUNCAO3_COMPARA_MATRIZES(n, A, B)
1    soma_A <- 0
2    soma_B <- 0
-
3    PARA i <- 0 ATÉ n - 1 FAÇA
4      PARA j <- 0 ATÉ n - 1 FAÇA
5        PARA k <- 0 ATÉ n - 1 FAÇA
6          soma_A <- soma_A + A[i][j][k]
7          soma_B <- soma_B + B[i][j][k]
-        FIM_PARA
-      FIM_PARA
-    FIM_PARA
-
8    SE soma_A >= soma_B ENTÃO
9      RETORNE 1
-    SENÃO
-      RETORNE 0
-    FIM_SE
-  FIM_FUNCAO3_COMPARA_MATRIZES
FIM
```

* **Análise de Complexidade (Linha a linha):**

| Linha | Comando | Execuções | Complexidade |
|:---:|---|---|:---:|
| 1 | `soma_A <- 0` | 1 | O(1) |
| 2 | `soma_B <- 0` | 1 | O(1) |
| 3 | `PARA i <- 0 ATÉ n-1` | n + 1 | O(n) |
| 4 | `PARA j <- 0 ATÉ n-1` | n(n + 1) | O(n²) |
| 5 | `PARA k <- 0 ATÉ n-1` | n²(n + 1) | O(n³) |
| 6 | `soma_A <- soma_A + A[i][j][k]` | n³ | O(n³) |
| 7 | `soma_B <- soma_B + B[i][j][k]` | n³ | O(n³) |
| 8 | `SE soma_A >= soma_B` | 1 | O(1) |
| 9 | `RETORNE` | 1 | O(1) |

* **Expressão de Complexidade e Big O:**
```
T(n) = 2 + (n+1) + (n²+n) + (n³+n²) + n³ + n³ + 1 + 1
T(n) = 3n³ + 2n² + 2n + 5
```
O termo dominante é `3n³`, pois cresce muito mais rápido que os demais quando n aumenta.

* **Big O:** `O(n³)`

* **Cálculo de Tempo (Entrada n = 300):**
```
Número de operações: n³ = 300³ = 27.000.000

Tempo = instruções / vel. de processamento (10^8 inst./s)
Tempo = 27.000.000 / 100.000.000
Tempo = 0,27 segundos
```

---

### Função 4: Análise de Casos Assimétricos no Condicional

* **Responsável:** Tasso Tanouss

* **Pseudocódigo:**
```text
INICIO
-  PROCESSAR_VETOR(n, V[n])
1    somatorio = 0
-
2    PARA i DE 0 ATÉ n-1 FAÇA
3      SE V[i] MOD 2 = 0 ENTÃO
4        somatorio = somatorio + V[i]
-      SENÃO
5        fatorial = 1
6        PARA j DE 2 ATÉ V[i] FAÇA
7          fatorial = fatorial * j
-        FIM_PARA
8        somatorio = somatorio + fatorial
-      FIM_SE
-    FIM_PARA
-
9    RETORNE somatorio
-  FIM_PROCESSAR_VETOR
FIM
```

* **Análise de Complexidade — Pior caso (todos os elementos ímpares):**

*Hipótese necessária, pois o enunciado não limita o valor máximo do vetor: assume-se que cada elemento pode valer até n.*

| Linha | Comando | Execuções | Complexidade |
|:---:|---|---|:---:|
| 1 | `somatorio = 0` | 1 | O(1) |
| 2 | `PARA i DE 0 ATÉ n-1` | n + 1 | O(n) |
| 3 | `SE V[i] MOD 2 = 0` | n | O(n) |
| 4 | `somatorio = somatorio + V[i]` | 0 (nenhum par) | O(1) |
| 5 | `fatorial = 1` | n | O(n) |
| 6 | `PARA j DE 2 ATÉ V[i]` | n² | O(n²) |
| 7 | `fatorial = fatorial * j` | n² - n | O(n²) |
| 8 | `somatorio = somatorio + fatorial` | n | O(n) |
| 9 | `RETORNE somatorio` | 1 | O(1) |

* **Análise de Complexidade — Melhor caso (todos os elementos pares):**

| Linha | Execuções | Complexidade |
|:---:|---|:---:|
| 1 | 1 | O(1) |
| 2 | n + 1 | O(n) |
| 3 | n | O(n) |
| 4 | n | O(n) |
| 5–8 | 0 (laço ímpar nunca entra) | O(1) |
| 9 | 1 | O(1) |

* **Expressão de Complexidade e Big O:**

*Pior caso:*
```
T(n) = 1 (linha 1) + (n+1) (linha 2) + n (linha 3) + n (linha 5) + n² (linha 6)
     + (n²-n) (linha 7) + n (linha 8) + 1 (linha 9)
T(n) = 2n² + 3n + 3
```
**Big O (pior caso): O(n²)**

*Melhor caso:*
```
T(n) = 1 (linha 1) + (n+1) (linha 2) + n (linha 3) + n (linha 4) + 1 (linha 9)
T(n) = 3n + 3
```
**Big O (melhor caso): O(n)**

* **Cálculo de Tempo (Entrada n = 50.000, pior caso):**
```
T(n) = 2n² + 3n + 3
T(50.000) = 2 × (50.000)² + 3 × 50.000 + 3
T(50.000) = 5.000.150.003 instruções

Tempo = instruções / vel. de processamento (10^8 inst./s)
Tempo = 5.000.150.003 / 10^8
Tempo ≈ 50,0015 segundos
```

---

### Função 5: Contagem de Elementos Presentes em Vetor Ordenado

* **Responsável:** Daniel Costa Carvalho Martins

* **Pseudocódigo:**
```text
INICIO
-  BUSCA_BINARIA(A, n, valor)
1    inicio <- 0
2    fim <- n - 1
-
3    ENQUANTO inicio <= fim FAÇA
4      meio <- inicio + (fim - inicio) / 2
-
5      SE A[meio] = valor ENTÃO
6        RETORNE VERDADEIRO
-      FIM_SE
-
7      SE A[meio] < valor ENTÃO
8        inicio <- meio + 1
-      SENÃO
9        fim <- meio - 1
-      FIM_SE
-    FIM_ENQUANTO
-
10   RETORNE FALSO
-  FIM_BUSCA_BINARIA
-
-  FUNCAO5_BUSCA_BINARIA(n, A, B)
1    total_encontrados <- 0
-
2    PARA i <- 0 ATÉ n - 1 FAÇA
3      SE BUSCA_BINARIA(B, n, A[i]) ENTÃO
4        total_encontrados <- total_encontrados + 1
-      FIM_SE
-    FIM_PARA
-
5    RETORNE total_encontrados
-  FIM_FUNCAO5_BUSCA_BINARIA
FIM
```

* **Análise de Complexidade (Pior Caso):**

No pior caso, o elemento não é encontrado e a busca binária divide o vetor até o fim, executando ≈ log₂n iterações.

| Componente | Custo |
|---|:---:|
| `BUSCA_BINARIA` (por chamada) — o espaço de busca é dividido ao meio a cada iteração | O(log n) |
| Laço principal (`FUNCAO5_BUSCA_BINARIA`) — chama `BUSCA_BINARIA` n vezes | n × O(log n) |
| **Custo total** | **O(n log n)** |

* **Expressão de Complexidade e Big O:**

Como o vetor B já é fornecido **ordenado** (não é necessário ordená-lo), o custo total vem apenas do laço de n buscas binárias.

* Expressão simplificada das operações dominantes: `n log₂n`
* **Big O:** `O(n log n)`

* **Cálculo de Tempo (Entrada n = 10.000.000, pior caso da busca):**
```
T(n) = n × log2(n)
T(n) = 10.000.000 × log2(10.000.000)
T(n) ≈ 10.000.000 × 23,2535
T(n) ≈ 232.534.966 operações

Tempo = operações / vel. de processamento (10^8 inst./s)
Tempo = 232.534.966 / 100.000.000
Tempo ≈ 2,3253 segundos
```