#include <stdio.h>
#define TAM 3

int main(){ 
    int idade[TAM];
    char sexo[TAM];
    int sair = 0;
    int opcao;
    
    while (!sair){    //sair == 0    OU    sair != 1
        printf("Opções\n");
        printf("1 - Cadastrar\n");
        printf("2 - Imprimir todos\n");
        printf("3 - Imprimir maiores que a média\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
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
    
    // fazendo a leitura dos dados
    for (int i = 0; i < TAM; i++){
        printf("Digite a idade: ");
        scanf("%d", &idade[i]);
        getchar();
        printf("Digite a sexo: ");
        scanf("%c", &sexo[i]);
    }

    //imprimindo todos
    printf("#### Todos animais\n");
    for (int i = 0; i < TAM; i++){
        printf("Idade: %d - Sexo: %c\n", idade[i], sexo[i]);
    }
    
    // calcular a média
    int soma = 0;
    for (int i = 0; i < TAM; i++){
        soma += idade[i];
    }
    int media = soma / TAM;

    //imprimindo maiores que a média
    printf("#### Animais com idade acima da média\n");
    for (int i = 0; i < TAM; i++){
        if (idade[i] > media)
            printf("Idade: %d - Sexo: %c\n", idade[i], sexo[i]);
    }
}