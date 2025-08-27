#include <stdio.h>

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 1; i<=expoente; i++) { 
        resultado *= base;
    }
    return resultado;
}

int main() {
    int base, expoente, resultado;
    printf("Calcula potenciação, base: ");
    scanf("%d", &base);
    printf("expoente: ");
    scanf("%d", &expoente);
    resultado = potencia(base, expoente);
    printf("Resultado: %d\n", resultado);
    return 0;
}