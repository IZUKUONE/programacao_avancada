#include <stdlib.h>
#include "numeros.h"

Numeros* criar_numeros(int n1, int n2) {
    Numeros* novo = (Numeros*) malloc(sizeof(Numeros));
    if (novo != NULL) {
        novo->num1 = n1;
        novo->num2 = n2;
    }
    return novo;
}

int somar_numeros(Numeros* n) {
    return n->num1 + n->num2;
}

int multiplicar_numeros(Numeros* n) {
    return n->num1 * n->num2;
}

int sao_iguais(Numeros* n) {
    return n->num1 == n->num2;
}

void liberar_numeros(Numeros* n) {
    free(n);
}

