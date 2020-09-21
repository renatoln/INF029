//copia o conteudo do arquivo tmp.txt em tmpCopy.txt
// copiando linha a linha
#include<stdio.h>

#define MAX 80

int main(){          
    int ch;
    char linha[MAX];
    FILE *input, *output;
    input = fopen("tmp.txt", "r");
    if (input){
        output = fopen("tmpCopy.txt", "w");
        fgets(linha, MAX, input);
        
        while(!feof(input)) {
            fputs(linha, output);
            fgets(linha, MAX, input);
        }
        //para escrever a última linha (do EOF)
        fputs(linha, output); 
        fclose(input);
        fclose(output);
    }
    else 
        printf ("Erro na abertura do arquivo tmp.txt\n");
}


