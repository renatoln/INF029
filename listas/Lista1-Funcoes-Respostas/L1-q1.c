#include <stdio.h>

//assinaturas das funções
int soma(int x, int y);

int main()
{
    int a, b, resultado;
    a = 5;
    b = 6;

    resultado = soma(a, b);

    printf("A soma entre %d e %d eh %d\n", a, b, resultado);
    return 1;
}

int soma(int x, int y)
{
    int res = x + y;
    return res;
}
