#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();

void dobrar(int *x);

int menu()
{
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma estrutura\n");
    printf("4 - Dobrar Numero\n");
    printf("5 - \n");
    scanf("%d", &op);
    return op;
}

int main()
{
    inicializar();
    int op;
    int sair = 0;
    int ret;
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            finalizar();
            break;
        }
        case 1:
        { //inserir
            //TODO
            ret = inserirNumeroEmEstrutura(5, 25);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem Espaço");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar");
            }
            break;
        }

        case 2:
        { //excluir
            //TODO
            break;
        }

        case 3:
        { //recuperar dados estrutura auxiliar
            int posicao, retorno;
            printf("Qual a estrutura a ser listada (1..10)?");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição inválida");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

                if (retorno == SUCESSO)
                {
                    //imprimir para os dados para o usuário
                    int i = 0;
                    for (; i < qtd; i++)
                    {
                        printf("%d", vetorAux[i]);
                    }
                }
            }
            break;
        }

        case 10:
        { //dobrar
            //ler um numero
            int valor;
            scanf("%i", &valor);

            dobrar(&valor);

            //passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)

            printf("%i", valor);

            break;
        }

        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    return 0;
}
