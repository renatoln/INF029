// Este programa cria uma função que calcula o maior entre dois números
#include <stdio.h>

int maiorNumero(int a, int b);

int main(){
    int x = 45;
    int y = 12;
    int maior = maiorNumero(x, y);

    printf("O maior número entre %d e %d é %d\n", x, y, maior);

}


int maiorNumero(int a, int b){
    if (a > b)
        return a;
    else 
        return b;


}
