#include <stdio.h>

int main(){
  int idade;
  printf("Digite a idade: \n");
  scanf("%d", &idade);
  
  if (idade >= 18){
    printf("A pessoa é de maior.");
  }else{
    printf("A pessoa é de menor.");

  }
}