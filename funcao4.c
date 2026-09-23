#include "funcao4.h"

int funcao4_assimetricos(int n, int *vetor) {
    if (n <= 1) {
        return 1; 
    }

    for (int i = 0; i < n - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return 0; 
        }
    }

    return 1; 
}
