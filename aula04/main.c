#include <stdio.h>
#define TAMANHO_VETOR 7

int modVetor(int vetor[], int n) {
    int qtde =0;
    for (int i = 0; i < n; i++) {
        if (vetor[i] >= 10 && vetor[i] <= 20) {
            vetor[i] = 0;
            qtde++;
        }
    }

    return qtde;
}

int main() { 
    int num[TAMANHO_VETOR];
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("Valor[%d]: ", i);
        scanf("%d", &num[i]);
    }
    
    int totalMod = modVetor(num, TAMANHO_VETOR);
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");
    printf("Quantidade de modificações: %d\n", totalMod);

    return 0;
}
