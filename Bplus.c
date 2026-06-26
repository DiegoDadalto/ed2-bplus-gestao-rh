// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#include <stdio.h>
#include <stdlib.h>
#include "Bplus.h"

Pagina *criaPagina() {
    Pagina *nova = (Pagina *)malloc(sizeof(Pagina));
    if (nova == NULL) {
        printf("Erro ao alocar página.");
        return NULL;
    }
    nova->numChaves = 0;
    nova->ehFolha = true;
    nova->ponteiros = (Pagina **)malloc((2 * ORDEM + 1) * sizeof(Pagina *));
    nova->chaves = (void **)malloc(2 * ORDEM * sizeof(void*));
    nova->proximo = NULL;

    return nova;
}

void liberaPagina(Pagina *pagina) {
    if (pagina->ponteiros != NULL) free(pagina->ponteiros);

    for (int i = 0; i < pagina->numChaves; i++) {
        if (pagina->chaves[i] != NULL) {
            free(pagina->chaves[i]);
        }
    }
    free(pagina->chaves);

    if (pagina->proximo != NULL) free(pagina->proximo);
    free(pagina);
}

void liberaBplus(Pagina *raiz) {
    if (raiz == NULL) return;

    if (!raiz->ehFolha) {
        for (int i = 0; i < raiz->numChaves; i++) {
            liberaBplus(raiz->ponteiros[i]); // Libera primeiro as páginas folha
        }
    }

    liberaPagina(raiz);
}

bool comparaChaves(void *chave, void *chavePagina, int direcao){
    
}

void *buscaBplus(Pagina *raiz, void *chave) {
    void *retorno[2];
    for (int i = 0; i < raiz->numChaves; i++) {
        if (chave > raiz->chaves[i] && !raiz->ehFolha) {
            buscaBplus(raiz->ponteiros[i], chave); 
        }

        if (chave == raiz->chaves[i] && raiz->ehFolha) {
            retorno[0] = (void*)raiz;
            retorno[1] = chave; 
            return retorno;
        }
    }
}

// Julia vai terminar a insercao
void insereBplus(Pagina *raiz, void *chave, int* flagEncontrado) {
    // "pilha" para manter a referência para a página mãe
    int q = raiz->numChaves; // [Diego] tentem não usar variáveis de uma letra só gente
    for (int i = 0; i < raiz->numChaves; i++) {

        // se a chave a ser inserida é menor ou igual a chave na pagina
        if(comparaChaves(chave, raiz->chaves[i], 0)){
            insereBplus(raiz->ponteiros[i], chave, flagEncontrado);
        }
        
        // se a chave a ser inserida é maior que a chave na pagina
        if(comparaChaves(chave, raiz->chaves[i], 1)){
            insereBplus(raiz->ponteiros[i], chave, flagEncontrado);
        }
    }
}

void cisao(Pagina *paginaMae, Pagina *paginaFilha, int posFilha) {
    Pagina *nova = criaPagina();
    nova->numChaves = ORDEM;

    for (int i = 0; i < ORDEM; i++) {
        nova->chaves[i] = paginaFilha->chaves[i + ORDEM + 1]; // Transpõe as chaves da página sofrendo cisão para a nova página
        paginaFilha->numChaves--;
    }

    if (!paginaFilha->ehFolha) {
        for (int i = 0; i < ORDEM; i++) {
            nova->ponteiros[i] = paginaFilha->ponteiros[i + ORDEM + 1]; // Transpõe os ponteiros da página sofrendo cisão para a nova página
        }
    }

    // Abrindo espaço na página mãe para a chave que vai subir
    for (int i = paginaMae->numChaves; i > posFilha; i--) { // comentario bobor aqui usa numChaves ao invés de numChaves - 1 pq e pra abrir espaço pro ponteiro nao pra chave
        paginaMae->ponteiros[i + 1] = paginaMae->ponteiros[i];
    }

    paginaMae->ponteiros[posFilha + 1] = nova; // Atribui a nova página ao ponteiro vago no vetor de ponteiros

    for (int i = paginaMae->numChaves - 1; i > posFilha - 1; i--) { // agoura simmm!! usa as coisas tudo com -1 pq é pra botar a chave
        paginaMae->chaves[i + 1] = paginaMae->chaves[i];
    }

    paginaMae->chaves[posFilha] = paginaFilha->chaves[ORDEM]; // Insere a chave intermediária da página filha no espaço adjacente a ambos os ponteiros das páginas filhas
    paginaMae->numChaves++;
}

void removeBplus(Pagina *raiz, void *chave) {
    void *info = buscaBplus(raiz, chave);

    
}