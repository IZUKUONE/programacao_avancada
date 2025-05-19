#include <stdio.h>
#include "questao01.h"

int main() {
    // Exemplo de uso das funções
    printf("Cadastro de Aluno\n");
    printf("================\n");
    
    Aluno* aluno = criarAluno();
    
    printf("\nInformações do aluno cadastrado:\n");
    imprimirCadastro(aluno);
    
    printf("\nApenas a média do aluno:\n");
    imprimirMedia(aluno);
    
    // Libera a memória alocada
    liberarAluno(aluno);
    
    return 0;
}
