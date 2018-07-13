/* 

Escola-v02.c, 13/07/2018, Autor: Renato Novais

Descrição: esta versão tem:
- usar o define TAM
- funções

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_LISTA_ALUNO 5
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3


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

int opcaoMenuPrincipal();
int inserirAluno(Aluno lista_aluno[], int qtd_alunos);
void listarAlunos(Aluno lista_aluno[], int qtd_alunos);

int main(void)
{    
 
  Aluno aluno; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Aluno lista_aluno[TAM_LISTA_ALUNO]; // vetor para armazenar a lista de alunos
  int qtd_alunos = 0; // variável para controlar a quantidade de alunos cadastrados

  int opcao, retorno;
  int sair = 0;
  
  while (!sair){
    
    opcao = opcaoMenuPrincipal();
    
    switch(opcao){
      case 0:{
        printf("Finalizando Escola\n");
        sair = 1;
        break;
      }
      case 1: {
        retorno = inserirAluno(lista_aluno, qtd_alunos);
        if (retorno == SUCESSO_CADASTRO){
            printf("Cadastro realizado com sucesso\n");
            qtd_alunos++;
        }else{
            switch(retorno) {
                case ERRO_CADASTRO_MATRICULA:{
                    printf("Matrícula Inválida");
                    break;
                }
                case ERRO_CADASTRO_SEXO:{
                    printf("Sexo Inválido");
                    break;
                }
                default:{
                    printf("Erro desconhecido!");
                }
               
            }
           printf("Não foi possível fazer o cadastro\n"); 
            
        }    
        break;
      }
      case 2: {
        listarAlunos(lista_aluno, qtd_alunos);
        break;
      }
      default:{
        printf("Opção Inválida\n");
      }
    }
  }


  return 1;

}

int opcaoMenuPrincipal(){
    int opcao;
    printf("Digite a opção:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir Aluno\n");
    printf("2 - Listar Alunos\n");
    scanf("%d",&opcao);
    return opcao;
}

int inserirAluno(Aluno lista_aluno[], int qtd_alunos){
    
    printf("\n### Cadastro de Aluno ###\n");
    printf("Digite a matrícula: ");
    scanf("%d", &lista_aluno[qtd_alunos].matricula);
    getchar();
    
    if (lista_aluno[qtd_alunos].matricula <= 0) {
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
    if (lista_aluno[qtd_alunos].sexo != 'M' && lista_aluno[qtd_alunos].sexo != 'F') {
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

void listarAlunos(Aluno lista_aluno[], int qtd_alunos){
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
}
