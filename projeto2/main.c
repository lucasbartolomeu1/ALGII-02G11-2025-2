#include <stdio.h>
#include <string.h>
#include "imagem.h"
#include "encoder.h"

void imprimirAjuda() {
    printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n");
    printf("Codifica imagens binárias dadas em arquivos PBM ou por dados informados\n");
    printf("manualmente.\n");
    printf("Argumentos:\n");
    printf("  -?, --help : apresenta essa orientação na tela.\n");
    printf("  -m, --manual : ativa o modo de entrada manual, em que o usuário fornece\n");
    printf("                 todos os dados da imagem informando-os através do teclado.\n");
    printf("  -f, --file   : considera a imagem representada no arquivo PBM (Portable\n");
    printf("                 bitmap).\n");
}

int main(int argc, char *argv[]) {
    
    // Se nenhum argumento foi dado ou é ajuda [cite: 129, 136]
    if (argc == 1 || strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "--help") == 0) {
        imprimirAjuda();
        return 0;
    }

    Imagem img; // Cria a instância da nossa imagem

    // Modo Manual [cite: 137]
    if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "--manual") == 0) {
        lerImagemModoManual(&img);
    } 
    // Modo Arquivo [cite: 138]
    else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0) {
        if (argc < 3) { // Verifica se o nome do arquivo foi fornecido
            printf("Erro: O argumento -f requer um nome de arquivo.\n");
            imprimirAjuda();
            return 1;
        }
        
        // Tenta ler o arquivo
        if (lerImagemArquivoPBM(&img, argv[2]) != 0) {
            // A função lerImagemArquivoPBM já imprime o erro
            return 1; // Termina o programa se houve erro na leitura
        }
    } 
    // Argumento inválido
    else {
        printf("Argumento desconhecido: %s\n", argv[1]);
        imprimirAjuda();
        return 1;
    }

    // Se a imagem foi carregada com sucesso (altura e largura > 0)
    if (img.altura > 0 && img.largura > 0) {
        // Inicia o processo de codificação [cite: 151]
        codificarImagem(&img, 0, 0, img.altura, img.largura);
        printf("\n"); // Adiciona uma nova linha no final para formatação
    }

    return 0;
}