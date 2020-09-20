#include <stdio.h>

int main(){
   	FILE *fp;

   	//abre o arquivo para leitura
   	fp = fopen("teste1.txt","r"); 
   
   	//testa se o arquivo foi aberto com sucesso
   	if (fp == 0)
      	printf("Erro na leitura do arquivo\n");
   	else
    	printf("Arquivo aberto com sucesso\n");   
   
	//fecha arquivo
   fclose(fp); 

}
