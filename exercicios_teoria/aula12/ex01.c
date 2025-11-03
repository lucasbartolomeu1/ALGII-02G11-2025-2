#include <stdio.h>

/*Função dobrar número utilizando um ponteiro.*/
void dobrarNumero(int *n) {
    *n *= 2; /* *n o valor que está guardado no endereço, n apenas o valor da memória.*/
}


int main() {
    int num;
    printf("Dobrar número: ");
    scanf("%d", &num);
    dobrarNumero(&num);
    printf("Número dobrado: %d\n", num);
    return 0;
}

/* resumo besta para entender mais fácil.
num (na main): É uma casa. Dentro dela, está o valor (ex: 5).

&num: É o endereço da casa (ex: "Rua Principal, 123").

n (na função): É um pedaço de papel onde você anotou o endereço "Rua Principal, 123".

*n: É o ato de ir até o endereço no papel e mexer no que está dentro da casa.*/