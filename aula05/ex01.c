#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerarMatriz(int tam, int matriz[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            matriz[i][j] = rand() % 10 + 1;
        }
    }
}


int calcularTraco(int tam, int matriz[tam][tam]) {
    int soma = 0;
    for (int i = 0; i < tam; i++) {
                soma += matriz[i][i];
            }
    return soma;
}

void mostrarMatriz(int tam, int matriz[tam][tam]) {
    printf("\n Matriz %dx%d:\n", tam, tam);
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int tam;
    printf("Calcular traço de uma matriz quadrada! \n");
    printf("Quantidade de linhas e colunas: ");
    scanf("%d", &tam); 
    int matriz[tam][tam];
    srand(time(NULL));
    gerarMatriz(tam, matriz);
    mostrarMatriz(tam, matriz);
    int tracoMatriz = calcularTraco(tam, matriz);
    printf("\nO traço da matriz %dx%d é %d\n", tam, tam, tracoMatriz);

    return 0;
}
