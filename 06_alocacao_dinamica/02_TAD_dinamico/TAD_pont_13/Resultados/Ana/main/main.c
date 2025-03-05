#include <stdio.h>
#include <stdlib.h>
#include "pad.h"

int main(){
    tPad *pad;

    pad = CriaPad();

    RodaPad(pad);
    ImprimeRelatorioPad(pad);
    LiberaPad(pad);

    return 0;
}