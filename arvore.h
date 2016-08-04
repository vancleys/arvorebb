#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED


typedef char TipoChave[20];
typedef struct Registro {
    TipoChave Chave;
    int posicaoTexto[30];
    int ocorrencia;
} Registro;
typedef struct No * Apontador;
typedef struct No {
    Registro Reg;
    Apontador Esq, Dir;
} No;
typedef Apontador TipoDicionario;

typedef enum Direcao {
    // Indica que a subárvore esquerda tem maior altura,
    // Que devemos caminhar para a esquerda na pesquisa
    // ou que queremos acessar a Subárvore da esquerda.
    ESQ = 0,

    // Indica que a subárvore direita tem maior altura,
    // Que devemos caminhar para a direita na pesquisa
    // ou que queremos acessar a Subárvore da direita.
    DIR = 1,

    // Indica que as subárvore tem alturas iguais.
    // Não é válida nos outros contextos.
    IGUAL = 2,
} Direcao;


Direcao comparaContexto(int posicao1, int posicao2);
int buscaABB(TipoDicionario arvore, TipoChave chave);
int buscaABBContexto(TipoDicionario arvoreContexto, int contexto);
void insereABB(TipoDicionario * arvore, TipoChave chave, int posPalavra);
void imprimeInOrderABB(TipoDicionario arvore);
void imprimeABB(TipoDicionario arvore, int indent);
void insereABBContexto(TipoDicionario * arvoreContexto, TipoChave chave, int posPalavra);
int imprimeContexto(TipoDicionario arvoreContexto, int contexto);

#endif // ARVORE_H_INCLUDED
