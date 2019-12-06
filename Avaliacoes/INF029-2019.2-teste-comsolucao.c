#include <stdio.h>

typedef struct alu{
	int idAluno; // id da aluno
	char nome[100]; // nome do aluno
	char sexo; // sexo do aluno
	int deletado = 0;
} Aluno;

typedef struct disc{
	int idDisciplina; // id da disicplina
	int idProfessor; // id do professor responsável
	char nome[100]; // nome da disciplina
	int vagas = 40; // total de vagas da disciplina
	int qtdAlunos = 0; //guarda a quantidade de alunos matriculados
	int idAlunosMatriculados[vagas]; /* guarda o id dos alunos matriculados. */
} Disciplina;

int excluirAlunoDeDisciplina(int idDisc, int idAlu, Disciplina listaDisc[]);

int main(){

	Aluno listaAluno[100];
	Disciplina listaDisciplinas[100];

	/* suponha que todas os idAlunosMatriculados de todas as disciplinas são inicializados com menos -1 */

	/* chamar a seguir a funcao excluirAlunoDeDisciplina e a depender do retorno informar se foi excluido ou não */

    int ret = excluirAlunoDeDisciplina(20, 30, listaDisciplinas);
    if (ret == 1) printf ("Nao achou o aluno");
    if (ret == 2) printf ("Nao achou a disciplina");
    if (ret == 3) {
        printf ("aluno excluido com sucesso");
        
        
    }


}
// 1 - naou achou aluno
// 2 - nao achou disciplina
// 3 - excluiu o aluno

int excluirAlunoDeDisciplina(int idDisc, int idAlu, Disciplina listaDisc[]){
    int i;
    int achouDisciplina = 0;
    for (i = 0; i < 100; i ++){
        
        if (listaDisc[i].idDisciplina == idDisc){
            achouDisciplina = 1;    
            int j = 0;
            int achouAluno = 0;
            for (; j < listaDisc[i].qtdAlunos; j++){
                if (listaDisc[i].idAlunosMatriculados[j] == idAlu){
                    achouAluno = 1;
                    int qtd = listaDisc[i].qtdAlunos;
                    listaDisc[i].idAlunosMatriculados[j] = listaDisc[i].idAlunosMatriculados[qtd - 1];
                    listaDisc[i].idAlunosMatriculados[qtd - 1] = -1;
                    listaDisc[i].qtdAlunos--;
                    return 3;
                    
                } 
            }
            if (!achouAluno) return 1;
        }
   
    }
    
    if (!achouDisciplina) return 2;
    
}

// 1 - naou achou aluno
// 2 - nao achou disciplina
// 3 - excluiu o aluno

//shift = deslocamento dos elementos na frente do excluido

int excluirAlunoDeDisciplinaComShift(int idDisc, int idAlu, Disciplina listaDisc[]){
    int i;
    int achouDisciplina = 0;
    for (i = 0; i < 100; i ++){
        
        if (listaDisc[i].idDisciplina == idDisc){
            achouDisciplina = 1;    
            int j = 0;
            int achouAluno = 0;
            for (; j < listaDisc[i].qtdAlunos; j++){
                if (listaDisc[i].idAlunosMatriculados[j] == idAlu){
                    achouAluno = 1;
                    int qtd = listaDisc[i].qtdAlunos;
                    
                    int k = 0;
                    for (; k < qtd; k++)
                        listaDisc[i].idAlunosMatriculados[k - 1] = listaDisc[i].idAlunosMatriculados[k];
                    
                    listaDisc[i].idAlunosMatriculados[k] = - 1;
                    
                    listaDisc[i].qtdAlunos--;
                    
                    return 3;
                    
                } 
            }
            if (!achouAluno) return 1;
        }
   
    }
    
    if (!achouDisciplina) return 2;
    
}


