#include "encoder.h"
#include <stdio.h>

void codificarImagem(Imagem *img, int y, int x, int h, int w) {
    
    // --- 1. Verificar Uniformidade (Caso Base da Recursão) ---
    int corPrimeiroPixel = img->dados[y][x];
    int ehUniforme = 1; // Assume que é uniforme

    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            if (img->dados[i][j] != corPrimeiroPixel) {
                ehUniforme = 0; // Encontrou um pixel diferente
                break;
            }
        }
        if (!ehUniforme) break;
    }

    // --- 2. Agir ---

    // REGRA 1: Se for uniforme, imprime 'P' ou 'B' e para. [cite: 34]
    if (ehUniforme) {
        if (corPrimeiroPixel == 1) { // 1 = Preto [cite: 101]
            printf("P");
        } else { // 0 = Branco [cite: 101]
            printf("B");
        }
        return; // Fim da recursão para este ramo
    }

    // REGRA 2: Se for misto, imprime 'X' e divide. [cite: 38]
    printf("X");

    // Calcular os pontos de divisão
    // Regra: "superiores terão uma linha a mais" [cite: 43]
    int h1 = (h + 1) / 2;
    int h2 = h - h1;
    // Regra: "esquerdo terão uma coluna a mais" [cite: 42]
    int w1 = (w + 1) / 2;
    int w2 = w - w1;

    // Fazer as 4 chamadas recursivas NA ORDEM CORRETA [cite: 40]
    
    // Q1 (Superior Esquerdo)
    if (h1 > 0 && w1 > 0) codificarImagem(img, y, x, h1, w1);
    
    // Q2 (Superior Direito)
    if (h1 > 0 && w2 > 0) codificarImagem(img, y, x + w1, h1, w2);
    
    // Q3 (Inferior Esquerdo)
    if (h2 > 0 && w1 > 0) codificarImagem(img, y + h1, x, h2, w1);
    
    // Q4 (Inferior Direito)
    if (h2 > 0 && w2 > 0) codificarImagem(img, y + h1, x + w1, h2, w2);
}