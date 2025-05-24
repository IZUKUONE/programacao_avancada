#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"


Produto* criar_produto(int codigo, const char* nome, int quantidade, float preco) {
    Produto* novo_produto = (Produto*) malloc(sizeof(Produto));
    if (novo_produto == NULL) {
        return NULL;
    }
    
    novo_produto->codigo = codigo;
    strncpy(novo_produto->nome, nome, sizeof(novo_produto->nome) - 1);
    novo_produto->nome[sizeof(novo_produto->nome) - 1] = '\0';
    novo_produto->quantidade = quantidade;
    novo_produto->preco = preco;

    return novo_produto;
}

void exibir_produto(Produto* p) {
    if (p != NULL) {
        printf("Código: %d\n", p->codigo);
        printf("Nome: %s\n", p->nome);
        printf("Quantidade: %d\n", p->quantidade);
        printf("Preço: R$ %.2f\n", p->preco);
    }
}

// Função para liberar memória
void liberar_produto(Produto* p) {
    free(p);
}

