#include <stdio.h>

int buscaBinaria(int vetor[], int valor, int i, int f) {
    if (i > f) 
        return -1;
    int meio = (i + f) / 2;
    if (vetor[meio] == valor) 
        return meio;
    if (vetor[meio] > valor) 
        return buscaBinaria(vetor, valor, i, meio - 1);
    else
        return buscaBinaria(vetor, valor, meio + 1, f);
}

int busca_binaria(int vetor[], int valor, int n) {
    return buscaBinaria(vetor, valor, 0, n - 1);
}

int main() {
    int v[6] = {10, 20, 30, 40, 50, 60};
    int p = busca_binaria(v, 20, 6);
    printf("%d\n", p);
    return 0;
}
