#include <stdio.h>
#include "Aluno.h"

int main(){
	Aluno aluno; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
	Aluno* inicioLista = NULL; // inicio da lista de alunos

	int opcao;
	int sair = 0;

	while (!sair){
    
	    opcao = menuAluno();
	    
	    switch(opcao){
	      case 0:{
	        printf("Finalizando Escola\n");
	        sair = 1;
	        break;
	      }
	      case 1: {
	      	retorno = inserirAluno(&inicioLista);
	           
	      	break;
	      }
	      case 2: {
	      	printf("listar os alunos\n");
	      	break;
	      }default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}

}