#ifndef NUMEROS_H
#define NUMEROS_H

typedef struct {
    int num1;
    int num2;
} Numeros;

Numeros* criar_numeros(int n1, int n2);
int somar_numeros(Numeros* n);
int multiplicar_numeros(Numeros* n);
int sao_iguais(Numeros* n);
void liberar_numeros(Numeros* n);

#endif

