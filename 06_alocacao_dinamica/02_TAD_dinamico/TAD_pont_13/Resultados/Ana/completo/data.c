#include <stdio.h>
#include <stdlib.h>
#include "data.h"

tData* LeData(){
    tData *d;
    int dia, mes, ano;

    scanf("%d/%d/%d%*c", &dia, &mes, &ano);

    d = CriaData(dia, mes, ano);

    return d;
}

tData* CriaData(int dia, int mes, int ano){
    tData *d;

    d = (tData*) calloc(1, sizeof(tData));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void LiberaData(tData* d){
    if (d != NULL)
        free(d);
}

int CalculaIdadeData(tData* nascimento, tData* diacalc){
    int diff = diacalc->ano - nascimento->ano;

    if (diacalc->mes <= nascimento->mes){
        if (diacalc->mes < nascimento->mes) diff--;

        else if (diacalc->dia < nascimento->dia) diff--;
    }

    return diff;
}

void ImprimeData(tData* d){
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}