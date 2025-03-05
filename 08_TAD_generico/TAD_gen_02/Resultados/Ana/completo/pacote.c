#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"

typedef struct pacote {
    void* vetor;
    int numElem;
    int valor;
    Type tipo;
} tPacote;

tPacote* CriaPacote(Type type, int numElem){
    tPacote* p = (tPacote*) malloc(sizeof(tPacote));
    p->numElem = numElem;
    p->valor = 0;
    p->tipo = type;

    if (type == INT){
        p->vetor = (int*) calloc(numElem, sizeof(int));
    }

    else if(type == CHAR){
        p->vetor = (char*) calloc(numElem + 1, sizeof(char));
    }

    return p;
}

void DestroiPacote(tPacote* pac){
    if (pac != NULL){
        free(pac->vetor);
        free(pac);
    }
}

void LePacote(tPacote* pac){
    char tipoDado;

    scanf("%c %d\n", &tipoDado, &pac->numElem);

    if (tipoDado == '0'){
        pac->tipo = CHAR;

        pac->vetor = realloc(pac->vetor, (pac->numElem + 1) * sizeof(char));// chatgpt

        scanf("%s\n", (char*)pac->vetor);
    }

    else if (tipoDado == '1'){
        pac->tipo = INT;

        pac->vetor = realloc(pac->vetor, pac->numElem * sizeof(int));// chatgpt

        for (int i = 0; i < pac->numElem; i++){
            scanf("%d%*c", &((int*)pac->vetor)[i]);
        }
    }

    else {
        printf("Digite um tipo valido!\n");
    }
}

void ImprimePacote(tPacote* pac){
    if (pac->tipo == CHAR){
        printf("%d %s\n", pac->valor, (char*)pac->vetor);
    }

    else if (pac->tipo == INT){
        printf("%d", pac->valor);

        for (int i = 0; i < pac->numElem; i++){
            printf(" %d", ((int*)pac->vetor)[i]);
        }
        

        printf("\n");
    }
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->valor = 0;

    if (pac->tipo == CHAR){
        
        for (int i = 0; i < pac->numElem; i++){
            pac->valor += (int) ((char*)pac->vetor)[i];
        }
    }

    else if (pac->tipo == INT){
        for (int i = 0; i < pac->numElem; i++){
            pac->valor += ((int*)pac->vetor)[i];
        }
        
    }
}