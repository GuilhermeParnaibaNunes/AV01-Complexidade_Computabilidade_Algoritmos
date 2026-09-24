#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// --- Inclusão dos Cabeçalhos das Funções ---
#include "funcao1.h"
#include "funcao2.h"
#include "funcao3.h"
#include "funcao4.h"
#include "funcao5.h"

// --- Funções Utilitárias ---

// Função para imprimir matriz 2D
void imprimir_matriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("\nMatriz Gerada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para preencher matriz com valores aleatórios
void preencher_matriz_aleatoria(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 100; // Valores de 0 a 99
        }
    }
}

// Função para preencher matriz com valores manuais
void preencher_matriz_manual(int linhas, int colunas, int matriz[linhas][colunas]) {
    int valor;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Insira o valor a ser inserido na posição:\n"
                    "\tmatriz[%d][%d] = ", i+1, j+1);
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }
}

// Função para imprimir a matriz 3D
void imprimir_matriz_3d(int n, int matriz[n][n][n]){
    for (int i = 0; i < n; i++) {
        printf("Camada %d:\n", i+1);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%4d ", matriz[i][j][k]);
            }
            printf("\n"); // Quebra de linha após cada linha da matriz 2D
        }
        printf("\n"); // Linha em branco entre camadas
    }
}

// Função para preencher matriz 3D com valores aleatórios
void preencher_matriz_aleatoria_3d(int n, int matriz[n][n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                matriz[i][j][k] = rand() % 100;
}

// Função para preencher matriz 3D com valores manuais
void preencher_matriz_manual_3d(int n, char nome, int matriz[n][n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                printf("%c[%d][%d][%d] = ", nome, i, j, k);
                scanf("%d", &matriz[i][j][k]);
            }
}

// Função para comparar inteiros
int comparar_inteiros(const void *a, const void *b) {
    int valor_a = *(const int *)a;
    int valor_b = *(const int *)b;

    return (valor_a > valor_b) - (valor_a < valor_b);
}

// Função para preencher vetor com valores aleatórios
void preencher_vetor_aleatorio(int n, int vetor[], int limite) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % limite;
    }
}

// Função para preencher vetor com valores manuais
void preencher_vetor_manual(int n, int vetor[], char nome) {
    for (int i = 0; i < n; i++) {
        printf("Insira o valor de %c[%d]: ", nome, i);
        scanf("%d", &vetor[i]);
    }
}

