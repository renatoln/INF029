#include <stdio.h>
#define TAM 3

int main(){ 
    int idade[TAM];
    char sexo[TAM];

    for (int i = 0; i < TAM; i++){
        printf("Digite a idade: ");
        scanf("%d", &idade[i]);
        getchar();
        printf("Digite a sexo: ");
        scanf("%c", &sexo[i]);
    }

    for (int i = 0; i < TAM; i++){
        printf("Idade: %d - Sexo: %c\n", idade[i], sexo[i]);
    }

}