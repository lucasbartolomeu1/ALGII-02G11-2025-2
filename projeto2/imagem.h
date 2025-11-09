#ifndef IMAGEM_H
#define IMAGEM_H

// Define os limites máximos (conforme enunciado) [cite: 161]
#define MAX_LARG 1024
#define MAX_ALT 768

// Estrutura para armazenar a imagem
typedef struct {
    // 0 = Branco, 1 = Preto [cite: 101]
    int dados[MAX_ALT][MAX_LARG]; 
    int largura;
    int altura;
} Imagem;

/**
 * @brief Lê os dados da imagem (dimensões e pixels) 
 * via entrada manual do teclado.
 * @param img Ponteiro para a estrutura Imagem a ser preenchida.
 */
void lerImagemModoManual(Imagem *img);

/**
 * @brief Lê os dados da imagem de um arquivo PBM.
 * @param img Ponteiro para a estrutura Imagem a ser preenchida.
 * @param nomeArquivo O nome do arquivo PBM a ser lido.
 * @return 0 em caso de sucesso, 1 em caso de erro (ex: arquivo não encontrado).
 */
int lerImagemArquivoPBM(Imagem *img, char* nomeArquivo);

#endif // IMAGEM_H