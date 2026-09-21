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

int comparar_inteiros(const void *a, const void *b) {
    int valor_a = *(const int *)a;
    int valor_b = *(const int *)b;

    return (valor_a > valor_b) - (valor_a < valor_b);
}

void preencher_vetor_aleatorio(int n, int vetor[]) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }
}

void preencher_vetor_manual(int n, int vetor[], char nome) {
    for (int i = 0; i < n; i++) {
        printf("Insira o valor de %c[%d]: ", nome, i);
        scanf("%d", &vetor[i]);
    }
}

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
                case 1:
                    printf("\n--- Executando Função 1 ---\n");
                    // funcao1_ocorrencias()
                    break;
                    
                case 2: {
                    int n;
                    printf("Digite a dimensão N da matriz quadrada: ");
                    scanf("%d", &n);
                    
                    int matriz[n][n]; // VLA
                    
                    if (preenchimento == 2) {
                        preencher_matriz_aleatoria(n, n, matriz);
                    } else {
                        preencher_matriz_manual(n, n, matriz);
                    }
                    
                    imprimir_matriz(n, n, matriz);
                    // funcao2_pares_matriz(n, matriz);
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

                    int total = funcao3_compara_matrizes(n, A, B);
                    printf("\nTotal de elementos iguais entre A e B: %d\n", total);
                    break;
                }
                case 4:
                    printf("\n--- Executando Função 4 ---\n");
                    //funcao4_assimetricos()
                    break;
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
                        preencher_vetor_aleatorio(n, A);
                        preencher_vetor_aleatorio(n, B);
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
    printf("Equipe: [Nome 1], [Nome 2], [Nome 3], [Nome 4], [Nome 5]\n");

    // Delega todo o controle de fluxo para a função do menu
    executar_menu();

    printf("Encerrando o programa...\n");
    return 0;
}
