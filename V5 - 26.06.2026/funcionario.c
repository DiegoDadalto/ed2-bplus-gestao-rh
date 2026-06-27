// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

// Sol
bool comparaChaves(char *chave, char *chavePagina, Data *funcioProcurado, Data *funcioPagina){ // TERMINAR DE FAZER
    if(strcmp(chave, chavePagina) < 0) return true;
    if(strcmp(chave, chavePagina) > 0) return false;
    if(strcmp(chave, chavePagina) == 0){
        if(funcioProcurado->ano < funcioPagina->ano) return true;
        if(funcioProcurado->ano > funcioPagina->ano) return false;
        if(funcioProcurado->mes < funcioPagina->mes) return true;
        if(funcioProcurado->mes > funcioPagina->mes) return false;
        if(funcioProcurado->dia < funcioPagina->dia) return true;
        if(funcioProcurado->dia > funcioPagina->dia) return false;
    }
}