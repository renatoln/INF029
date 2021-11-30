#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

void show_log(char *str);

void testeInserirSemNada();
void testeCriarEstrutura();
void testeInserirComEstrutura();
void testeExcluir();
void testeExcluirNumeroEspecifico();
void testeListar();
void testeRetornarTodosNumeros();
void testeMudarTamanhoEstrutura();
void testeListaEncadeada();

int main()
{
    inicializar();
    testeInserirSemNada();
    /*testeCriarEstrutura();
    testeInserirComEstrutura();
    testeExcluir();
    testeExcluirNumeroEspecifico();
    testeListar();
    testeRetornarTodosNumeros();
    testeMudarTamanhoEstrutura();
    testeListaEncadeada();*/
    finalizar();
}
int ligado = 0;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}

void testeInserirSemNada()
{
    show_log("testeInserirSemNada()");
    printf("%d\n", inserirNumeroEmEstrutura(2, 2) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", inserirNumeroEmEstrutura(-2, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(0, 2) == POSICAO_INVALIDA);
    printf("%d\n", inserirNumeroEmEstrutura(11, 2) == POSICAO_INVALIDA);
}

void testeCriarEstrutura()
{
    show_log("testeCriarEstrutura()");
    printf("%d\n", criarEstruturaAuxiliar(-2, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(0, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(11, 5) == POSICAO_INVALIDA);
    printf("%d\n", criarEstruturaAuxiliar(2, -5) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(2, 0) == TAMANHO_INVALIDO);
    printf("%d\n", criarEstruturaAuxiliar(2, 3) == SUCESSO);
    printf("%d\n", criarEstruturaAuxiliar(2, 6) == JA_TEM_ESTRUTURA_AUXILIAR);
}
/*
2 [ , , ]
*/

void testeInserirComEstrutura()
{
    show_log("testeInserirComEstrutura()");
    //###  int inserirNumeroEmEstrutura(int valor, int posicao); ###
    printf("%d\n", inserirNumeroEmEstrutura(2, 4) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, -2) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
}
/*
2 [4,-2,6]
*/
void testeExcluir()
{
    show_log("testeExcluir()");
    //###  int excluirNumeroDoFinaldaEstrutura(int posicao); ###
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(0) == POSICAO_INVALIDA);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(1) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == ESTRUTURA_AUXILIAR_VAZIA);
}

/*
2 [ , , ]
*/

void testeExcluirNumeroEspecifico()
{
    show_log("testeExcluirNumeroEspecifico()");
    //###  int excluirNumeroEspecificoDeEstrutura(int posicao, int valor); ###
    printf("%d\n", criarEstruturaAuxiliar(9, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(9, 7) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 12) == NUMERO_INEXISTENTE);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 7) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(9, 4) == SUCESSO);
    printf("%d\n", excluirNumeroEspecificoDeEstrutura(1, 2) == SEM_ESTRUTURA_AUXILIAR);
}
/*
9 [ 4, , ] 
*/

void testeListar()
{
    show_log("testeListar()");
    //###  int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); ###
    printf("%d\n", inserirNumeroEmEstrutura(2, 7) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, -9) == SUCESSO);

    int vet[2];

    printf("%d\n", getDadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", getDadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("%d\n", vet[0] == 7);
    printf("%d\n", vet[1] == -9);

    printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(1, vet) == SEM_ESTRUTURA_AUXILIAR);
    printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(11, vet) == POSICAO_INVALIDA);
    printf("%d\n", getDadosOrdenadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("%d\n", vet[0] == -9);
    printf("%d\n", vet[1] == 7);

    printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);

    printf("%d\n", vet[0] == 7);
    printf("%d\n", vet[1] == -9);

    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
    printf("%d\n", excluirNumeroDoFinaldaEstrutura(2) == SUCESSO);
}

/*
2 [ , , ]
*/

