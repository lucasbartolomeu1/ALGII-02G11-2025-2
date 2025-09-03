#include <stdio.h>

float calcularMediaTurma(float alunos[], int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += alunos[i];
    }
    float media_turma = soma / n;
    return media_turma;
}

void imprimirResultados(float alunos[], int n) {
    for (int i = 0; i < n; i++ ) {
        if (alunos[i] < 7) {
            printf("O aluno %d está de RECUPERAÇÃO.\n", i);
        }
        else {
            printf("O aluno %d está APROVADO.\n", i);
        }
    }
}

int main() {
    int qtd_alunos;
    printf("Número de estudantes: ");
    scanf("%d", &qtd_alunos);
    float alunos[qtd_alunos];
    for (int i = 0; i < qtd_alunos; i++) {
        printf("Nota do Aluno %d: ", i);
        scanf("%f", &alunos[i]);
    }

    float media_turma = calcularMediaTurma(alunos, qtd_alunos);
    printf("A média da turma é: %.1f \n", media_turma);
    imprimirResultados(alunos, qtd_alunos);
    return 0;
}
