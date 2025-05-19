#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao01.h"

// Função para criar o cadastro de um aluno
Aluno* criarAluno() {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    
    if (novo == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    
    printf("Digite o nome do aluno: ");
    scanf(" %80[^\n]", novo->nome);
    
    printf("Digite a matrícula (até 7 caracteres): ");
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

// Função para calcular a média das notas
float calcularMedia(Aluno* a) {
    if (a == NULL) return 0.0;
    return (a->p1 + a->p2 + a->p3) / 3.0;
}

// Função para imprimir a média de um aluno
void imprimirMedia(Aluno* a) {
    if (a == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }
    
    float media = calcularMedia(a);
    printf("Média do aluno %s: %.2f\n", a->nome, media);
}

// Função para imprimir o cadastro completo do aluno
void imprimirCadastro(Aluno* a) {
    if (a == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }
    
    printf("===== DADOS DO ALUNO =====\n");
    printf("Nome: %s\n", a->nome);
    printf("Matrícula: %s\n", a->matricula);
    printf("Turma: %c\n", a->turma);
    printf("Nota P1: %.2f\n", a->p1);
    printf("Nota P2: %.2f\n", a->p2);
    printf("Nota P3: %.2f\n", a->p3);
    printf("Média: %.2f\n", calcularMedia(a));
    printf("=========================\n");
}

// Função para liberar a memória alocada
void liberarAluno(Aluno* a) {
    if (a != NULL) {
        free(a);
    }
}
