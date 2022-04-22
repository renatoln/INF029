#include <stdio.h>

void imprimePares(int n);

int main()
{
	int n = 20;
	imprimePares(n);


}


void imprimePares(int n){
	//printf("%d\n", n);
	if (n % 2 == 0)
		printf("%d\n", n);

	if (n > 0)
		imprimePares(n-1);
	
}