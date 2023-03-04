#include <stdio.h>
#define TAM_ALUNO 3

int main(void) {

  int listaAluno[TAM_ALUNO];
  int opcao;
  int qtdAluno = 0;
  int sair = 0; //falso

  while (!sair){
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
  
    scanf("%d", &opcao);

    switch (opcao){
      case 0:{
        sair = 1;
        break;
      }
      case 1:{
        printf("Módulo Aluno\n");
        int sairAluno = 0;
        int opcaoAluno;
        while (!sair){
          printf("0 - Voltar\n");
          printf("1 - Casdatrar Aluno\n");
          printf("2 - Listar Aluno\n");
          printf("3 - Atualizar Aluno\n");
          printf("4 - Excluir Aluno\n");
          scanf("%d", &opcaoAluno);

          switch (opcaoAluno){
            case 0:{
              sairAluno = 1;
              break;
            }
            case 1:{
              printf("Casdatrar Aluno\n");
              printf("Digite a matricula\n");
              int matricula;
              scanf("%d", &matricula);
              if (matricula < 0){
                printf("Matrícula Inválida\n");
              }else{
                if (qtdAluno == TAM_ALUNO){
                  printf("Lista de alunos Cheia\n"); 
                }else{
                  listaAluno[qtdAluno] = matricula;
                  qtdAluno++;
                }
              }
              break;
            }
            case 2:{
              printf("Listar Aluno\n");
              break;
            }
            case 3:{
              printf("Atualizar Aluno\n");
              break;
            }
            case 4:{
              printf("Escluir Aluno\n");
              break;
            }
            default:{
              printf("Opção Inválida\n");  
            }
            
          
        }
        
        
        break;
      }
      case 2:{
        printf("Módulo Professor\n");
        break;
      }
      case 3:{
        printf("Módulo Disciplina\n");
        break;
      }
      default:{
        printf("Opção Inválida\n");  
      }
    }
  }
  
  return 0;
}