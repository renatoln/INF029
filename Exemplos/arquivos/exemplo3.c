//copia o conteudo do arquivo tmp.txt em tmpCopy.txt
// copiando caractere a caractere
#include<stdio.h>

#define MAX 80

int main(){          
    int ch;
    char linha[MAX];
    FILE *input, *output;
    input = fopen("tmp.txt", "r");
    if (input){
        output = fopen("tmpCopy.txt", "w");
        ch = fgetc(input);
        while(ch != EOF) {
          fputc(ch, output);
          ch = fgetc(input);
        }
        fclose(input);
        fclose(output);
    }
    else 
        printf ("Erro na abertura do arquivo tmp.txt\n");
}


