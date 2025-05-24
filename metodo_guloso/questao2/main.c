#include <stdio.h>

int calcula(int troco, int qtdopcoes, int *notas) {
    int total = 0;
    int i;
    for(i = qtdopcoes - 1; i >= 0; i--) {
        int totalparc = troco / notas[i];
        troco = troco - totalparc * notas[i];
        total += totalparc;
        if (totalparc != 0) {
            printf("%d nota(s) de %d\n", totalparc, notas[i]);
        }
    }
    return total;
}

int main() {
    int troco, qtdopcoes;
    int i, j;
    printf("Informe o valor do troco: ");
    scanf("%d", &troco);
    printf("Informe a quantidade de tipos de notas: ");
    scanf("%d", &qtdopcoes);
    int notas[qtdopcoes];
    printf("Informe os valores das notas:\n");
    for( i = 0; i < qtdopcoes; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &notas[i]);
    }
    for( i = 0; i < qtdopcoes - 1; i++) {
        for(j = i + 1; j < qtdopcoes; j++) {
            if (notas[i] > notas[j]) {
                int temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
    printf("Quantidade de notas usadas: %d\n", calcula(troco, qtdopcoes, notas));
    return 0;
}

