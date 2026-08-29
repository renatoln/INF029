#include <stdio.h>

typedef struct{
    int ano;
    float preco;
}Celular;

int main(){
    Celular listaCelulares[3];

    int sair = 0;
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
                qtdCelulares++;
                break;
            }
            case 2: {
                printf("Lista Celulares\n");
                
                for (int i = 0; i < qtdCelulares; i++)
                    printf("%d - %f\n", listaCelulares[i].ano, listaCelulares[i].preco);

                break;
            }
            case 3: {
                printf("Atualizar");
                break;
            }
            case 4: {
                printf("Deletar");
                break;
            }
            default: printf("Opção Inválida");
        }

    }

}