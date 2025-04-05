#include <stdio.h>
#define TAM 3

typedef struct 
{
    int idade;   
    char sexo;  

} Animal;

int main(){ 
    Animal listaAnimais[TAM];
   

    int sair = 0;
    int opcao;
    int qtd = 0;
    
    while (!sair){    //sair == 0    OU    sair != 1
        printf("Opções\n");
        printf("1 - Cadastrar\n");
        printf("2 - Imprimir todos\n");
        printf("3 - Imprimir maiores que a média\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                // fazendo a leitura dos dados
                if (qtd < TAM){
                    printf("Digite a idade: ");
                    scanf("%d", &listaAnimais[qtd].idade);
                    getchar();
                    printf("Digite a sexo: ");
                    scanf("%c", &listaAnimais[qtd].sexo);
                    qtd ++;
                }else{
                    printf("PET cheio");
                }
            
                break;
            }
            case 2:{
                 //imprimindo todos
                printf("#### Todos animais\n");
                for (int i = 0; i < qtd; i++){
                    printf("Idade: %d - Sexo: %c\n", listaAnimais[i].idade, listaAnimais[i].sexo);
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
            case 0:{
                sair = 1;
                break;
            }
            default: 
                printf("Opção inválida\n");
        }

    }
    
    

   
    
   
}