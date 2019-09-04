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
    testeRetornarTodosNumeros();
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
    
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n",excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);

} 


void testeRetornarTodosNumeros(){
    int vet1[2];
    printf("%d\n",getDadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    
    printf("%d\n",getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);
    
    printf("%d\n",inserirNumeroEmEstrutura(3, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(8, 2) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(0, 2) == SUCESSO);
    
    printf("%d\n",criarEstruturaAuxiliar(10, 5) == SUCESSO);
    
    printf("%d\n",inserirNumeroEmEstrutura(1, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(34, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(12, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(6, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(27, 5) == SUCESSO);
    printf("%d\n",inserirNumeroEmEstrutura(-6, 5) == SUCESSO);
    
    int vet[9];

    printf("%d\n",getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);
        
    printf("%d\n",vet[0] == 3);
    printf("%d\n",vet[1] == 8);
    printf("%d\n",vet[2] == 0);
    printf("%d\n",vet[3] == 1);
    printf("%d\n",vet[4] == 34);
    printf("%d\n",vet[5] == 12);
    printf("%d\n",vet[6] == 6);
    printf("%d\n",vet[7] == 27);
    printf("%d\n",vet[8] == -6);
    
    int vet2[9];
    
    printf("%d\n",getDadosOrdenadosDeTodasEstruturasAuxiliares(vet2) == SUCESSO);
        
    printf("%d\n",vet2[0] == -6);
    printf("%d\n",vet2[1] == 0);
    printf("%d\n",vet2[2] == 1);
    printf("%d\n",vet2[3] == 3);
    printf("%d\n",vet2[4] == 6);
    printf("%d\n",vet2[5] == 8);
    printf("%d\n",vet2[6] == 12);
    printf("%d\n",vet2[7] == 27);
    printf("%d\n",vet2[8] == 34);
    
    

}
