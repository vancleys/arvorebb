#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "palavras.h"


/*
 * BUSCAS
 */
int buscaABB(TipoDicionario arvore, TipoChave chave) {
    if (!arvore) // Árvore vazia
        return 0;

    int i;

    switch (compara(chave, arvore->Reg.Chave)) {
        case 0: // Elemento é menor que o contido no nó atual
            return buscaABB(arvore->Esq, chave);
        case 1: // Elemento é maior
            return buscaABB(arvore->Dir, chave);
        default: // Elemento possui a mesma chave     
            for (i=0; i < arvore->Reg.ocorrencia; i++) {
                printf("%d ", arvore->Reg.posicaoTexto[i]+1);
            }
            printf("\n");
            return 1;
    }
}


int buscaABBContexto(TipoDicionario arvoreContexto, int contexto) {

    if (!arvoreContexto)
        return 0;

    if (arvoreContexto->Reg.posicaoTexto[0] > contexto) {
        buscaABBContexto(arvoreContexto->Esq, contexto);
    } else if (arvoreContexto->Reg.posicaoTexto[0] < contexto) {
        buscaABBContexto(arvoreContexto->Dir, contexto);
    } else {
        printf("%s ", arvoreContexto->Reg.Chave);
        return 1;
    }
}




/*
 * INSERÇÕES
 */
void insereABB(TipoDicionario * arvore, TipoChave chave, int posPalavra) {
    if (!(*arvore)) { // Árvore vazia
        *arvore = malloc(sizeof(No));
        (*arvore)->Esq = NULL;
        (*arvore)->Dir = NULL;
        strcpy((*arvore)->Reg.Chave, chave);
        (*arvore)->Reg.ocorrencia=1;
        (*arvore)->Reg.posicaoTexto[(*arvore)->Reg.ocorrencia-1] = posPalavra;

    }
    else switch (compara(chave, (*arvore)->Reg.Chave)) {
        case 0: // Elemento é menor que o contido no nó atual
            insereABB(&((*arvore)->Esq), chave, posPalavra);
            break;
        case 1: // Elemento é maior
            insereABB(&((*arvore)->Dir), chave, posPalavra);
            break;
        default:
            (*arvore)->Reg.ocorrencia++;
            (*arvore)->Reg.posicaoTexto[(*arvore)->Reg.ocorrencia-1] = posPalavra;
    }
}


void insereABBContexto(TipoDicionario * arvoreContexto, TipoChave chave, int posPalavra) {

    if (!(*arvoreContexto)) {
        *arvoreContexto = malloc(sizeof(No));
        (*arvoreContexto)->Esq = NULL;
        (*arvoreContexto)->Dir = NULL;
        strcpy((*arvoreContexto)->Reg.Chave, chave);
        (*arvoreContexto)->Reg.posicaoTexto[0] = posPalavra;
    } else switch (comparaContexto(posPalavra, (*arvoreContexto)->Reg.posicaoTexto[0])) {
        case 0:
            insereABBContexto(&((*arvoreContexto)->Esq), chave, posPalavra);
            break;
        case 1:
            insereABBContexto(&((*arvoreContexto)->Dir), chave, posPalavra);
            break;

    }
}


/*
 *  IMPRESSÃO
 */
int imprimeContexto(TipoDicionario arvoreContexto, int contexto) {

    int i = 0;
    if (arvoreContexto) {

        for (i = 4; i > -3; i--) {
            buscaABBContexto(arvoreContexto, contexto-i);
        }
        printf("\n");
    }

    return 1;
}
