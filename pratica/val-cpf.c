#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarCPF(char cpf[]) {
    int digitos[11];
    int i, j = 0;
    int soma, resto;
    int todos_iguais = 1;

    if (strlen(cpf) != 14) {
        printf("Formato Inválido!\n");
        return 0;
    }
    if ((cpf[3] != '.') || (cpf[7] != '.') || (cpf[11] != '-')) {
        printf("Formato Inválido!\n");
        return 0; 
    }
    for (i = 0; i<14; i++) {
        if (isdigit(cpf[i])) {
            digitos[j] = cpf[i] - '0'; // truque para transformar o caractere hexadecimal num inteiro!
            j++;
        }
    }
    if (j != 11) {
        printf("Número de digitos do CPF incorreto!\n");
        return 0;
    }

    for (i = 1; i < 11; i++) {
        if (digitos[i] != digitos[0]) {
            todos_iguais = 0;
            break;
        }
    }
    if (todos_iguais) { 
        printf("Digitos todos iguais!\n");
        return 0;
    }

    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += digitos[i] * (10 - i);
    }
    resto = (soma * 10) % 11;
    if (resto == 10) {
        resto = 0;
    }
    if (resto != digitos[9]) {
        printf("Primeiro digito verificador inválido.\n");
        return 0; 
    }

    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += digitos[i] * (11 - i);
    }
    resto = (soma * 10) % 11;
    if (resto == 10) {
        resto = 0;
    }
    if (resto != digitos[10]) {
        printf("Segundo digito verificador inválido.\n");
        return 0;
    }

    return 1; // passou por tudo!
}


int main() {
    char cpf[16];
    printf("Digite seu CPF no formato (XXX.XXX.XXX-YY): ");
    scanf("%s", cpf);
    int resultado = validarCPF(cpf);
    if (resultado) {
        printf("O cpf /%s/ é VÁLIDO.\n", cpf);
    }
    else {
        printf("O cpf /%s/ é INVÁLIDO.\n", cpf);
    }
    return 0;
}
