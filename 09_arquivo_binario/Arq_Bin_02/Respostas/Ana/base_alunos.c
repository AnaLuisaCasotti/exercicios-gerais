#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_alunos.h"
#include "aluno.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
typedef struct BaseAlunos {

    tAluno** vetorAlunos;
    int qtdAlunos;

} tBaseAlunos;

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos* base = (tBaseAlunos*) malloc(sizeof(tBaseAlunos));
    base->vetorAlunos = (tAluno**) malloc(sizeof(tAluno*));

    base->qtdAlunos = 0;    

    return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    if (baseAlunos != NULL){
        for (int i = 0; i < baseAlunos->qtdAlunos; i++){
            DestruirAluno(baseAlunos->vetorAlunos[i]);
        }

        free(baseAlunos->vetorAlunos);
        free(baseAlunos);
    }
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "rb");
    int qtdAlunos;

    fread(&qtdAlunos, sizeof(int), 1, arq);
    baseAlunos->qtdAlunos = qtdAlunos;

    baseAlunos->vetorAlunos = (tAluno**) realloc(baseAlunos->vetorAlunos, qtdAlunos * sizeof(tAluno*));
    
    for (int i = 0; i < qtdAlunos; i++){
        baseAlunos->vetorAlunos[i] = LeAluno(arq);
    }

    fclose(arq);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float media = 0;

    if (baseAlunos->qtdAlunos > 0){
        for (int i = 0; i < baseAlunos->qtdAlunos; i++){
            media += GetCoeficienteRendimentoAluno(baseAlunos->vetorAlunos[i]);
        }
    
        media /= baseAlunos->qtdAlunos;
    }

    return media;
}