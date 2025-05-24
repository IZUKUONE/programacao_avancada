#ifndef SOCIO_H
#define SOCIO_H

typedef struct {
    int matricula;
    char nome[50];
    int idade;
    char estado_civil[10];
    char turno[10];
    float renda;
} Socio;

Socio* criar_socio(int matricula, const char* nome, int idade, const char* estado_civil, const char* turno, float renda);
int total_por_turno(Socio* socios, int tamanho, const char* turno);
float media_renda_casados(Socio* socios, int tamanho);
void liberar_socios(Socio* socios);

#endif

