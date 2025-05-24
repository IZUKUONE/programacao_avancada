#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;


Produto* criar_produto(int codigo, const char* nome, int quantidade, float preco);
void exibir_produto(Produto* p);
void liberar_produto(Produto* p);

#endif

