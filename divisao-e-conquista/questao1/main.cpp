#include <stdio.h>

int multiplica(int a, int b) {
    if (b == 0) {
        return 0;
    } else if (b > 0) {
        return a + multiplica(a, b - 1);
    } else {
        return -multiplica(a, -b);
    }
}

int main() {
    int x, y;
    printf("Informe o primeiro numero: ");
    scanf("%d", &x);
    printf("Informe o segundo numero: ");
    scanf("%d", &y);

    int resultado = multiplica(x, y);
    printf("Resultado da multiplicacao: %d\n", resultado);

    return 0;
}

