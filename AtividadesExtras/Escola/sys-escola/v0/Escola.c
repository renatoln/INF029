/* 

Escola.c, 22/09/2021, Autor: Renato Novais

Descrição: esta versão tem:
- usar o define TAM
- funções

*/

#include <stdio.h>
#include <string.h>

#include "Aluno.h"
#include "Escola.h"

int opcaoMenuPrincipal();

int main(void)
{

  Aluno aluno;                        /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Aluno lista_aluno[TAM_LISTA_ALUNO]; // vetor para armazenar a lista de alunos
  int qtd_alunos = 0;                 // variável para controlar a quantidade de alunos cadastrados

  int opcao, retorno;
  int sair = 0;

  while (!sair)
  {

    opcao = opcaoMenuPrincipal();

    switch (opcao)
    {
    case 0:
    {
      printf("Finalizando Escola\n");
      sair = 1;
      break;
    }
    case 1:
    {
      retorno = inserirAluno(lista_aluno, qtd_alunos);
      if (retorno == SUCESSO_CADASTRO)
      {
        printf("Cadastro realizado com sucesso\n");
        qtd_alunos++;
      }
      else
      {
        switch (retorno)
        {
        case ERRO_CADASTRO_MATRICULA:
        {
          printf("Matrícula Inválida");
          break;
        }
        case ERRO_CADASTRO_SEXO:
        {
          printf("Sexo Inválido");
          break;
        }
        default:
        {
          printf("Erro desconhecido!");
        }
        }
        printf("Não foi possível fazer o cadastro\n");
      }
      break;
    }
    case 2:
    {
      listarAlunos(lista_aluno, qtd_alunos);
      break;
    }
    case 3:
    {
      int retorno = excluirAlunoDoFinal(qtd_alunos);
      if (retorno == ERRO_EXCLUSAO_ALUNO)
      {
        printf("Erro ao excluir aluno\n");
      }
      else
      {
        printf("Aluno excluido com sucesso\n");
        qtd_alunos--;
      }
      break;
    }
    default:
    {
      printf("Opção Inválida\n");
    }
    }
  }

  return 1;
}

int opcaoMenuPrincipal()
{
  int opcao;
  printf("Digite a opção:\n");
  printf("0 - Sair\n");
  printf("1 - Inserir Aluno\n");
  printf("2 - Listar Alunos\n");
  printf("3 - Excluir útlimo aluno cadastrado\n");

  scanf("%d", &opcao);
  return opcao;
}
