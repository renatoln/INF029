/*

Escola-v02.c, 13/07/2018, Autor: Renato Novais

Descrição: esta versão tem:
- usar o define TAM
- funções
- suporte a arquivos (incompleto)

*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define TAM_LISTA_ALUNO 5
#define SUCESSO_CADASTRO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define TAM_LINE_FILE 100

typedef struct dma {
  int dia;
  int mes;
  int ano;
} Data;

/*Criando a struct aluno */
typedef struct dados_aluno {
  int matricula;
  char nome[50];
  char sexo; // M - Masculino, F - Feminino
  Data data_nascimento;
  char cpf[15];

} Aluno;

int opcaoMenuPrincipal();
int inserirAluno(Aluno lista_aluno[], int qtd_alunos);
void listarAlunos(Aluno lista_aluno[], int qtd_alunos);
void gravarAlunoNaLista(Aluno lista_aluno[], int qtd_alunos, Aluno aluno);

void stringAluno(Aluno a, char texto[]) { sprintf(texto, "%d", a.matricula); }

void carregarAlunoNaLista(char linha[], Aluno lista_aluno[], int qtd_aluno) {
  Aluno aluno;

  // char *dadosAluno;
  // dadosAluno = strtok(dadosAluno, ";");
  // printf("----------\n");
  // printf("%s",dadosAluno);

  // Declaration of delimiter
  const char s[4] = ";";
  char *tok;

  int cont = 1;
  tok = strtok(linha, s);

  while (tok != 0) {
    switch (cont) {
    case 1: {
      aluno.matricula = atoi(tok);
      break;
    }
    case 2: {
      strcpy(aluno.nome, tok);
      break;
    }
    case 3: {
      // aluno.sexo = tok;
      break;
    }
    case 4: {
      aluno.data_nascimento.dia = atoi(tok);
      break;
    }
    case 5: {
      aluno.data_nascimento.mes = atoi(tok);
      break;a
    }
    case 6: {
      aluno.data_nascimento.ano = atoi(tok);
      break;
    }
    case 7: {
      strcpy(aluno.cpf, tok);
      break;
    }
    }
    printf(" %s\n", tok);
    tok = strtok(0, s);
    cont++;
  }

  gravarAlunoNaLista(lista_aluno, qtd_aluno, aluno);
}

int recuperar(Aluno lista_aluno[]) {
  FILE *arq;
  char linha[TAM_LINE_FILE];
  int qtd_aluno = 0;
  arq = fopen("escola.txt", "r");

  fgets(linha, TAM_LINE_FILE, arq);

  while (!feof(arq)) {
    carregarAlunoNaLista(linha, lista_aluno, qtd_aluno);
    qtd_aluno++;
    fgets(linha, TAM_LINE_FILE, arq);
  }

  return qtd_aluno;
}

void salvar(Aluno lista_aluno[], int qtd_alunos) {
  FILE *arq;
  arq = fopen("escola.txt", "w+");
  int i;
  char texto[80];
  for (i = 0; i < qtd_alunos; i++) {
    stringAluno(lista_aluno[i], texto);
    fputs(texto, arq);
    fputs(";", arq);
    fputs(lista_aluno[i].nome, arq);
    fputs(";", arq);
    fputc(lista_aluno[i].sexo, arq);
    fputs(";", arq);
    fprintf(arq, "%d;%d;%d", lista_aluno[i].data_nascimento.dia,
            lista_aluno[i].data_nascimento.mes,
            lista_aluno[i].data_nascimento.ano);
    fputs(";", arq);
    fputs(lista_aluno[i].cpf, arq);
    if (i < qtd_alunos - 1)
      fputs("\n", arq);
  }
  fclose(arq);
}

