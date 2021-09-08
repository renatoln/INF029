#include <stdio.h>

void mudaValorDeI(int i){
	i = 20;
}

void mudaValorDeV(int v[]){
	v[0] = 50;
	v[1] = 60;
}


int main(){
	int i = 10;
	printf("1: Valor de i: %d\n", i);
	mudaValorDeI(i);
	printf("2: Valor de i: %d\n", i);

	int v[2];
	v[0] = 5;
	v[1] = 6;
	printf("1: Valor de v[0]: %d\n", v[0]);
	printf("1: Valor de v[1]: %d\n", v[1]);
	mudaValorDeV(v);
	printf("2: Valor de v[0]: %d\n", v[0]);
	printf("2: Valor de v[1]: %d\n", v[1]);
}

