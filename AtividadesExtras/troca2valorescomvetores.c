#include <stdio.h>
//vetores
//struct
//ponteiros

void troca(int valores[]);

int main(){
    
    int a = 2;
    int b = 3;
    
    int numeros[2];
    numeros[0] = 24;
    numeros[1] = 3;
    
    
    troca(numeros);
    
    printf("%d %d", numeros[0], numeros[1]);
    
    return 0;
}

void troca(int valores[]){ 
    int aux = valores[0];
    valores[0] = valores[1]; 
    valores[1] = aux;
}
