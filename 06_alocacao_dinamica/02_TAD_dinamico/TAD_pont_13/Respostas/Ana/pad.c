#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pad.h"

tPad* CriaPad(){
    tPad *pad;

    pad = (tPad*) calloc(1, sizeof(tPad));
    pad->qtdpacientes = 0;

    return pad;
}

void RodaPad(tPad *p){
    char c;

    while(1){
        scanf("%c%*c", &c);
        
        if (c == 'P'){
            p->listapacientes[p->qtdpacientes] = CriaPaciente();
            LePaciente(p->listapacientes[p->qtdpacientes]);
            p->qtdpacientes++;
        }

        else if (c == 'L'){
            tLesao *l;
            int existePaciente = 0;
            char cSus[TAM_CSUS];
            l = CriaLesao();

            scanf("%[^\n]%*c", cSus);
            LeLesao(l);

            for (int i = 0; i < p->qtdpacientes; i++){
                if (strcmp(GetCartaoSusPaciente(p->listapacientes[i]), cSus) == 0){
                    AdicionaLesaoPaciente(p->listapacientes[i], l);
                    existePaciente = 1;
                }
            }

            if (!existePaciente)
                LiberaLesao(l);
        }

        else if (c == 'F')
            break;
    }
}

void ImprimeRelatorioPad(tPad *p){
    int mediaIdade = 0, totalLesoes = 0, totalCirurgias = 0;
    tData *hoje;
    hoje = CriaData(DIA_PAD, MES_PAD, ANO_PAD);
 

    for (int i = 0; i < p->qtdpacientes; i++) {
        mediaIdade += CalculaIdadeData(GetNascimentoPaciente(p->listapacientes[i]), hoje);
        totalLesoes += GetQtdLesoesPaciente(p->listapacientes[i]);
        totalCirurgias += GetQtdCirurgiasPaciente(p->listapacientes[i]);
    }

    if (p->qtdpacientes > 0)
        mediaIdade /= p->qtdpacientes;

    printf("TOTAL PACIENTES: %d\n", p->qtdpacientes);
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
    printf("LISTA DE PACIENTES: \n");

    for (int i = 0; i < p->qtdpacientes; i++) {
        ImprimePaciente(p->listapacientes[i]);
    }

    LiberaData(hoje);
}

void LiberaPad(tPad *p){
    for (int i = 0; i < p->qtdpacientes; i++) {
        LiberaPaciente(p->listapacientes[i]);
    }

    free(p);
}