#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao01.h"

// Fun��o para criar o cadastro de um aluno
Aluno* criarAluno() {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    
    if (novo == NULL) {
        printf("Erro na aloca��o de mem�ria!\n");
        exit(1);
    }
    
    printf("Digite o nome do aluno: ");
    scanf(" %80[^\n]", novo->nome);
    
    printf("Digite a matr�cula (at� 7 caracteres): ");
    scanf(" %7[^\n]", novo->matricula);
    
    printf("Digite a turma: ");
    scanf(" %c", &novo->turma);
    
    printf("Digite a nota da P1: ");
    scanf("%f", &novo->p1);
    
    printf("Digite a nota da P2: ");
    scanf("%f", &novo->p2);
    
    printf("Digite a nota da P3: ");
    scanf("%f", &novo->p3);
    
    return novo;
}

// Fun��o para calcular a m�dia das notas
float calcularMedia(Aluno* a) {
    if (a == NULL) return 0.0;
    return (a->p1 + a->p2 + a->p3) / 3.0;
}

// Fun��o para imprimir a m�dia de um aluno
void imprimirMedia(Aluno* a) {
    if (a == NULL) {
        printf("Aluno n�o encontrado!\n");
        return;
    }
    
    float media = calcularMedia(a);
    printf("M�dia do aluno %s: %.2f\n", a->nome, media);
}

// Fun��o para imprimir o cadastro completo do aluno
void imprimirCadastro(Aluno* a) {
    if (a == NULL) {
        printf("Aluno n�o encontrado!\n");
        return;
    }
    
    printf("===== DADOS DO ALUNO =====\n");
    printf("Nome: %s\n", a->nome);
    printf("Matr�cula: %s\n", a->matricula);
    printf("Turma: %c\n", a->turma);
    printf("Nota P1: %.2f\n", a->p1);
    printf("Nota P2: %.2f\n", a->p2);
    printf("Nota P3: %.2f\n", a->p3);
    printf("M�dia: %.2f\n", calcularMedia(a));
    printf("=========================\n");
}

// Fun��o para liberar a mem�ria alocada
void liberarAluno(Aluno* a) {
    if (a != NULL) {
        free(a);
    }
}
