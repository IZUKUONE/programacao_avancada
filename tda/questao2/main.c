#include <stdio.h>
#include "produto.h"

int main() {
    Produto* p1 = criar_produto(1, "Notebook", 10, 3499.90);
    
    if (p1 != NULL) {
        exibir_produto(p1);
        liberar_produto(p1);
    } else {
        printf("Erro ao alocar memória para o produto.\n");
    }

    return 0;
}

