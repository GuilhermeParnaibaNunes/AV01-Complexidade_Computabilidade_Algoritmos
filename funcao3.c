#include <stdio.h>
#include "funcao3.h"

int funcao3_compara_matrizes(int n, int A[n][n][n], int B[n][n][n]) {
    long long soma_A = 0;
    long long soma_B = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                soma_A += A[i][j][k];
                soma_B += B[i][j][k];
            }
        }
    }

    printf("Soma total de A: %lld\n", soma_A);
    printf("Soma total de B: %lld\n", soma_B);
    return soma_A >= soma_B;
}