
#include <stdio.h>

int q6(int numerobase, int numerobusca);
int main(){

    printf("%d\n", q6(1234, 4));
    printf("%d\n", q6(1434, 4));
    printf("%d\n", q6(1211, 1));
    printf("%d\n", q6(1211, 9));

}

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int restoNumerobase;
    while (numerobase > 0){
        
        restoNumerobase = numerobase % 10;
        if (restoNumerobase == numerobusca)
            qtdOcorrencias ++;

        numerobase = numerobase / 10;
    }

    return qtdOcorrencias;
}