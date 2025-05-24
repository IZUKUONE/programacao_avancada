#include <stdlib.h>
#include <string.h>
#include "socio.h"

Socio* criar_socio(int matricula, const char* nome, int idade, const char* estado_civil, const char* turno, float renda) {
    Socio* novo = (Socio*) malloc(sizeof(Socio));
    if (novo != NULL) {
        novo->matricula = matricula;
        strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
        novo->nome[sizeof(novo->nome) - 1] = '\0';
        novo->idade = idade;
        strncpy(novo->estado_civil, estado_civil, sizeof(novo->estado_civil) - 1);
        novo->estado_civil[sizeof(novo->estado_civil) - 1] = '\0';
        strncpy(novo->turno, turno, sizeof(novo->turno) - 1);
        novo->turno[sizeof(novo->turno) - 1] = '\0';
        novo->renda = renda;
    }
    return novo;
}

int total_por_turno(Socio* socios, int tamanho, const char* turno) {
    int total = 0;
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(socios[i].turno, turno) == 0) {
            total++;
        }
    }
    return total;
}

float media_renda_casados(Socio* socios, int tamanho) {
    float soma = 0.0;
    int count = 0;
    int i;
    for (i = 0; i < tamanho; i++) {
        if (strcmp(socios[i].estado_civil, "casado") == 0) {
            soma += socios[i].renda;
            count++;
        }
    }
    if (count == 0) return 0.0;
    return soma / count;
}

void liberar_socios(Socio* socios) {
    free(socios);
}

