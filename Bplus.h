// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#ifndef BPLUS_H
#define BPLUS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDEM_INTERNA 3
#define ORDEM_FOLHA 2
#define MAX_CHAVES_INTERNA 6
#define MAX_CHAVES_FOLHA 4

typedef struct pagina {
    int numChaves; // numero de chaves que a pagina contem
    bool ehFolha; // flag
    Pagina **ponteiros; // ponteiro para os ponteiros para as paginas filhas
    void **ponteiroDados; // ponteiro para os ponteiros de dados quando a pagina eh folha
    int *chaves; // ponteiro para as chaves da pagina
    Pagina *proximo; // ponteiro para a proxima pagina folha
    Pagina *anterior; // ponteiro para a pagina folha anterior a atual
} Pagina;

Pagina *criaPagina();
void liberaPagina(Pagina *pagina);
void liberaBplus(Pagina *raiz);
void insereBplus(Pagina *raiz, void *chave, int* flagEncontrado);
void *buscaBplus(Pagina *raiz, void *chave);
void cisao(Pagina *paginaMae, Pagina *paginaFilha, int posFilha);
void removeBplus(Pagina *raiz, void *chave);

#endif