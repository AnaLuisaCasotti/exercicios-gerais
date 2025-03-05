#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    int tipotemp, numElem;
    tGeneric* gen;
    Type tipo;

    printf("tad_gen_01\nDigite o tipo e numero de elementos:");
    scanf("%d %d\n", &tipotemp, &numElem);

    tipo = (Type)tipotemp;

    gen = CriaGenerico(tipo, numElem);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}