#include <stdio.h>
#include <string.h>

int q4(char *strTexto, char *strBusca, int posicoes[30]);


int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int m = 0;
    for (int i = 0; i < strlen(strTexto); i++){
        if (strTexto[i] == strBusca[0]){
            int qtd = 1;
            for (int j = 1; j < strlen(strBusca); j++){
                if (strTexto[i+j] != strBusca[j]){
                    break;
                }
                qtd++;
            }
            if (qtd == strlen(strBusca)){
                //achou
                posicoes[m] = i + 1;
                m++;
                posicoes[m] = i + qtd; 
                m++;
            }

        }

    }

}
void printPosicoes(int posicoes[30]){
    for (int i = 0; i < 30; i ++){
        printf("%d\n", posicoes[i]);

    }

}

int main(){
  char strTexto[250];
  char strBusca[50];
  int posicoes[30];
  int i;
  for (i = 0; i < 30; i++)
  {
      posicoes[i] = -1;
  }
  strcpy(strTexto, "PROGRAMADOR PROGRO PROGRAMAGRAMÁ");
  strcpy(strBusca, "GRA");
  q4(strTexto, strBusca, posicoes);
  printPosicoes(posicoes);
  /*printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
  printf("%d\n", posicoes[0] == 5);
  printf("%d\n", posicoes[1] == 8);
  printf("%d\n", posicoes[2] == 34);
  printf("%d\n", posicoes[3] == 37);*/

  
  
}
