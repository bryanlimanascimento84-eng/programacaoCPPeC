#include <stdio.h>
int main() {
    double numero;

    printf("Introduza um número racional: ");
    if (scanf("%lf", &numero) != 1) {
        printf("Erro de leitura.\n");
        return 1;
    }

    printf("O número introduzido é: %g\n", numero);
    if (numero > 0.0) {
        printf("número é positivo\n");
    } else if (numero < 0.0) {
        printf("número é negativo\n");
    } else {
        printf("número é zero\n");
    }

    return 0;
}