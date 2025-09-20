#include <stdio.h>
#define TAM 3

//CRUD = Create, Read, Update, Delete

int main(){
    
    int anos[TAM];
    int chassis[TAM];
    int qtdCarros = 0;
    int sair = 0;
    
    while(sair == 0){
        printf("digite a opcao:\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Atualizar\n");
        printf("4 - Excluir\n");
        int opcao = -1;
        scanf("%d", &opcao);
        switch (opcao){
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                
                if (qtdCarros == TAM ){
                    printf("Quantidade de carros excedida!\n");
                }else{
                    printf("Cadastrando....\n");
                    printf("Digite o ano: ");
                    scanf("%d", &anos[qtdCarros]);
    
                    printf("Digite o chassi: ");
                    scanf("%d", &chassis[qtdCarros]);
                }

                qtdCarros++;
                break;
            }
            case 2: {
                printf("Listando....\n");
                for (int i = 0; i < qtdCarros; i++){
                    printf("Carro... Ano: %d ... Chassi: %d\n", anos[i], chassis[i]);
                }
                
                break;
            }
            case 3: {
                printf("Atualizando....\n");
                for (int i = 0; i < qtdCarros; i++){
                    printf("Carro #%d: Ano: %d ... Chassi: %d\n", i+1, anos[i], chassis[i]);
                }
                printf("Digite o número do carro que vc quer atualizar: \n");
                int num;
                scanf("%d", &num);
                if (num >= 1 && num <= qtdCarros){
                    printf("Digite o ano: ");
                    scanf("%d", &anos[num - 1]);
    
                    printf("Digite o chassi: ");
                    scanf("%d", &chassis[num - 1]);
                }else {
                    printf("Número inválido\n");
                }

                break;
            }
            case 4: {
                printf("Excluindo....\n");
                if (qtdCarros > 0)
                    qtdCarros --;
                else
                    printf("Sem carros cadastrados\n");
                break;
            }
            default: printf("Opcao inválida....\n");
        }

    }

    //cadastrar
    /*

    */


}