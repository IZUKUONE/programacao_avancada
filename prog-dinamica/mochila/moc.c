#include <stdio.h>

#define NUM_ITENS 7
#define CAPACIDADE 5

int main() {
    int pesos[NUM_ITENS] = {1, 2, 5, 6, 7, 9, 11};
    int valores[NUM_ITENS] = {1, 6, 18, 22, 28, 40, 60};
    int dp[NUM_ITENS + 1][CAPACIDADE + 1];
    int i, j;
    int incluir, excluir;
    int capacidade_restante;

    for (i = 0; i <= NUM_ITENS; i++) {
        for (j = 0; j <= CAPACIDADE; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= NUM_ITENS; i++) {
        for (j = 1; j <= CAPACIDADE; j++) {
            if (pesos[i - 1] <= j) {
                incluir = valores[i - 1] + dp[i - 1][j - pesos[i - 1]];
                excluir = dp[i - 1][j];
                dp[i][j] = (incluir > excluir) ? incluir : excluir;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("Matriz DP:\n");
    for (i = 0; i <= NUM_ITENS; i++) {
        for (j = 0; j <= CAPACIDADE; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }
    
    printf("\nValor máximo que pode ser carregado: %d\n", dp[NUM_ITENS][CAPACIDADE]);
    printf("Itens escolhidos:\n");

    capacidade_restante = CAPACIDADE;
    for (i = NUM_ITENS; i > 0 && capacidade_restante > 0; i--) {
        if (dp[i][capacidade_restante] != dp[i - 1][capacidade_restante]) {
            printf(" - Item %d (peso = %d, valor = %d)\n", i, pesos[i - 1], valores[i - 1]);
            capacidade_restante -= pesos[i - 1];
        }
    }

    return 0;
}
