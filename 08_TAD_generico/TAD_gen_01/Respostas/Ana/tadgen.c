#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

typedef struct generic {
    Type tipo;
    int tamanho;
    void* array;

} tGeneric;

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* gen = (tGeneric*) calloc(1, sizeof(tGeneric));

    gen->tamanho = numElem;
    gen->tipo = type;

    switch(type){
        case (INT):
            gen->array = calloc(numElem, sizeof(int));
            break;

        case(FLOAT):
            gen->array = calloc(numElem, sizeof(float));
            break;
    }

    return gen;
}

void DestroiGenerico(tGeneric* gen){
    if (gen != NULL){
        free(gen->array);
        free(gen);
    }
}

void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");

    if(gen->tipo == INT){
        int temp;
        for (int i = 0; i < gen->tamanho; i++){
            scanf("%d%*c", &temp);
            ((int *)gen->array)[i] = temp;
        }
    }

    else {
        float temp2;
        for (int i = 0; i < gen->tamanho; i++){
            scanf("%f%*c", &temp2);
            ((float *)gen->array)[i] = temp2;
        }
    }
}

void ImprimeGenerico(tGeneric* gen){
    if (gen->tipo == INT){
        for (int i = 0; i < gen->tamanho; i++){
            
            if (i == gen->tamanho - 1){
                printf("%d\n", ((int *)gen->array)[i]);
            }

            else {
                printf("%d ", ((int *)gen->array)[i]);
            }
        }
    }

    else {
        for (int i = 0; i < gen->tamanho; i++){
            
            if (i == gen->tamanho - 1){
                printf("%.2f\n", ((float *)gen->array)[i]);
            }
            
            else {
                printf("%.2f ", ((float *)gen->array)[i]);
            }
        }
    }
}