#include "palavras.h"

// Compara duas palavras, retornando 0 se palavra1 < palavra2,
// 1 se palavra1 > palavra2 e 2 se elas forem iguais
// Obs: maiúsculas e minúsculas não são diferenciadas
Direcao compara(TipoChave palavra1, TipoChave palavra2) {
    char * p1, * p2;
    int comp1, comp2;

    for (p1 = palavra1, p2 = palavra2; (*p1) != '\0'; p1++, p2++) {
        // comp1 e comp2 procuram letras maiusculas nas palavras
        // caso existam, é somado 0x20 ao seu valor, para que sejam
        // equivalentes às minúsculas
        comp1 = ((*p1) >= 'A' && (*p1) <= 'Z');
        comp2 = ((*p2) >= 'A' && (*p2) <= 'Z');
        if (comp1) {
            if (comp2) {
                if ((*p1)+0x20 < (*p2)+0x20)
                    return ESQ; // palavra1 < palavra2
                else if ((*p1)+0x20 > (*p2)+0x20)
                    return DIR; // palavra1 > palavra2
            }
            else if ((*p1)+0x20 < (*p2))
                return ESQ;
            else if ((*p1)+0x20 > (*p2))
                return DIR;
        }
        else if (comp2) {
            if ((*p1) < (*p2)+0x20)
                return ESQ;
            else if ((*p1) > (*p2)+0x20)
                return DIR;
        }
        else if ((*p1) < (*p2))
            return ESQ;
        else if ((*p1) > (*p2))
            return DIR;
    }
    if ((*p2) == '\0')
        return IGUAL; // As palavras são iguais
    return ESQ;
}


// Compara o valor das duas posicoes, retornando 0 se posicao1 < posicao2,
// 1 se posicao 1 > posicao2 e 2 se elas forem iguais
Direcao comparaContexto(int posicao1, int posicao2) { 

    if (posicao1 < posicao2) {
        return ESQ;
    } else if (posicao1 > posicao2) {
        return DIR;
    } else {
        return IGUAL;
    }

}