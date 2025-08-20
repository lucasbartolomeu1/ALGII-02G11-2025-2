#include <stdio.h>

int main() {
    double salario_bruto;
    printf("Salario Bruto: ");
    scanf("%lf", &salario_bruto);
    double imposto;
    if (salario_bruto <= 2000) {
        imposto = 0.0;
    }
    else if (salario_bruto <= 4000) {
        imposto = salario_bruto * 0.075;
    }
    else if (salario_bruto <= 6000) {
        imposto = salario_bruto * 0.15;
    }
    else if (salario_bruto <= 10000) {
        imposto = salario_bruto * 0.225;
    }
    else {
        imposto = salario_bruto * 0.275;
    }
    double salario_liquido = salario_bruto - imposto;
    printf("Imposto = %.2f\n", imposto);
    printf("Salário Bruto: %.2f\n", salario_bruto);
    printf("Salário Liquído: %.2f\n", salario_liquido);
    return 0;
}