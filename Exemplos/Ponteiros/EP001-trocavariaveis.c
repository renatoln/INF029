#include <stdio.h>
#include <stdlib.h>

/*Troca de variáveis*/

void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(){
	int x, y;

	printf("Digite x: ");
	scanf("%d", &x);
	printf("\nDigite y: ");
	scanf("%d", &y);	
	troca(&x, &y);
	printf("\n x = %d; y = %d\n", x, y);

	return 0;

}