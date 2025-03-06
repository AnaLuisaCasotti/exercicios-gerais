#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno {

    char nome[100];
    char dataNasc[50];
    char curso[50];
    char periodoIngresso[50];
    int concluido;
    float CRA;

} Aluno;

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno** vetorAlunos = (Aluno**) calloc(numeroAlunos, sizeof(Aluno*));

    return vetorAlunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno* a = (Aluno*) malloc(sizeof(Aluno));

    if (!a){
        exit(1);
    }
    
    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodoIngresso, periodoIngresso);
    a->concluido = percConclusao;
    a->CRA = CRA;

    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[100], dataNasc[50], curso[50], periodoIngresso[50];
    int percConluido;
    float CRA;

    for (int i = 0; i < numeroAlunos; i++){
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", dataNasc);
        scanf("%[^\n]\n", curso);
        scanf("%[^\n]\n", periodoIngresso);
        scanf("%d\n", &percConluido);
        scanf("%f\n", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dataNasc, curso, periodoIngresso, percConluido, CRA);
        //printf("\n%s\n", vetorAlunos[i]->nome);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    if (alunos != NULL){
        for (int i = 0; i < numeroAlunos; i++){
            if (alunos[i] != NULL){
                free(alunos[i]);
            }
        }

        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE *alunosBin;
    int numBytes = 0;

    alunosBin = fopen(fileName, "wb");

    numBytes = fwrite(alunos, sizeof(Aluno), numeroAlunos, alunosBin);

    printf("Numero de bytes salvos: %d\n", numBytes);

    fclose(alunosBin);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE *alunosBin;
    int i = 0;

    alunosBin = fopen(fileName, "rb");

    //alunos[i] = (Aluno*) malloc(sizeof(Aluno));
    while(fread(&alunos[i], sizeof(Aluno), 1, alunosBin) == 1){
        printf("%s\n", alunos[i]->nome);
        i++;
        //alunos[i] = (Aluno*) malloc(sizeof(Aluno));
    }

    //free(alunos[i]);

    fclose(alunosBin);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++){
        printf("Aluno: %d\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dataNasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->concluido);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}