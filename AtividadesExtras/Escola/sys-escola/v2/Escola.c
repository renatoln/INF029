/**
Projeto Escola: Sistema de controle de uma escola.

Desenvolvimento em C

Realizado no contexto da disciplina INF029 - Laboratório de Programação
do curso de Análise e Desenvolvimento de Sistemas do Instituto Federal da Bahia, campus Salvador
http://ads.ifba.edu.br

Prof. Renato Novais

@2020

*/

#include <stdio.h>

#include "Escola.h"
#include "Aluno.h"

int menuGeral(){

	int opcao;

	printf("#### Digite a opção: ####\n");
	printf("0 - Sair\n");
	printf("1 - Gerenciar Aluno\n");
	printf("2 - Gerenciar Professor\n");
	printf("3 - Gerenciar Disciplina\n");

	scanf("%d",&opcao);

	return opcao;

}

//v2
void finalizarEscola(Aluno* inicio){
	liberarListaAluno(inicio);
}

int main(){
	Aluno aluno; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
	Aluno* inicioListaAluno = NULL; // inicio da lista de alunos

	int opcao, retorno;
	int sair = 0;

	while (!sair){
    
	    opcao = menuGeral();
	    
	    switch(opcao){
	      case 0:{
	        printf("Finalizando Escola\n");
	        finalizarEscola(inicioListaAluno); //v2
	        sair = 1;
	        break;
	      }
	      case 1: {
	      	mainAluno(&inicioListaAluno);
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