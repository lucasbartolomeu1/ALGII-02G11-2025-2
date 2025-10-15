#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cargo[30];
    float salario;
} Funcionario;

void lerFuncionarios(Funcionario vet[], int n) {
    for (int i = 0; i < n; i++) {
        printf("-------------------------");
        printf("\nFuncionário %d\n", i + 1);
        
        printf("Nome: ");
        fgets(vet[i].nome, sizeof(vet[i].nome), stdin);
        vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0';

        printf("Cargo: ");
        fgets(vet[i].cargo, sizeof(vet[i].cargo), stdin);
        vet[i].cargo[strcspn(vet[i].cargo, "\n")] = '\0';

        printf("Salário: ");
        scanf("%f", &vet[i].salario);
        getchar();
    }
}

void exibirFuncionarios(Funcionario vet[], int n) {
    printf("\n### Lista de Funcionários ###\n");
    printf("%-20s | %-15s | %-10s\n", "Nome", "Cargo", "Salário");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s | %-15s | R$ %-9.2f\n", vet[i].nome, vet[i].cargo, vet[i].salario);
    }
    printf("-----------------------------------------------------------\n");
}

int indiceMaiorSalario(Funcionario vet[], int n) {
    if (n <= 0) return -1;
    int idxMax = 0;
    for (int i = 1; i < n; i++) {
        if (vet[i].salario > vet[idxMax].salario) {
            idxMax = i;
        }
    }
    return idxMax;
}

void ordenarPorNome(Funcionario vet[], int n) {
    Funcionario temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(vet[i].nome, vet[j].nome) > 0) {
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Quantidade de funcionários a serem cadastrados: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }
    getchar();

    Funcionario vet[n];
    lerFuncionarios(vet, n);
    ordenarPorNome(vet, n);
    exibirFuncionarios(vet, n);

    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += vet[i].salario;
    }
    double media = soma / n;
    printf("\nMédia dos salários: R$ %.2f\n", media);

    int idxMaior = indiceMaiorSalario(vet, n);
    if (idxMaior >= 0) {
        printf("Maior salário: %s — R$ %.2f (índice %d)\n",
               vet[idxMaior].nome, vet[idxMaior].salario, idxMaior);
    }

    return 0;
}
