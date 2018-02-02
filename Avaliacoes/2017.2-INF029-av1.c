#include <stdio.h> 

#define TAM 10
int insereCaracteres(char vetor[TAM], int qtd);

int menu(){
   int op;
   printf("Digite a opcao:\n");
   printf("0 - Sair\n");
   printf("1 - Inserir\n");
   printf("2 - Trocar caracter\n");
   printf("3 - Remover\n");
   printf("4 - listar\n");
   printf("5 - Contar\n");
   scanf("%d", &op);
   return op;
    
}


int main(){
    int qtd = 0;
    char vetor[TAM], vetRetorno[2];
    int sair = 0;
    int op, retorno;
    while(!sair){
        op = menu();
        switch(op){
            case 0:{
               sair = 1;
               break;
            }
            case 1:{
               //inserir
                retorno = insereCaracteres(vetor, qtd);
                if (retorno == 1){
                   printf("caracter inserido com sucesso\n"); 
                   qtd++;
                }else{
                    printf("nao foi possivel inserir\n"); 
                }    
                break;
            }
            case 2:{
               //trocar
                vetRetorno[0] = '0';
                vetRetorno[1] = '\0';
                if (vetRetorno[0] == '1'){
                    printf("houve troca, caracter que saiu foi: %c\n", vetRetorno[1]);
                }else{
                    printf("nao houve troca\n");
                }
               break;
            }
            case 3:{
               //remover
                qtd = removeCaracter(qtd);
               break;
            }
            case 4:{
               //listar
               break;
            }
            case 5:{
               //contar
               break;
            }
            default:{
                printf ("opcao invalida");
                
            }
            

           
        } 
        
        
    }
    
    
    
}

//b - insere caracter
int insereCaracteres(char vetor[TAM], int qtd){
    char c;
    if (qtd < TAM){
        printf("Digite um caracter\n");
        scanf("%c", %c);
        vetor[qtd] = c;
        return 1;
    }else{
        return 0;    
    }   
    
}


//c - troca caracter
void trocarCaracter(char vetRetorno[2]; char vetor[TAM], int qtd){
    char c;
    int i = 0;
    printf("Digite um caracter\n");
    scanf("%c", %c);
    for (;i < qtd; i++){
        if (vetor[i] > c){
            vetRetorno[0] = '1';
            vetRetorno[1] = vetor[i];
            vetor[i] = c;
        }
    }
}
//d - remover caracter
int removeCaracter(int qtd){
   return --qtd; 
}
//e - listar caracteres

void listarCaracteres(char vetor[TAM], int qtd){
    int i = 0;
    for (;i < qtd; i++){
        printf("%c\n", vetor[i]);
    }
    
}

//f - imprimir qtd por valor
