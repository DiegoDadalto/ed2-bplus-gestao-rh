// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bplus.h"


// Diego
Pagina *criaPagina(bool ehFolhaNova) {
    Pagina *nova = (Pagina *)malloc(sizeof(Pagina));
    if (nova == NULL) {
        printf("Erro ao alocar página.");
        return NULL;
    }
    nova->numChaves = 0;
    nova->ehFolha = ehFolhaNova;
    nova->ponteiroDados = (void **)malloc((MAX_CHAVES_FOLHA + 1) * sizeof(void *));
    nova->chaves = (char **)malloc(MAX_CHAVES_FOLHA * sizeof(char*));
    nova->proximo = NULL;
    nova->anterior = NULL;

    return nova;
}

// Diego
void liberaPagina(Pagina *pagina) {
    if (pagina->ponteiros != NULL) free(pagina->ponteiros);
    
    for (int i = 0; i < MAX_CHAVES_FOLHA + 1; i++) {
        if (pagina->ponteiroDados[i] != NULL) {
            free(pagina->ponteiroDados[i]);
        }
    }

    for (int i = 0; i < pagina->numChaves; i++) {
        if (pagina->chaves[i] != NULL) {
            free(pagina->chaves[i]);
        }
    }
    free(pagina->chaves);

    if (pagina->proximo != NULL) free(pagina->proximo);
    if (pagina->anterior != NULL) free(pagina->proximo);
    free(pagina);
}

// Diego
void liberaBplus(Pagina *raiz) {
    if (raiz == NULL) return;

    if (!raiz->ehFolha) {
        for (int i = 0; i < raiz->numChaves; i++) {
            liberaBplus(raiz->ponteiros[i]); // Libera primeiro as páginas folha
        }
    }

    liberaPagina(raiz);
}


// Diego e Julia
void *buscaBplus(Pagina *raiz, char *chave) {
    void *retorno[3];
    for (int i = 0; i < raiz->numChaves; i++) {
        if (strcmp(chave, raiz->chaves[i]) > 1 && !raiz->ehFolha) {
            buscaBplus(raiz->ponteiros[i], chave); 
        }

        if (strcmp(chave, raiz->chaves[i]) == 0 && raiz->ehFolha) {
            retorno[0] = (void*)raiz; // pagina onde esta a chave
            retorno[1] = (void*)i; // pos da pagina onde esta a chave
            retorno[2] = (void*)1; // chave encontrada
            return retorno;
        } else {
            retorno[0] = (void*)raiz; // pagina onde deveria estar a chave
            retorno[1] = (void*)i; // pos da pagina onde deveria estar a chave
            retorno[2] = (void*)0; // chave nao encontrada
            return retorno;
        }
    }
}

// Diego
Pagina* buscaMae(Pagina *raiz, Pagina *filha) {
    void *referenciaBusca = filha->chaves[0]; // Referência para achar a página fila

    for (int i = 0; i < raiz->numChaves; i++) {
        if (filha == raiz->ponteiros[i]) {
            return raiz;
        }
    }

    for (int i = 1; i < raiz->numChaves; i++) {
        if (referenciaBusca < raiz->chaves[i-1]) {
            buscaMae(raiz->ponteiros[i - 1], filha);
        }
        else if (referenciaBusca > raiz->chaves[i - 1] && referenciaBusca < raiz->chaves[i]) {
            buscaMae(raiz->ponteiros[i], filha);
        }
        else buscaMae(raiz->ponteiros[i + 1]);
    }
}

// Julia
void insereBplus(Pagina *raiz, char *chave) {
    void* resultadoBusca = buscaBplus(raiz, chave);
    int encontrado = (int)resultadoBusca[2]; // [Diego] casting invalido
    if (encontrado == 1) {
        printf("Chave ja existente na arvore.\n");
        return;
    } else {
        // TERMINAR
        /* inserir na pagina correspondente de resultadoBusca[0]
        na posicao da pagina correspondente a resultadoBusca[1] */
        Pagina *pg = (Pagina*)resultadoBusca[0]; // [Diego] casting invalido aqui tb
        if (pg->numChaves > MAX_CHAVES_FOLHA) {
        // redistribuicao com a pagina irma ou nova pagina criada (?)
        } else {
        int i = pg->numChaves;
        strcpy(pg->chaves[i + 1], chave);
        // ordenar as chaves na folha (algum algoritmo de ordenacao???)
        // inserir um novo ponteiro de dado (o ponteiro 'proximo' tambem eh modificado?)
        }
    }
}

// Diego
void cisao(Pagina *paginaMae, Pagina *paginaFilha, int posFilha) {
    Pagina *nova = NULL;
    
    if (paginaFilha->ehFolha) {
        Pagina *nova = criaPagina(true);
        nova->numChaves = ORDEM_FOLHA;
    }
    else {
        Pagina *nova = criaPagina(false);
        nova->numChaves = ORDEM_INTERNA;
    }
    

    for (int i = 0; i < nova->numChaves; i++) {
        strcpy(nova->chaves[i], paginaFilha->chaves[i + nova->numChaves + 1]); // Transpõe as chaves da página sofrendo cisão para a nova página
        paginaFilha->numChaves--;
    }

    if (!paginaFilha->ehFolha) {
        for (int i = 0; i < ORDEM_INTERNA; i++) {
            nova->ponteiros[i] = paginaFilha->ponteiros[i + ORDEM_INTERNA + 1]; // Transpõe os ponteiros da página sofrendo cisão para a nova página
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

    paginaMae->chaves[posFilha] = paginaFilha->chaves[nova->numChaves]; // Insere a chave intermediária da página filha no espaço adjacente a ambos os ponteiros das páginas filhas
    paginaMae->numChaves++;
}



// Sol
bool redistribuicao(Pagina *paginaChaveRemovida, Pagina *paginaMae, Pagina *paginaIrma, bool direcaoPaginaIrma, int posMae){
    
    if(direcaoPaginaIrma){ 
        // Irma a direita
        
        strcpy(paginaChaveRemovida->chaves[paginaChaveRemovida->numChaves + 1], paginaMae->chaves[posMae]);
        paginaChaveRemovida->numChaves++;
        strcpy(paginaMae->chaves[posMae], paginaIrma->chaves[0]);
        removeBplus(paginaIrma, paginaIrma->chaves[0]);
    } else {
        // Irma a esquerda

        strcpy(paginaChaveRemovida->chaves[paginaChaveRemovida->numChaves + 1], paginaMae->chaves[posMae]);
        paginaChaveRemovida->numChaves++;
        strcpy(paginaMae->chaves[posMae], paginaIrma->chaves[0]);
        removeBplus(paginaIrma, paginaIrma->chaves[0]);
    }

    // Julia: por que retorna bool??
}

// Diego
void removeBplus(Pagina *raiz, char *chave) {
    void *info[2] = buscaBplus(raiz, chave);
    Pagina *localArvore = (Pagina*)info[0];
    int posicaoVetorChaves = *((int*)info[1]);
    
    for (int i = posicaoVetorChaves + 1; i < localArvore->numChaves; i++) {
        localArvore->ponteiroDados[i - 1] = localArvore->ponteiroDados[i];
        strcpy(localArvore->ponteiros[i - 1], localArvore->ponteiros[i]);
    }
    localArvore->numChaves--;

    if (localArvore->numChaves < ORDEM_FOLHA) {
        if (localArvore->anterior->numChaves + localArvore->numChaves == ORDEM_FOLHA + 1) {
            // redistribuicao(localArvore, )
        }
    }

    // Julia:
    free(info);
    return;
}