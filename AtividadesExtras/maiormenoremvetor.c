/*
Faça uma programa que defina um vetor de 10 posições no main(). Deve existir (pelo menos) três funções, conforme determinado a seguir:
i) preencherVetor(…..), que interage com o usuário para preencher os dados no vetor;
ii) descobreMaiorMenor(……), que identifica o maior e menor valor existente no vetor;
iii) imprimeMaiorMenor(….) que imprime os valores maior e  menor identificados na função anterior.
Todas as três funções devem ser chamadas apenas a partir do main().
*/

#include <stdio.h>
#define TAM 5

typedef struct val{
    int maior;
    int menor;
} MaiorMenor;

void preencherVetor(int lista[]);
MaiorMenor descobreMaiorMenor(int lista[]);
void imprimeMaiorMenor(MaiorMenor mm);
void imprimeMaiorMenor2(int maior, int menor);

int main(){
    
    int vetor[TAM];
    MaiorMenor mm;
    preencherVetor(vetor);
    mm = descobreMaiorMenor(vetor);
    imprimeMaiorMenor(mm);
    imprimeMaiorMenor2(mm.maior, mm.menor);
    
    return 0;
}

void preencherVetor(int lista[]){
    int i = 0;
    
    for (; i < TAM; i++){
        printf("Digite um valor:\n");
        scanf("%d", &lista[i]);
    }
    
}

MaiorMenor descobreMaiorMenor(int lista[]){
    MaiorMenor mm;
    int maior = lista[0];
    int menor = lista[0];
    int i = 1;
    
    for (; i < TAM; i++){
        if (lista[i] > maior)
            maior = lista[i];
        if (lista[i] < menor)
            menor = lista[i];
    }
    
    mm.maior = maior;
    mm.menor = menor;
    
    return mm;
}

void imprimeMaiorMenor(MaiorMenor mm){
    printf("Maior: %d, Menor: %d", mm.maior, mm.menor);
    
}

void imprimeMaiorMenor2(int maior, int menor){
    printf("Maior: %d, Menor: %d", maior, menor);
    
}