// Função para imprimir vetor
void imprimir_vetor(int n, int vetor[], char nome) {
    printf("\nVetor %c:\n", nome);
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// --- Encapsulamento Total do Fluxo do Menu ---
void executar_menu() {
    int opcao;
    
    do {
        printf("\n=======================================\n");
        printf("1. Contagem de Ocorrências Distintas\n");
        printf("2. Análise de Pares em Matriz Triangular\n");
        printf("3. Comparação de Matrizes Tridimensionais\n");
        printf("4. Análise de Casos Assimtricos no Condicional\n");
        printf("5. Contagem de Elementos Presentes em Vetor Ordenado\n");
        printf("0. Sair\n");
        printf("Escolha uma função: ");
        scanf("%d", &opcao);
        puts("");
        
        if (!opcao) break;

        // Checa se opção fornecida é válida
        if (opcao < 0 || opcao > 5) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }
        
        int preenchimento;
        printf("Selecione como deseja preencher os dados:"
                "\n\t(1) - Manualmente"
                "\n\t(2) - Automaticamente\n\t");
        scanf("%d", &preenchimento);

        switch (opcao) {
            case 1: {
                int n, k;

                printf("\n--- Executando Função 1 ---\n");

                printf("Digite o tamanho do vetor principal: ");
                scanf("%d", &n);

                printf("Digite a quantidade de elementos buscados: ");
                scanf("%d", &k);

                if (n <= 0 || k <= 0) {
                    printf("Tamanho inválido!\n");
                    break;
                }

                int vetor[n];
                int buscados[k];

                if (preenchimento == 2) {
                    preencher_vetor_aleatorio(n, vetor, 100);
                    preencher_vetor_aleatorio(k, buscados, 100);
                } else {
                    preencher_vetor_manual(n, vetor, 'A');
                    preencher_vetor_manual(k, buscados, 'B');
                }

                imprimir_vetor(n, vetor, 'A');
                imprimir_vetor(k, buscados, 'B');

                int total = funcao1_ocorrencias(n, vetor, k, buscados);

                printf("\nTotal de ocorrências encontradas: %d\n", total);

                break;
            }
            
            case 2: {
                int n;

                printf("\n--- Executando Função 2 ---\n");
                printf("Digite a dimensão N da matriz quadrada: ");
                scanf("%d", &n);
                
                int matriz[n][n]; // VLA
                
                if (preenchimento == 2) {
                    preencher_matriz_aleatoria(n, n, matriz);
                } else {
                    preencher_matriz_manual(n, n, matriz);
                }
                
                imprimir_matriz(n, n, matriz);
                int pares_m5 = funcao2_pares_matriz(n, matriz);

                printf("\nA quantidade de pares múltiplos de 5 é de:\n"
                        "\t- %d par(es).\n", pares_m5);
                break;
            }
            
            case 3: {
                int n;
                printf("\n--- Executando Função 3 ---\n");
                printf("Digite a dimensão N das matrizes (NxNxN): ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Tamanho inválido!\n");
                    break;
                }

                int A[n][n][n];
                int B[n][n][n];

                if (preenchimento == 2) {
                    preencher_matriz_aleatoria_3d(n, A);
                    preencher_matriz_aleatoria_3d(n, B);
                } else {
                    preencher_matriz_manual_3d(n, 'A', A);
                    preencher_matriz_manual_3d(n, 'B', B);
                }

                printf("*** Matriz A ***\n");
                imprimir_matriz_3d(n, A);
                printf("*** Matriz B ***\n");
                imprimir_matriz_3d(n, B);

                int maior_ou_igual = funcao3_compara_matrizes(n, A, B);
                printf("\nA soma total de A é %s soma total de B.\n", maior_ou_igual ? "maior ou igual à" : "menor do que a");
                break;
            }
        
            case 4: {
                int n;

                printf("\n--- Executando Função 4 ---\n");
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Tamanho inválido!\n");
                    break;
                }

                int vetor[n];

                if (preenchimento == 2) {
                    preencher_vetor_aleatorio(n, vetor, 15);
                } else {
                    preencher_vetor_manual(n, vetor, 'A');
                }

                imprimir_vetor(n, vetor, 'A');

                unsigned long long somatorio = funcao4_assimetricos(n, vetor);

                printf("\nSomatório resultante (pares somados diretamente, "
                        "ímpares somados como fatorial): %lu\n", somatorio);

                break;
            }

            case 5: {
                int n;

                printf("\n--- Executando Função 5 ---\n");
                printf("Digite o tamanho dos vetores: ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Tamanho inválido!\n");
                    break;
                }

                int A[n];
                int B[n];

                if (preenchimento == 2) {
                    preencher_vetor_aleatorio(n, A, 100);
                    preencher_vetor_aleatorio(n, B, 100);
                } else {
                    preencher_vetor_manual(n, A, 'A');
                    preencher_vetor_manual(n, B, 'B');
                }

                qsort(A, n, sizeof(int), comparar_inteiros);

                imprimir_vetor(n, A, 'A');
                imprimir_vetor(n, B, 'B');

                int total = funcao5_busca_binaria(n, A, B);
                printf("\nTotal de elementos de B encontrados em A: %d\n", total);
                break;
            }
        }   
    } while (opcao != 0);
}

// --- Função Principal ---
int main() {
    // Inclui os caracteres do português ao sistema
    setlocale(LC_ALL, "pt-BR");

    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));

    // A regra exige a exibição dos nomes dos 5 membros no programa
    printf("Equipe:\n"
            "\t - Matheus Ferreira Amaral\n"
            "\t - Guilherme Parnaíba Nunes\n"
            "\t - Caique Brito\n"
            "\t - Tasso Tanouss\n"
            "\t - Daniel Costa Carvalho Martins\n");

    // Delega todo o controle de fluxo para a função do menu
    executar_menu();

    printf("Encerrando o programa...\n");
    return 0;
}
