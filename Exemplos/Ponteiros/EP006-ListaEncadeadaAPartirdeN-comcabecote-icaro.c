#include <stdio.h>
#include <stdlib.h>


typedef struct lista celula;

struct lista{
	int conteudo;
	celula* prox;
};


void insereNoFinal( celula *inicio, int num){

	celula* tmp;
	celula* novo = (celula*) malloc(sizeof(celula));

	if(!novo){
		printf("Sem memoria disponivel");
		exit(1);
	}
	novo->prox = NULL;
	novo->conteudo = num;


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

void imprimelista(celula *inicio){

	/*aqui é onde se faz para começar no segundo elemento, ou seja pulando o cabeçote*/
	celula* tmp = inicio->prox;

	while(tmp != NULL){
		printf(" %d ", tmp->conteudo);
		tmp = tmp->prox;
	}
}

void liberaLista(celula* inicio){

	celula* atual = inicio;
	celula* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}


int main(){

	celula* inicio = (celula*) malloc(sizeof(celula));
	inicio->prox = NULL;

	int qtd; int conteudo = 1;

	printf("Digite a quantidade de nós que deseja criar: ");
	scanf("%d", &qtd);

	for(int i = 1; i <= qtd; i++)
		insereNoFinal(inicio, i);

	imprimelista(inicio);

	liberaLista(inicio);


}
