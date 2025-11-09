#include "imagem.h"
#include <stdio.h>
#include <string.h> // para strcmp

// Implementação da leitura manual
void lerImagemModoManual(Imagem *img) {
    printf("Digite a largura da imagem: ");
    scanf("%d", &img->largura);

    printf("Digite a altura da imagem: ");
    scanf("%d", &img->altura);

    if (img->largura > MAX_LARG || img->altura > MAX_ALT) {
        printf("Erro: Dimensões excedem o limite de %dx%d.\n", MAX_LARG, MAX_ALT);
        img->largura = 0;
        img->altura = 0;
        return;
    }

    printf("Digite os pixels (0 para branco, 1 para preto), linha por linha:\n");
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            scanf("%d", &img->dados[i][j]);
        }
    }
}

// Implementação da leitura de arquivo PBM
int lerImagemArquivoPBM(Imagem *img, char* nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "r");
    if (f == NULL) {
        printf("Erro: Não foi possível abrir o arquivo '%s'\n", nomeArquivo);
        return 1;
    }

    // 1. Ler Magic Number
    char magicNum[3];
    fscanf(f, "%2s", magicNum);
    if (strcmp(magicNum, "P1") != 0) { // [cite: 99]
        printf("Erro: Formato de arquivo não suportado. Esperado 'P1'.\n");
        fclose(f);
        return 1;
    }

    // 2. Ignorar comentários e ler dimensões
    char ch;
    // Pula para a próxima linha após o P1
    while ((ch = fgetc(f)) != '\n' && ch != EOF); 

    while ((ch = fgetc(f)) == '#') { // Se a linha é um comentário [cite: 104]
        // Descarta o resto da linha
        while ((ch = fgetc(f)) != '\n' && ch != EOF);
    }
    ungetc(ch, f); // Devolve o último caractere lido (que não é '#')

    // 3. Ler Largura e Altura [cite: 100]
    if (fscanf(f, "%d %d", &img->largura, &img->altura) != 2) {
         printf("Erro: Falha ao ler dimensões do arquivo.\n");
         fclose(f);
         return 1;
    }

    if (img->largura > MAX_LARG || img->altura > MAX_ALT) {
        printf("Erro: Dimensões do arquivo (%dx%d) excedem o limite de %dx%d.\n", img->largura, img->altura, MAX_LARG, MAX_ALT);
        fclose(f);
        return 1;
    }

    // 4. Ler os dados (pixels) [cite: 101]
    for (int i = 0; i < img->altura; i++) {
        for (int j = 0; j < img->largura; j++) {
            if (fscanf(f, "%d", &img->dados[i][j]) != 1) {
                printf("Erro: Falha ao ler dados dos pixels.\n");
                fclose(f);
                return 1;
            }
        }
    }

    fclose(f);
    return 0; // Sucesso
}