#include <stdio.h>

int main() {
    int taxa;
    printf("Taxa: ");
    scanf("%d", &taxa);

    int selo5, selo3;

    if (taxa < 8) { 
        printf("Taxa menor que a quantidade minima.\n");
        return 1;
    }
    if (taxa % 5 == 0) {
        selo5 = taxa / 5;
        selo3 = 0;
    }
    else if (taxa % 5 == 1) {
        selo5 = taxa / 5 - 1;
        selo3 = (taxa - selo5 * 5) / 3;
    }
    else if (taxa % 5 == 2) {
        selo5 = taxa / 5 - 2;
        selo3 = (taxa - selo5 * 5) / 3;
    }
    else if (taxa % 5 == 3) {
        selo5 = taxa / 5;
        selo3 = (taxa - selo5 * 5) / 3;
    }
    else if (taxa % 5 == 4) {
        selo5 = taxa / 5 - 1;
        selo3 = (taxa - selo5 * 5) / 3;
    }
    printf("Para a taxa de %d, foram usados:\n", taxa);
    printf("Selos de 5: %d\n", selo5);
    printf("Selos de 3: %d\n", selo3);
    return 0;
}