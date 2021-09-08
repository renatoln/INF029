#include <stdio.h>

typedef struct
{
    int num1;
    int num2;
    int num3;
    int num4;
} Numeros;

Numeros lerNumeros();
void imprimeNumeros(Numeros myNumbers);

int main(){
	Numeros meusNumeros;

	meusNumeros = lerNumeros();

	imprimeNumeros(meusNumeros);

}

Numeros lerNumeros(){
	Numeros numeros;
	printf("Digite o primeiro valor\n");
	scanf("%d", &numeros.num1);

	printf("Digite o segundo valor\n");
	scanf("%d", &numeros.num2);

	printf("Digite o terceiro valor\n");
	scanf("%d", &numeros.num3);

	printf("Digite o quarto valor\n");
	scanf("%d", &numeros.num4);

	return numeros;
}

void imprimeNumeros(Numeros myNumbers){
	printf("Valor 1: %d\n", myNumbers.num1);
	printf("Valor 2: %d\n", myNumbers.num2);
	printf("Valor 3: %d\n", myNumbers.num3);
	printf("Valor 4: %d\n", myNumbers.num4);
}