#include <stdio.h>

typedef struct {
    int soma;
    int sub;
    int mult;
    int div;
} Calc;

Calc calculadora(int x, int y);
void calculadora2(int x, int y, int lista[]);

int main(){	
	//usando struct
    Calc d = calculadora(2, 3);
    printf ("%d", d.soma);
    printf ("%d", d.sub);
    printf ("%d", d.mult);
    printf ("%d", d.div);

    //usando vetor
    int meuvetor[4];
    calculadora2(2, 3, meuvetor);
    printf ("%d", meuvetor[0]);
    printf ("%d", meuvetor[1]);
    printf ("%d", meuvetor[2]);
    printf ("%d", meuvetor[3]);

    //usando ponteiros

}

Calc calculadora(int x, int y){
    Calc dados;
	dados.soma = x + y;
    dados.sub = x - y;
    dados.mult = x * y;
    if (y != 0)
        dados.div = x / y; 
    
	return dados;
}

void calculadora2(int x, int y, int lista[]){
	lista[0] = x + y;
    lista[1] = x - y;
    lista[2] = x * y;
    if (y != 0)
        lista[3] = x / y;
}