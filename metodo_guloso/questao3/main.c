#include <stdio.h>

int main() {
    int raiz = 7;
    int esq1 = 3, dir1 = 12;
    int esq_esq = 99, dir_esq = 8;
    int esq_dir = 5, dir_dir = 6;
    
    int soma = 0;
    int atual = raiz;
    
    printf("Arvore:\n");
    printf("      %d\n", raiz);
    printf("    %d   %d\n", esq1, dir1);
    printf("   %d %d %d %d\n", esq_esq, dir_esq, esq_dir, dir_dir);
    
    printf("\nMetodo guloso:\n");
    
    soma += atual;
    printf("Raiz: %d (soma: %d)\n", atual, soma);
    
    if(esq1 >= dir1) {
        atual = esq1;
        printf("Escolhe %d (esquerda)\n", atual);
        soma += atual;
        
        if(esq_esq >= dir_esq) {
            atual = esq_esq;
            printf("Escolhe %d (esquerda)\n", atual);
        } else {
            atual = dir_esq;
            printf("Escolhe %d (direita)\n", atual);
        }
    } else {
        atual = dir1;
        printf("Escolhe %d (direita)\n", atual);
        soma += atual;
        
        if(esq_dir >= dir_dir) {
            atual = esq_dir;
            printf("Escolhe %d (esquerda)\n", atual);
        } else {
            atual = dir_dir;
            printf("Escolhe %d (direita)\n", atual);
        }
    }
    
    soma += atual;
    printf("Soma final: %d\n", soma);
    
    printf("\nTodos os caminhos:\n");
    printf("7+3+99 = %d\n", raiz+esq1+esq_esq);
    printf("7+3+8 = %d\n", raiz+esq1+dir_esq);
    printf("7+12+5 = %d\n", raiz+dir1+esq_dir);
    printf("7+12+6 = %d\n", raiz+dir1+dir_dir);
    
    printf("\nMaior possivel: 109\n");
    printf("encontrou: %d\n", soma);
    
    return 0;
}
