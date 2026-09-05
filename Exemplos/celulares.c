#include <stdio.h>
#define TAM_CELULARES 3

typedef struct{
    int id;
    int ano;
    float preco;
}Celular;

int main(){
    Celular listaCelulares[TAM_CELULARES];

    int sair = 0;
    int idAtual = 1;
    int qtdCelulares = 0;
    while(!sair){ //sair == 0
        printf("Digite a opção: \n");
        printf("0 - Sair \n");
        printf("1 - Inserir \n");
        printf("2 - Listar \n");
        printf("3 - Atualizar \n");
        printf("4 - Deletar \n");

        int opcao;

        scanf("%d", &opcao);

        switch (opcao){
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                printf("Digite o ano: ");
                scanf("%d", &listaCelulares[qtdCelulares].ano);
                printf("Digite o Preço: ");
                scanf("%f", &listaCelulares[qtdCelulares].preco);
                listaCelulares[qtdCelulares].id = idAtual;
                idAtual++;
                qtdCelulares++;
                break;
            }
            case 2: {
                printf("Lista Celulares\n");
                
                for (int i = 0; i < qtdCelulares; i++)
                    printf("%d - %d - %f\n", listaCelulares[i].id, listaCelulares[i].ano, listaCelulares[i].preco);

                break;
            }
            case 3: {
                printf("Atualizar");
                printf("Lista Celulares\n");
                for (int i = 0; i < qtdCelulares; i++)
                    printf("%d - %d - %f\n", listaCelulares[i].id, listaCelulares[i].ano, listaCelulares[i].preco);
                printf("Digite o id do celular: \n");
                int id;
                scanf("%d", &id);
                int achou = 0;
                for (int i = 0; i < qtdCelulares; i++){
                    if (id == listaCelulares[i].id){
                        printf("Digite o ano: ");
                        scanf("%d", &listaCelulares[i].ano);
                        printf("Digite o Preço: ");
                        scanf("%f", &listaCelulares[i].preco);
                        achou = 1;
                        break;
                    }
                }
                if (!achou) printf("Celular não encontrado!\n");
                else printf("Celular atualizado com sucesso \n");

                break;
            }
            case 4: {
                printf("Deletar");
                qtdCelulares--;
                break;
            }
            default: printf("Opção Inválida");
        }

    }

}