#include<stdio.h>

// Fun��o de ordena��o QuickSort
void Quick(int vetor[10], int inicio, int fim);

int main() {
    int vetor[10] = {7, 9, 4, 3, 6, 1, 18, 2, 10, 5};
    int i;

    // Exibe o vetor antes da ordena��o
    printf("Vetor desordenado:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama a fun��o de ordena��o QuickSort
    Quick(vetor, 0, 9);

    // Exibe o vetor ap�s a ordena��o
    printf("Vetor ordenado:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Fun��o de ordena��o QuickSort
void Quick(int vetor[10], int inicio, int fim) {
    int pivo, aux, i, j, meio;

    i = inicio;       // In�cio do subvetor
    j = fim;          // Fim do subvetor
    meio = (int)((i + j) / 2);  // Calcula o meio
    pivo = vetor[meio];         // Define o piv� como o elemento do meio

    // Particionamento
    do {
        // Avan�a i at� encontrar elemento maior ou igual ao piv�
        while (vetor[i] < pivo) i = i + 1;
        
        // Retrocede j at� encontrar elemento menor ou igual ao piv�
        while (vetor[j] > pivo) j = j - 1;
        
        // Troca elementos fora do lugar
        if(i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while(j > i);  // Continua enquanto os �ndices n�o se cruzarem

    // Recurs�o para as duas metades do vetor
    if(inicio < j) Quick(vetor, inicio, j);
    if(i < fim) Quick(vetor, i, fim);
}

