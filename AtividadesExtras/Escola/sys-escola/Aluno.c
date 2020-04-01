#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Aluno.h"



int menuAluno(){

	int opcao;

	printf("#### Módulo de Aluno ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Aluno\n");
	printf("2 - Listar Alunos\n");
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
	           
	      	break;
	      }
	      case 2: {
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
    //scanf("%d", &lista_aluno[qtd_alunos].matricula);
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

		    int retorno = validar_data(novoAluno->data_nascimento.dataCompleta);
		    if (retorno == 0){
		        retorno = ERRO_DATA_INVALIDA;
		    }else{
			    
			    printf("Digite o CPF: ");
			    fgets(novoAluno->cpf, 15, stdin); 
			    ln = strlen(novoAluno->cpf) - 1; 
			    if (novoAluno->cpf[ln] == '\n')
			        novoAluno->cpf[ln] = '\0';

			    printf("\n");
		    }

	    }

    }    

    if (retorno == SUCESSO_CADASTRO){
    	inserirAlunoNaLista(inicio, novoAluno);
    	return SUCESSO_CADASTRO;
    }else{
    	//ToDo - free no objeto criado
    	return retorno;

    }
    
}

void listarAlunos(Aluno** inicio){
    printf("\n### Alunos Cadastrasdos ####\n");
    int i;
    Aluno* alunoAtual = *inicio;
    if (*inicio == NULL){
        printf("Lista Vazia\n");
        
    }else{
    
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


