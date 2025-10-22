#include <stdio.h>

int mdc(int a, int b) {
    if (b > a) {
        return mdc(b, a);
    }
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}


int main() {
    int a, b, emedece;
    printf("Digito A: ");
    scanf("%d", &a);
    printf("Digito B: ");
    scanf("%d", &b);
    emedece = mdc(a, b);
    printf("O mdc de %d com %d é: %d \n", a, b, emedece);
    return 0;
}
