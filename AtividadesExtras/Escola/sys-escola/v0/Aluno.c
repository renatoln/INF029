#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Aluno.h"

int opcaoMenuAluno();
int inserirAluno(Aluno lista_aluno[], int qtd_alunos);
void listarAlunos(Aluno lista_aluno[], int qtd_alunos);
int excluirAlunoDoFinal(int qtd_alunos);

int mainAluno(Aluno lista_aluno[], int qtd_alunos)
{

  Aluno aluno;

  int opcao, retorno;
  int sair = 0;

  while (!sair)
  {

    opcao = opcaoMenuAluno();

    switch (opcao)
    {
    case 0:
    {
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



int inserirAluno(Aluno lista_aluno[], int qtd_alunos)
{

    printf("\n### Cadastro de Aluno ###\n");
    printf("Digite a matrícula: ");
    scanf("%d", &lista_aluno[qtd_alunos].matricula);
    getchar();

    if (lista_aluno[qtd_alunos].matricula <= 0)
    {
        return ERRO_CADASTRO_MATRICULA;
    }

    printf("Digite o nome: ");
    fgets(lista_aluno[qtd_alunos].nome, 50, stdin);
    /*o fgets é uma das funções mais indicadas para ler string do teclado. 
    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
    Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir*/
    size_t ln = strlen(lista_aluno[qtd_alunos].nome) - 1; //size_t = unsigned integer type
    if (lista_aluno[qtd_alunos].nome[ln] == '\n')
        lista_aluno[qtd_alunos].nome[ln] = '\0';

    printf("Digite o sexo: ");
    scanf("%c", &lista_aluno[qtd_alunos].sexo);

    lista_aluno[qtd_alunos].sexo = toupper(lista_aluno[qtd_alunos].sexo);
    if (lista_aluno[qtd_alunos].sexo != 'M' && lista_aluno[qtd_alunos].sexo != 'F')
    {
        return ERRO_CADASTRO_SEXO;
    }

    /* obs. a data nascimento será recuperada separadamente o dia, mês e ano, 
        mas depois tem que mudar para informar uma string dd/mm/aaaa, e validar a data*/
    printf("Digite o dia de nascimento: ");
    scanf("%d", &lista_aluno[qtd_alunos].data_nascimento.dia);

    printf("Digite o mês de nascimento: ");
    scanf("%d", &lista_aluno[qtd_alunos].data_nascimento.mes);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &lista_aluno[qtd_alunos].data_nascimento.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(lista_aluno[qtd_alunos].cpf, 15, stdin);
    ln = strlen(lista_aluno[qtd_alunos].cpf) - 1;
    if (lista_aluno[qtd_alunos].cpf[ln] == '\n')
        lista_aluno[qtd_alunos].cpf[ln] = '\0';

    printf("\n");

    return SUCESSO_CADASTRO;
}
void listarAlunos(Aluno lista_aluno[], int qtd_alunos)
{
    printf("\n### Alunos Cadastrasdos ####\n");
    int i;
    for (i = 0; i < qtd_alunos; i++)
    {
        printf("-----\n");
        printf("Matrícula: %d\n", lista_aluno[i].matricula);
        printf("Nome: %s\n", lista_aluno[i].nome);
        printf("Sexo: %c\n", lista_aluno[i].sexo);
        printf("Data Nascimento: %d/%d/%d\n", lista_aluno[i].data_nascimento.dia, lista_aluno[i].data_nascimento.mes, lista_aluno[i].data_nascimento.ano);
        printf("CPF: %s\n", lista_aluno[i].cpf);
    }
    printf("-----\n\n");
}

int excluirAlunoDoFinal(int qtd_alunos){
    if (qtd_alunos < 1)
        return ERRO_EXCLUSAO_ALUNO;
    else   
        return SUCESSO_EXCLUSAO_ALUNO; 

}

int opcaoMenuAluno()
{
  int opcao;
  printf("Digite a opção:\n");
  printf("0 - Voltar\n");
  printf("1 - Inserir Aluno\n");
  printf("2 - Listar Alunos\n");
  printf("3 - Excluir útlimo aluno cadastrado\n");

  scanf("%d", &opcao);
  return opcao;
}

