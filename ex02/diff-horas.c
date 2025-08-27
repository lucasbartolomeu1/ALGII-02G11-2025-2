#include <stdio.h>

void minutos (int *hr1, int *hr2, int *min1, int *min2) {
    int *hr1 = (hr1*60) + min1;
    int *hr2 = (hr2*60) + min2;
}


int main() {
    int hr1, min1, hr2, min2;
    printf("Hora 1: ");
    scanf("%d:%d", &hr1, &min1);
    printf("Hora 2: ");
    scanf("%d:%d", &hr2, &min2);
    minutos (&hr1, &hr2, &min1, &min2);
}