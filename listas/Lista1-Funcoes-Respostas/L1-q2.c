#include <stdio.h>

//assinaturas das funções
int subtrai(int x, int y, int k);

int main()
{
    int a, b, c, resultado;
    a = 5;
    b = 6;
    c = 9;

    resultado = subtrai(a, b, c);

    printf("A subtração  entre %d, %d e %d eh %d\n", a, b, c, resultado);
    return 1;
}

int subtrai(int x, int y, int k)
{
    int res = x - y - k;
    return res;
}
