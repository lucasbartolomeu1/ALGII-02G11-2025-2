#include <stdio.h>

int minutos(int hora, int minutos) {
    return (hora * 60) + minutos;
}


int diferenca(int tempo_minutos1, int tempo_minutos2) { 
    int resultado = tempo_minutos1 - tempo_minutos2;
    if (resultado < 0) {
        return resultado * -1; 
    }
    else {
        return resultado;
    }
}

int main() {
    int hora1, minuto1;
    int hora2, minuto2;
    printf("Primeira hora (formato hr:min): ");
    scanf("%d:%d", &hora1, &minuto1);
    printf("Segunda hora (formato hr:min): ");
    scanf("%d:%d", &hora2, &minuto2);

    int total_minutos1 = minutos(hora1, minuto1);
    int total_minutos2 = minutos(hora2, minuto2);

    int resultado = diferenca(total_minutos1, total_minutos2);
    printf("A diferença entre os horários é de: %d minutos\n", resultado);
    return 0;
}
