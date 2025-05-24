#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int peso;
    int indice;
} Objeto;

int comparar(const void *a, const void *b) {
    Objeto *objA = (Objeto *)a;
    Objeto *objB = (Objeto *)b;
    return objB->peso - objA->peso;
}

void mochilaGulosa(int capacidade, Objeto objetos[], int n) {
    int pesoTotal = 0;
    int objetosSelecionados[n];
    int numSelecionados = 0;
    int i, z, j, q;
    
    printf("=== METODO GULOSO - PROBLEMA DA MOCHILA ===\n");
    printf("Capacidade da mochila: %d kg\n", capacidade);
    printf("Objetos disponiveis:\n");
    
    for(i = 0; i < n; i++) {
        printf("  Objeto %d: %d kg\n", objetos[i].indice, objetos[i].peso);
    }
    
    qsort(objetos, n, sizeof(Objeto), comparar);
    
    printf("\nOrdem de consideracao (peso decrescente):\n");
    for( z = 0; z < n; z++) {
        printf("  Objeto %d: %d kg\n", objetos[i].indice, objetos[i].peso);
    }
    
    printf("\nProcesso de selecao:\n");
    
    for(j = 0; j < n; j++) {
        if(pesoTotal + objetos[i].peso <= capacidade) {
            objetosSelecionados[numSelecionados] = objetos[i].indice;
            pesoTotal += objetos[i].peso;
            numSelecionados++;
            printf("  Objeto %d (%d kg) adicionado. Peso total: %d kg\n", 
                   objetos[i].indice, objetos[i].peso, pesoTotal);
        } else {
            printf("  Objeto %d (%d kg) nao cabe. Espaco restante: %d kg\n", 
                   objetos[i].indice, objetos[i].peso, capacidade - pesoTotal);
        }
    }
    
    printf("\n=== RESULTADO ===\n");
    printf("Objetos selecionados: ");
    for(q = 0; q < numSelecionados; q++) {
        printf("%d ", objetosSelecionados[i]);
    }
    printf("\nPeso total: %d kg\n", pesoTotal);
    printf("Espaco utilizado: %.1f%%\n", (float)pesoTotal/capacidade * 100);
    printf("Espaco desperdicado: %d kg\n", capacidade - pesoTotal);
}

void verificarOtimalidade() {
    printf("\n=== ANALISE DA OTIMALIDADE ===\n");
    printf("A solucao gulosa para este problema NAO e sempre otima!\n\n");
    
    printf("Solucao gulosa encontrada:\n");
    printf("  - Objeto 1 (12 kg) + Objeto 3 (4 kg) = 16 kg\n");
    printf("  - Utiliza 100%% da capacidade\n\n");
    
    printf("Outras solucoes possiveis:\n");
    printf("  - Objeto 2 (8 kg) + Objeto 3 (4 kg) + Objeto 4 (2 kg) = 14 kg\n");
    printf("  - Objeto 1 (12 kg) + Objeto 4 (2 kg) = 14 kg\n");
    printf("  - Objeto 2 (8 kg) + Objeto 4 (2 kg) = 10 kg\n");
    printf("  - E outras combinacoes...\n\n");
    
    printf("CONCLUSAO: Neste caso especifico, o metodo guloso encontrou\n");
    printf("a solucao otima (16 kg), mas isso nao e garantido em geral.\n\n");
    
    printf("Exemplo onde o guloso falha:\n");
    printf("  Capacidade: 10 kg\n");
    printf("  Objetos: 6 kg, 5 kg, 5 kg\n");
    printf("  Guloso escolhe: 6 kg (total: 6 kg)\n");
    printf("  Otimo seria: 5 kg + 5 kg (total: 10 kg)\n");
}

int main() {
    int capacidade = 16;
    int n = 4;
    
    Objeto objetos[4] = {
        {12, 1},
        {8, 2},
        {4, 3},
        {2, 4}
    };
    
    mochilaGulosa(capacidade, objetos, n);
    
    verificarOtimalidade();
    
    return 0;
}
