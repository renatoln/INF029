#include <stdio.h>

int soma(int x, int y);

int main(){
	int x, y, resultado;
	int res;
	scanf("%d", &x);
	scanf("%d", &y);	
	res = soma(x, y);
	printf("%d", res);
	return 0;
}

int soma(int x, int y){
	int resultado = x + y;
	return resultado;
}

