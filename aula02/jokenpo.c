#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Professor fez de uma forma mais prática com menos if else*/
int main() {
    srand(time(NULL));
    int user;
    printf("Jogo: Pedra Papel Tesoura!\n");
    printf("1- Pedra 2-Papel 3-Tesoura\n");
    printf("Sua escolha: ");
    scanf("%d", &user );
    int random = rand() % 3 + 1;
    if (random == user) {
        printf("Deu empate!\n");
    }
    else if (user == 1 && random == 2) {
        printf("O computador jogou Papel e Voce Pedra\n");
        printf("Voce perdeu! Papel > Pedra\n");
    }
    else if (user == 1 && random == 3) {
        printf("O computador jogou Tesoura e Voce Papel\n");
        printf("Voce perdeu! Papel > Pedra\n");
    }
    else if (user == 2 && random == 1) {
        printf("O computador jogou Pedra e Voce Papel\n");
        printf("Voce ganhou! Papel > Pedra\n");
    }
    else if (user == 2 && random == 3) { 
        printf("O computador jogou Tesoura e Voce jogou Papel\n");
        printf("Voce perdeu! Tesoura > Papel\n");
    }
    else if (user == 3 && random == 1) {
        printf("O computador jogou Pedra e Voce Tesoura\n");
        printf("Voce Perdeu! Pedra > Tesoura\n");
    }
    else if (user == 3 && random == 2) {
        printf("O computador jogou Papel e Voce Tesoura\n");
        printf("Voce Ganhou! Tesoura > Papel\n");
    }
    else {
        printf("Algo deu Errado! Por favor tente novamente.\n")
    }
    return 0;
}
