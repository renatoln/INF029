#include <stdio.h>
#include <string.h>

int main(){
  FILE *p;
  char c, str[30], frase[80] = "Este e um arquivo chamado: "; 
  char alunos [5][50], mostratexto [50];
  int i,j=0, cont=0;

  // Le um nome para o arquivo a ser aberto: 
	printf("\n\n Entre com um nome para o arquivo:\n");
	gets(str);
  // le os nomes dos alunos e coloca no vetor alunos
  for (cont = 0; cont < 5; cont++)
  {
    printf ("\nInforme o nome do aluno %d: ", cont+1);
    gets(alunos[cont]);
  }
  // abre o arquivo para gravacao    
  if (!(p = fopen(str,"w"))) 
  {                          
    /* Caso ocorra algum erro na abertura
    do arquivo da' mensagem e nao faz nada*/ 
    printf("Erro! Impossivel abrir o arquivo!\n");
  }
  else {
  // Se nao houve erro, grava o arquivo e o fecha ...
    for (i=0; i<5; i++){
      strcat(alunos[i], "\n"); //concatena o \n no final da linha
      fputs(alunos[i],p);      // grava no arquivo p
    }     
    fclose(p);  // fecha o arquivo ao final da gravacao
    printf("\nTerminei de escrever, agora vou ler.\n");
    // Abre novamente, agora  para  leitura  
    p = fopen(str,"r");
    //uma forma de mostrar
    fgets(mostratexto, 50, p);
    while (!feof(p)) // Enquanto não chegar no final do arquivo p
    {
      printf("%s",mostratexto);
      fgets(mostratexto, 50, p);
    }
    fclose(p);   // Fecha o arquivo p
  }
}     




