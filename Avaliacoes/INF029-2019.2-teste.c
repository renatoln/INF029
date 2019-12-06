#include <stdio.h>

typedef struct alu{
	int idAluno; // id da aluno
	char nome[100]; // nome do aluno
	char sexo; // sexo do aluno
} Aluno;

typedef struct disc{
	int idDisciplina; // id da disicplina
	int idProfessor; // id do professor responsável
	char nome[100]; // nome da disciplina
	int vagas = 40; // total de vagas da disciplina
	int qtdAlunos = 0; //guarda a quantidade de alunos matriculados
	int idAlunosMatriculados[vagas]; /* guarda o id dos alunos matriculados. */
} Disciplina;


int main(){

	Aluno listaAluno[100];
	Disciplina listaDisciplinas[100];

	/* suponha que todas os idAlunosMatriculados de todas as disciplinas são inicializados com menos -1 */

	/* chamar a seguir a funcao excluirAlunoDeDisciplina e a depender do retorno informar se foi excluido ou não */





}




