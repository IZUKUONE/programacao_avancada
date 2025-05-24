#include<stdio.h>

// Função de ordenação QuickSort
void Quick(int vetor[10], int inicio, int fim);

int main() {
    int vetor[10] = {7, 9, 4, 3, 6, 1, 18, 2, 10, 5};
    int i;

    // Exibe o vetor antes da ordenação
    printf("Vetor desordenado:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama a função de ordenação QuickSort
    Quick(vetor, 0, 9);

    // Exibe o vetor após a ordenação
    printf("Vetor ordenado:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função de ordenação QuickSort
void Quick(int vetor[10], int inicio, int fim) {
    int pivo, aux, i, j, meio;

    i = inicio;       // Início do subvetor
    j = fim;          // Fim do subvetor
    meio = (int)((i + j) / 2);  // Calcula o meio
    pivo = vetor[meio];         // Define o pivô como o elemento do meio

    // Particionamento
    do {
        // Avança i até encontrar elemento maior ou igual ao pivô
        while (vetor[i] < pivo) i = i + 1;
        
        // Retrocede j até encontrar elemento menor ou igual ao pivô
        while (vetor[j] > pivo) j = j - 1;
        
        // Troca elementos fora do lugar
        if(i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while(j > i);  // Continua enquanto os índices não se cruzarem

    // Recursão para as duas metades do vetor
    if(inicio < j) Quick(vetor, inicio, j);
    if(i < fim) Quick(vetor, i, fim);
}

