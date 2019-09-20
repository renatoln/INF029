#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

void iniciarPrincipal(cell vetorPrincipal[])
{
    int i;

	for(i=0;i<10;i++)
	{
        vetorPrincipal[i].vetorAux = NULL;
        vetorPrincipal[i].posicaoAtual=0;
    	vetorPrincipal[i].tam=0;
	}
}

int receberValor()
{
	int x;
	printf("Informe o valor a ser colocado:\n");
	scanf("%d", &x);
	return x;
}

void dobrar(int *x)
{
    *x = *x * 2;
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao, int valor)
{	
	int retorno = 0;

	if(posicao < 0 && posicao > 9)
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}
	

     
    if(tamanho <= 1 && tamanho >= 50)
		{
        	printf("\nERRO !!! TAMANHO INVALIDO!\n");
        	
			retorno = TAMANHO_INVALIDO;
			return retorno;
		}
			
	
	vetorPrincipal[posicao].vetorAux=(int*)malloc(tamanho * sizeof(int));

	if(vetorPrincipal[posicao].vetorAux==NULL)
		{	
 			retorno = SEM_ESPACO_DE_MEMORIA;
			return retorno;
		} 
	else 
		{
			vetorPrincipal[posicao].vetorAux[vetorPrincipal[posicao].posicaoAtual] = valor;
			vetorPrincipal[posicao].posicaoAtual++;
			retorno = SUCESSO;
		}

			
		return retorno;	
} 
	   

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao)
{

    	int retorno;
		int tamanho;

   	if(posicao < 0 || posicao > 9)
		{
			retorno = POSICAO_INVALIDA;
			return retorno;
		}

   	if(vetorPrincipal[posicao].vetorAux == NULL)
		{
			printf("Estrutura auxiliar ainda nao incializada!\n");

			retorno = criarEstruturaAuxiliar(vetorPrincipal[posicao].tam,posicao,valor);
		}
	else 
		{

			if(vetorPrincipal[posicao].posicaoAtual >= vetorPrincipal[posicao].tam)
				{
					retorno = SEM_ESPACO;
					return retorno;
				}
			
				printf("Estrutura auxiliar ja criada!\n");
				vetorPrincipal[posicao].vetorAux[vetorPrincipal[posicao].posicaoAtual] = valor;
				vetorPrincipal[posicao].posicaoAtual++;

		}	
	
	retorno = SUCESSO;
    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
		
  	int retorno;
		
	if(posicao < 0 && posicao > 9)
		{
			retorno = POSICAO_INVALIDA;
			return retorno;
		}

   	if(vetorPrincipal[posicao].vetorAux == NULL)
		{
			printf("Estrutura auxiliar ainda nao incializada!\n");
			retorno = SEM_ESTRUTURA_AUXILIAR;
			return retorno;
		}
	else
		{
			vetorPrincipal[posicao].posicaoAtual--;
			retorno = SUCESSO;
			return retorno;
		}	

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao)
{
  	int retorno;
	int i,tamanho, j = 1;

	tamanho = vetorPrincipal[posicao].posicaoAtual;

	if(posicao < 0 && posicao > 9)
		{
			retorno = POSICAO_INVALIDA;
			return retorno;
		}

   	if(vetorPrincipal[posicao].vetorAux == NULL)
		{
			printf("Estrutura auxiliar ainda nao incializada!\n");
			retorno = SEM_ESTRUTURA_AUXILIAR;
			return retorno;
		}
	else
		{
			for(i = 0; i < tamanho; i++)
				{
					if(vetorPrincipal[posicao].vetorAux[i] == valor)
						{
							while(j <= tamanho)
							{
								vetorPrincipal[posicao].vetorAux[i] = vetorPrincipal[posicao].vetorAux[i = i + j];
								j++;
							}
							vetorPrincipal[posicao].posicaoAtual--;
						}
				}
			retorno = SUCESSO;
			return retorno;
		}
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno;
    int i, tam;
    
    
    if(posicao < 0 && posicao > 9)
		{
			retorno = POSICAO_INVALIDA;
			return retorno;
		}
		
	if(vetorPrincipal[posicao].vetorAux == NULL)
		{
			printf("Estrutura auxiliar ainda nao incializada!\n");
			retorno = SEM_ESTRUTURA_AUXILIAR;
			return retorno;
		}
	else
        {
                tam = vetorPrincipal[posicao].posicaoAtual;
                
                for(i = 0; i <= tam; i++)
                    {
                        vetorAux[i] = vetorPrincipal[posicao].vetorAux[i];
                    }
                    
            retorno = SUCESSO;
			return retorno;    
        }

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;


    return retorno;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    return retorno;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    return retorno;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho'

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;

	if(posicao < 0 && posicao > 9)
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}
	

     
    if(novoTamanho < 1 && novoTamanho > 50)
		{
        	printf("\nERRO !!! TAMANHO INVALIDO!\n");
        	
			retorno = TAMANHO_INVALIDO;
			return retorno;
		}
			
	vetorPrincipal[posicao].tam = novoTamanho;
	vetorPrincipal[posicao].vetorAux = (int*)realloc(vetorPrincipal[posicao].vetorAux, vetorPrincipal[posicao].tam * sizeof(int));

	if(vetorPrincipal[posicao].vetorAux == NULL)
			{
				printf("Realloc nao efetuado por falta de memoria!\n");
				retorno = SEM_ESPACO_DE_MEMORIA;
				return retorno;
			}


	retorno = SUCESSO;		
	return retorno;	

}

/*
Objetivo: retorna a quantidade de elementos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = 0;


    return retorno;

}

/*
Objetivo: liberar todos os espaços de memória das estruturas auxiliares.

*/

void liberarEspacosEstruturasAuxiliares()
{
    int i;
	for(i=0;i<10;i++)
		{
        	if(vetorPrincipal[i].vetorAux != NULL)
            	free(vetorPrincipal[i].vetorAux);
		}
    
}

void imprimirEstruturaAux(int posicao, cell vetorPrincipal[])
{
	int i, j, tamanhoUnitario, valorUnitario, tamanhoPrint;

	tamanhoUnitario = vetorPrincipal[posicao].posicaoAtual;
	tamanhoPrint = vetorPrincipal[posicao].tam; 

	printf("O tamanho alocado dinamicamente para a posição %d da estrutura principal eh: %d\n", i+1, tamanhoPrint);

	for(j=0;j<tamanhoUnitario;j++)
		{
			valorUnitario = vetorPrincipal[posicao].vetorAux[j];
			if(valorUnitario!=0)
				{
						printf("O elemento %d contem o valor: %d\n", j, valorUnitario);
				}
		}
	
}

void swift(cell vetorPrincipal[], int indicePrincipal, int posAtual, int tamTotal, int valor){
	int i, aux, tamanho;
	
	tamanho = vetorPrincipal[indicePrincipal].posicaoAtual;	
	
	for(i = 0; i < tamanho; i++)
	{
		vetorPrincipal[indicePrincipal].vetorAux[posAtual] = vetorPrincipal[indicePrincipal].vetorAux[posAtual + i];
	}

	vetorPrincipal[indicePrincipal].posicaoAtual--;
}
