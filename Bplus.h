// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#ifndef BPLUS_H
#define BPLUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ORDEM 3

typedef struct pagina {
    int numChaves;
    int ordem;
    bool ehFolha;
    Pagina **ponteiros;
    void **chaves;
    Pagina *proximo;
} Pagina;

Pagina *criaPagina();
void liberaPagina(Pagina *pagina);
void liberaBplus(Pagina *raiz);
void insereBplus(Pagina *raiz, void *chave, int* flagEncontrado);
void *buscaBplus(Pagina *raiz, void *chave);
void cisao(Pagina *paginaMae, Pagina *paginaFilha, int posFilha);
void removeBplus(Pagina *raiz, void *chave);

#endif