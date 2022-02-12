#include <stdio.h>

int main(){
  int idade;
  
  do {
    printf("Digite a idade: \n");
    scanf("%d", &idade);
    if (idade >= 0){
      if (idade >= 18){
        printf("A pessoa é de maior.\n");
      }else{
        printf("A pessoa é de menor.\n");
      }
    }else{
      printf("Finalizando o programa....\n");
    }  
  }while (idade >= 0); 
}