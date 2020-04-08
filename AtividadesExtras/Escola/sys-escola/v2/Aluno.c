#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Aluno.h"

int inserirAluno(Aluno** inicio);
int excluirAluno(Aluno** inicio);
void listarAlunos(Aluno** inicio);
int menuAluno();

int menuAluno(){

	int opcao;

	printf("#### Módulo de Aluno ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Aluno\n");
	printf("2 - Excluir Aluno\n");
	printf("3 - Listar Alunos\n");
	scanf("%d",&opcao);

	return opcao;

}


void mainAluno(Aluno** inicioListaAluno){
	int opcao, retorno;
	int sair = 0;

	while (!sair){
    
	    opcao = menuAluno();
	    
	    switch(opcao){
	      case 0:{
	        sair = 1;
	        break;
	      }
	      case 1: {
	      	retorno = inserirAluno(inicioListaAluno);

	      	//v2 - adicao do controle de retorno da funcao
	      	if (retorno == SUCESSO_CADASTRO){ 
	      		printf("Aluno cadastrado com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case ERRO_CADASTRO_MATRICULA:{
	      				printf("Matrícula Inválida. Deve ser maior que 0.\n");
	      				break;
	      			}
	      			case ERRO_CADASTRO_SEXO:{
	      				printf("Sexo Inválido. Digite 'm' ou 'M' para Masculino ou 'f' ou 'F' para Feminino.\n");
	      				break;
	      			}
	      			case ERRO_DATA_INVALIDA:{
	      				printf("Data Inválida.\n");
	      				break;
	      			}default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 2: {
	      	retorno = excluirAluno(inicioListaAluno);
	      	//v2 - adicao do controle de retorno da funcao
	      	if (retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Aluno excluido com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrado o aluno com a matrícula digitada.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 3: {
	      	listarAlunos(inicioListaAluno);
	      	break;	
	      }default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}


}

void inserirAlunoNaLista(Aluno** inicio, Aluno* novoAluno){
    Aluno *atual;
    
    if (*inicio == NULL)
        *inicio = novoAluno;
    else{
        atual = *inicio;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novoAluno;
    }
    
    novoAluno->prox = NULL;
}

int inserirAluno(Aluno** inicio){
    int retorno = SUCESSO_CADASTRO;

    //criar o aluno
    Aluno* novoAluno = (Aluno *)malloc(sizeof(Aluno));
    
    printf("\n### Cadastro de Aluno ###\n");
    printf("Digite a matrícula: ");    
    scanf("%d", &novoAluno->matricula);
    getchar();
    
    if (novoAluno->matricula <= 0) {
        retorno = ERRO_CADASTRO_MATRICULA;
    }else{
    	printf("Digite o nome: ");
	    fgets(novoAluno->nome, 50, stdin); 
	    /*o fgets é uma das funções mais indicadas para ler string do teclado. 
	    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
	    Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir*/
	    size_t ln = strlen(novoAluno->nome) - 1; //size_t = unsigned integer type
	    if (novoAluno->nome[ln] == '\n')
	        novoAluno->nome[ln] = '\0';
	    
	    printf("Digite o sexo: ");
	    scanf("%c", &novoAluno->sexo);
	    
	    novoAluno->sexo = toupper(novoAluno->sexo);
	    if (novoAluno->sexo != 'M' && novoAluno->sexo != 'F') {
	        retorno = ERRO_CADASTRO_SEXO;
	    }else{
		    char data[11];
		    printf("Digite a data de nascimento: ");
		    scanf("%s", novoAluno->data_nascimento.dataCompleta);
		    getchar();

		    int dataValida = validar_data(novoAluno->data_nascimento.dataCompleta);
		    if (dataValida == 0){
		        retorno = ERRO_DATA_INVALIDA;
		    }else{
			    
			    printf("Digite o CPF: ");
			    fgets(novoAluno->cpf, 15, stdin); 
			    ln = strlen(novoAluno->cpf) - 1; 
			    if (novoAluno->cpf[ln] == '\n')
			        novoAluno->cpf[ln] = '\0';
		    }

	    }

    }    

    if (retorno == SUCESSO_CADASTRO){
    	inserirAlunoNaLista(inicio, novoAluno);
    	return SUCESSO_CADASTRO;
    }else{
    	//v2 - free no objeto criado
    	free(novoAluno);
    	return retorno;

    }
    
}

//v2
int excluirAlunoNaLista(Aluno** inicio, int matricula){
	if (*inicio == NULL)
		return LISTA_VAZIA; // lista vazia

	Aluno* anterior = *inicio;
	Aluno* atual = *inicio;
	Aluno* proximo = atual->prox;
	int achou = 0;

	while(atual != NULL){
		if (atual->matricula == matricula){
			achou = 1;
			break;
		}
		anterior = atual;
		atual = proximo;
		if (atual != NULL)
			proximo = atual->prox;
	}

	if (achou){
		if (atual == *inicio)
			*inicio = proximo;
		else
			anterior->prox = atual->prox;
		free(atual);
		return SUCESSO_EXCLUSAO;
	}else
		return NAO_ENCONTRADO;

}
//v2
int excluirAluno(Aluno** inicio){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return excluirAlunoNaLista(inicio, matricula);
	
}


void listarAlunos(Aluno** inicio){
    int i;
    Aluno* alunoAtual = *inicio;
    if (*inicio == NULL){
        printf("Lista Vazia\n");
        
    }else{
    	printf("\n### Alunos Cadastrados ####\n");
        do{
            printf("-----\n");
            printf("Matrícula: %d\n", alunoAtual->matricula);
            printf("Nome: %s\n", alunoAtual->nome);
            printf("Sexo: %c\n", alunoAtual->sexo);
            printf("Data Nascimento: %s\n", alunoAtual->data_nascimento.dataCompleta);
            //printf("Data Nascimento: %d/%d/%d\n", alunoAtual->data_nascimento.dia, alunoAtual->data_nascimento.mes, alunoAtual->data_nascimento.ano);
            printf("CPF: %s\n", alunoAtual->cpf);
            
            alunoAtual = alunoAtual->prox;

        }while (alunoAtual != NULL);
    }    
    printf("-----\n\n");
}

//v2 - Liberação da lista de aluno
void liberarListaAluno(Aluno* inicio){

	Aluno* atual = inicio;
	Aluno* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}