void testeRetornarTodosNumeros()
{
    show_log("testeRetornarTodosNumeros()");
    int vet1[2];
    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet1) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS);

    printf("%d\n", inserirNumeroEmEstrutura(2, 3) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 8) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 0) == SUCESSO);
    /*
2 [3,8,0]
*/

    printf("%d\n", criarEstruturaAuxiliar(5, 10) == SUCESSO);

    printf("%d\n", inserirNumeroEmEstrutura(5, 1) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 34) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 12) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, 27) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(5, -6) == SUCESSO);
    /*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/
    int vet[9];

    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);

    printf("%d\n", vet[0] == 3);
    printf("%d\n", vet[1] == 8);
    printf("%d\n", vet[2] == 0);
    printf("%d\n", vet[3] == 1);
    printf("%d\n", vet[4] == 34);
    printf("%d\n", vet[5] == 12);
    printf("%d\n", vet[6] == 6);
    printf("%d\n", vet[7] == 27);
    printf("%d\n", vet[8] == -6);

    int vet2[9];

    printf("%d\n", getDadosOrdenadosDeTodasEstruturasAuxiliares(vet2) == SUCESSO);

    printf("%d\n", vet2[0] == -6);
    printf("%d\n", vet2[1] == 0);
    printf("%d\n", vet2[2] == 1);
    printf("%d\n", vet2[3] == 3);
    printf("%d\n", vet2[4] == 6);
    printf("%d\n", vet2[5] == 8);
    printf("%d\n", vet2[6] == 12);
    printf("%d\n", vet2[7] == 27);
    printf("%d\n", vet2[8] == 34);

    printf("%d\n", getDadosDeTodasEstruturasAuxiliares(vet) == SUCESSO);

    printf("%d\n", vet[0] == 3);
    printf("%d\n", vet[1] == 8);
    printf("%d\n", vet[2] == 0);
    printf("%d\n", vet[3] == 1);
    printf("%d\n", vet[4] == 34);
    printf("%d\n", vet[5] == 12);
    printf("%d\n", vet[6] == 6);
    printf("%d\n", vet[7] == 27);
    printf("%d\n", vet[8] == -6);
}
/*
2 [3,8,0]
5 [1,34,12,6,27,-6, , , , ]
*/

/*
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
void testeMudarTamanhoEstrutura()
{
    show_log("testeMudarTamanhoEstrutura()");
    int vet[1];
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -3) == NOVO_TAMANHO_INVALIDO);
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -4) == NOVO_TAMANHO_INVALIDO);
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(11, 7) == POSICAO_INVALIDA);
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(0, 7) == POSICAO_INVALIDA);
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(1, 7) == SEM_ESTRUTURA_AUXILIAR);

    //modificar para tamanho de 3 para 1
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, -2) == SUCESSO);
    printf("%d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
    printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
    printf("%d\n", vet[0] == 3);

    //modificar para tamanho de 1 para 4
    printf("%d\n", modificarTamanhoEstruturaAuxiliar(2, 3) == SUCESSO);
    printf("%d\n", getQuantidadeElementosEstruturaAuxiliar(2) == 1);
    printf("%d\n", getDadosEstruturaAuxiliar(2, vet) == SUCESSO);
    printf("%d\n", vet[0] == 3);

    printf("%d\n", inserirNumeroEmEstrutura(2, 4) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, -2) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 6) == SUCESSO);
    printf("%d\n", inserirNumeroEmEstrutura(2, 5) == SEM_ESPACO);
}

/*
2 [3,4,-2,6]
5 [1,34,12,6,27,-6, , , , ]
*/

void testeListaEncadeada()
{
    show_log("testeListaEncadeada()");
    int vet[10];
    No *inicio = montarListaEncadeadaComCabecote();
    getDadosListaEncadeadaComCabecote(inicio, vet);

    printf("%d\n", vet[0] == 3);
    printf("%d\n", vet[1] == 4);
    printf("%d\n", vet[2] == -2);
    printf("%d\n", vet[3] == 6);
    printf("%d\n", vet[4] == 1);
    printf("%d\n", vet[5] == 34);
    printf("%d\n", vet[6] == 12);
    printf("%d\n", vet[7] == 6);
    printf("%d\n", vet[8] == 27);
    printf("%d\n", vet[9] == -6);

    destruirListaEncadeadaComCabecote(&inicio);

    printf("%d\n", inicio == NULL);
}
