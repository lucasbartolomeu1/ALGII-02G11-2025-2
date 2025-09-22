#include <stdio.h>


int verificarInscricao(int vetor[], int candidato, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == candidato) {
            return 1;
        }
    }
    return 0; 
}


int consultaInscricao(int vetor_ordenado[], int candidato_consulta, int tamanho) { 
    int inicio = 0;
    int fim = tamanho - 1 ;
    while (inicio <= fim) { 
        int meio = (inicio+fim) / 2;
        if (vetor_ordenado[meio] == candidato_consulta) {
            return 1; 
        } else if (vetor_ordenado[meio] < candidato_consulta) {
            inicio = meio + 1; 
        }
        else {
            fim = meio - 1; 
        }
    } 
    return 0; 
}
