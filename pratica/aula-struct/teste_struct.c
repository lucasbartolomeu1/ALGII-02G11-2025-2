#include <stdio.h>
#define TAM 3 

typedef struct 
{
    int codigo;
    char nome[100];
    int idade;
    int gravidade;
} Paciente;





int main() {
    Paciente pacientes[TAM];
    for (int i = 0; i < TAM; i++) {
        printf("Paciente %d \n", i+1);
        printf("Código: ");
        scanf("%d", &pacientes[i].codigo);
        getchar();
        printf("Nome: ");
        fgets(pacientes[i].nome, sizeof(pacientes[i].nome), stdin);
        printf("Idade: ");
        scanf("%d", &pacientes[i].idade);
        getchar();
        printf("Gravidade: ");
        scanf("%d", &pacientes[i].gravidade);
    }

    return 0;
}