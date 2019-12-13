#include <stdio.h>
#define TAM 100
typedef struct prof{
	int idProfessor; // id do professor
	char nome[100]; // nome do professor
	char sexo; // sexo do professor
} Professor;

typedef struct disc{
	int idDisciplina; // id da disicplina
	int idProfessor; // id do professor responsável
	char nome[100]; // nome da disciplina
	int vagas = 40; // total de vagas da disciplina
	int qtdAlunos = 0; //guarda a quantidade de alunos matriculados
	int idAlunosMatriculados[vagas]; /* guarda o id dos alunos matriculados. */
} Disciplina;

int main(){
	Professor listaProfessores[TAM];
	Disciplina listaDisciplinas[TAM];
    int numeroLimiteDeAlunos = 20; //número limite de alunos por disciplina

	/* - Chamar a seguir a funcao imprimirDisciplinasExtrapolandoNumeroDeAlunos.
       - Aqui na função main deve ser impresso a quantidade de disciplinas que extrapolaram o numeroLimiteDeAlunos*/
    
    
    
    
    
}





