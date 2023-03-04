#include <stdio.h>
#define TAM_ALUNO 3

typedef struct alu{
  int matricula;
  char sexo;
  int ativo;
} Aluno;

int main(void) {

  Aluno listaAluno[TAM_ALUNO];
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
              if (qtdAluno == TAM_ALUNO){
                printf("Lista de alunos cheia\n"); 
              }else{
                printf("Digite a matricula\n");
                int matricula;
                scanf("%d", &matricula);
                if (matricula < 0){
                  printf("Matrícula Inválida\n");
                }
                listaAluno[qtdAluno].matricula = matricula;
                listaAluno[qtdAluno].ativo = 1;
                qtdAluno++;
                printf("Cadastrado com sucesso\n");
              }
              
              break;
            }
            case 2:{
              printf("Listar Aluno\n");
              if (qtdAluno == 0){
                printf("Lista aluno vazia\n");
              } else{
                for (int i = 0; i < qtdAluno ; i++)
                {
                  if (listaAluno[i].ativo == 1)
                    printf("Matrícula: %d\n", listaAluno[i].matricula);  
                }  
              }
              break;
            }
            case 3:{
              printf("Atualizar Aluno\n");
              break;
            }
            case 4:{
              printf("Escluir Aluno\n");
              printf("Digite a matricula\n");
              int matricula;
              scanf("%d", &matricula);
              int achou = 0;
              if (matricula < 0){
                printf("Matrícula Inválida\n");
              }else{
                for (int i = 0; i < qtdAluno; i++)
                {
                  if (matricula == listaAluno[i].matricula){
                    //exclusão lógica
                    listaAluno[i].ativo = -1;
                    qtdAluno --;
                    for (int j = i; j < qtdAluno - 1; j++){ //shift
                      listaAluno[j].matricula = listaAluno[j+1].matricula;
                      listaAluno[j].sexo = listaAluno[j+1].sexo;
                      listaAluno[j].ativo = listaAluno[j+1].ativo;
                    }
                    achou = 1;
                    break;
                  }  
                }
                if (achou)
                  printf("Aluno excluído com sucesso\n");
                else
                  printf("Matrícula inexistente\n");
                
              }
              break;
            }
            default:{
              printf("Opção Inválida\n");  
            }         
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