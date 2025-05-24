#include <stdio.h>
#include "numeros.h"

int main() {
    Numeros* n = criar_numeros(10, 20);

    if (n != NULL) {
        printf("Soma: %d\n", somar_numeros(n));
        printf("Multiplicacao: %d\n", multiplicar_numeros(n));

        if (sao_iguais(n)) {
            printf("Os numeros sao iguais.\n");
        } else {
            printf("Os numeros sao diferentes.\n");
        }

        liberar_numeros(n);
    } else {
        printf("Erro ao alocar memoria para os numeros.\n");
    }

    return 0;
}

