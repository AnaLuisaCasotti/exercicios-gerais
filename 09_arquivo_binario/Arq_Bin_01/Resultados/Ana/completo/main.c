#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    int numAlunos;
    char nomeBinario[11] = "alunos.bin";
    Aluno** vetorAlunos;

    printf("Digite o numero de alunos: ");
    scanf("%d%*c", &numAlunos);
    vetorAlunos = CriaVetorAlunos(numAlunos);
    LeAlunos(vetorAlunos, numAlunos);
    SalvaAlunosBinario(vetorAlunos, nomeBinario, numAlunos);
    LiberaAlunos(vetorAlunos, numAlunos);

    vetorAlunos = CriaVetorAlunos(numAlunos);
    CarregaAlunosBinario(vetorAlunos, nomeBinario);
    ImprimeAlunos(vetorAlunos, numAlunos);
    LiberaAlunos(vetorAlunos, numAlunos);

    return 0;
}