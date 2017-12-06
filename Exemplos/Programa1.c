#include <stdio.h> 
#include <time.h>

void menu(){
    
    printf("Digite a opcao\n");
    printf("0. Sair\n");
    printf("1. Hora\n");
    printf("2. Data\n");
    printf("3. Soma\n");
    printf("4. Imprime resultados da opção 3\n");
    
}

void imprimeHora(){
    printf("HORA: %s\n",__TIME__);
}


void imprimeData(){
    printf("DATA : %s\n",__DATE__);
}




void somar(int z[3]){
    int num1, num2, res;
    
    printf("digite o primeiro numero\n");
    scanf("%i", &num1);
    
    printf("digite o segundo numero\n");
    scanf("%i", &num2);
    
    res = num1 + num2;
    printf("o resultado da soma eh %i\n",res);
    
    z[0] = num1;
    z[1] = num2;
    z[2] = res;
    
    
}

void apresentarResultadoSoma(int k[]){
    printf("Num1 = %d, Num2 = %d, Resultado = %d\n", k[0], k[1], k[2]);
    
}

int main(){
    int sair = 0;
    int opcao;
    int a[3];
    
    while(!sair){
    
        menu();
        scanf("%i", &opcao);
        
        switch(opcao){
            case 0:{
                printf("sair\n");  
                sair = 1;
                break;
            }
            case 1:{
                imprimeHora();    
                break;
            }
            case 2:{
                imprimeData();
                break;
            }
            case 3:{
                
                a[0] = 2; a[1] = 3; a[2] = 5;
                somar(a);
                break;
            }
            case 4:{
                apresentarResultadoSoma(a);
                break;
            }

            default:{
                printf("opcao inválida\n");    
            }
        }
        
    }
    
    
    
    
    //imprimir hora do sistema
    //imprimir data do sistema
    //somar dois numeros, dentro da funcao
    //imprimir os dois ultimos valores que foram digitados na funcao anterior
    
    
}
