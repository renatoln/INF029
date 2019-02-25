#include <stdio.h>
#include <stdlib.h>

/** Criar uma lista encadeada a partir de um valor N informado pelo usuário. Os nós devem ter valores sequenciais a partir de 1*/
int tam = 0;
typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;

No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No));
	novo->conteudo = valor;
	novo->prox = NULL;
	return novo;
}

int inserirNoFinal(No **inicio, int val){
    No *novo;
    No *atual;

    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
        printf("Falta Memoria\n");
        return -1;
    }
    novo->conteudo = val;
    novo->prox = NULL;

    if(*inicio == NULL)
        *inicio = novo;
    else{
        atual = *inicio;

        while(atual->prox != NULL)
            atual = atual->prox;

        atual->prox = novo;
    }
		return 1;
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
	No *inicio = NULL;
	No *temp = NULL;
	printf("Digite um número!\n");
	scanf("%d", &n);
	if (n <= 0){
		printf("valor inválido\n");
		exit(0);
	}

	for (i = 1; i <= n; i++)
		inserirNoFinal(&inicio, i);

	listarElementos(inicio);

	liberarLista(inicio);
}
