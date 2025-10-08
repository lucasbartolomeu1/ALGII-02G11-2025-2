#include <stdio.h>
#define TAM 10

typedef struct 
{
    int codigo;
    char nome[100];
    int idade;
    int gravidade;
} Paciente;

void imprimirPacientes(Paciente pacientes[], int n) { 
    for (int i = 0; i < n; i++) {
        printf("\n---------------------------------------");
        printf("\nCódigo: %d", pacientes[i].codigo);
        printf("\nPaciente %d", i+1);
        printf("\nNome: %s", pacientes[i].nome);
        printf("\nIdade: %d", pacientes[i].idade);
        printf("\nGravidade: %d", pacientes[i].gravidade);
    }
}

int main() {
    Paciente pacientes[10] = {
    {101, "Ana Paula", 45, 85},
    {102, "Carlos Eduardo", 60, 92},
    {103, "Fernanda Lima", 33, 76},
    {104, "João Marcos", 70, 98},
    {105, "Luciana Alves", 55, 88},
    {106, "Bruno Rocha", 40, 69},
    {107, "Marta Silva", 28, 58},
    {108, "Rafael Tavares", 38, 73},
    {109, "Juliana Costa", 49, 91},
    {110, "Roberto Teixeira",65, 94}
    };
    imprimirPacientes(pacientes, TAM);
    return 0;
}
