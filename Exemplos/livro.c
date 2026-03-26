#include <stdio.h>

typedef struct{
    int id; //chave primária / identificador
    int ano;
    int edicao;
}Livro;

#define TAM_LISTA_LIVRO 3


int main(){
    int codigo = 1;
	printf("Olá mundo\n");

    Livro listaLivros[TAM_LISTA_LIVRO];
    
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
                if (qtdLivros == TAM_LISTA_LIVRO){
                    printf("Biblioteca cheia!\n");
                }else{
                    listaLivros[qtdLivros].id = codigo;
                    int ano; 
                    printf("Digite o ano: ");
                    scanf("%d", &ano);
                    listaLivros[qtdLivros].ano = ano;
                    printf("Digite a edicao: ");
                    scanf("%d", &listaLivros[qtdLivros].edicao);
                    codigo++;
                    qtdLivros ++;
                }
                break;
            }
            case 2:{
                //listar livro
                printf("### Listando os livros ###\n");
                for (int i = 0; i < qtdLivros; i++){
                    
                    printf("Id: %d - Ano: %d - Edição: %d\n", listaLivros[i].id, listaLivros[i].ano, listaLivros[i].edicao);
                }
                break;
            }
            case 3:{
                //atualizar livro
                printf("### Listando os livros ###\n");
                for (int i = 0; i < qtdLivros; i++){
                    
                    printf("Código: %d - Ano: %d - Edição: %d\n", listaLivros[i].id, listaLivros[i].ano, listaLivros[i].edicao);
                }
                printf("Digite o código do livro que você deseja atualizar: ");
                int id, novoAno, novaEdicao;
                scanf("%d", &id);

                
                int achou = 0;
                for (int i = 0; i < qtdLivros; i++){
                    if (listaLivros[i].id == id){
                        achou = 1;
                        printf("Digite o novo Ano: ");
                        scanf("%d", &novoAno);

                        printf("Digite a nova Edição: ");
                        scanf("%d", &novaEdicao);
                        listaLivros[i].ano = novoAno;
                        listaLivros[i].edicao = novaEdicao;
                        break;
                    }
                    
                }
                if (achou == 0){
                    printf("Livro não encontrado!\n");
                }


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