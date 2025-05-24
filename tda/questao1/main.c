#include <stdio.h>
#include "questao01.h"

int main() {

    printf("Cadastro de Aluno\n");
    printf("================\n");
    
    Aluno* aluno = criarAluno();
    
    printf("\nInforma��es do aluno cadastrado:\n");
    imprimirCadastro(aluno);
    
    printf("\nApenas a m�dia do aluno:\n");
    imprimirMedia(aluno);
    
    liberarAluno(aluno);
    
    return 0;
}
