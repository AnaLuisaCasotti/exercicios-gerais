#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servidor.h"

int main(){

    Servidor serv = leRegistrosServidor();
    criaRelatorioServidor(serv);
    
    return 0;
}