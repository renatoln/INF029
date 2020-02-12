#include <stdio.h>
#include <string.h>

//questão para calcular a diferença entre duas datas

int main (){
    char datainicial[11], datafinal[11];
    strcpy(datainicial,"10/06/2015");
    strcpy(datafinal,"20/03/2019");
    
    int iDiaInicial, iMesInicial, iAnoInicial;
    int iDiaFinal, iMesFinal, iAnoFinal;
    int qtdAnos, qtdMeses, qtdDias;
    
    //fazer as validações iniciais
    //tranformar de string para os inteiros
    
    qtdDias = iDiaFinal - iDiaInicial;
    qtdMeses = iMesFinal - iMesInicial;
    qtdAnos = iAnoFinal - iAnoInicial;
    
    if (qtdMeses < 0){
        qtdAnos--;
        qtdMeses = 12 + iMeses;
    }
    if (qtdDias < 0){
        qtdMeses--;
        qtdDias = QuantidadeDeDiasMesAnterior(iMesFinal) - iDiaInicial + iDiaFinal;
    }
    
    
    
    
    
    
    
    
    
}    
