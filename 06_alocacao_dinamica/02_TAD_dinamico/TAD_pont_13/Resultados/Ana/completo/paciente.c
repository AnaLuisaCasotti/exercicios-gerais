#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

char* GetCartaoSusPaciente(tPaciente* p){
    return p->cartaoSus;
}

int GetQtdLesoesPaciente(tPaciente* p){
    return p->qtdLesoes;
}

int GetQtdCirurgiasPaciente(tPaciente* p){
    int qtdCirurgias = 0;

    for (int i = 0; i < GetQtdLesoesPaciente(p); i++){
        if (PrecisaCirurgiaLesao(p->listaLesao[i]))
            qtdCirurgias++;
    }

    return qtdCirurgias;
}

tData* GetNascimentoPaciente(tPaciente* p){
    return p->nascimento;
}

tPaciente* CriaPaciente(){
    tPaciente *p;

    p = (tPaciente*) calloc(1, sizeof(tPaciente));
    p->nome = (char*) calloc(TAM_NOME, sizeof(char));
    //p->nascimento = (tData*) calloc(1, sizeof(tData));
    p->cartaoSus = (char*) calloc(TAM_CSUS, sizeof(char));
    p->listaLesao = (tLesao**) calloc(QTD_LESAO, sizeof(tLesao*));
    p->genero = ' ';
    p->qtdLesoes = 0;
    p->maxLesoes = QTD_LESAO;

    return p;
}

void LePaciente(tPaciente* p){
    scanf("%[^\n]%*c", p->nome);
    p->nascimento = LeData();
    scanf("%[^\n]%*c", p->cartaoSus);
    scanf("%c%*c", &p->genero);
}

void ImprimePaciente(tPaciente* p){
    
    if (p->qtdLesoes != 0){
        printf("- %s -", p->nome);

        for (int i = 0; i < p->qtdLesoes; i++){
            printf(" %s", p->listaLesao[i]->id);
        }

        printf("\n");
    }
}

void LiberaPaciente(tPaciente* p){
    
    free(p->nome);
    LiberaData(p->nascimento);
    free(p->cartaoSus);

    for (int i = 0; i < p->qtdLesoes; i++){
        if (p->listaLesao[i] != NULL)
            LiberaLesao(p->listaLesao[i]);
    }
    
    free(p->listaLesao);
    free(p);
}

void AdicionaLesaoPaciente(tPaciente* p, tLesao* l){
    if (p->qtdLesoes < QTD_LESAO){
        p->listaLesao[p->qtdLesoes] = l;
        p->qtdLesoes++;
    }
}