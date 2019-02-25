/* observe a questão EP006 que tem duas abordagens
  - EP006-ListaEncadeadaAPartirdeN-comcabecote-icaro.c usa cabeçote (inicio). Cabeçote é um elemento que não tem valor serve só para ter acesso ao início da lista. ELe é definido no main(). A função crialista() usa um ponteiro
  Por outro lado,
  - EP006-ListaEncadeadaAPartirdeN.c NÃO usa cabeçote. O primeiro elemento já é um elemento válido da lista. Ele é definido dentro da função. Neste caso, é preciso usar ponteiro para ponteiro.
*/


#include <stdio.h>
#include <stdlib.h>

int tam = 0;
typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;

No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No));
	if(novo == NULL){
			printf("Falta Memoria\n");
			exit(1);
	}
	novo->conteudo = valor;
	novo->prox = NULL;
	return novo;
}

void inserirNoFinalSemCabecote(No **inicioSemCabecote, int val){
    No *novo;
    No *atual;

    novo = criarElemento(val);

    if(*inicioSemCabecote == NULL)
        *inicioSemCabecote = novo;
    else{
        atual = *inicioSemCabecote;

        while(atual->prox != NULL)
            atual = atual->prox;

        atual->prox = novo;
    }
}


void inserirNoFinalComCabecote(No *inicio, int val){

	No* tmp;
	No* novo = criarElemento(val);

	if(inicio->prox == NULL){
		inicio->prox = novo;
	}
	else{
		tmp = inicio->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void listarElementos(No* inicio){
	No *p;
	printf ("lista\n");
  for (p = inicio; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
}

void liberarLista(No* inicio){

	No* atual = inicio;
	No* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}

int main()
{
	int n, i;
	No *inicioListaSemCabecote = NULL;

  No *inicioListaComCabecote = (No*) malloc(sizeof(No));
	inicioListaComCabecote->prox = NULL;
	printf("Digite um número!\n");
	scanf("%d", &n);
	if (n <= 0){
		printf("valor inválido\n");
		exit(0);
	}

	for (i = 1; i <= n; i++){
		inserirNoFinalSemCabecote(&inicioListaSemCabecote, i);
    inserirNoFinalComCabecote(inicioListaComCabecote, i);
  }

	listarElementos(inicioListaSemCabecote);
  listarElementos(inicioListaComCabecote->prox);

	liberarLista(inicioListaSemCabecote);
	liberarLista(inicioListaComCabecote);

}
