#include <stdio.h>
#define TAM 3

typedef struct 
{
    int matricula;
    int idade;   
    char sexo;  
    

} Animal;

int menu(){
    int opcao;
    printf("Opções\n");
    printf("1 - Cadastrar\n");
    printf("2 - Imprimir todos\n");
    printf("3 - Imprimir maiores que a média\n");
    printf("4 - Excluir do final\n");
    printf("5 - Excluir por matricula\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    return opcao;
}

int main(){ 
    Animal listaAnimais[TAM];
   
    int incrementadorMatricula = 0;
    int sair = 0;
    int opcao = 0;
    int qtd = 0;
    
    while (!sair){    //sair == 0    OU    sair != 1
        opcao = menu();
        

        switch (opcao){
            case 1:{
                // fazendo a leitura dos dados
                if (qtd < TAM){
                    printf("Digite a idade: ");
                    scanf("%d", &listaAnimais[qtd].idade);
                    getchar();
                    printf("Digite a sexo: ");
                    scanf("%c", &listaAnimais[qtd].sexo);
                    listaAnimais[qtd].matricula = ++incrementadorMatricula;
                    qtd ++;
                    
                }else{
                    printf("PET cheio\n");
                }
            
                break;
            }
            case 2:{
                 //imprimindo todos
                printf("#### Todos animais\n");
                for (int i = 0; i < qtd; i++){
                    printf("Matricula: %d - Idade: %d - Sexo: %c\n", listaAnimais[i].matricula, listaAnimais[i].idade, listaAnimais[i].sexo);
                }
                break;
            }
            case 3:{
                // calcular a média
                int soma = 0;
                for (int i = 0; i < qtd; i++){
                    soma += listaAnimais[i].idade;
                }
                int media = soma / qtd;

                //imprimindo maiores que a média
                printf("#### Animais com idade acima da média\n");
                for (int i = 0; i < qtd; i++){
                    if (listaAnimais[i].idade > media)
                        printf("Idade: %d - Sexo: %c\n", listaAnimais[i].idade, listaAnimais[i].sexo);
                }
                break;
            }
            case 4:{
                if (qtd > 0){
                    qtd--;
                    printf("Exclusão Realizada com sucesso\n");
                }else{
                    printf("Não há animais cadastrados\n");
                }    
                break;
            }
            case 5:{
                //listar os animais
                printf("#### Todos animais\n");
                for (int i = 0; i < qtd; i++){
                    printf("Matricula: %d - Idade: %d - Sexo: %c\n", listaAnimais[i].matricula, listaAnimais[i].idade, listaAnimais[i].sexo);
                }
                //peguntar qual a matricula
                printf("Digite a matrícula do animal\n");
                int mat;
                scanf("%d", &mat);
                //achar o elemento
                int achou = 0;
                for (int i = 0; i < qtd; i++){
                    if (listaAnimais[i].matricula == mat){
                        achou = 1;
                        //fazer o shift
                        for (int j = i; j < qtd; j++){
                            listaAnimais[j] = listaAnimais[j + 1];
                        }
                        qtd--;
                        break;
                    }
                }
                if (achou){
                    printf("Animal excluido com sucesso\n");
                }else{
                    printf("Não existe animal com essa matricula\n");
                }
                
                break;
            }
            case 0:{
                sair = 1;
                break;
            }
            default: 
                printf("Opção inválida\n");
        }

    }
    
    

   
    
   
}