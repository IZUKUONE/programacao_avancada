#include <stdio.h>

double exponenciacao(double a, int n) {
    if (n == 0) {
        return 1;
    } else {
        return a * exponenciacao(a, n - 1);
    }
}

int main() {
    double base, resultado;
    int expoente;

    printf("Informe a base: ");
    scanf("%lf", &base);

    printf("Informe o expoente (inteiro >= 0): ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("Erro: expoente deve ser inteiro nao-negativo.\n");
    } else {
        resultado = exponenciacao(base, expoente);
        printf("Resultado: %.2lf elevado a %d = %.2lf\n", base, expoente, resultado);
    }

    return 0;
}

