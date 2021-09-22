#include "Utils.h"
/*Criando a struct aluno */
typedef struct dados_aluno
{
    int matricula;
    char nome[50];
    char sexo; //M - Masculino, F - Feminino
    Data data_nascimento;
    char cpf[15];
    struct dados_aluno *prox;

} Aluno;

int inserirAluno(Aluno lista_aluno[], int qtd_alunos);
void listarAlunos(Aluno lista_aluno[], int qtd_alunos);

int excluirAlunoDoFinal(int qtd_alunos);
