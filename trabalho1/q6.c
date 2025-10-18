
#include <stdio.h>

/*
A linha de raciocínio na q6 é parecida com a q3/q4. 
Na q3/q4 (discutido em sala) varremos a strTexto até 
achar o primeiro caracter igual ao primeiro caracter 
de strBusca. Quando acha, varremos strBusca até o 
fim para ver se tem ela toda. É exateamente esse o processo. 
Na q6 que ta na pasta, eu já fiz a primeira parte, 
eu varro o numerobase para encontrar o primeiro 
digito igual o primeiro digito de numerobusca. 
Falta agora varrer o numerobusca para ver se 
todos os digitos sao iguais. se nao for, eu devo 
recomeçar o processo. assim como foi feito em q3/q4
*/

int q6_simplificada(int numerobase, int numerobusca);
int q6(int numerobase, int numerobusca);
int main(){

    printf("%d\n", q6_simplificada(1234, 4));
    printf("%d\n", q6_simplificada(1434, 4));
    printf("%d\n", q6_simplificada(1211, 1));
    printf("%d\n", qq6_simplificada6(1211, 9));

}

/*
Nesta questão simplificada, é buscado apenas um número.
*/
int q6_simplificada(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int restoNumerobase;
    while (numerobase > 0){
        
        restoNumerobase = numerobase % 10;
        if (restoNumerobase == numerobusca) 
            qtdOcorrencias ++;

        numerobase = numerobase / 10;
    }

    return qtdOcorrencias;
}


int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int restoNumerobase;
    while (numerobase > 0){
        
        restoNumerobase = numerobase % 10;
        if (restoNumerobase == numerobusca) 
        {
            /*como achou o primeiro número é preciso
            agora varrer o numerobusca para ver se os 
            outros digitos são iguais. 
            Se todos forem ai sim contabiliza.
            */

        }

        numerobase = numerobase / 10;
    }

    return qtdOcorrencias;
}