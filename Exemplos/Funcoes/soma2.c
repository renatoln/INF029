#include <stdio.h>

int soma();

int main(){	
	int res;
	res = soma();
	printf("%d", res);
	return 0;
}

int soma(){
	int x, y, resultado;
	scanf("%d", &x);
	scanf("%d", &y);
	resultado = x + y;
	return resultado;
	
}

