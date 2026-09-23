#include "funcao4.h"

int funcao4_assimetricos(int n, int *vetor) {
    int somatorio = 0;

    for (int i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            // Caminho barato: apenas soma o valor atual
            somatorio += vetor[i];
        } else {
            // Caminho caro: calcula o fatorial de vetor[i]
            int fatorial = 1;
            for (int j = 2; j <= vetor[i]; j++) {
                fatorial *= j;
            }
            somatorio += fatorial;
        }
    }

    return somatorio;
}
