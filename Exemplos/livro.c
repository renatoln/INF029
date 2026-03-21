#include <stdio.h>

int main(){

	printf("Olá mundo\n");

    int listaAnos[3];
    int sair = 0;
    int qtdLivros = 0;
    int opcao;
    while (sair == 0){
        printf("Escolha a opcão: \n");
        printf("0 - Sair \n");
        printf("1 - Cadastrar Livro \n");
        printf("2 - Listar Livros \n");
        printf("3 - Atualizar Livro \n");
        printf("4 - Excluir Livro \n");
        scanf("%d", &opcao);

        switch (opcao){
            case 0:{
                sair = 1;
                break;
            }
            case 1:{
                //cadastrar livro
                if (qtdLivros == 3){
                    printf("Biblioteca cheia!\n");
                }else{
                    printf("Digite um ano: \n");
                    int ano; 
                    scanf("%d", &ano);
                    listaAnos[qtdLivros] = ano;
                    qtdLivros ++;
                }
                break;
            }
            case 2:{
                //listar livro
                printf("### Listando os livros ###\n");
                for (int i = 0; i < qtdLivros; i++){
                    printf("%d\n", listaAnos[i]);
                }
                break;
            }
            case 3:{
                //atualizar livro
                break;
            }
            case 4:{
                //excluir livro
                if (qtdLivros == 0){
                    printf("Biblioteca vazia!\n");
                }else{
                    printf("Livro excluido com sucesso!\n");
                    qtdLivros--;
                }
                break;
            }



        }




    }
    



}