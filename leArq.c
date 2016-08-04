#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int leArqABB(const char * nomeArq, TipoDicionario * arvore) {
    TipoChave palavra;
    char * p;
    FILE * arq;
    int posPalavra;
    char * aux;

    arq = fopen(nomeArq, "r");
    if (!arq)
        return 0;

    posPalavra = 0;
    while (!feof(arq)) {
        fscanf(arq, "%s", palavra); // Lê uma palavra no arquivo
        for (p = palavra; (*p) != '\0'; p++)
            // Desconsidera caracteres que não estejam nos intervalos abaixo
            if (((*p) < 'A' || (*p) > 'Z') &&
                ((*p) < 'a' || (*p) > 'z') &&
                ((*p) < '0' || (*p) > '9') &&
                ((*p) < '�' || (*p) > '�')
            ) {
                // Se for achado um caractere inválido, é inserido um
                // terminador de string em seu lugar
                (*p) = '\0';
                break;
            }

        aux  = strtok(palavra, ",.()");
        if (palavra[0] != '\0') // Se a palvara não é vazia
            insereABB(arvore, aux, posPalavra); // Insere na árvore
            posPalavra++;
    }
    fclose(arq);
    return 1;
}

int leArqABBContexto(const char * nomeArq, TipoDicionario * arvoreContexto) {
    TipoChave palavra;
    char * p;
    FILE * arq;
    int posPalavra;

    arq = fopen(nomeArq, "r");
    if (!arq)
        return 0;

    posPalavra = 0;
    while (!feof(arq)) {
        fscanf(arq, "%s", palavra); // Lê uma palavra no arquivo
        for (p = palavra; (*p) != '\0'; p++)
            // Desconsidera caracteres que não estejam nos intervalos abaixo
            if (((*p) < 'A' || (*p) > 'Z') &&
                ((*p) < 'a' || (*p) > 'z') &&
                ((*p) < '0' || (*p) > '9') &&
                ((*p) < '�' || (*p) > '�')
            ) {
                // Se for achado um caractere inválido, é inserido um
                // terminador de string em seu lugar
                (*p) = '\0';
                break;
            }
        if (palavra[0] != '\0') // Se a palvara não é vazia
            insereABBContexto(arvoreContexto, palavra, posPalavra);
            posPalavra++; // Insere na árvore
    }
    fclose(arq);
    return 1;
}
