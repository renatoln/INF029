#include <stdio.h>
#define TAM 3

//CRUD = Create, Read, Update, Delete

void menu_principal();
void listar_carros(int qtdCarros, int anos[TAM], int chassis[TAM]);
int inserir_carros(int qtdCarros, int anos[TAM], int chassis[TAM]);
int excluir_carros(int qtdCarros);
void atualizar_carros(int qtdCarros, int anos[TAM], int chassis[TAM]);

int main(){
    
    int anos[TAM];
    int chassis[TAM];
    int ativos[TAM];

    int qtdCarros = 0;
    int sair = 0;
    
    while(sair == 0){
        menu_principal();
        int opcao = -1;
        scanf("%d", &opcao);
        switch (opcao){
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                int retorno = inserir_carros(qtdCarros, anos, chassis);
                if (retorno == 1)
                    printf("Quantidade de carros excedida!\n");
                else if (retorno == 2){
                    printf("Cadastro realizado com sucesso!\n");
                    qtdCarros++;
                }

                break;
            }
            case 2: {
                listar_carros(qtdCarros, anos, chassis);
                
                break;
            }
            case 3: {
                atualizar_carros(qtdCarros, anos, chassis);

                break;
            }
            case 4: {
                int retorno = excluir_carros(qtdCarros);
                if (retorno == 1){
                    printf("Carro excluido com sucesso\n");
                    qtdCarros--;
                }
                else
                    printf("Sem carros cadastrados\n");
                break;
            }
            default: printf("Opcao inválida....\n");
        }
    }
}

void menu_principal(){
    printf("Digite a opcao:\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
}

void listar_carros(int qtdCarros, int anos[TAM], int chassis[TAM]){

    printf("Listando....\n");
    for (int i = 0; i < qtdCarros; i++){
        printf("Carro... Ano: %d ... Chassi: %d\n", anos[i], chassis[i]);
    }
}

int inserir_carros(int qtdCarros, int anos[TAM], int chassis[TAM]){

    if (qtdCarros == TAM ){
        return 1; //tamanho excedido
    }else{
        printf("Cadastrando....\n");
        printf("Digite o ano: ");
        scanf("%d", &anos[qtdCarros]);

        printf("Digite o chassi: ");
        scanf("%d", &chassis[qtdCarros]);
        return 2; //cadastro correto
    }

    
}

int excluir_carros(int qtdCarros){
    printf("Excluindo....\n");
    if (qtdCarros > 0)
        return 1;
    else
        return 0;
}

void atualizar_carros(int qtdCarros, int anos[TAM], int chassis[TAM]){
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
}