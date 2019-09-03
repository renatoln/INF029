#include <stdio.h> 
#include <stdlib.h>

#include "EstruturaVetores.h"

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeListar();

int main(){
    inicializar();
    testeInserirSemNada();
    testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    testeListar();
    finalizar();

}  

void testeInserirSemNada(){
    //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d\n",inserirNumeroEmEstrutura(2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",inserirNumeroEmEstrutura(2, -2) == POSICAO_INVALIDA);
    printf("%d\n",inserirNumeroEmEstrutura(2, 0) == POSICAO_INVALIDA);
    printf("%d\n",inserirNumeroEmEstrutura(2, 11) == POSICAO_INVALIDA);
} 


void testeCriarEstrutura(){
    //###  int criarEstruturaAuxiliar(int tamanho, int posicao); ###
    printf("%d\n",criarEstruturaAuxiliar(5, -2) == POSICAO_INVALIDA);
    printf("%d\n",criarEstruturaAuxiliar(5, 0) == POSICAO_INVALIDA);
    printf("%d\n",criarEstruturaAuxiliar(5, 11) == POSICAO_INVALIDA);
    printf("%d\n",criarEstruturaAuxiliar(-5, 2) == TAMANHO_INVALIDO);
    printf("%d\n",criarEstruturaAuxiliar(0, 2) == TAMANHO_INVALIDO);
    printf("%d\n",criarEstruturaAuxiliar(3, 2) == SUCESSO);
    printf("%d\n",criarEstruturaAuxiliar(6, 2) == JA_TEM_ESTRUTURA_AUXILIAR);
}


void testeInserirComEstrutura(){
    //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d\n",inserirNumeroEmEstrutura(4, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(-2, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(6, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(5, 2) == SEM_ESPACO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);

} 

void testeExcluir(){
    //###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(0) == POSICAO_INVALIDA);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == ESTRUTURA_AUXILIAR_VAZIA);
} 

void testeListar(){
    //###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###
    printf("%d\n",inserirNumeroEmEstrutura(7, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(-9, 2) == SUCESSO);
    
    int vet[2];

    printf("%d\n",getDadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",getDadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("%d\n",getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("%d\n",vet[0] == 7);
    printf("%d\n",vet[1] == -9);

    printf("%d\n",getDadosOrdenadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n",getDadosOrdenadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("%d\n",getDadosOrdenadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("%d\n",vet[0] == -9);
    printf("%d\n",vet[1] == 7);

} 
