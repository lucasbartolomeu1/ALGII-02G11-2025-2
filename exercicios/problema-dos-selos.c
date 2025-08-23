#include <stdio.h>

int main() {
    int taxa, selo5, selo3, resto, solucao;
    printf("Problema dos Selos\n");
    printf("Valor da taxa (mínimo de 8 centavos): ");
    scanf("%d", &taxa);
    if (taxa < 8) {
        printf("Erro, valor da taxa menor do que o mínimo necessário!\n");
        return 1;
    }
    for (selo5 = taxa / 5; selo5 >= 0; selo5--) {
        resto = taxa - (selo5 * 5);
    
        if (resto % 3 == 0) {
            selo3 = resto / 3;
            solucao = 1;
            break;
        }   
    }
    if (solucao) {
        printf("Para pagar %d de taxa serão necessários %d selos de 5 centavos e %d selos de 3 centavos.\n", taxa, selo5, selo3);
    }
    else {
        printf("Não foi possível encontrar uma combinação de selos para a taxa de %d\n", taxa);
    }
    return 0;
}
