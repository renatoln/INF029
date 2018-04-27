/* 

Escola-v01.c, 27/04/2018, Autor: Renato Novais

Descrição: esta versão tem:
- definição de struct para Aluno
- leitura dos dados de aluno
- impressão dos dados de alunos

*/

#include <stdio.h>
#include <string.h>

typedef struct dma {
  int dia;
  int mes;
  int ano; 
} Data; 

/*Criando a struct aluno */
typedef struct dados_aluno
{
  int matricula;
  char nome[50];
  char sexo; //M - Masculino, F - Feminino
  Data data_nascimento;
  char cpf[15];
    
} Aluno;

int main(void)
{    
 
  Aluno aluno; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Aluno lista_aluno[10]; // vetor para armazenar a lista de alunos
  int qtd_alunos = 0; // variável para controlar a quantidade de alunos cadastrados

  int opcao;
  int sair = 0;
  
  while (!sair){
    
    printf("Digite a opção:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir Aluno\n");
    printf("2 - Listar Alunos\n");
    scanf("%d",&opcao);
    
    switch(opcao){
      case 0:{
        printf("Finalizando Escola\n");
        sair = 1;
        break;
      }
      case 1: {
        printf("\n### Cadastro de Aluno ###\n");
        printf("Digite a matrícula: ");
        scanf("%d", &lista_aluno[qtd_alunos].matricula);
        getchar();
        
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

        qtd_alunos++;

        printf("\n");

        break;
      }
      case 2: {
        printf("\n### Alunos Cadastrasdos ####\n");
        int i;
        for (i = 0; i < qtd_alunos; i++){
          printf("-----\n");
          printf("Matrícula: %d\n", lista_aluno[i].matricula);
          printf("Nome: %s\n", lista_aluno[i].nome);
          printf("Sexo: %c\n", lista_aluno[i].sexo);
          printf("Data Nascimento: %d/%d/%d\n", lista_aluno[i].data_nascimento.dia, lista_aluno[i].data_nascimento.mes, lista_aluno[i].data_nascimento.ano);
          printf("CPF: %s\n", lista_aluno[i].cpf);

        }
        printf("-----\n\n");
        break;
      }
      default:{
        printf("Opção Inválida\n");
      }
    }
  }


  return 1;

}