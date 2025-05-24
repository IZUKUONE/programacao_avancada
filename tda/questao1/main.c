#include <stdio.h>
#include "questao01.h"

int main() {
    // Exemplo de uso das fun��es
    printf("Cadastro de Aluno\n");
    printf("================\n");
    
    Aluno* aluno = criarAluno();
    
    printf("\nInforma��es do aluno cadastrado:\n");
    imprimirCadastro(aluno);
    
    printf("\nApenas a m�dia do aluno:\n");
    imprimirMedia(aluno);
    
    // Libera a mem�ria alocada
    liberarAluno(aluno);
    
    return 0;
}
