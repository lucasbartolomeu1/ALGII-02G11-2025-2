#include <stdio.h>

void converteBinario(int n) {
    if (n / 2 != 0) {
        converteBinario(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    printf("Este número em binário é: ");
    converteBinario(numero);
    printf("\n");

    return 0;
}
