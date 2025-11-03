#include <stdio.h>
#include <string.h>


struct Pedido {
    int codigo;
    char nome[50];
    int quantidadeItens;
    double valorTotal;
};


void trocar(struct Pedido v[], int i, int j) {
    struct Pedido temp = v[i];
    v[i] = v[j];
    v[j] = temp; 
}


int particionar(struct Pedido v[], int inicio, int fim, int indice_pivo) {
    double pivo = v[indice_pivo].valorTotal;
    int esquerda = inicio;
    int direita = fim - 1;

    while (esquerda <= direita) {
        while (esquerda <= direita && v[esquerda].valorTotal >= pivo) {
            ++esquerda;
        }
    
        while (esquerda <= direita && v[direita].valorTotal <= pivo) {
        --direita;
        }

        if (esquerda < direita) {
        trocar(v, esquerda, direita);
        }
    }

    int nova_posicao_pivo = esquerda;
    trocar(v, indice_pivo, nova_posicao_pivo);
    return nova_posicao_pivo;
}


void quick_sort(struct Pedido v[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    
    int  indice_pivo = fim; 
    indice_pivo = particionar(v, inicio, fim, indice_pivo);

    quick_sort(v, inicio, indice_pivo - 1);
    quick_sort(v, indice_pivo + 1, fim);
}


int main() {
    struct Pedido pedidos[12] = {
        {1001, "Maria Silva", 3, 450.75},
        {1002, "João Pereira", 1, 120.00},
        {1003, "Fernanda Costa", 5, 799.90},
        {1004, "Carlos Eduardo", 2, 310.50},
        {1005, "Beatriz Almeida", 4, 625.20},
        {1006, "Rafael Tavares", 6, 950.00},
        {1007, "Patrícia Gomes", 2, 299.99},
        {1008, "Luciana Ribeiro", 1, 150.00},
        {1009, "Bruno Fernandes", 3, 480.00},
        {1010, "Camila Andrade", 4, 699.90},
        {1011, "Thiago Souza", 7, 1120.00},
        {1012, "Juliana Rocha", 2, 350.30}
    };
    int n = 12; 
    quick_sort(pedidos, 0, n - 1);

    printf("--- 5 Pedidos com Maior Valor Total (Ordem Decrescente) ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Posicao %d:\n", i + 1);
        printf("  Codigo: %d\n", pedidos[i].codigo);
        printf("  Cliente: %s\n", pedidos[i].nome);
        printf("  Itens: %d\n", pedidos[i].quantidadeItens);
        printf("  Valor Total: R$ %.2f\n\n", pedidos[i].valorTotal);
    }

    return 0;
}
