#include <stdio.h>
#include <string.h>


int q4(char *strTexto, char *strBusca, int posicoes[30]);
void printVetor(int texto_int[], int tamanho);

//retorna o tamanho do novo vetor
int transformaVetor(char strTexto[], int intTexto[100]){
  int k = 0;
  for (int j = 0; j < strlen(strTexto); j++)
  {
      if (strTexto[j] != -61)
      {
          intTexto[k] = strTexto[j];
          k++;
      }
  }
  return k;
}



int q4(char *strTexto, char *strBusca, int posicoes[30]){
  int intTexto[100];
  int intBusca[100];
  //remover os numeros que representam os caracteres especiais
  //textos originais
  printf("%s\n", strTexto);
  printf("%s\n", strBusca);

  printf("copia strtexto\n");

  int tam = transformaVetor(strTexto, intTexto);

  printVetor(intTexto, tam);

  tam = transformaVetor(strBusca, intBusca);

  printVetor(intBusca, tam); 

  //buscar intBusca em intTexto
  
  return 0;

  
}




int main2(){
  char strTexto[250];
  char strBusca[50];
  int posicoes[30];
  int i;
  for (i = 0; i < 30; i++)
  {
      posicoes[i] = -1;
  }
  strcpy(strTexto, "Labóratórió");
  strcpy(strBusca, "tór");
  q4(strTexto, strBusca, posicoes);
  /*printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
  printf("%d\n", posicoes[0] == 5);
  printf("%d\n", posicoes[1] == 8);
  printf("%d\n", posicoes[2] == 34);
  printf("%d\n", posicoes[3] == 37);*/

  
  
}


void printVetor(int texto_int[], int tamanho){

  for (int j = 0; j < tamanho; j++)
  {

      printf("%i\n", texto_int[j]);
  }

  
}

int main()
{
    char texto[100] = "Laboratório";//"áóôéRenatoêíÚûç";
    int texto_int[100];
    int texto_int2[100];
    int i, j;
    printf("Impressão 1\n");
    for (i = 0; texto[i] != '\0'; i += 2)
    {
        printf("%c : ", texto[i]);
        printf("%d, %d\n", texto[i], texto[i + 1]);

        texto_int[i] = texto[i];
        texto_int[i + 1] = texto[i + 1];
    }

    printf("Numeros \n");
    for (j = 0; j < i; j++)
    {
        printf("%i\n", texto_int[j]);
    }

    printf("copia \n");
    int k = 0;
    for (j = 0; j < i; j++)
    {
        if (texto_int[j] != -61)
        {
            texto_int2[k] = texto_int[j];
            k++;
        }
    }

    printf("Numeros copiados \n");

    for (j = 0; j < k; j++)
    {

        printf("%i\n", texto_int2[j]);
    }
}
