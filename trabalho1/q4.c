#include <stdio.h>
#include <string.h>

int main()
{

    char texto[100] = "áóôéRenatoêíÚûç";
    int texto_int[100];
    int texto_int2[100];
    int i, j;
    printf("Impressão 1\n");
    for (i = 0; texto[i] != '\0'; i += 2)
    {
        printf("%c : ", texto[i]);
        printf("%d, %d\n", texto[i], texto[i + 1]);

        texto_int[i] = texto[i];
        texto_int[i + 1] = texto[i + 1];
    }

    printf("Numeros \n");
    for (j = 0; j < i; j++)
    {
        printf("%i\n", texto_int[j]);
    }

    printf("copia \n");
    int k = 0;
    for (j = 0; j < i; j++)
    {
        if (texto_int[j] != -61)
        {
            texto_int2[k] = texto_int[j];
            k++;
        }
    }

    printf("Numeros copiados \n");

    for (j = 0; j < k; j++)
    {

        printf("%i\n", texto_int2[j]);
    }
}
