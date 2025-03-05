#include <stdio.h>
#include <stdlib.h>
#include "lesao.h"

tLesao* CriaLesao(){
    tLesao *les;

    les = (tLesao*) calloc(1, sizeof(tLesao));
    les->id = (char*) calloc(TAM_ID, sizeof(char));
    les->diagnostico = (char*) calloc(TAM_DIAG, sizeof(char));
    les->regiao_corpo = (char*) calloc(TAM_REG, sizeof(char));

    return les;
}

void LeLesao(tLesao* l){
    scanf("%s%*c", l->id);
    scanf("%[^\n]%*c", l->diagnostico);
    scanf("%[^\n]%*c", l->regiao_corpo);
    scanf("%d%*c", &l->chance_malignidade);
}

void LiberaLesao(tLesao* l){
    
    if (l->id != NULL)
        free(l->id);
    if (l->diagnostico != NULL)
        free(l->diagnostico);
    if (l->regiao_corpo != NULL)
        free(l->regiao_corpo);
    if (l != NULL)
        free(l);
}

char* GetIdLesao(tLesao* l){
    return l->id;
}

int PrecisaCirurgiaLesao(tLesao* l){
    if (l->chance_malignidade > 50) return 1;
    else return 0;
}