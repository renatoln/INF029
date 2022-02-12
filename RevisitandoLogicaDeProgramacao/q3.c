#include <stdio.h>

int main(){
  int a, b, c;
  printf("Digite a primeiro número: \n");
  scanf("%d", &a);
  printf("Digite a segundo número: \n");
  scanf("%d", &b);
  c = a;
  a = b;
  b = c;
  printf("O valor de a eh %d e de b eh %d: \n", a, b);
}