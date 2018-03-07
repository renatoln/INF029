#include <stdio.h>
#include <stdlib.h>

int size1 = 5;

int inserirElemento(int *vetPar, int *vetImpar, int *tamPar, int *tamImpar, int *qualVetor);
void listarElementos(int *vetPar, int *vetImpar, int tamPar, int tamImpar);
int removerElemento(int *vetPar, int *vetImpar, int *tamPar, int *tamImpar);
void printMenu(){
	printf("Digite a opção:\n");
	printf("1 - Inserir\n");
	printf("2 - Remover elementos\n");
	printf("3 - Listar\n");
	
	printf("0 - Sair\n");
}


int main()
{
    printf("Hello Pilha ponteiros!\n");
    int vetPar[size1];
	int vetImpar[size1];
	int qualVetor = 0;
	int tamPar = 0;
	int tamImpar = 0;
	int sair = 0, opcao;
	while (!sair){
		printMenu();
		scanf("%d",&opcao);
		switch(opcao){
			case 0:{
				sair = 1;
				break;
			}
			case 1: {
				int cheio;
				cheio = inserirElemento(vetPar, vetImpar, &tamPar, &tamImpar, &qualVetor);
				if (cheio){
					
					if (qualVetor == 2)
						printf("Vetor PAR Cheio\n");	
					else
						printf("Vetor IMPAR Cheio\n");	
					
				}else{
					if (qualVetor == 2)
						printf("Valor inserido no vetor PAR com sucesso\n");	
					else
						printf("Valor inserido no vetor IMPAR com sucesso\n");
				}
				break;
			}
			case 2: {
				removerElemento(vetPar, vetImpar, &tamPar, &tamImpar);
				break;
			}
			case 3: {
				listarElementos(vetPar, vetImpar, tamPar, tamImpar);
				break;
			}
			default:{
				printf("Opção inválida\n");				
			}
		}
	}
	
	
    //printf("Endereco de i: %p\n", p);
    //printf("Valor de i %d\n", *p);
    //printf("%p\n", &pinteiro);
    return 0;
}

int inserirElemento(int *vetPar, int *vetImpar, int *tamPar, int *tamImpar, int *qualVetor){
    printf("Digite o elemento\n");
    int i;
	int cheio = 0;
    scanf("%d", &i);
    if (i % 2 == 0){ //par
		*qualVetor = 2;
		if (*tamPar < size1){
			vetPar[*tamPar] = i;
			//*(vetPar+tamPar) = i;
			*tamPar = *tamPar + 1; 
		}else{
		    cheio = 1;
		}
    }else{
    	*qualVetor = 1;
		if (*tamImpar < size1){
			vetImpar[*tamImpar] = i;
			//*(vetPar+tamImpar) = i;
			*tamImpar = *tamImpar + 1;
		}else{
		    cheio = 1;
		}	
	
	}
	return cheio;
}

void listarElementos(int *vetPar, int *vetImpar, int tamPar, int tamImpar){
	printf("Vetor par\n");
	for (int i = 0; i < tamPar; i++)
			printf("%d\n",vetPar[i]);
	printf("Vetor impar\n")	;
	for (int i = 0; i < tamImpar; i++)
			printf("%d\n",vetImpar[i]);	

}

int removerElemento(int *vetPar, int *vetImpar, int *tamPar, int *tamImpar){
	int op;
	printf("Remover último elemento (1) par ou (2) impar?\n");
	scanf("%d", &op);
	if (op == 1 && *tamPar > 0) {
		*tamPar = *tamPar - 1;
	}else if (op == 2 && *tamImpar > 0){
		*tamImpar = *tamImpar - 1;
	}	
	return 0;	
}


