#include "funcao5.h"

static int busca_binaria(int *vetor, int n, int valor) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor) {
            return 1;
        }

        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return 0;
}

int funcao5_busca_binaria(int n, int *A, int *B) {
    int total_encontrados = 0;

    for (int i = 0; i < n; i++) {
        if (busca_binaria(A, n, B[i])) {
            total_encontrados++;
        }
    }

    return total_encontrados;
}
