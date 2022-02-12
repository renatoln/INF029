#include <stdio.h>

int main(){
  int a, b, c;
  printf("Digite a primeira idade: \n");
  scanf("%d", &a);
  printf("Digite a segunda idade: \n");
  scanf("%d", &b);
  c = a + b;
  printf("O valor da soma de %d e %d eh %d: \n", a, b, c);
}