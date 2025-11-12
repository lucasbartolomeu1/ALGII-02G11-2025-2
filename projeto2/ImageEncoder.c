/*
 * Projeto 2 – Codificador de Imagens Binárias
 * Disciplina: Algoritmos e Programação II
 * Universidade Presbiteriana Mackenzie
 *
 * Programa: ImageEncoder
 * 
 * Autores: [Coloque aqui seu nome e RA]
 * Link do vídeo: [cole aqui o link do vídeo no YouTube]
 *
 * Descrição:
 * Este programa lê uma imagem binária (0=branco, 1=preto) em formato PBM (P1)
 * e gera um código de texto composto por P, B e X, conforme o processo
 * descrito no enunciado do projeto.
 *
 * Uso:
 *   ./ImageEncoder -?              -> mostra o help
 *   ./ImageEncoder -f arquivo.pbm  -> lê imagem PBM e codifica
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LARGURA 1024
#define MAX_ALTURA 768

// ------------------ Funções auxiliares ------------------

// Lê um arquivo PBM e armazena os dados na matriz imagem
int lerPBM(const char *nomeArquivo, int imagem[MAX_ALTURA][MAX_LARGURA], int *largura, int *altura) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    char linha[256];
    // Lê o "magic number" (deve ser P1)
    fgets(linha, sizeof(linha), arq);
    if (strncmp(linha, "P1", 2) != 0) {
        printf("Formato invalido! O arquivo deve comecar com P1.\n");
        fclose(arq);
        return 0;
    }

    // Ignora comentários (linhas que começam com #)
    do {
        fgets(linha, sizeof(linha), arq);
    } while (linha[0] == '#');

    // Lê largura e altura
    sscanf(linha, "%d %d", largura, altura);

    // Lê os pixels (0 ou 1)
    for (int i = 0; i < *altura; i++) {
        for (int j = 0; j < *largura; j++) {
            fscanf(arq, "%d", &imagem[i][j]);
        }
    }

    fclose(arq);
    return 1;
}

// Verifica se uma subimagem é uniforme
char corUniforme(int imagem[MAX_ALTURA][MAX_LARGURA], int x1, int y1, int x2, int y2) {
    int cor = imagem[y1][x1];
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (imagem[i][j] != cor) {
                return 'X'; // não é uniforme
            }
        }
    }
    return (cor == 1) ? 'P' : 'B';
}

// Função recursiva que gera o código
void codificarImagem(int imagem[MAX_ALTURA][MAX_LARGURA], int x1, int y1, int x2, int y2) {
    char cor = corUniforme(imagem, x1, y1, x2, y2);
    if (cor == 'P' || cor == 'B') {
        printf("%c", cor);
        return;
    }

    printf("X"); // imagem mista → dividir

    int largura = x2 - x1 + 1;
    int altura = y2 - y1 + 1;

    int meioX = x1 + largura / 2;
    int meioY = y1 + altura / 2;

    // Ajusta se tamanho for ímpar (a parte de cima e a esquerda ficam maiores)
    if (largura % 2 != 0) meioX++;
    if (altura % 2 != 0) meioY++;

    // 1º quadrante (superior esquerdo)
    codificarImagem(imagem, x1, y1, meioX - 1, meioY - 1);
    // 2º quadrante (superior direito)
    codificarImagem(imagem, meioX, y1, x2, meioY - 1);
    // 3º quadrante (inferior esquerdo)
    codificarImagem(imagem, x1, meioY, meioX - 1, y2);
    // 4º quadrante (inferior direito)
    codificarImagem(imagem, meioX, meioY, x2, y2);
}

// Mostra o "help"
void mostrarAjuda() {
    printf("Uso: ImageEncoder [-? | -f ARQUIVO]\n\n");
    printf("Codifica imagens binarias dadas em arquivos PBM (P1).\n\n");
    printf("Argumentos:\n");
    printf("  -? , --help  : mostra esta ajuda.\n");
    printf("  -f , --file  : le a imagem PBM e gera o codigo.\n");
}

// ------------------ Função principal ------------------

int main(int argc, char *argv[]) {
    if (argc < 2) {
        mostrarAjuda();
        return 0;
    }

    int imagem[MAX_ALTURA][MAX_LARGURA];
    int largura, altura;

    if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "--help") == 0) {
        mostrarAjuda();
        return 0;
    } 
    else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0) {
        if (argc < 3) {
            printf("Erro: informe o nome do arquivo PBM.\n");
            return 1;
        }
        if (lerPBM(argv[2], imagem, &largura, &altura)) {
            printf("Codigo gerado: ");
            codificarImagem(imagem, 0, 0, largura - 1, altura - 1);
            printf("\n");
        }
    } 
    else {
        mostrarAjuda();
    }

    return 0;
}
