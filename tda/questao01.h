#ifndef EXEMPLO_H
#define EXEMPLO_H


struct aluno {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
};
typedef struct aluno Aluno;

Aluno* criarAluno();
float calcularMedia(Aluno* a);
void imprimirMedia(Aluno* a);
void imprimirCadastro(Aluno* a);
void liberarAluno(Aluno* a);

#endif
