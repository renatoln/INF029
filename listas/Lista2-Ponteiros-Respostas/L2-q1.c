#include <stdio.h>
#include <string.h>


int main()
{
    //definindo variáveis primitivas
    int i;
    char c;
    char nome[10];
    float valor;

    //definindo variáveis de ponteiro
    int *p_i;
    char *p_c;
    char *p_nome;
    float *p_valor;

    //setando valores das variáveis primitivas
    i = 1;
    c = 'R';
    strcpy(nome, "Renato");
    valor = 10.0;

    //associar o ponteiro à uma variável primitiva 
    // (inicalizar um ponteiro = fazer ele apontar para um lugar válido)

    p_i = &i;
    p_c = &c;
    p_nome = nome;
    p_valor = &valor;

    //manipular o conteúdo de onde o ponteiro está apontando, usando os ponteiros

    *p_i = 5;
    *p_c = 'O';
    p_nome[0] = 'I';
    *p_valor = 5.0;



}