#include "funcao3.h"

int funcao3_compara_matrizes(int n, int A[n][n][n], int B[n][n][n]) {
    int total_iguais = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (A[i][j][k] == B[i][j][k]) {
                    total_iguais++;
                }
            }
        }
    }

    return total_iguais;
}