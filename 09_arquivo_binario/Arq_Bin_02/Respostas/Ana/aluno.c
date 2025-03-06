#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

/**
 * @brief Estrutura para representar um aluno.
 */
typedef struct Aluno {

    char nome[100];
    char dataNasc[11];
    char curso[50];
    int periodo;
    float CR;

} tAluno;

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno* a = (tAluno*) malloc(sizeof(tAluno));

    if (!a){
        exit(1);
    }

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->CR = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    if (aluno != NULL){
        free(aluno);
    }
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
    char nome[100], dataNasc[11], curso[50];
    int periodo;
    float CR;

    fread(&nome, sizeof(char), 100, arquivo_binario);
    fread(&dataNasc, sizeof(char), 11, arquivo_binario);
    fread(&curso, sizeof(char), 50, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&CR, sizeof(float), 1, arquivo_binario);

    tAluno* a = CriarAluno(nome, dataNasc, curso, periodo, CR);

    return a;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->CR;
}