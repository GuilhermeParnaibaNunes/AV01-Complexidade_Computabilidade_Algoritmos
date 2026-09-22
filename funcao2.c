#include "funcao2.h"

int funcao2_pares_matriz(int n, int matriz[n][n]) {
    int maiores_que_5 = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if((matriz[j][i] + matriz[i][j]) % 5 == 0) 
                maiores_que_5++;
        }
    }

    return maiores_que_5;
}