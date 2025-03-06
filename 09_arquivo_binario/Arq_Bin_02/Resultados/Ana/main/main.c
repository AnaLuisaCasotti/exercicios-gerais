#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_alunos.h"

int main(){
    char nomeBin[50];
    float coefMedio;

    scanf("%[^\n]\n", nomeBin);

    tBaseAlunos *base = CriarBaseAlunos();
    LerBaseAlunos(base, nomeBin);
    coefMedio = GetCoeficienteRendimentoMedioBaseAlunos(base);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", coefMedio);
    DestruirBaseAlunos(base);

    return 0;
}