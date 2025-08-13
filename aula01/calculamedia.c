#include <stdio.h>

int main() {
    float nota1, nota2;
    printf("Nota 1: ");
    scanf("&f", &nota1);
    printf("Nota 2: ");
    scanf("%f", &nota2);
    float media = (nota1 + nota2) / 2;
    printf("Media = %f\n", &media);
    return 0;
}