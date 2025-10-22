#include <stdio.h>

int Fib(int n) {
    if (n < 2) {
        return n;
    }
    return Fib(n-1) + Fib(n-2);
}

int main() {
    int n, r;
    printf("Calcular termo na sequência de Fibonacci");
    printf("\nDigite a posição do termo: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        r = Fib(i);
        printf("%d ", r);
    } 
    printf("\n");
    return 0;
}