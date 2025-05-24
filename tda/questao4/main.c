#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socio.h"

int main() {
    int n;
    int i;
    printf("Quantidade de socios: ");
    scanf("%d", &n);
    
    Socio* socios = (Socio*) malloc(n * sizeof(Socio));

    for (i = 0; i < n; i++) {
        printf("Socio %d\n", i + 1);
        printf("Matricula: ");
        scanf("%d", &socios[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", socios[i].nome);
        printf("Idade: ");
        scanf("%d", &socios[i].idade);
        printf("Estado Civil: ");
        scanf(" %s", socios[i].estado_civil);
        printf("Turno: ");
        scanf(" %s", socios[i].turno);
        printf("Renda: ");
        scanf("%f", &socios[i].renda);
    }

    char turno_consulta[10];
    printf("Informe o turno para contagem: ");
    scanf(" %s", turno_consulta);

    int total = total_por_turno(socios, n, turno_consulta);
    printf("Total de socios no turno %s: %d\n", turno_consulta, total);

    float media = media_renda_casados(socios, n);
    printf("Media de renda dos socios casados: %.2f\n", media);

    liberar_socios(socios);

    return 0;
}

