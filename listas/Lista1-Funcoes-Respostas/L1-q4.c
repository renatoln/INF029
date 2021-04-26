
#include <stdio.h>

typedef struct
{
    int a;
} Data;

void fazAlgo(int a, int vet[]);

int main()
{
    int meuVetor[3];
    meuVetor[0] = 11;
    meuVetor[1] = 22;
    meuVetor[2] = 33;
    int a = 10;
    fazAlgo(a, meuVetor);
    printf("%d\n", meuVetor[0]);
    printf("%d\n", meuVetor[1]);
    printf("%d\n", meuVetor[2]);
    printf("%d\n", a);
}

void fazAlgo(int a, int vet[])
{

    vet[0] = 1;
    vet[1] = 2;
    vet[2] = 3;
    a = 4;
}