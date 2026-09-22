#include "funcao1.h"

int funcao1_ocorrencias(int n, int *vetor, int k, int *buscados) {
    int total = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (buscados[i] == vetor[j]) {
                total++;
            }
        }
    }

    return total;
}
