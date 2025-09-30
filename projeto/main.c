#include <stdio.h>
#include <string.h>

/*
Nome: Lucas dos Santos Bartolomeu RA: 10747984
Nome: Gustavo Moslay Murata       RA: 10741155	
*/

const char* CODIGO_MORSE[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

const char ALFABETO[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void traduzir_morse(const char* codigo) {
    for (int i = 0; i < 26; i++) {
        if (strcmp(codigo, CODIGO_MORSE[i]) == 0) {
            printf("%c", ALFABETO[i]);
            return; 
        }
    }
}

void traduzir_morse_corrompido(const char* codigo) {
    char prefixo[20];
    strncpy(prefixo, codigo, strlen(codigo) - 1);
    prefixo[strlen(codigo) - 1] = '\0';
    size_t tamanho_prefixo = strlen(prefixo);

    printf("[");
    for (int i = 0; i < 26; i++) {
        if (strncmp(prefixo, CODIGO_MORSE[i], tamanho_prefixo) == 0) {
            printf("%c", ALFABETO[i]);
        }
    }
    printf("]");
}

int main() {
    char linha_entrada[1024];
    char codigo_letra[20];
    int indice_letra = 0;
    int contador_espacos = 0;

    fgets(linha_entrada, sizeof(linha_entrada), stdin);
    
    for (int i = 0; i < strlen(linha_entrada); i++) {
        char caractere_atual = linha_entrada[i];

        if (caractere_atual == ' ') {
            contador_espacos++;
        } else if (caractere_atual == '\n' || caractere_atual == '\0') {
            if (indice_letra > 0) {
                codigo_letra[indice_letra] = '\0';
                if (codigo_letra[strlen(codigo_letra) - 1] == '*') {
                    traduzir_morse_corrompido(codigo_letra);
                } else {
                    traduzir_morse(codigo_letra);
                }
            }
            break; 
        } else {
            if (contador_espacos > 0) {
                if (indice_letra > 0) {
                    codigo_letra[indice_letra] = '\0';
                    if (codigo_letra[strlen(codigo_letra) - 1] == '*') {
                        traduzir_morse_corrompido(codigo_letra);
                    } else {
                        traduzir_morse(codigo_letra);
                    }
                    indice_letra = 0;
                }
                
                if (contador_espacos >= 2) {
                    printf(" ");
                }
                contador_espacos = 0;
            }
            
            codigo_letra[indice_letra] = caractere_atual;
            indice_letra++;
        }
    }
    
    printf("\n");
    return 0; 
}
