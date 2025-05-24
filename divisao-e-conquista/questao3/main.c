#include <stdio.h>

// Função para imprimir o vetor com destaque na região atual
void imprimirVetor(int vetor[], int tamanho, int inicio, int fim, int meio) {
    printf("Vetor completo: ");
    int i, j;
    for (i = 0; i < tamanho; i++) {
        if (i == inicio && i == fim) {
            printf("[%d] ", vetor[i]);
        } else if (i == inicio) {
            printf("[%d ", vetor[i]);
        } else if (i == fim) {
            printf("%d] ", vetor[i]);
        } else if (i == meio && i >= inicio && i <= fim) {
            printf("*%d* ", vetor[i]);
        } else if (i >= inicio && i <= fim) {
            printf("%d ", vetor[i]);
        } else {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
    
    printf("Região atual: ");
    for (j = inicio; j <= fim; j++) {
        if (i == meio) {
            printf("*%d* ", vetor[i]);
        } else {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

int pesquisaBinaria(int vetor[], int tamanho, int valorProcurado) {
    int inicio = 0;
    int fim = tamanho - 1;
    int iteracao = 1;
    
    printf("\n=== PESQUISA BINÁRIA ===\n");
    printf("Valor procurado: %d\n", valorProcurado);
    printf("Tamanho do vetor: %d\n\n", tamanho);
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        printf("--- Iteracao %d ---\n", iteracao);
        printf("Endereco inicial: %d (posicao %d)\n", inicio, inicio);
        printf("Endereco final: %d (posicao %d)\n", fim, fim);
        printf("Endereco do meio: %d (posicao %d)\n", meio, meio);
        printf("Valor do meio: %d\n", vetor[meio]);
        
        imprimirVetor(vetor, tamanho, inicio, fim, meio);
        
        if (vetor[meio] == valorProcurado) {
            printf("? ENCONTRADO! O valor %d esta na posicao %d\n\n", valorProcurado, meio);
            return meio;
        }
        
        if (valorProcurado < vetor[meio]) {
            printf("? %d < %d: procurar na metade esquerda\n", valorProcurado, vetor[meio]);
            fim = meio - 1;
        } else {
            printf("? %d > %d: procurar na metade direita\n", valorProcurado, vetor[meio]);
            inicio = meio + 1;
        }
        
        printf("\n");
        iteracao++;
    }
    
    printf("? VALOR NAO ENCONTRADO!\n\n");
    return -1;
}

int main() {
    int vetor[] = {5, 12, 18, 23, 31, 45, 56, 67, 78, 89};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorProcurado;
    int i, j;
    
    printf("=== DEMONSTRACAO DA PESQUISA BINARIA ===\n");
    printf("Vetor ordenado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    printf("Posicoes:       ");
    for (j = 0; j < tamanho; j++) {
        printf("%d ", i);
    }
    printf("\n");
    
    printf("\n========== EXEMPLO 1 ==========\n");
    valorProcurado = 31;
    pesquisaBinaria(vetor, tamanho, valorProcurado);
    
    printf("========== EXEMPLO 2 ==========\n");
    valorProcurado = 67;
    pesquisaBinaria(vetor, tamanho, valorProcurado);
    
    printf("========== EXEMPLO 3 ==========\n");
    valorProcurado = 25;
    pesquisaBinaria(vetor, tamanho, valorProcurado);
    
    printf("========== TESTE INTERATIVO ==========\n");
    printf("Digite um valor para buscar no vetor: ");
    scanf("%d", &valorProcurado);
    
    int resultado = pesquisaBinaria(vetor, tamanho, valorProcurado);
    
    if (resultado != -1) {
        printf("RESULTADO: Valor %d encontrado na posicao %d\n", valorProcurado, resultado);
    } else {
        printf("RESULTADO: Valor %d nao foi encontrado no vetor\n", valorProcurado);
    }
    
    return 0;
}