int main(void) {

  Aluno aluno; /*Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Aluno lista_aluno[TAM_LISTA_ALUNO]; // vetor para armazenar a lista de alunos
  int qtd_alunos =
      0; // variável para controlar a quantidade de alunos cadastrados
  qtd_alunos = recuperar(lista_aluno);

  int opcao, retorno;
  int sair = 0;

  while (!sair) {

    opcao = opcaoMenuPrincipal();

    switch (opcao) {
    case 0: {
      salvar(lista_aluno, qtd_alunos);
      printf("Finalizando Escola\n");
      sair = 1;
      break;
    }
    case 1: {
      retorno = inserirAluno(lista_aluno, qtd_alunos);
      if (retorno == SUCESSO_CADASTRO) {
        printf("Cadastro realizado com sucesso\n");
        qtd_alunos++;
      } else {
        switch (retorno) {
        case ERRO_CADASTRO_MATRICULA: {
          printf("Matrícula Inválida");
          break;
        }
        case ERRO_CADASTRO_SEXO: {
          printf("Sexo Inválido");
          break;
        }
        default: {
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
    default: {
      printf("Opção Inválida\n");
    }
    }
  }

  return 1;
}

int opcaoMenuPrincipal() {
  int opcao;
  printf("Digite a opção:\n");
  printf("0 - Sair\n");
  printf("1 - Inserir Aluno\n");
  printf("2 - Listar Alunos\n");
  scanf("%d", &opcao);
  return opcao;
}

int inserirAluno(Aluno lista_aluno[], int qtd_alunos) {
  Aluno aluno_tmp;
  printf("\n### Cadastro de Aluno ###\n");
  printf("Digite a matrícula: ");
  scanf("%d", &aluno_tmp.matricula);
  getchar();

  if (aluno_tmp.matricula <= 0) {
    return ERRO_CADASTRO_MATRICULA;
  }

  printf("Digite o nome: ");
  fgets(aluno_tmp.nome, 50, stdin);
  /*o fgets é uma das funções mais indicadas para ler string do teclado.
  Ela controla o tamanho do buffer, e não deixa o buffer com lixo.
  Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo,
  como feito a seguir*/
  size_t ln = strlen(aluno_tmp.nome) - 1; // size_t = unsigned integer type
  if (aluno_tmp.nome[ln] == '\n')
    aluno_tmp.nome[ln] = '\0';

  printf("Digite o sexo: ");
  scanf("%c", &aluno_tmp.sexo);

  aluno_tmp.sexo = toupper(aluno_tmp.sexo);
  if (aluno_tmp.sexo != 'M' && aluno_tmp.sexo != 'F') {
    return ERRO_CADASTRO_SEXO;
  }

  /* obs. a data nascimento será recuperada separadamente o dia, mês e ano,
      mas depois tem que mudar para informar uma string dd/mm/aaaa, e validar a
     data*/
  printf("Digite o dia de nascimento: ");
  scanf("%d", &aluno_tmp.data_nascimento.dia);

  printf("Digite o mês de nascimento: ");
  scanf("%d", &aluno_tmp.data_nascimento.mes);

  printf("Digite o ano de nascimento: ");
  scanf("%d", &aluno_tmp.data_nascimento.ano);
  getchar();

  printf("Digite o CPF: ");
  fgets(aluno_tmp.cpf, 15, stdin);
  ln = strlen(aluno_tmp.cpf) - 1;
  if (aluno_tmp.cpf[ln] == '\n')
    aluno_tmp.cpf[ln] = '\0';

  printf("\n");

  gravarAlunoNaLista(lista_aluno, qtd_alunos, aluno_tmp);
  return SUCESSO_CADASTRO;
}

void gravarAlunoNaLista(Aluno lista_aluno[], int qtd_alunos, Aluno aluno) {
  lista_aluno[qtd_alunos] = aluno;
}

void listarAlunos(Aluno lista_aluno[], int qtd_alunos) {
  printf("\n### Alunos Cadastrasdos ####\n");
  int i;
  for (i = 0; i < qtd_alunos; i++) {
    printf("-----\n");
    printf("Matrícula: %d\n", lista_aluno[i].matricula);
    printf("Nome: %s\n", lista_aluno[i].nome);
    printf("Sexo: %c\n", lista_aluno[i].sexo);
    printf("Data Nascimento: %d/%d/%d\n", lista_aluno[i].data_nascimento.dia,
           lista_aluno[i].data_nascimento.mes,
           lista_aluno[i].data_nascimento.ano);
    printf("CPF: %s\n", lista_aluno[i].cpf);
  }
  printf("-----\n\n");
}
