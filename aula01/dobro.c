#include <stdio.h>

int main() {           // função principal do programa
    int num;
    printf("Informe um número: "); // escreve no terminal
    scanf("%d", &num); // formatar o tipo de dado para ler, %d inteiro %f float %lf double %c char
                       // &num obtem o endereço de memória da variável
    int dobro = num * 2;
    printf("Dobro = %d\n", dobro);
    return 0;          // retorna 0, ou seja está tudo certo
}
