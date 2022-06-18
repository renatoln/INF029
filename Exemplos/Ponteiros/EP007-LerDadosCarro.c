#include <stdio.h>

void lerDados(char pMarca[], char *pModelo, int *ano){  
  //printf("Ano inicial: %d\n", ano);
  printf("Digite o ano: ");
  scanf("%d", ano);
  printf("Digite a marca: ");
  scanf("%s", pMarca);
  printf("Digite o modelo: ");
  scanf("%s", pModelo);
  
}

int main(){
  int ano = 50;
  char marca[10];
  char modelo[10];
  
  lerDados(marca, modelo, &ano);
  printf("O ano eh: %d\n", ano);
  printf("A Marca eh: %s\n", marca);

}