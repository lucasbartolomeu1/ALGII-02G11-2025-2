#ifndef ENCODER_H
#define ENCODER_H

#include "imagem.h" // Precisa da definição da struct Imagem

/**
 * @brief Função recursiva que codifica uma região da imagem.
 * @param img Ponteiro para a estrutura Imagem (contém os dados).
 * @param y Coordenada Y (linha) inicial da sub-imagem.
 * @param x Coordenada X (coluna) inicial da sub-imagem.
 * @param h Altura (height) da sub-imagem.
 * @param w Largura (width) da sub-imagem.
 */
void codificarImagem(Imagem *img, int y, int x, int h, int w);

#endif // ENCODER_H