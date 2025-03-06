#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"

/*
Função que recebe o número de um log e o caminho da pasta de logs e retorna um Registro de partida
lido do arquivo binário correspondente ao log.

@param logNum: Número do log
@param pastaLogs: Caminho da pasta de logs (já com a barra no final)
*/
Registro leRegistro(int logNum, char *pastaLogs){
    char path[100];

    sprintf(path, "%slog_%d.bin", pastaLogs, logNum);
    FILE *arqLog = fopen(path, "rb");

    Registro r;
    fread(&r.idPartida, sizeof(int), 1, arqLog);

    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++){
        r.jogadores[i] = leJogador(arqLog);
    }

    fclose(arqLog);

    return r;
}

/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog){
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++){
        if (idJog == getIdJogador(r.jogadores[i])){
            return r.jogadores[i];
        }
    }

    Jogador j = inicializaJogador(-1);
    return j;
}