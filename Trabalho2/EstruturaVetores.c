#include <stdio.h> 
#include <stdlib.h>
#define TAM 10


#include "EstruturaVetores.h"

int vetorPrincipal[TAM];

void dobrar(int *x){
    
    *x = *x * 2;
    
    
}


int criarEstruturaAuxiliar(int tamanho, int posicao){
    
    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;

    return retorno;

}

/*
Rertono (int)
    1 - inserido com sucesso
    2 - não tem espaço
    3 - Não tem estrutura auxiliar

CONSTANTES
*/ 
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    
    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else{
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar){
          if (temEspaco){
              //insere 
              retorno = SUCESSO;  
          }else{
              retorno = SEM_ESPACO;
          }
        }else{
          retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }  
  
    return retorno;

}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}

int listaEstruturaAuxiliar(int posicao){
    
    int retorno = 0;

    if (ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }else{
        //print
        retorno = SUCESSO;
    }   

    return retorno;

}

