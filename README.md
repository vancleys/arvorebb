Descrição da funções

-> Arvore.c

	int buscaABB(TipoDicionario arvore, TipoChave chave)

	Tem como parâmetros de entrada uma estrutura do TipoDicionario, e uma chave a ser procurada.
	Verifica se uma arvore existe, e caso não retorna 0 e sai da função. Em seguida testa o
	retorno da função compara(chave, arvore->Reg.Chave), e compara os resultados de acordo com
	os cases implementados. Case 0, o elemento buscado é menor que a Chave armazenada no nó e
	a função caminha para o nó filho a esquerda. Case 1, o elemento é maior que a chave buscada e
	aponta para nó filho a direita. Case default, a chave é igual a buscada.



	int buscaABBContexto(TipoDicionario arvoreContexto, int contexto)

	Tem como parâmetros de entrada uma estrutura do TipoDicionario, e uma variavél que expressa
	qual posição do texto deve ser buscada o contexto. Caso não exista uma arvore, retorna 0 e sai
	função. Caso o valor da posição do texto seja menor que o valor da posição armazenada do registro,
	caminha pra esquerda, caso seja maior, caminha pra direita, e caso seja o mesmo imprime o valor
	da Chave armazenada no registro.



	void insereABB(TipoDicionario * arvore, TipoChave chave, int posPalavra)

	Se não existe uma árvore, ela aloca uma nova arvore, com os ponteiros pra esquerda e pra direita
	com os valores NULL. E copia o valor da chave e da posição da palavra lidos do arquivo no registro
	do novo nó alocado. Caso já exista um nó na arvore, ele compara o valor da chave a ser inserida com
	a chave que está no Registro do nó, e se for menor, caminha pra esquerda; se for maior, caminha pra
	direita; e se for igual, aumenta o numero de ocorrencias, e armazenda uma nova posicao na variavel
	posicaoTexto do Registro.



	void insereABBContexto(TipoDicionario * arvoreContexto, TipoChave chave, int posPalavra)

	Faz a mesma coisa que a função de cima, só que ao inves de comparar o valor da Chave, pra decidir pra qual
	lado da árvore ela deve caminhar até achar a posição de inserir, ela vai usar o valor da posição da palavra
	no texto.



	int imprimeContexto(TipoDicionario arvoreContexto, int contexto)

	Busca o valor do contexto, e quando acha o valor na árvore, imprime 3 chaves antes e 3 depois.



-> leArq.c

	int leArqABB(const char * nomeArq, TipoDicionario * arvore) 

	Recebe como parametros um nome do arquivo que contem as palavras e um ponteiro pra uma estrutura do TipoDicionario.
	Retira as palavras do texto e processa cada caractere das palavras, verificando se eles estão entre os caracteres
	aceitáveis, caso tenha algum que não esteja no intervalo determinado, esse caractere é desconsiderado. Se tiver algum
	caractere invalido, ele é substituido por \0. E depois de verficada a palavras, ela é inserida na arvore.


	int leArqABBContexto(const char * nomeArq, TipoDicionario * arvoreContexto)

	Mesma função que a de cima, só que ao inves de inserir na árvore ordenada pelas chaves, insere na arvore de contexto.



-> palavras.c

	Direcao compara(TipoChave palavra1, TipoChave palavra2)

	Recebe duas palavras como parametro, depois verifica se existe algum caractere maisculo e caso tenha é adicionado 0x20
	ao valor do caractere para que seja equivalente as minusculas. Depois verifica qual palavra é maior ou menor e indica
	qual lado da arvore deve apontar. Se a palavra1 < palavra2, retorna ESQ; se palavra1 >  palavra2, retorna DIR; e se as
	palavras forem iguais, retorna IGUAL.


	
	Direcao comparaContexto(int posicao1, int posicao2)

	Compara o valor da posicao do texto de dois registos. Se posicao1 < posicao2, retorna ESQ; se posicao1 > posicao2,
	retorna DIR; se forem iguais, retorna IGUAL.