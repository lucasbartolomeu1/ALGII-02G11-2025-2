#include <stdio.h>
#include <string.h>

int posNomes(char nomes[10][50], char nome[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
     
    }
    return -1;
} 

int main() {
    char nome[50];
    char nomes[10][50];

    for (int i = 0; i < 10; i++) {
        printf("Nome %d: ", i + 1);
        scanf("%49s", nomes[i]);
    }

    int tamanho = sizeof(nomes) / sizeof(nomes[0]);

    printf("Nome que deseja encontrar a posição: ");
    scanf("%49s", nome);

    int pos = posNomes(nomes, nome, tamanho); 

    if (pos != -1) {
        printf("A posição do nome %s é %d.", nome, pos);
    } else {
        printf("O nome %s não foi encontrado.", nome);
    }

    return 0;
}