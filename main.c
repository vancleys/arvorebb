#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"
#include "leArq.h"


int main(int argc, char *argv[]) {

	char arq[200], aux[20], chaveProcurada[30];
    TipoDicionario arvore = NULL;
    TipoDicionario arvoreContexto = NULL;
    int posArvore, opcao = 1;
    char * arg1, * arg2;

	if (argc == 2) {

		fflush(stdin);
		strcpy(arq, argv[1]);
		int resposta, resposta2;


		resposta = leArqABB(arq, &arvore);
		resposta2 = leArqABBContexto(arq, &arvoreContexto);


		if (resposta && resposta2) {
			for (;;) {
				printf("\nPalavra: ");
				gets(chaveProcurada);
				fflush(stdin);
				arg1 = strtok(chaveProcurada, " \n");
				arg2 = strtok(NULL, " \n");

				if ((strcmp(arg1, ".")) != 0 && (arg2 == NULL)) {
					printf("Posição: ");
					buscaABB(arvore, arg1);
					fflush(stdin);
				} else if (arg2 != NULL) {
					imprimeContexto(arvoreContexto, atoi(arg2));
				} else if (strcmp(arg1, ".") == 0){
					return 0;
				}
			}
		} else {
			printf("Erro na inserção\n");
		}



	} else if (argc > 2) {
		char msgError1[] = "ERROR ARGUMENTOS 1: Digite somente o nome do arquivo como parametro !";
		printf("%s\n", msgError1);
	} else if (argc < 2) {
		char msgError2[] = "ERROR ARGUMENTOS 2: Digite o nome do arquivo como parametro!";
		printf("%s\n", msgError2);
	}

	return 0;

}
