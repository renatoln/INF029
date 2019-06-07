#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM_PROFESSORES 2

typedef struct ficha_disciplina{
     int codigo;
     char nome[200];
     Professor prof;
     Aluno alunos[40];
} Disciplina;

Disciplina lista_disciplinas[10]

lista_disciplina[4].alunos[15].nome



typedef struct ficha_professor{
     int matricula;
     char nome[200];
     char sexo[15];
     char data_de_nascimento[100];
     char cpf[11];
} Professor;

void cadastra_professores(int i, Professor lista_professores[]);
void imprime_professores(Professor lista_professores[]);
void inicializar_lista(Professor lista_professores[]);

int main() {
    Professor lista_professores[TAM_PROFESSORES];
    inicializar_lista(lista_professores);
 	int i;

    printf("\t\ ---------------------- Cadastro do professor ----------------------\n\n ");

 	for (i = 0; i < TAM_PROFESSORES; i++){
        cadastra_professores(i, lista_professores);
    }

    imprime_professores(lista_professores);

	return 0;
}

void cadastra_professores(int i, Professor lista_professores[]){
    printf("Nome do professor......: ");
    fflush(stdin);
    gets(lista_professores[i].nome);

    printf("Digite numero de Matricula ......: ");
    fflush(stdin);
    scanf("%d", &lista_professores[i].matricula);

    printf("Digite sexo ......: ");
    fflush(stdin);
    gets(lista_professores[i].sexo);

    printf("Digite data de nascimento......: ");
    fflush(stdin);
    gets(lista_professores[i].data_de_nascimento);

    printf("Digite CPF ......: ");
    fflush(stdin);
    gets(lista_professores[i].cpf);
}

void imprime_professores(Professor lista_professores[]){
    int i;
    for (i = 0; i < TAM_PROFESSORES; i++){
        printf("\n\n");

        printf("---------------------- Cadastro do professor ----------------------\n\n ");
        printf("Professor: %s\n Matricula: %d\n Sexo: %s\n Data de Nascimento: %s\n CPF: %s\n\n",
                                         lista_professores[i].nome,
                                         lista_professores[i].matricula,
                                         lista_professores[i].sexo,
                                         lista_professores[i].data_de_nascimento,
                                         lista_professores[i].cpf);

        printf("\n\n");

    }

}

void inicializar_lista(Professor lista_professores[]){
    int i;
    for (i = 0; i < TAM_PROFESSORES; i++){
        lista_professores[i].matricula = -1;
    }

}

