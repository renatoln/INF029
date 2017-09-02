#include <stdio.h> 
#include <stdlib.h>

int menu();



int menu(){
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar\n");
    printf("4 - \n");
    printf("5 - \n");
    scanf("%d", &op);
    return op;
}

int main(){
    
    int op;
    int sair = 0;
    
    while (!sair){
        op = menu();
        switch (op){
            case 0:{
                sair =1;
                break;
            }
            case 1:{ //inserir
                //TODO
                break;
            }

            case 2:{ //excluir
                //TODO
                break;
            }
            default:{
                printf("opcao inválida\n");
            }

            
        }
        
        
    }
    
    return 0;
    
}
