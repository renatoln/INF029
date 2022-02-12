#include <stdio.h>

int main(){
  int numero;
  printf("Digite um número: \n");
  scanf("%d", &numero);

  int ehPrimo = 1;
  for (int i = 2; i < numero; i++)
    if (numero % i == 0){
      ehPrimo = 0;
      break;
    }
  

  if (ehPrimo == 1)
    printf("O número %d é primo", numero);
  else  
    printf("O número %d não é primo", numero);
 
}